
# 模組開關使用說明 

## 接入自家WIFI

設備上電手機搜尋熱點並指定自家wifi與密碼HA會自動發現(若沒跳出指定自家wifi頁面，請手機切換到瀏覽器，輸入192.168.4.1即可)，接入wifi後HA會自動發現設備，直接點選 "設定" 按紐並指定區域即完成。

## 1路接線方式

![Mosquitto_broker](/module_switch/image/214835.png)

## 2路接線方式

![Mosquitto_broker](/module_switch/image/214413.png)

## HA entity 功能說明(以1路為例)

![Mosquitto_broker](/module_switch/image/092704.png)


## 自動化提醒

若模組接智能燈需解藕，後期透過HA自動化來做該關燈，注意觸發條件要選正確的觸發條件如下圖。


![Mosquitto_broker](/module_switch/image/222200.png)

![Mosquitto_broker](/module_switch/image/222650.png)
