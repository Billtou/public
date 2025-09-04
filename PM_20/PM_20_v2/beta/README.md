# v3.0 beta 版新增內容(不需要安裝Taipower插件的版本)
## 本版本主要功能是自帶HA能源面板所需兩個必需entity，以及本期累計電費跟及時小時能耗成本。另外日後台電若電價調整，直接修改默認的計價參數即可。

![Mosquitto_broker](/PM_20/PM_20_v2/image/S__51159045-3.JPG)
# 接入自家網路(WIFI)
## -  上電稍待1~2分鐘手機靠近設備找wifi熱點 automate-pm-20-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。
# 接入自家網路(網線)
## -  上電插上網線即可。
# 匯流排式電箱介紹
![Mosquitto_broker](/PM_20/PM_20_v2/image/image10.JPG)
# 一般式電箱介紹
![Mosquitto_broker](/PM_20/PM_20_v2/image/a_15.JPG)
## 1.接線說明(ch1-L,N 與ch2-L各接在兩邊匯流排110V NFB 上，別裝在220V的NFB上，建議左邊接紅色110V，右邊裝黑色)

   ![Mosquitto_broker](/PM_20/PM_20_v2/image/S__51159045-2.JPG)
   
## 2.設備硬體安裝順序(entity ID 名稱視個別略為不同請自行調整)

* 請先將電源接上並連接網路後，CT線路先接好插入設備接口，最後再依順序將CT一一勾上電線並檢查鉤環卡扣是否正確扣住。

## 3.賦予本設備能自動雙月份歸零功能
![Mosquitto_broker](/PM_20/PM_20_v2/image/S__49905668_2.JPG)

## 4. 在HA建立迴路18個CT的功耗表(有幾個小CT就做幾個)
* 設定 > 裝置與服務 > 輔助工具 > 新增輔助工具 > 功耗表 ，名稱為 ct_01_energy 輸入感測器為Beraker Energy 01 依此類推，有幾個迴路CT就做幾個自訂功耗表。
* 做完後到 開發工具 > 狀態 > 在實體篩選器輸入sensor.ct_  應該要能看到剛剛建立的emtity才對。

  
![Mosquitto_broker](/PM_20/PM_20_v2/image/p943.JPG)

## 5. 設定HA能源面板
* 0設定  >  儀錶板  > 能源  依序填入必要entity即可。

![Mosquitto_broker](/PM_20/PM_20_v2/image/p941.JPG)

![Mosquitto_broker](/PM_20/PM_20_v2/image/20250519_18.JPG)
![Mosquitto_broker](/PM_20/PM_20_v2/image/20250519_17.JPG)
![Mosquitto_broker](/PM_20/PM_20_v2/image/20250519_16.JPG)




