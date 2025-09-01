# AUTOMATE PM-20_v2
![Mosquitto_broker](/PM_20/PM_20_v2/image/S__51159045-3.JPG)
# 接入自家網路(WIFI)
## -  上電稍待1~2分鐘手機靠近設備找wifi熱點 automate-pm-20-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。
# 接入自家網路(網線)
## -  上電插上網線即可。
# 匯流排式電箱介紹
![Mosquitto_broker](/PM_20/PM_20_v2/image/image10.JPG)
# 一般式電箱介紹
![Mosquitto_broker](/PM_20/PM_20_v2/image/a_15.JPG)
## 1 接線說明(ch1-L,N 與ch2-L,N各接在兩邊匯流排110V NFB 上，別裝在220V的NFB上)

   ![Mosquitto_broker](/PM_20/PM_20_v2/image/S__51159045-2.JPG)
   
## 2.設備硬體安裝順序(entity ID 名稱視個別略為不同請自行調整)

# 請先將電源接上並連接網路後，CT線路先接好插入設備接口，最後再依順序將CT一一勾上電線並檢查鉤環卡扣是否正確扣住。

## 3.賦予本設備能自動雙月份歸零功能
![Mosquitto_broker](/PM_20/PM_20_v2/image/S__49905668_2.JPG)

## 4.接入HA步驟 (前置作業)

 * 在HA建立一個入戶總功耗表  設定 >  裝置與服務  >  輔助工具  >  新增輔助工具 >  功耗表 ； 名稱填入 taipower_energy (名字要一樣否則無法自動化歸零)

 * 輸入感測器填入(PM20為例) sensor.automate_pm_20_XXXXXX_2_way_energy_sum (entity ID視個略為別不同) 

![Mosquitto_broker](/PM_20/PM_20_v2/image/20250519_44.JPG)

 * 依據步驟4再建立18個迴路的功耗表備用，名稱為 ct_01_energy 輸入感測器為Beraker Energy 01 依此類推，有幾個迴路CT就做幾個自訂功耗表。
 * 做完後到 開發工具 > 狀態 > 在實體篩選器輸入sensor.ct_01  應該要能看到剛剛建立的emtity才對。

![Mosquitto_broker](/PM_20/PM_20_v2/image/20250519_45.JPG)
 
 * 安裝網友撰寫的能源插件 HACS > 搜尋 Taipower 並安裝它 (HA須重開機才會生效)，然後在 設定 > 裝置與服務 > 新增整合 > 搜尋 Taipower 填入作為計算的entity以及最近一次抄表日。

![Mosquitto_broker](/electricity_meter_pro_20way/image/152326.png)

 * 修改entity 名稱 (改名稱就好不須改實體ID)

![Mosquitto_broker](/electricity_meter_pro_20way/image/153126.png)

## 5.接入HA的能源儀表板 建議方法1(entity ID視個別產品略為別不同)(請見底部update訊息)

![Mosquitto_broker](/electricity_meter_pro_20way/image/120153.png)

## 6.接入HA的能源儀表板 建議方法2(entity ID視個別產品略為別不同)

![Mosquitto_broker](/electricity_meter_pro_20way/image/115839.png)

## 7.計費週期歸零(搭配Taipower整合) 自帶自動化計費週期歸零

* 一般家用計費期間約2個月為一個週期，可以看一下繳費通知單上有寫，下圖是我家的範例

![Mosquitto_broker](/wt32_electricity/image/68D1224C2C0A.jpg)

可以看出來我家可能是雙月的月初抄表的，所以在esphome裡面的設定內打開自動歸零模式並選擇雙月以及日期1即可。
** 此功能還沒經過長期間的驗證，目前是bate版本，若有發現問題或錯誤請告知修改程序碼。
** 注意若家裡是雙月份月底抄表的，日期要選28號。 **

![Mosquitto_broker](/wt32_electricity/image/114753.png)

*PM-20已將奇數月改為"Odd_Months" 偶數月改為 "Even_Months"，若是每月須重置(2、3段式計費)選'Every_Month'*

## 備註

 * 本方案為2個BL0910元件組成的20路方案，本身沒有記憶歷史耗電數據的功能，若需此功能可透過HA助手中的功耗表來累計與歸零(見步驟4接入HA步驟 (前置作業))。

 * 內建的自動化歸零是搭配兩個月一次台電的計價機制，若以建議方法1導入能源面板，請用輔助工具個別建立01~18CT功耗表，然後將他導入HA的能源面板，需要歸零的話就歸零助手即可。

 * 若用輔助工具建立01~18CT功耗表ID名稱建議取為sensor.ct_01_energy ~ sensor.ct_18_energy，這樣就能搭配達到2個月一期的台電計價了。
 
 * 若熟悉yaml也可以參考energy_template.yaml檔案自己手動方式建立。


## 附錄A ，做一個可以即時計算每小時電費的sensor

    template:
      - sensor:
          - name: hour_power_cost
            unique_id: 1f3bfe9e-8042-46a5-9ce5-f1a9fd197ec4
            state: "{{((states.sensor.wt32_electricity_2_way_power.state|float)/1000 *(states.sensor.sensor_wt32_electricity_2_way_energy_kwh_cost.state|float))|round(1)}}"
            unit_of_measurement: "$"


## 附錄B **.手動建立所有相關實體方式(適用特殊計價方式或三階段電價或營業用電價等等)

* 目前台電一般民眾計費表

![Mosquitto_broker](/electricity_meter_pro_20way/image/104933.png)


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


