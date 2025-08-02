# 2.9" 電子紙開源範本
## 簡易日曆與氣象預報
### 檔案名稱 automate-ed-29-forecast.yaml
#### 使用方式: 
- HA安裝CWA插件。
- A. 修改氣象預報CVWA在HA裡面的ID

      # 來自CWA插件的ID原為 > 改成
        sensor.opencwa_XX_XXX_XXX_condition  >   sensor.opencwa_my_condition 
        sensor.opencwa_my_XX_XXX_XXX_temperature > sensor.opencwa_my_feels_like_temperature 
        sensor.opencwa_XX_XXX_XXX_weather > sensor.opencwa_my_weather
