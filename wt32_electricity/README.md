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