目前為止無法支持中文顯示，無法改變字體大小，無法放大icon，無法更換底圖，有問題都可發問，能接受再往下看。
本人不是原創，頁底有原創網頁連結，覺得有幫助可以贊助他喝一下咖啡。

# 認識sample yaml檔案

full_complete_sample.yaml  全功能範例-出廠默認

widgets_user_manual.pdf 小部件(widgets)詳細使用手冊

SCREEN_CURTAIN.yaml  窗簾控制畫面範例

SCREEN_LIVCLIMATE.yaml 冷氣控制畫面範例

SCREEN_MEDIA.yaml 媒體播放控制畫面範例

SCREEN_FAVORITE.yaml 參數設置畫面範例

SCREEN_ROOMS.yaml 各房間畫面範例

dashboard_one_客製化畫面說明.pdf  若沒空自建畫面可參考客製化方案

dashboard_one_客製化畫面說明_PTT.pptx 看完說明填寫ptt內容與作者溝通即可遠端完成客製化方案

# 第一步接入HA 並打開 "允許裝置呼叫HA服務"

上電(請用獨立豆腐頭供電，若不足瓦的供電會出錯)，因為預置自家wifi與密碼，HA應該會自己辨識到，導入HA記住設備默認名稱。dashboard-one-XXXXXX

![Mosquitto_broker](/dashboard_one/image/174818.png)

# 進入ESPHome開發模式開始編譯dashboard-one

## 步驟 0

HA附加元件安裝ESPHome(已安裝略，本篇以沒有安裝為例)

設定 > 附加元件 > 附加元件商店 > ESPHome > 安裝(稍待片刻) > 開啟WEB UI > 選右上角 "SECRETS" > 填入自家wifi SSID與密碼 > SAVE 。

![Mosquitto_broker](/dashboard_one/image/133935.png)

然後把custom_partitions_3584.csv 複製到 HA的 \config\esphome 裡面，否則編譯時會報錯(有些環境是\homeassistant\esphome 確定一下是哪個)。

## 步驟 1

進入ESPHome UI介面點選右下角 "+ NEW DEVICE"  選 "CONTINUE" 輸入 dashboard-one-XXXXXX (XXXXXX請替換自己的設備編號)  選"NEXT"，選esp32 選 SKIP，如果ESPHome顯示ONLINE代表成功一半了，接下來一定要注意，操作錯誤就會死機。(沒出現ONLINE很大的可能是沒弄對自已的設備編號，刪掉重來)(如何刪除, 點右下直三個小圓點 > 選Delete 即可)

![Mosquitto_broker](/dashboard_one/image/163202_1.png)

## 步驟 2

### 點選 "EDIT" 進入編輯頁面把full_complete_sample.yaml檔內容全數覆蓋原來的程式碼

### 修改產品序號取代XXXXXX內容 

### 修改產品序號取代XXXXXX內容 

### 修改產品序號取代XXXXXX內容 
![Mosquitto_broker](/dashboard_one/image/200656.png)

***  才能按右上 "SACVE" and "INSTALL" ***

![Mosquitto_broker](/dashboard_one/image/103407.png)

![Mosquitto_broker](/dashboard_one/image/102021.png)

![Mosquitto_broker](/dashboard_one/image/104052.png)

![Mosquitto_broker](/dashboard_one/image/103339.png)


停止呼吸，若有足夠的幸運應該會點亮螢幕成功，或連繫我回廠重灌~~


# 認識畫面
這裡著重如何自己規劃撰寫專屬的操作頁面。 #聲明這不是我原創的，文章最後有相關介紹，這裡只分享我使用心得。

## 螢幕解析度480*480

先說一下自帶的按鈕定位點，以正方形畫面區分16區
![Mosquitto_broker](/dashboard_one/image/143924_1.png)

## 畫面座標代號
![Mosquitto_broker](/dashboard_one/image/113553.png)

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

![Mosquitto_broker](/dashboard_one/image/113854.png)

# 畫面的組成階層

    ha_deck: (總屏幕,只能一個480*480解析度)
        |
        | screens: (頁面,可以很多頁)
            |
            | widgets: (小部件, 有三類可運用，一頁建議最多16個)
                |
                | - type: value-card
                | - type: button
                | - type: slider

                value-card (only 數據或文字顯示) 
                button (按鈕，按下後需要執行命令使用)
                slider (滑快， 調整指數用例如電燈亮度)
                           
# 解析一下整個full_complete_sample.yaml重要程序碼(有錯煩請指正)

### 指定esphome參數(以下若修改錯誤容易死機)

需下載custom_partitions_3584.csv檔案，放在HA的esphome資料夾中。(原創有兩個檔案，試過都能用也不清楚實際差在哪裡，有高手可反饋差異點)

    esphome:
      name: "dashboard-one-XXXXXX"  # 要修改成自己的號碼亂改會死機
      friendly_name: "dashboard-one-XXXXXX"  # ""內的文字可以改，例如 "Livingroom Dashboard"
      platformio_options:
        board_upload.maximum_ram_size: 327680
        board_upload.maximum_size: 16777216
        board_build.partitions: "/config/esphome/custom_partitions_3584.csv" 
        board_build.arduino.memory_type: qio_opi
        
esp32版本宣告以及必要參數

    esp32:
      board: esp32-s3-devkitc-1
      framework:
        type: arduino
      flash_size: 16MB
    logger:  
    api:
    ota:    
    web_server:
    
WIFI 參數宣告，為了避免每次燒寫後wifi需要重新綁定，可指定自家的wifi帳號與密碼，以下的程序碼是去參照secret檔案的內容，但須前置作業如下圖，方可正常運作。

![Mosquitto_broker](/dashboard_one/image/195334.png)

    wifi:
      ssid: !secret wifi_ssid
      password: !secret wifi_password
      ap: {}

找不到綁定的wifi時會跳出重新指定wifi的參數

    captive_portal:

### 指定頁面名稱(以下修改有錯不會死機)
    substitutions:
      SCREEN_MAIN: main
      SCREEN_ROOMS: rooms
      SCREEN_KITCHEN: kitchen
      SCREEN_FAVORITE: favorite
      SCREEN_MEDIA: media
      SCREEN_LIVCLIMATE: livclimate
      SCREEN_CURTAIN: curtain
            
要增加一個臥室頁面方式如下。

    SCREEN_BEDROOM: bedroom

###　指定 external 

打包畫面全局使參數，方便簡易，缺點是使用者想自訂修改門檻高，建議別糾結在缺點上而是盡量享受優點

    external_components:
      - source:
          type: git
          url: https://github.com/strange-v/ha_deck
          ref: main
        components: [ hd_device_wt32s3_86s, ha_deck ]

若要自行建構畫面參數，可以參考以下方案，把原先的external_components: 全部註解，到原PO github 網頁下載 ha_deck 以及hd_device_wt32s3_86s兩個資料夾檔案到自家自家/config/esphome/my_components 裡面並增加以下程序碼，即可。

     external_components:
       - source:
           type: local
           path: my_components

### 做個台灣的時間id sntp_time

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

### 做兩個調整亮度的entity
                
    number:
      - platform: template   # 定義活躍的entity螢幕亮度參數，與 enabled: return true; 搭配使用
        id: screen_brightness
        name: Active screen brightness
        min_value: 1
        max_value: 255
        step: 1
        initial_value: 75
        restore_value: true
        set_action:
          - lambda: |-
              if (!id(deck).get_inactivity())
                id(device).set_brightness(x);
    
      - platform: template ## 定義不活躍的entity螢幕亮度參數，見 (不活躍的小部件)
        id: inactive_screen_brightness
        name: Inactive screen brightness
        min_value: 0
        max_value: 255
        step: 1
        initial_value: 0
        restore_value: true
        set_action:
          - lambda: |-
              if (id(deck).get_inactivity())
                id(device).set_brightness(x);

### 默認螢幕亮度 75

    hd_device_wt32s3_86s:
      id: device
      brightness: 75            

### UI主程序60秒自動回主畫面並黑屏

    ha_deck:
      id: deck
      main_screen: ${SCREEN_MAIN}  # 設備參數，**沒事別動**
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

## 3類小部件type運用示範

value-card 只要顯示文字或數字可使用，舉凡entity的state都適用。

button 按下後可以指定執行命令，也可以有反饋狀態的顏色呈現，例如主畫面用button跳到另一個頁面，另一個頁面透過button跳回來。

slider 調整參數用滑快，例如調整電燈亮度數值。

        ...
        ...
        
        - type: value-card  #1-2 (value-card 調用HA裡的溫度entity)
          id: livingroom_temperature
          position: 126, 8 
          text: "°C"
          icon: 󰔏  #如何置換icon見文章附錄說明
          # unit: °C # 目前沒用到
          enabled: return true;
           #這個ID調用HA的entity見下方範例。
          value: |-
            char buff[10] = "-";
            sprintf(buff, "%.1f", id(living_temperature).state);  
            return std::string(buff);  

        ...
        ...
            
        - type: button
          position: 8, 127 # 2-1 (進入favorite頁面)
          text: "Favorite"
          icon: 󰋑
          enabled: return true;
          on_click:
            lambda: id(deck).switch_screen("$SCREEN_FAVORITE");  # 按下跳到favorite頁面


        ...
        ...
        
        - type: slider
          position: 155, 40
          dimensions: 60x255  # WLED亮度調整參數是0-255步，所以滑桿元件的大小 255 吻合
          min: 0
          max: 255
          enabled: return true;
          value: |-
            if(id(liv_light_brightness).state <= 255) { return id(liv_light_brightness).state; }
            else { return 0; }
          on_change:
            - homeassistant.service:
                service: light.turn_on
                data:
                  entity_id: light.wled
                  brightness: !lambda return x;
             

## 調用HA的entity方法                    

    sensor:  #"數值" 類用 sensor
      - platform: homeassistant #取得HA客廳溫度 
        id: living_temperature
        entity_id: sensor.livingroom_ikea_air_quality_livingroom_temperatur
        
      - platform: homeassistant #取得HA客廳冷氣目前溫度屬性數值
        id: climate_current
        entity_id: climate.livingroom
        attribute: current_temperature
        unit_of_measurement: "°C"        

    text_sensor:   #"文字" 類用text_sensor 開關的on/off 也算是
      - platform: homeassistant #取得HA中央氣象局天氣預報 
        id: weather_state
        entity_id: sensor.opencwb_forecast_condition 
        
      - platform: homeassistant #取得HA書房插頭狀態
        id: study_relay_state
        entity_id: switch.hp_print_relay_device_relay
    
    switch: #開關 同步畫面用
      - platform: template  #書房插頭虛擬 
        id: study_relay
        optimistic: true 

基於以上的範例就可以自組一個專屬的控制面板，有任何疏漏或錯誤煩請告知謝謝。

## 附錄

支援ICON 網站 (先到這個網站找尋喜歡的，沒錯就這麼多)

https://pictogrammers.com/docs/library/mdi/guides/home-assistant/


抓取ICON 網站 用這個網站搜尋同一個icon，點選紅圈圈copy icon 再貼到程序碼正確位置即可。

https://pictogrammers.com/library/mdi/

![Mosquitto_broker](/dashboard_one/image/163739.png)

參考原創網站
https://github.com/strange-v/ha_deck

備註: 第一次進入休眠畫面(黑畫面)會有點亮，這是請進入esphome裡面調整一下未觸發亮度就可以了，建議調整到1或0都可以。

![Mosquitto_broker](/dashboard_one/image/194122.png)

