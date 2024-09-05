# 外觀接線以及ESPhome固件功能說明 

## 如何接線 零火開關 影片
[![Watch the video](/wall_switch/image/154746.png)](https://youtu.be/xd02Zd4Uk7g)


## 如何接線 單火開關 影片

[![Watch the video](/wall_switch/image/161206.png)](https://youtu.be/TfvIE2JR22c)

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

![Mosquitto_broker](/wall_switch/image/165741.jpg)

![Mosquitto_broker](/wall_switch/image/121825.png)

## 自動化提醒

若模組接智能燈需解藕，後期透過HA自動化，注意觸發條件要選正確的觸發條件如下圖。


![Mosquitto_broker](/wall_switch/image/122930.png)

![Mosquitto_broker](/wall_switch/image/122957.png)


# 自行編輯固件一定要注意須按順序修改否則會死機，須回廠上機器重燒

## 必要環境

  0.先進入"裝置" > "裝置與服務" > "ESPHome" > 找到 "wall-switch-X-cbu-XXXXXX"  把正確的設備名稱copy到剪貼簿備用。(X-cbu-XXXXXX)每個開關都有不同編號須注意。

  0.下載相對應的yaml 文件

  0.必須安裝附加元件ESPHome

## 建立ESPHome開發環境

  1.進入ESPHome 右下 "+ NEW DEVICE"。
  
  2.選擇 "CONTINUE"。
  
  3.把剪貼簿的名稱貼上後 > "NEXT" > "BK72xx" > "CBU WI-FI Module" > SKIP。 就會建立一個ESPHome設備的編輯單元，若正確該元件右上角會出現 "ONLINE"

## 編輯yaml程式碼

  4.出現一個設備的編輯單元 > "EDIT" 進入編輯模式。
  
  5.依據說明替換正確的yaml程序碼。 *** 注意 name 一定要正確否則會死雞

## 進行程式碼編譯

  6.畫面右上 "SAVE" > "INSTALL"
  
  7.沒意外燒寫完成顯示on-line功能就會改變了，若所編輯的程式碼有修改現有的entity等等，需要到裝置與服務的esphome把舊的刪除(記住舊的ip，再手動建立即可)。

## 檔案說明 請注意檔案有些微不同，選擇與自己產品一致。


  wall-switch-1-cbu-xxxxxx.yaml (一路開關)
  
  wall-switch-2-cbu-xxxxxx.yaml (二路開關)
  
  wall-switch-2-chp-xxxxxx.yaml (三路開關 芯片模塊版本)
  
  wall-switch-3-cbu-xxxxxx.yaml (三路開關)

  wall-switch-3-chp-xxxxxx.yaml (三路開關 芯片模塊版本)
  
  light.yaml (在ESPHome裡面轉成原生電燈sample)
  
  fan.yaml (在ESPHome裡面轉成原生風扇sample)

  greenled.yaml (默認OFF亮綠燈，若想OFF不亮燈可以參考)
  
  
  ** 原本預計寫個解耦候透過偵測按壓模式不同分出三個虛擬開關single、double、hold但試不出來，我感覺是硬體上設計過濾按壓頻率，或是我間隔微秒沒抓好暫時宣布放棄。 或許有大神破解再請告知小弟 **
