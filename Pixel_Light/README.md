### 必須先安裝HA插件

請先安裝此插件 https://github.com/tsunglung/OpenCWB/blob/master/README_zh-tw.md 取得當地天氣預報的實體 sensor.opencwb_forecast，接著在HA裡面新增一個天氣的實體，例如範例中我把預估天氣狀態放在 condition_template: ， 溫/濕度用自家戶外溫度計sensor，預估風速我用opencwb的 sensor.opencwb_forecast_7,完成重啟HA會出現 weather.my_weather_station 的實體備用。

在HA的資料夾config > blueprints > automation > 建立一個 pixel_light的資料夾，將blueprints檔案copy到這裡來。 若電腦未能看到HA的資料夾，請確定是否安裝Samba share這個插件。



