
# 推薦像素燈安裝分享 

## 像素燈接入Home Assostant

### 建立mqtt user (原已建立者可略)

HA>設定>人員>使用者>新增使用者 mqtt-user，密碼我慣用mqtt-pass > 新增。

![Mosquitto_broker](/Pixel_Light/image/mqtt-user.png)

HA>設定>附加元件>附加元件商店>Mosquitto Broker 安裝 > 啟動。

![Mosquitto_broker](/Pixel_Light/image/Mosquitto_broker.png)

### 像素燈上電連上自家wifi

像素燈上電面板出現 AP MODE 手機搜尋 awtix_xxxxxx 熱點，指定自家的wifi 帳號與密碼，正常就會連到家裡的wifi並出現使用的IP位置。

瀏覽器打入ip位置會出現 Web Service，選單MQTT填入(Broker欄位就是你HA的IP，Prefix欄位就是該設備在HA顯示的名稱)，並打開Homeassistant Discovery 讓HA能發現。

![Mosquitto_broker](/Pixel_Light/image/mqtt-login.png)

選單 TIME NTP Server 填入 time.stdtime.gov.tw，Timezone填入 CST-8

![Mosquitto_broker](/Pixel_Light/image/timezone_1.png)

完成按 Save configuration 後再按 Restart ESP ，重啟後正常HA就會發現，HA > 裝置與服務 > MQTT > awtrix_xxxxxx。

 
### 安裝氣象預報跑馬燈示範 

## 必須先安裝HA插件 OpenCWB 與 Samba share (原已建立者可略)

![Mosquitto_broker](/Pixel_Light/image/cwba.png)


請先安裝此插件 https://github.com/tsunglung/OpenCWB/blob/master/README_zh-tw.md 

### 建立一個開關助手"
在HA裡面新增一個天氣的實體，condition_template: 瑱入OpenCWB相對應的ID， 溫/濕度用自家sensor ID，預估風速用opencwb的 sensor.opencwb_forecast_7,完成重啟HA會出現 weather.my_weather_station 的實體後續備用。



![Mosquitto_broker](/Pixel_Light/image/samba.png)

在HA的資料夾config > blueprints > automation > 建立一個 pixel_light的資料夾，將blueprints檔案copy到這裡來。 若電腦未能看到HA的資料夾，請確定是否安裝Samba share這個插件。(HA>設定>附加元件>附加元件商店>裡面應該可以找到這個插件)

### 製作相對功能的觸發 "開關助手"



