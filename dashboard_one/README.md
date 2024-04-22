無法支持中文顯示，無法改變字體大小，無法放大icon，要更換底圖有問原創還沒回答我，能接受再往下看。

# 認識sample yaml檔案

default_sample.yaml  出廠默認基本畫面(建議重這裡開始學習)

full_complete_sample.yaml  全功能範例

SCREEN_CURTAIN.yaml  窗簾控制畫面範例

SCREEN_LIVCLIMATE.yaml 冷氣控制畫面範例

SCREEN_MEDIA.yaml 媒體播放控制畫面範例

SCREEN_SETUP.yaml 參數設置畫面範例




# 第一步接入HA 並打開 "允許裝置呼叫HA服務"

上電(請用獨立豆腐頭供電，若不足瓦的供電會出錯)，手機搜尋設備熱點(需稍等片刻請耐心等候) 指定自家wifi與密碼，HA應該就會辨識到了，導入HA記住設備默認名稱。dashboard-one-XXXX

![Mosquitto_broker](/dashboard_one/image/174818.png)

# 進入ESPHome開發模式開始編譯dashboard-one

## 步驟 0

HA附加元件安裝ESPHome(已安裝略)，然後把custom_partitions_3584.csv 複製到 HA的 config\esphome\ 裡面，否則編譯時會報錯。

## 步驟 1

進入ESPHome UI介面點選右下角 "+ NEW DEVICE"  選 "CONTINUE" 輸入 dashboard-one-XXXX (XXXX請替換自己的設備編號)  選"NEXT"，選esp32 選 SKIP，如果ESPHome顯示ONLINE代表成功一半了，接下來一定要注意，操作錯誤就會死機。(沒出現ONLINE很大的可能是沒弄對自已的設備編號，刪掉重來)

![Mosquitto_broker](/dashboard_one/image/163202_1.png)

## 步驟 2

點選 "EDIT" 進入編輯頁面把自帶的程式碼刪除，替換成 default_sample.yaml 的內容

*** 然後注意注意 一定要替換成自己的設備號碼 才能按右上 "SACVE" and "INSTALL" ***

*** 然後注意注意 一定要替換成自己的設備號碼 才能按右上 "SACVE" and "INSTALL" ***

*** 然後注意注意 一定要替換成自己的設備號碼 才能按右上 "SACVE" and "INSTALL" ***

![Mosquitto_broker](/dashboard_one/image/165348.png)

停止呼吸，若有足夠的幸運應該會點亮螢幕成功，或連繫我回廠重灌~~




# 認識畫面
這裡著重如何自己規劃撰寫專屬的操作頁面。 #聲明這不是我原創的，文章最後有相關介紹，這裡只分享我使用心得。

## 螢幕解析度480*480

先說一下自帶的按鈕定位點，以正方形畫面區分16區
![Mosquitto_broker](/dashboard_one/image/143924_1.png)

## 畫面座標代號

    1-1  1-2  1-3  1-4
    2-1  2-2  2-3  2-4
    3-1  3-2  3-3  3-4
    4-1  4-2  4-3  4-4

##  座標代號 VS 像素落點位置 

    座標 1-1 : 落點 8,8
    座標 1-2 : 落點 126,8
    座標 1-3 : 落點 244,8
    座標 1-4 : 落點 362,8
    座標 2-1 : 落點 8,128
    座標 2-2 : 落點 126,128
    座標 2-3 : 落點 244,128
    座標 2-4 : 落點 362,128
    座標 3-1 : 落點 8,248
    座標 3-2 : 落點 126,248
    座標 3-3 : 落點 244,248
    座標 3-4 : 落點 362,248
    座標 4-1 : 落點 8,368
    座標 4-2 : 落點 126,368
    座標 4-3 : 落點 244,368
    座標 4-4 : 落點 362,368
    
##  默認小部件大小 VS 自定義大小




# 畫面的組成階層

    ha_deck: (總屏幕,只能一個480*480解析度)
        |
        | screens: (頁面,可以很多頁)
            |
            | widgets: (小部件, 有三類一頁建議最多16個)
                |
                | - type: value-card
                | - type: button
                | - type: slider

    value-card (only 數據或文字顯示) 
    button (按鈕，按下後需要執行命令使用)
    slider (滑快， 調整指數用例如電燈亮度)
           

            
![Mosquitto_broker](/dashboard_one/image/152844.png)

# 解析一下整個default_sample.yaml重要程序碼(有錯煩請指正)

    substitutions:
      SCREEN_MAIN: main
      SCREEN_ROOMS: rooms
      SCREEN_KITCHEN: kitchen
      SCREEN_SETUP: setup
      SCREEN_MEDIA: media
      SCREEN_LIVCLIMATE: livclimate
            
### 指定頁面名稱

要增加一個臥室頁面方式如下。

    SCREEN_BEDROOM: bedroom

### 指定esp32芯片參數

需下載.csv檔案，放在HA的esphome資料夾中。(原創有兩個檔案，試過都能用也不清楚實際差在哪裡，有高手可反饋給我差異點)

    esphome:
      name: "ha-deck-3d68"
      friendly_name: "HA Deck 3d68"
      platformio_options:
        board_upload.maximum_ram_size: 327680
        board_upload.maximum_size: 16777216
        board_build.partitions: "/config/esphome/custom_partitions_3584.csv"  # "/config/esphome/custom_partitions_8128.csv" #
        board_build.arduino.memory_type: qio_opi

###　指定 external 

打包畫面全局使用參數，方便簡易，缺點是使用者修改門檻高，建議別糾結在缺點上而是盡量享受優點

    external_components:
      - source:
          type: git
          url: https://github.com/strange-v/ha_deck
          ref: main
        components: [ hd_device_wt32s3_86s, ha_deck ]

### 做個台灣的時間id

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

### 做兩個調整畫面亮度的entity
                
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

### 照抄

    output:
      - platform: ledc  
        pin: 10
        id: out_10
        
    hd_device_wt32s3_86s:
      id: device
      brightness: 75            

### UI主程序60秒自動回主畫面並黑屏

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

## 重點小部件運用示範

value-card 只要顯示文字或數字可使用，舉凡entity的state都適用。

button 按下後可以指定執行命令，也可以有反饋狀態的顏色呈現，例如主畫面用button跳到另一個頁面，另一個頁面透過button跳回來。

slider 調整參數用滑快，例如調整螢幕亮度數值，或窗簾打開的百分比。

    - name: ${SCREEN_MAIN} #主畫面
      widgets:  # 定義該畫面小部件
        - type: value-card #  1-1 ( value-card 時鐘)
          id: local_time #把上面建立的Asia/Taipei id抓過來用
          position: 8, 8 #小部件落點座標
          text: "Taiwan"
          enabled: return true;

        - type: value-card  #1-2 (value-card 調用HA裡的溫度entity)
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
