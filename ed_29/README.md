# 2.9" 電子紙開源範本
## 簡易日曆與氣象預報
### 檔案名稱 automate-ed-29-forecast.yaml
#### 使用方式: 
- HA安裝CWA插件。
- A. 修改氣象預報CVWA在HA裡面的ID
- 
    my_condition: "sensor.opencwa_nan_tun_qu_condition_2"    # 來自CWA插件。置換成自家的id
    my_feels_like_temperature: "sensor.opencwa_nan_tun_qu_feels_like_temperature_2" # 來自CWA插件。置換成自家的id
    my_weather: "sensor.opencwa_nan_tun_qu_weather_2" # 來自CWA插件。置換成自家的id
