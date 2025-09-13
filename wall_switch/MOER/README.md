# MOER Wall Switch 接入自家WIFI

## 設備上電等待1-2分鐘手機搜尋熱點moer-cbu-x-xxxxxx 會跳出wifi引導頁面，輸入後按 "SAVE" 後約 5-10 秒請 "斷電重開機" 即可，連上網路後HA就會自動發現 
## 若沒跳出跳出wifi引導頁面，手機切換到瀏覽器，輸入192.168.4.1即可依上面步驟繼續。
![Mosquitto_broker](/wall_switch/image/moer_switch.JPG)
# 外觀接線以及ESPhome固件功能說明 
## V 3.0 Update
* 新增任一按鍵 短按=開關電燈， 長按5秒=重開機，長按10秒=重置(會清除wifi記憶)
* 新增可設置持續wifi斷網秒數後自動重啟。

![Mosquitto_broker](/wall_switch/image/moer_switch_2.JPG)  
![Mosquitto_broker](/wall_switch/image/moer_switch_1.JPG)

## 如何接線 零火開關 影片
[![Watch the video](/wall_switch/image/161206.png)](https://youtu.be/nIwzP0SKw_I?si=lUK7gXcIuBD8snV8)


### 名詞解說

繼電器: 導通電流的元件

物理按鍵: 開關上面的按鈕

解藕開關: OFF=物理按鍵連動繼電器  OMN= 不連動

應用場景1: 常規模式解藕開關=OFF

應用場景2: 作為雙切第二個開關，可解藕也可不解藕，我習慣不解藕只接電源，透過藍圖自動化與雙切第一個開關連動，好處是燈號顏色統一比較好辨識，缺點是會有繼電器的聲音，建議此場景不解藕。

應用場景3: 接智能電燈時解藕decouple_relay打開=ON，繼電器relay打開=ON ，透過HA自動化用binary_sensor觸發智能電燈，此場景必須解藕。

應用場景4: 閒置按鍵作為觸發場景的功能，建議解藕，透過HA的自動化觸發自訂義場景，建議解藕。 


![Mosquitto_broker](/wall_switch/image/121825.png)

## 自動化提醒

若模組接智能燈需解藕，後期透過HA自動化來做該關燈，注意觸發條件要選正確的觸發條件如下圖。

![Mosquitto_broker](/module_switch/image/213942.png)

![Mosquitto_broker](/module_switch/image/214028.png)
