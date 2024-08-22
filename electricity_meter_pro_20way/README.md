# 20路全屋迴路耗電偵測器
## 硬體規格 

## 計算公式參考資料

目前台電 "各類電價表及計算範例"

https://www.taipower.com.tw/2289/2558/49405/49408/49454/2601/22293/

## 自製計費標準(依據Taipower-Bimonthly-Energy-Cost-homeassistant) 全手動方式產生的 sensor entity

https://github.com/cnstudio/Taipower-Bimonthly-Energy-Cost-homeassistant/blob/main/Docs/old_manual_readme.md

template.yaml 建議檔放在HA 資料夾中的\config\packages\energy_template.yaml
sensor.cycle_kwh_cost  每度電累進電價

sensor.cycle_power_cost 計費區間累計店費

sensor.cycle_power_cost  realtime_hour_cost
