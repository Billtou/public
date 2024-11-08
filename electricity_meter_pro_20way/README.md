# 接線說明

![Mosquitto_broker](/electricity_meter_pro_20way/image/175458.png)
![Mosquitto_broker](/electricity_meter_pro_20way/image/185305.png)

# 20路全屋耗電偵測器

## 1.硬體規格

  * 2路總耗電偵測功能

  * 18路各別迴路耗電偵測功能

## 2.接入自家網路的方法

  * 默認網線板可透過OTA切換為WIFI版

  * 網線版: 插上網線只要線路是通的，HA會自動找到設備。

 * WIFI版: 通電，手機靠近本設備找wifi熱點 electricity_meter_pro-xxxxxx，指定自家wifi名稱與密碼(若沒跳出輸入自家wifi畫面，手機打開瀏覽器輸入192.168.4.1即可)，wifi 指示燈常滅即完成，HA會自動找到設備。(有時要稍微等待一下wifi熱點才會出現)

## 3.設備硬體安裝順序(entity ID 名稱視個別略為不同請自行調整)

# 請先將電源接上並連接網路後，CT線路先接好插入設備接口，最後再依順序將CT一一勾上電線並檢查鉤環卡扣是否正確扣住。

## 4.賦予本設備能自動雙月份歸零功能

![Mosquitto_broker](/electricity_meter_pro_20way/image/155055.png)

## 接入HA步驟 (前置作業)

 * 在HA建立一個功耗表  設定 >  裝置與服務  >  助手  >  新增助手  >  功耗表 ； 名稱填入 taipower_energy

 * 輸入感測器填入 ElectricityMeter Pro 2 Way Energy Sum (entity ID視個略為別不同)

![Mosquitto_broker](/electricity_meter_pro_20way/image/151837.png)

 * 安裝網友撰寫的能源插件 HACS > 搜尋 Taipower 並安裝它 (HA須重開機才會生效)，然後在 設定 > 裝置與服務 > 新增整合 > 搜尋 Taipower 填入作為計算的entity以及最近一次抄表日。

![Mosquitto_broker](/electricity_meter_pro_20way/image/152326.png)

 * 修改entity 名稱 (改名稱就好不須改實體ID)

![Mosquitto_broker](/electricity_meter_pro_20way/image/153126.png)

## 接入HA的能源儀表板 建議方法1(entity ID視個略為別不同)(請見底部update訊息)

![Mosquitto_broker](/electricity_meter_pro_20way/image/160737.png)

## 接入HA的能源儀表板 建議方法2(entity ID視個略為別不同)

![Mosquitto_broker](/electricity_meter_pro_20way/image/154712.png)


## 手動建立所有相關實體方式

目前台電計費表

![Mosquitto_broker](/electricity_meter_pro_20way/image/104933.png)


## 自製計費標準(依據Taipower-Bimonthly-Energy-Cost-homeassistant) 全手動方式產生的 sensor entity

https://github.com/cnstudio/Taipower-Bimonthly-Energy-Cost-homeassistant/blob/main/Docs/old_manual_readme.md

## energy_template.yaml檔案說明

建議檔案放在 HA 資料夾中的\config\packages\

## HA重開機會產生以下sensor entity

sensor.taipower_energy  手動建立 "功耗表" 實體

sensor.count_kwh_cost  每度電累進電價單價

sensor.count_power_cost 計費區間累計電費

sensor.realtime_hour_cost 即時每小時用電費預估

## 2024/11/08 Update

內建的自動化歸零是搭配雙月份台電的計價機制，若以建議方法1導入能源面板，請用助手個別建立01~18CT功耗表，然後將他導入HA的能源面板，需要歸零的話就歸零助手即可。

