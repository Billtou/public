# 接入自家WIFI

## 設備上電等待1-2分鐘手機搜尋熱點wall_switch-x-xxxxxx 會跳出wifi引導頁面，輸入後按 "SAVE" 後約 5-10 秒 "斷電重開機" 即可。 HA就會自動發現 
  
![Mosquitto_broker](/wall_switch/image/moer_switch.JPG)

# 模組開關使用說明 
## 如何接線 模組開關 影片
[![Watch the video](/module_switch/image/154644.png)](https://youtu.be/oL1PVQXvEHQ?si=OWOFjIUSMLn_HVU_)

## 接入自家WIFI

設備上電手機搜尋熱點並指定自家wifi與密碼HA會自動發現(若沒跳出指定自家wifi頁面，請手機切換到瀏覽器，輸入192.168.4.1即可)，接入WIFI後請先斷電重送電，HA就\會自動發現設備，直接點選 "設定" 按紐並指定區域即完成。

## 1路接線方式

![Mosquitto_broker](/module_switch/image/214835.png)

## 2路接線方式

![Mosquitto_broker](/module_switch/image/214413.png)

## HA entity 功能說明(以1路為例)

![Mosquitto_broker](/module_switch/image/092704.png)


## 自動化提醒

若模組接智能燈需解藕，後期透過HA自動化來做該關燈，注意觸發條件要選正確的觸發條件如下圖。

![Mosquitto_broker](/module_switch/image/213942.png)

![Mosquitto_broker](/module_switch/image/214028.png)


