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

## 檔案說明  

  wall-switch-1-cbu-xxxxxx.yaml (一路開關)
  
  wall-switch-2-cbu-xxxxxx.yaml (二路開關)
  
  wall-switch-3-cbu-xxxxxx.yaml (三路開關)
  
  light.yaml (在ESPHome裡面轉成原生電燈sample)
  
  fan.yaml (在ESPHome裡面轉成原生風扇sample)

  greenled.yaml (默認OFF亮綠燈，若想OFF不亮燈可以參考)
  
  
  ** 原本預計寫個解耦候透過偵測按壓模式不同分出三個虛擬開關single、double、hold但試不出來，我感覺是硬體上設計過濾按壓頻率，或是我間隔微秒沒抓好暫時宣布放棄。 或許有大神破解再請告知小弟 **
