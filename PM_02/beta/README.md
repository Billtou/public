# AUTOMATE PM-02 v3.0 beta 2路入戶總電力
## . 接入自家網路(WIFI)
### 上電稍待1~2分鐘手機靠近設備找wifi熱點 automate-pm-20-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。
## . 接入自家網路(網線)
### - 上電插上網線即可。

# 安裝線路與順序
### 1. 斷電施作
### 2. 接上L，N線上電連接網線或WIFI (若要切換連線方式請見下方說明)
### 3. 所有線路都連接完成接入HA之後，最後最後才鉤CT鉤環 (順序不對會有高頻聲音)
![Mosquitto_broker](/PM_02/image/p45.JPG)
*若不熟悉水電方面，建議諮詢專業水電師傅*
# 導入HA裡面的entity運用介紹
![Mosquitto_broker](/PM_02/image/p48.JPG)
![Mosquitto_broker](/PM_02/image/p47.JPG)

### 設定HA能源面板

設定  >  儀錶板  > 能源  依序填入必要entity即可。

![Mosquitto_broker](/PM_02/image/p49.JPG)

## 計費週期歸零

手動歸零。
![Mosquitto_broker](/wt32_electricity/image/110341.png)

## 設備自帶自動化計費週期歸零 
一般家用計費期間約2個月為一個週期，可以看一下繳費通知單上有寫，下圖是我家的範例
![Mosquitto_broker](/wt32_electricity/image/68D1224C2C0A.jpg)

可以看出來我家可能是雙月的月初抄表的，所以在esphome裡面的設定內打開自動歸零模式並選擇雙月以及日期1即可。
** 注意若家裡是雙月份月底抄表的，日期要選28號。 **

![Mosquitto_broker](/wt32_electricity/image/114753.png)

*PM-02已將奇數月改為"Odd_Months" 偶數月改為 "Even_Months"，若每月要更新選 "Every_Month" (2、3階段計價模式適用)*

* 目前台電一般民眾計費表

![Mosquitto_broker](/electricity_meter_pro_20way/image/104933.png)
