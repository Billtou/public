# AUTOMATE PM-20_v2(beta)
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
PM_20/image/S__49905668_2.JPG

## 7.計費週期歸零(搭配Taipower整合) 自帶自動化計費週期歸零

* 一般家用計費期間約2個月為一個週期，可以看一下繳費通知單上有寫，下圖是我家的範例

![Mosquitto_broker](/wt32_electricity/image/68D1224C2C0A.jpg)

可以看出來我家可能是雙月的月初抄表的，所以在esphome裡面的設定內打開自動歸零模式並選擇雙月以及日期1即可。
** 此功能還沒經過長期間的驗證，目前是bate版本，若有發現問題或錯誤請告知修改程序碼。
** 注意若家裡是雙月份月底抄表的，日期要選28號。 **

![Mosquitto_broker](/wt32_electricity/image/114753.png)

*PM-20已將奇數月改為"Odd_Months" 偶數月改為 "Even_Months"，若是每月須重置(2、3段式計費)選'Every_Month'*

## 備註

* 目前台電一般家用2個月一次計費表，若電費計價模式有所調整，請於HA 的 esphome 後台改變對應的參數

![Mosquitto_broker](/electricity_meter_pro_20way/image/104933.png)




