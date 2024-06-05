# 使用說明

## 接線方式示意圖

** 若不熟悉水電方面，建議諮詢專業水電師傅**

首先打開家裡台電入戶電箱，會有很多的通斷器(俗稱"不累尬")通常體積最大上面數字最大的就是入戶總開關，(橫式排列通常在左側，新款直式排列在最上方)將兩個CT鉤環分別確實勾住即可(壓緊扣環確實扣住)。設備必續接網路線以及供電，紅線接L，白線接N。最後理一下線路盡量靠兩旁用束線帶固定即可。

![Mosquitto_broker](/wt32_electricity/103927.png)

## HA裡面的運用介紹
### 接入HA
網路線若是通的HA會自行發現，設定 >  裝置與服務  >  會自動出現一個WT32 Electricity ESPHome接入點，按下設定指定空間位置即可接入HA。

### 安裝 計算電費整合插件
前置作業，先安裝網友撰寫的能源插件 HACS > 搜尋 Taipower 並安裝它 (HA須重開機才會生效)，然後在 設定  > 裝置與服務  > 新增整合  >   搜尋 Taipower 填入作為計算的entity以及最近一次抄表日。

![Mosquitto_broker](/wt32_electricity/111141.png)

### 修改entity 名稱 (改名稱就好不須改實體ID)

進入TaiPower Bimonthly Energy Cost 插件會有2個實體，建議改成"電費單價" 以及 "累計費用" 方便辨識。

![Mosquitto_broker](/wt32_electricity/112313.png)

### 設定HA能源面板

設定  >  儀錶板  > 能源  依序填入必要entity即可。

![Mosquitto_broker](/wt32_electricity/112914.png)
![Mosquitto_broker](/wt32_electricity/113034.png)

## 計費週期歸零

可自行在HA裡面的自動化指定特定時間按下這兩個button做週期開始的歸零動作，方法有很多種可網路搜尋參考。
![Mosquitto_broker](/wt32_electricity/115409.png)

## 設備自帶自動化計費週期歸零 (bate)
一般家用計費期間約2個月為一個週期，可以看一下繳費通知單上有寫，下圖是我家的範例

![Mosquitto_broker](/wt32_electricity/68D1224C2C0A.jpg)

可以看出來我家可能是雙月的月初抄表的，所以在esphome裡面的設定內打開自動歸零模式並選擇單雙月以及日期即可。
** 此功能還沒經過長期間的驗證，目前是bate版本，若有發現問題或錯誤請告知修改程序碼。

![Mosquitto_broker](/wt32_electricity/114753.png)

## 附錄，做一個可以計算每小時電費的sensor

    template:
      - sensor:
          - name: hour_power_cost
            unique_id: 1f3bfe9e-8042-46a5-9ce5-f1a9fd197ec4
            state: "{{((states.sensor.wt32_electricity_2_way_power.state|float)/1000 *(states.sensor.sensor_wt32_electricity_2_way_energy_kwh_cost.state|float))|round(1)}}"
            unit_of_measurement: "$"
