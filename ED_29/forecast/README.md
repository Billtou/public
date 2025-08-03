![081733](/ED_29/image/B8AD097F.jpg)

# 2.9" 電子紙範本
## 簡易日曆與氣象預報 (預設10分鐘更新一次頁面)
### 上電稍待1~2分鐘手機靠近設備找wifi熱點 automate-ed-29-forecast-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。
#### 使用方式: 安裝CWA插件或增加第二個CWA插件，修改HA的entity吻合指定的名稱即可 

- HA安裝CWA插件(若已經有安裝CWA插件可以增加第二個避免改了ID名稱後破壞原先的卡片或自動化內容)。
- 步驟1. 修改氣象預報CWA在HA裡面的ID (若已有CWA且不想改現有的ID可以安裝第二個CWA，用第二個CWA改ID就不會影響原先的設置了)

      # 來自CWA插件的ID原為 > 改成
        sensor.opencwa_XX_XXX_XXX_condition  >   sensor.opencwa_condition_xxxxxx
        sensor.opencwa_my_XX_XXX_XXX_feels_liketemperature > sensor.opencwa_feels_like_temperature_xxxxxx
        sensor.opencwa_XX_XXX_XXX_weather > sensor.opencwa_weather_xxxxxx

![081733](/ED_29/image/B8AD097F33.JPG)

  - 步驟2. 賦予本設備抓取HA訊息的權限
  * 設定> 裝置與服務 > ESPHome > 找到本設備名稱 > 右上有一個小齒輪 >  允許裝置執行 Home Assistant 動作 > 打勾  > 傳送。

- 步驟3. 重新上電等待每個10分鐘就會更新頁面資訊
