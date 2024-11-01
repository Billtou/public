
# 像素燈熱點密碼 12345678

## 1. 設備上方3個觸控式開關操作說明
    * SD卡插在底部 像素燈熱點密碼 12345678
    * 產品上蓋三個按鍵分別是(左)、(下)、(右)。
    * (下)長按進入menu，再長按來開menu。
 
    示範修改亮度:
    *(下)長按出現BRIGHT，(下)短按出現x%，再按一次(下)出現AUTO。 在x%畫面按(左)減少 (右) 增加，確定設定值長按(下)回到MENU，再長按(下) 離開。
 
    常用選單說明
    menu
     - BRIGHT (亮度調節/auto)
     - COLOR (默認時間顯示顏色)
     - SWITCH
     - T-SPEED
     - APPTIME
     - TIME
     - DATE
     - WEEKDAY (設定一周第一天)
     - TEMP (不含溫溼度)
     - APPS (顯示內建輪播)打開時間日期即可。
     - SOUNS (喇叭on/off)
     - VOLUME (喇吧大小聲)
     - UPDATE
       其他沒事別亂調~


## 2. 像素燈接入Home Assostant

* ### 建立mqtt user (原已建立者可略)

    HA>設定>人員>使用者>新增使用者 mqtt-user，密碼我慣用mqtt-pass > 新增。
    ![Mosquitto_broker](/Pixel_Light/image/mqtt-user.png)
    HA>設定>附加元件>附加元件商店>Mosquitto Broker 安裝 > 啟動。
    ![Mosquitto_broker](/Pixel_Light/image/Mosquitto_broker.png)

## 3.像素燈上電連上自家wifi

    像素燈上電面板出現 AP MODE 手機搜尋 awtix_xxxxxx 熱點密碼是 12345678 再指定自家的wifi 帳號與密碼，正常就會連到家裡的wifi並出在畫面出現使用的IP位置。瀏覽器打入ip位置會出現 Web Service，選單MQTT填入(Broker欄位就是你HA的IP，Prefix欄位就是該設備在HA顯示的名稱)，並打開Homeassistant Discovery 讓HA能發現。

    ![Mosquitto_broker](/Pixel_Light/image/mqtt-login.png)

    選單 TIME NTP Server 填入 time.stdtime.gov.tw，Timezone填入 CST-8

    ![Mosquitto_broker](/Pixel_Light/image/timezone_1.png)

    完成按 Save configuration 後再按 Restart ESP ，重啟後正常HA就會發現，HA > 裝置與服務 > MQTT > awtrix_xxxxxx。

## 4.測試發送文字
    HA>設定>裝置與服務>MQTT>設定，輸入以下內容(XXXXXX 請改為自己的序號)按發布(要等10-15秒左右)看到像素燈顯示彩虹字就OK了。

    主題

    awtrix_XXXXXX/notify

    { "sound":"0001",
      "text":"Good morning get up!",
      "rainbow":true,
      "duration":25 }

    ![Mosquitto_broker](/Pixel_Light/image/175836.png)

    ![Mosquitto_broker](/Pixel_Light/image/175912.png)

## 5.SD卡mp3命名方式 (以腳本示範)

    *** 附贈sd卡(已經格式化fat32，裡面mp3資料夾有一個mp3示範檔) ***

    sd卡mp3資料夾內可放mp3音樂檔，命名方式請按照以下格式否則無法撥放。

    0001 - XXXX.mp3 (XXXX可英文名稱字)

    0002 - XXXX.mp3

    ...
## 6. HA自動化發送文字與mp3音效
    設定>自動化>腳本>新增腳本>命名>新增一個動作>其他動作>MQTT>發布>主題>awtrix_XXXXXX/notify>內容> 
    { "sound":"0001","text":"Good morning get up!","rainbow":true,"duration":25 } > Qos >1

    執行看看應該會發出我兒子的起床聲音。 **mp3檔名前面一率用數字取名子空格 - 空格後可以取容易辨識的英文稱，播放時指定前面數字即可正常撥放。

    ![Mosquitto_broker](/Pixel_Light/image/213415.png)

## 7.推薦像素燈購買國外小哥blueprints安裝分享 

    https://youtu.be/N0NKPJzGHuA?si=Qu2s4GEHaSAnrwz3

    https://ko-fi.com/s/0d1e4419bd

    在HA的資料夾config > blueprints > automation > 建立一個 pixel_light的資料夾，將購買下載的blueprints檔案放到這裡來。 若電腦未能看到HA的資料夾，請確定是否安裝Samba share這個插件。
    
    (HA>設定>附加元件>附加元件商店>裡面應該可以找到這個插件)

    把天氣的icon依序上傳到像素燈內 (注意不是copy到SD卡)

    ![Mosquitto_broker](/Pixel_Light/image/215806.png)

    ![Mosquitto_broker](/Pixel_Light/image/220018.png)

    就可以使用blueprints自動化輪播像素燈了


## 8.附錄安裝氣象預報跑馬燈示範(用氣象局的資訊比較準確) 

    必須先安裝HA插件 OpenCWB 與 Samba share (原已建立者可略)

    ![Mosquitto_broker](/Pixel_Light/image/cwba.png)


    請先安裝此插件 https://github.com/tsunglung/OpenCWB/blob/master/README_zh-tw.md 

    ![Mosquitto_broker](/Pixel_Light/image/samba.png)


* ### 建立一個天氣的實體"
    在HA裡面新增一個天氣的實體 "請參考檔案 weather.yaml"，entity瑱入OpenCWB相對應的ID， 溫/濕度用自家sensor，預估風速用opencwb的sensor.opencwb_forecast_7,完成重啟HA會出現 weather.my_weather_station 的實體後續備用。

    ![Mosquitto_broker](/Pixel_Light/image/weather.png)

* ### 製作相對功能的觸發 "開關助手"

    HA>設定>裝置與服務>助手>新增助手>開關> 名稱自取 ex: Awtrix Weather APP Trigger

* ### 開始設置氣象預報顯示功能

    HA>設定>自動化與場景>Blueprint > 找到 awtrix_weather_app 依序填入Awtrix Displays(awtrix_xxxxxx), Toggle Helper(input_boolean.awtrix_weather_app_trigger), Sensor(weather.my_weather_station), Show Weather Text(打開), Show temperature Show Wind Speed Show Humidity 依自己需要打開 Push Icon 任選 > 存檔。

    一切順利的話，叫出input_boolean.awtrix_weather_app_trigger 打開他像素燈就會開始輪播資訊了。


## 9. 自行下載icon使用
    到這個網站挑選喜歡的icon, 記住icon id 號碼。
    https://developer.lametric.com/icons
    icon自動放在像素燈內存，mp3音樂放在sd卡內(sd轉usb自備)
    ![Mosquitto_broker](/Pixel_Light/image/webicon.png)
    到web service 輸入該號碼按"Preview" 喜歡就"dwonload"，會自動存在\ICONS\資料夾中備用。

    ![Mosquitto_broker](/Pixel_Light/image/downmloadicon.png)




## 2024/05/20 update

    國外小哥新版藍圖已經取消awtrix_weather_app 改由 Pixel Light App 這個藍圖取代了

## 2424/05/22 新增rain.yaml 自動化方案，方法如下

    1.網頁開啟像素燈IP，把2284的icon下載到像素燈內備用
    2.透過國外小哥藍圖 Awtrix Create Sensor App 指定必要的id與2284 icon 號碼 > 存檔。
    3.建立條件化自動化參考rain.yaml內容改一下自家的ID即可。 當下雨高於0%就會跑出提醒下雨的輪播了


## 2024/05/23 update

    有買國外小哥的藍圖，但藍圖選單上無法找到像素燈實體的朋友請注意，因為像素燈新版0.96把廠牌改成AWTRIX 3，但舊藍圖是基於0.94版建立的，需要到國外小哥那去升級(目前是2.11)才正常，
