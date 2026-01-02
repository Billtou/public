### 2026/1/3 v3.3 Update
- 更新2025/10/1日實施的電價計費標準。
- ## 加濕器設定
[前往加濕器設定](#加濕器設定)

# AUTOMATE PM-02 2路入戶總電力
## 接入自家網路(WIFI)
### 上電稍待1~2分鐘手機靠近設備找wifi熱點 automate-pm-20-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。
## 接入自家網路(網線)
### 上電插上網線即可。

# 安裝線路與順序
### 1. 斷電施作
### 2. 接上L，N線上電連接網線或WIFI (若要切換連線方式，可在OTA資料夾找到對應的檔案)
### 3. 所有線路都連接完成接入HA之後，最後最後才鉤CT鉤環 (順序不對會有高頻聲音)
![Mosquitto_broker](/PM_02/image/pm_02_1.JPG)
*若不熟悉水電方面，建議諮詢專業水電師傅*
# HA裡面的運用介紹
## 安裝"計算電費整合插件"
前置作業，先安裝網友撰寫的能源插件 HACS > 搜尋 Taipower 並安裝它 (HA須重開機才會生效)，然後在 設定  > 裝置與服務  > 新增整合  >   搜尋 Taipower 填入作為計算的entity以及最近一次抄表日。 因應產品跌代，entity名稱可能略有差異

![Mosquitto_broker](/wt32_electricity/image/214920.png)

### 修改entity 名稱 (改名稱就好不須改實體ID)

進入TaiPower Bimonthly Energy Cost 插件會有2個實體，建議改成"電費單價" 以及 "累計費用" 方便辨識。

![Mosquitto_broker](/wt32_electricity/image/112313.png)

### 設定HA能源面板

設定  >  儀錶板  > 能源  依序填入必要entity即可。

![Mosquitto_broker](/wt32_electricity/image/112914.png)
![Mosquitto_broker](/wt32_electricity/image/214521.png)

## 計費週期歸零

可自行在HA裡面的自動化指定特定時間按下這兩個button做週期開始的歸零動作，方法有很多種可網路搜尋參考。
![Mosquitto_broker](/wt32_electricity/image/110341.png)

## 設備自帶自動化計費週期歸零 (bate)
一般家用計費期間約2個月為一個週期，可以看一下繳費通知單上有寫，下圖是我家的範例

![Mosquitto_broker](/wt32_electricity/image/68D1224C2C0A.jpg)

可以看出來我家可能是雙月的月初抄表的，所以在esphome裡面的設定內打開自動歸零模式並選擇雙月以及日期1即可。
** 此功能還沒經過長期間的驗證，目前是bate版本，若有發現問題或錯誤請告知修改程序碼。
** 注意若家裡是雙月份月底抄表的，日期要選28號。 **

![Mosquitto_broker](/wt32_electricity/image/114753.png)

*PM-02已將奇數月改為"Odd_Months" 偶數月改為 "Even_Months"，其餘不變*
## 附錄A ，做一個可以即時計算每小時電費的sensor

    template:
      - sensor:
          - name: hour_power_cost
            unique_id: 1f3bfe9e-8042-46a5-9ce5-f1a9fd197ec4
            state: "{{((states.sensor.wt32_electricity_2_way_power.state|float)/1000 *(states.sensor.sensor_wt32_electricity_2_way_energy_kwh_cost.state|float))|round(1)}}"
            unit_of_measurement: "$"

## 附錄B.手動建立所有相關實體方式(適用特殊計價方式或三階段電價或營業用電價等等)

## 目前台電一般民眾計費表(2025/10/1)

![Mosquitto_broker](/electricity_meter_pro_20way/image/10-1-power-price.JPG)

## 自製計費標準(依據Taipower-Bimonthly-Energy-Cost-homeassistant) 全手動方式產生的 sensor entity

參考來源 https://github.com/cnstudio/Taipower-Bimonthly-Energy-Cost-homeassistant/blob/main/Docs/old_manual_readme.md


## energy_template.yaml檔案說明

* 建議檔案放在 HA 資料夾中的\config\packages\

## HA重開機會產生以下sensor entity

 sensor.taipower_energy  手動建立 "功耗表" 實體
 
 sensor.ct_01 ~ 18_energy  手動建立10路CT "功耗表" 實體
 
 sensor.count_kwh_cost  每度電累進電價單價
 
 sensor.count_power_cost 計費區間累計電費
 
 sensor.realtime_hour_cost 即時每小時用電費預估
