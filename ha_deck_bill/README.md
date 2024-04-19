這裡著重如何自己規劃撰寫專屬的操作頁面。

##螢幕解析度480*480

先說一下自帶的按鈕定位點，以正方形畫面區分16區
![Mosquitto_broker](/ha_deck_bill/image/143924.png)


    1-1  1-2  1-3  1-4
    2-1  2-2  2-3  2-4
    3-1  3-2  3-3  3-4
    4-1  4-2  4-3  4-4

    1-1定位點:8,8
    1-2定位點:126,8
    1-3定位點:244,8
    1-4定位點:362,8
    2-1定位點:8,127
    2-2定位點:126,127
    2-3定位點:244,127
    2-4定位點:362,127
    3-1定位點:8,246
    3-2定位點:126,246
    3-3定位點:244,246
    3-4定位點:362,246
    4-1定位點:8,365
    4-2定位點:126,365
    4-3定位點:244,365
    4-4定位點:362,365

指定"button"定位點後若沒特別參數，自帶默認大小，若加上dimensions參數，可以自訂button大小。

        - type: button #元件類別 
          position: 126, 8  #定位點  1-2 
          dimensions: 228x96  #指定元件大小(兩個默認大小的參數) 位置涵蓋1-2~1-3 (刪掉這行變常規正方形大小)
          text: "Livingroom"  #顯示文字(只能用英文)
          icon: 󰀛   # 只能用HA自帶，稍後說明
          # toggle: true  #是否要觸發
          enabled: return true;  #狀態顏色是否顯示
          checked: |-  #狀態判斷程序碼
            if(id(climate_state).state != "off") { return 1; }
            else { return 0; }
            
![Mosquitto_broker](/ha_deck_bill/image/152844.png)

解析一下整個畫面說明。

    substitutions:
      SCREEN_MAIN: main
      SCREEN_ROOMS: rooms
      SCREEN_KITCHEN: kitchen
      SCREEN_LED: led
      SCREEN_MEDIA: media
      SCREEN_LIVCLIMATE: livclimate
      
指定頁面名稱，一個SCREEN一個參數，例如要增加一格臥室頁面如下。

    SCREEN_BEDROOM: bedroom

指定esp32芯片參數。需下載.csv檔案，放在HA裡面esphome資料夾中。(原創有兩個檔案，試過都能用也不清楚實際差在哪裡)

    esphome:
      name: "ha-deck-3d68"
      friendly_name: "HA Deck 3d68"
      platformio_options:
        board_upload.maximum_ram_size: 327680
        board_upload.maximum_size: 16777216
        board_build.partitions: "/config/esphome/custom_partitions_8128.csv"  # "/config/esphome/custom_partitions_3584.csv" #
        board_build.arduino.memory_type: qio_opi

指定 external

    external_components:
      - source:
          type: git
          url: https://github.com/strange-v/ha_deck
          ref: main
        components: [ hd_device_wt32s3_86s, ha_deck ]

做個台灣的時間id

    time:
      - platform: sntp  #定義時間參數
        id: sntp_time
        timezone: Asia/Taipei
        on_time:
          - cron: '* * * * * *'
            then:
              lambda: |-
                char buff[10] = "-";
                auto time = id(sntp_time).now();
                if (time.is_valid())
                  sprintf(buff, "%02d:%02d:%02d", time.hour, time.minute, time.second);
                id(local_time).set_value(std::string(buff));

做兩個調整畫面亮度的entity
                
    number:
      - platform: template   # 定義螢幕亮度參數
        id: screen_brightness
        # name: Active screen brightness
        min_value: 0
        max_value: 100
        step: 5
        initial_value: 75   # 活躍中默認亮度75
        restore_value: true
        set_action:
          - lambda: |-
              if (!id(deck).get_inactivity())
                id(device).set_brightness(x);
    
      - platform: template  # 定義螢幕亮度參數
        id: inactive_screen_brightness
        # name: Inactive screen brightness
        min_value: 0
        max_value: 100
        step: 5
        initial_value: 20  # "非" 活躍中默認亮度20
        restore_value: true
        set_action:
          - lambda: |-
              if (id(deck).get_inactivity())
                id(device).set_brightness(x);

照抄

    output:
      - platform: ledc  
        pin: 10
        id: out_10
        
    hd_device_wt32s3_86s:
      id: device
      brightness: 75            

UI主程序60秒自動回主畫面並黑屏

    ha_deck:
      id: deck
      main_screen: ${SCREEN_MAIN}  # 設備參數
      inactivity:
        period: 60 # seconds 60秒回主畫面
        blank_screen: true  #休眠黑畫面有效
      on_inactivity_change:
        lambda:  |-
          if (x) {
            id(device).set_brightness(id(inactive_screen_brightness).state);
          } else {
            id(device).set_brightness(id(screen_brightness).state);
          }

首頁兩個元件示範
    
    - name: ${SCREEN_MAIN} 
      widgets:
        - type: value-card #  1-1 (時鐘)
          id: local_time
          position: 8, 8
          text: "Taiwan"
          enabled: return true;

        - type: value-card  #1-2 (溫度)
          id: livingroom_temperature
          position: 126, 8  
          text: "°C"
          icon: 󰔏
          # unit: °C
          enabled: return true;
          value: |-
            char buff[10] = "-";
            sprintf(buff, "%.1f", id(living_temperature).state);   #這個ID來自以下 sensor: 自訂義，抓取HA的entity同步。
            return std::string(buff);  

        - type: value-card  #1-3 (天氣預報)
          id: livingroom_humidity
          position:  244, 8
          dimensions: 228x96          
          text: "Weather Forecast"
          # icon: 󰖎
          # unit: °C
          enabled: return true;
          value: |-
             return id(weather_state).state;  # 個ID來自以下 text_sensor: 自訂義，抓取HA的entity同步。
          on_click:
            lambda: |-
                id(deck).switch_screen("$SCREEN_ROOMS");   #按下後跳到SCREEN_ROOMS 這個頁面

抓取HA的entity使用                    

    sensor:
      - platform: homeassistant #同步抓取HA客廳溫度數值
        id: living_temperature
        entity_id: sensor.livingroom_ikea_air_quality_livingroom_temperatur

    text_sensor:
      - platform: homeassistant #同步抓取HA中央氣象局天氣預報文字
        id: weather_state
        entity_id: sensor.opencwb_forecast_condition 


支援ICON 網站 (先到這個網站找尋喜歡的)

https://pictogrammers.com/docs/library/mdi/guides/home-assistant/


抓取ICON 網站 用這個網站搜尋同一個icon，點選紅圈圈copy icon 再貼到esphome裡面即可。

https://pictogrammers.com/library/mdi/

![Mosquitto_broker](/ha_deck_bill/image/163739.png)

參考網站

https://github.com/strange-v/ha_deck

https://www.youtube.com/watch?v=NPr9ryyTVB4&ab_channel=strange_v

https://github.com/ivan-rio/ha_deck_cyd

https://www.youtube.com/watch?v=NtF0wyf12DM&t=317s&ab_channel=%D0%86%D0%B2%D0%B0%D0%BDRIO
