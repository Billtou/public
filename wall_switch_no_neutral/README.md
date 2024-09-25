# 外觀接線以及ESPhome固件功能說明 

## 如何接線 **單火開關** 影片
[![Watch the video](/wall_switch_no_neutral/image/161206.png)](https://youtu.be/F29yXvkCFT8?si=TY2oCMKZJvu-UOtl)

## 接入自家WIFI

設備上電手機搜尋熱點並指定自家wifi與密碼HA會自動發現(若沒跳出指定自家wifi頁面，請手機切換到瀏覽器，輸入192.168.4.1即可)，接入wifi後HA會自動發現設備，直接點選 "設定" 按紐並指定區域即完成。

## 名詞解說

繼電器: 導通電流的元件

物理按鍵: 開關上面的按鈕

解藕開關: 常閉=物理按鍵連動繼電器  常開= 不連動

應用場景1: 常規模式解藕開關=OFF

應用場景2: 作為雙切第二個開關，可解藕也可不解藕，我習慣不解藕只接電源，透過藍圖自動化與雙切第一個開關連動，好處是燈號顏色統一比較好辨識，缺點是會有繼電器的聲音，建議此場景不解藕。

應用場景3: 接智能電燈時解藕decouple_relay打開=ON，繼電器relay打開=ON ，透過HA自動化用binary_sensor觸發智能電燈，此場景必須解藕。

應用場景4: 閒置按鍵作為觸發場景的功能，建議解藕，透過HA的自動化觸發自訂義場景，建議解藕。 


![Mosquitto_broker](/wall_switch/image/161734.jpg)

![Mosquitto_broker](/wall_switch/image/162214.png)

![Mosquitto_broker](/wall_switch/image/121825.png)

## 自動化提醒

若模組接智能燈需解藕，後期透過HA自動化，注意觸發條件要選正確的觸發條件如下圖。


![Mosquitto_broker](/wall_switch/image/122930.png)

![Mosquitto_broker](/wall_switch/image/122957.png)
