無法支持中文顯示，無法改變字體大小，無法放大icon，能接受再往下看。

## 接入HA

上電(請用單獨豆腐頭給電，不足瓦的供電會出錯)，手機搜尋設備熱點(需稍等片刻請耐心等候) 指定自家wifi與密碼，HA應該就會辨識到了，導入HA記住設備默認名稱。dashboard-one-XXXX

## 進入ESPHome開發模式開始編譯dashboard-one

HA附加元件安裝ESPHome(已安裝者略過)，進入ESPHome UI介面點選右下角 "+ NEW DEVICE"  選 "CONTINUE" 輸入 dashboard-one-XXXX (XXXX請替換你的設備編號)  選"NEXT"，選esp32 選 SKIP，如果ESPHome顯示ONLINE代表成功一半了，接下來一定要注意，操作錯誤就會死機。

![Mosquitto_broker](/dashboard_one/image/163202.png)


點選 "EDIT" 進入編輯頁面把自帶的程式碼刪除，替換為 default_sample.yaml 的內容

*** 然後注意注意 XXXX 替換成自己的設備號碼 才能按右上 "SACVE" and "INSTALL" ***

*** 然後注意注意 XXXX 替換成自己的設備號碼 才能按右上 "SACVE" and "INSTALL" ***

*** 然後注意注意 XXXX 替換成自己的設備號碼 才能按右上 "SACVE" and "INSTALL" ***

![Mosquitto_broker](/dashboard_one/image/165348.png)

有足夠幸運的話應該會點亮螢幕了~~

## 檔案介紹

default_sample.yaml  出廠默認基本畫面(建議重這裡開始學習)

SCREEN_CURTAIN.yaml  窗簾控制畫面範例

SCREEN_LIVCLIMATE.yaml 冷氣控制畫面範例

SCREEN_MEDIA.yaml 媒體播放控制畫面範例

SCREEN_SETUP.yaml 參數設置畫面範例

full_complete_sample.yaml  全功能範例


## 認識畫面
這裡著重如何自己規劃撰寫專屬的操作頁面。 #聲明這不是我原創的，文章最後有相關介紹，這裡只分享我使用心得。

##螢幕解析度480*480

先說一下自帶的按鈕定位點，以正方形畫面區分16區
![Mosquitto_broker](/dashboard_one/image/143924.png)


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
          enabled: return true;  #反饋選項
          checked: |-  #狀態反饋程序碼
            if(id(climate_state).state != "off") { return 1; }
            else { return 0; }
            
![Mosquitto_broker](/dashboard_one/image/152844.png)

## 解析一下整個重要程序碼

    substitutions:
      SCREEN_MAIN: main
      SCREEN_ROOMS: rooms
      SCREEN_KITCHEN: kitchen
      SCREEN_SETUP: setup
      SCREEN_MEDIA: media
      SCREEN_LIVCLIMATE: livclimate
            
指定頁面名稱，一個SCREEN一個參數，例如要增加一個臥室頁面如下。

    SCREEN_BEDROOM: bedroom

指定esp32芯片參數。需下載.csv檔案，放在HA的esphome資料夾中。(原創有兩個檔案，試過都能用也不清楚實際差在哪裡，有高手可反饋給我差異點)

    esphome:
      name: "ha-deck-3d68"
      friendly_name: "HA Deck 3d68"
      platformio_options:
        board_upload.maximum_ram_size: 327680
        board_upload.maximum_size: 16777216
        board_build.partitions: "/config/esphome/custom_partitions_3584.csv"  # "/config/esphome/custom_partitions_8128.csv" #
        board_build.arduino.memory_type: qio_opi

指定 external (打包畫面全局使用參數，方便簡易，缺點是使用者修改門檻高，建議忽略缺點享受優點)

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

首頁4個元件示範 (基本上就是在主頁透過button 跳到另一個頁面，另一個頁面透過button跳回來)
    
    - name: ${SCREEN_MAIN} #主畫面
      widgets:  # 定義該畫面小部件
        - type: value-card #  1-1 (時鐘)
          id: local_time #把上面建立的Asia/Taipei id抓過來用
          position: 8, 8 #小部件落點座標
          text: "Taiwan"
          enabled: return true;

        - type: value-card  #1-2 (調用HA裡的溫度entity)
          id: livingroom_temperature
          position: 126, 8 
          text: "°C"
          icon: 󰔏  #如何置換icon見文章附錄說明
          # unit: °C # 目前沒用到
          enabled: return true;
          value: |-
            char buff[10] = "-";
            sprintf(buff, "%.1f", id(living_temperature).state);   #這個ID調用HA的entity見下方範例。
            return std::string(buff);  

        - type: value-card  #1-3 (天氣預報)
          id: livingroom_humidity
          position:  244, 8   
          dimensions: 228x96   #指定兩個小部件大小
          text: "Weather Forecast"
          # icon: 󰖎
          enabled: return true;
          value: |-
             return id(weather_state).state;  
             
        - type: button
          id: floors
          position: 126, 127 # 2-1 (進入房間頁面)
          text: "Rooms"
          icon: 󰠡
          enabled: return true;
          on_click:
            lambda: |-
                id(deck).switch_screen("$SCREEN_ROOMS");
                
        - type: button
          id: study
          position: 244, 127  #2-2 (一般Relay)
          text: "Study"
          icon: 󰟩
          toggle: true  #小部件觸發反饋
          enabled: return true;
          checked: |-
            if(id(study_relay_state).state == "on") { return 1; }  #同步study_relay_state 小部件背景反饋狀態
            else { return 0; }
          on_turn_on:  #處理按下後ON的動作
            - switch.turn_on:
                id: study_relay
            - homeassistant.service:  #直接控制HA裡面的entity
                service: switch.turn_on
                data:
                  entity_id: switch.hp_print_relay_device_relay #這是HA的entity
          on_turn_off: #處理按下後OFF的動作
            - switch.turn_off:
                id: study_relay
            - homeassistant.service:
                service: switch.turn_off
                data:
                  entity_id: switch.hp_print_relay_device_relay
             

## 調用HA的entity方法                    

    sensor:
      - platform: homeassistant #取得HA客廳溫度 "數值" 類用 sensor
        id: living_temperature
        entity_id: sensor.livingroom_ikea_air_quality_livingroom_temperatur
        
      - platform: homeassistant #取得HA客廳冷氣目前溫度濕度數值
        id: climate_current
        entity_id: climate.livingroom
        attribute: current_temperature
        unit_of_measurement: "°C"        

    text_sensor:
      - platform: homeassistant #取得HA中央氣象局天氣預報 "文字" 類用text_sensor 開關的on/off 也算是
        id: weather_state
        entity_id: sensor.opencwb_forecast_condition 
        
      - platform: homeassistant #取得HA書房插頭狀態
        id: study_relay_state
        entity_id: switch.hp_print_relay_device_relay
    
    switch:
      - platform: template  #書房插頭虛擬 開關 同步畫面用
        # name: "Study Relay"  
        id: study_relay
        optimistic: true 

基於以上的範例就可以自組一個專屬的控制面板，有任何疏漏或錯誤煩請告知謝謝。

## 附錄

支援ICON 網站 (先到這個網站找尋喜歡的，沒錯就這麼多)

https://pictogrammers.com/docs/library/mdi/guides/home-assistant/


抓取ICON 網站 用這個網站搜尋同一個icon，點選紅圈圈copy icon 再貼到程序碼正確位置即可。

https://pictogrammers.com/library/mdi/

![Mosquitto_broker](/dashboard_one/image/163739.png)

參考網站
