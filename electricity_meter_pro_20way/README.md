# 20迴路全屋耗電偵測器
## 硬體規格 

默認網線板可透過OTA切換為WIFI版

2路總耗電偵測功能

18路各別迴路耗電偵測功能

## 接入HA的能源儀表板




## 計算公式參考資料

目前台電計費表

![Mosquitto_broker](/electricity_meter_pro_20way/image/104933.png)


## 自製計費標準(依據Taipower-Bimonthly-Energy-Cost-homeassistant) 全手動方式產生的 sensor entity

https://github.com/cnstudio/Taipower-Bimonthly-Energy-Cost-homeassistant/blob/main/Docs/old_manual_readme.md

## energy_template.yaml檔案說明

建議檔案放在 HA 資料夾中的\config\packages\

## HA重開機會產生以下sensor entity

sensor.cycle_kwh_cost  每度電累進電價單價(能源面板用這個entity來計費)

sensor.cycle_power_cost 計費區間累計電費

sensor.realtime_hour_cost 即時每小時用電預估
