![081733](/ED_29/image/834866CA.jpg)

# 2.9" 電子紙範本
## 簡易傳感器顯示螢幕 (預設10分鐘更新一次頁面)
### 上電稍待1~2分鐘手機靠近設備找wifi熱點 automate-ed-29-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。
#### 使用方式: 將現有的sensor透過HA "輔助工具" 複製出指定的entity吻合預設的名稱即可。 

- 步驟1. 設定 > 裝置與服務 > 輔助工具 > 新增輔助工具 > 結合多個感測器狀態 > 輸入正確名稱 ed29_temperature_xxxxxx(後綴流水號每台都不同見下表) > 輸入現有溫度實體ID > 選擇"最近更新" > 精準度設0 > 傳送。這樣就會得到一個sensor.ed29_temperature__xxxxxx ，依序將下表4個sensor做出來備用。

        項目     正確名稱
        ------  -------------          
        溫度     ed29_temperature_xxxxxx
        濕度     ed29_humidity_xxxxxx
        CO2     ed29_co2_xxxxxx
        PM2.5   ed29_pm25_xxxxxx


![081733](/ED_29/image/B8AD097F1.JPG)

  
- 步驟2. 賦予本設備抓取HA訊息的權限
  * 設定> 裝置與服務 > ESPHome > 找到本設備名稱 > 右上有一個小齒輪 >  允許裝置執行 Home Assistant 動作 > 打勾  > 傳送。
- 步驟3. 重新上電等待每個10分鐘就會更新頁面資訊

