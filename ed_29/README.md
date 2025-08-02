# 2.9" 電子紙開源範本
## 簡易日曆與氣象預報
### 上電稍待1~2分鐘手機靠近設備找wifi熱點 automate-ed-29-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。
### 檔案名稱 automate-ed-29-forecast.yaml
#### 使用方式: A 修改HA的entity吻合預設的名稱即可 

- HA安裝CWA插件。
- A. 修改氣象預報CVWA在HA裡面的ID

      # 來自CWA插件的ID原為 > 改成
        sensor.opencwa_XX_XXX_XXX_condition  >   sensor.opencwa_my_condition 
        sensor.opencwa_my_XX_XXX_XXX_temperature > sensor.opencwa_my_feels_like_temperature 
        sensor.opencwa_XX_XXX_XXX_weather > sensor.opencwa_my_weather
- B. 賦予本設備抓取HA訊息的權限
  * 設定> 裝置與服務 > ESPHome > 找到本設備名稱 > 右上有一個小齒輪 >  允許裝置執行 Home Assistant 動作 > 打勾  > 傳送。
#### 使用方式: B 在HA裡面安裝ESPHome開發環境，自行編譯
- 在HA安裝附加元件 "ESPHome Device Builder"
- 在HA裡面找到esphome資料夾裡面建立一個fonts資料夾把字型都copy進來。(電腦要能看見HA的資料夾，附加元件必須安裝Samba share)
- 進入ESPHome Device Builder + NEW DEVICE > CONTINUE > 名稱取與接入的ESPHome相同的名稱 "AUTOMATE ED-29-XXXXXX" xxxxxx是流水號每台設備不同 > NEXT > ESP8266 > SKIP。
- 找到剛剛建立的設備名稱(右上會出現ONLINE) > EDIT  >  貼上檔案 automate-ed-29-forecast.yaml 的內容 > 並將名稱修改成正確的內容。


