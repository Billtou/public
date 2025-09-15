# 線上OTA檔案
### 2025/09/7 Update
* 取代tiapower插件以及自製功能表的功能，自帶HA能源中的電網所需的entity。
* 本固件適配黑色20Pin端口的產品
  
  electricitymeter-pro.ota_e_3.0.bin 網線版本
  
  electricitymeter-pro.ota_w_3.0.bin  WIFI 版本
  
![Mosquitto_broker](/electricity_meter_pro_20way/image/p123.jpg)


## 1.設備硬體安裝順序
* (entity ID 名稱視個別略為不同請自行調整)
* 請先將電源接上並連接網路後，CT訊號線先接好插入設備接口，最後最後再依序將CT一一勾上電線並檢查鉤環卡扣是否正確扣住。

## 2. 設定HA能源面板架構-電網
![Mosquitto_broker](/PM_20/PM_20_v2/image/上游.JPG)
* 設定  >  儀錶板  > 能源  依序填入必要entity即可。
![Mosquitto_broker](/PM_20/PM_20_v2/image/p941.JPG)
## 3. 設定HA能源面板-個別裝置
* 接入18個迴路，末端個別裝置(例如s31能耗插頭)必須指定其中一個迴路為上游以避免重複計算能耗
![Mosquitto_broker](/PM_20/PM_20_v2/image/bk-03.JPG)
![Mosquitto_broker](/PM_20/PM_20_v2/image/洗衣機能耗.JPG)

## 4. 實體說明
* (瀏覽器輸入ip位置即可顯示本頁面)

![Mosquitto_broker](/electricity_meter_pro_20way/image/pro-2.JPG)

![Mosquitto_broker](/electricity_meter_pro_20way/image/pro-1.JPG)

### 2025/03/14 update
- 2路加總與20路sensor時間同步為20秒一次更新。
- electricitymeter-pro.ota_WIFI_v2025.3.14.bin
- electricitymeter-pro.ota_ETH_v2025.3.14.bin

2025/02/20 update
優化程式碼，簡化entity(取消18路用電佔比改由HA yaml完成避免計算問題造成MCU資源耗盡)。提高更新效率每20秒/次

- electricitymeter-pro.ota_ETH.bin 網線版
- electricitymeter-pro.ota_WIFI.bin WIFI版


# OTA 刷機方法
- ![Mosquitto_broker](/wall_switch/image/ota.png)  
