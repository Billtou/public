# 2.9" 電子紙開源範本
## 簡易日曆與氣象預報 (預設10分鐘更新一次頁面)
### 上電稍待1~2分鐘手機靠近設備找wifi熱點 automate-ed-29-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。
### 檔案名稱 automate-ed-29-forecast.yaml
#### 使用方式: A 修改HA的entity吻合預設的名稱即可 

- HA安裝CWA插件。
- 步驟1. 修改氣象預報CVWA在HA裡面的ID (若已有CWA且不想改現有的ID可以安裝第二個CWA，用第二個CWA改ID就不會影響原先的設置了)

      # 來自CWA插件的ID原為 > 改成
        sensor.opencwa_XX_XXX_XXX_condition  >   sensor.opencwa_nan_tun_qu_condition
        sensor.opencwa_my_XX_XXX_XXX_temperature > sensor.opencwa_nan_tun_qu_feels_like_temperature
        sensor.opencwa_XX_XXX_XXX_weather > sensor.opencwa_nan_tun_qu_weather
- 步驟2. 賦予本設備抓取HA訊息的權限
  * 設定> 裝置與服務 > ESPHome > 找到本設備名稱 > 右上有一個小齒輪 >  允許裝置執行 Home Assistant 動作 > 打勾  > 傳送。


