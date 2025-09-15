# 線上OTA檔案
### 2025/09/7 Update
* 取代tiapower插件以及自製功能表的功能，自帶HA能源中的電網所需的entity。
* 本固件適配黑色20Pin端口的產品
  
  electricitymeter-pro.ota_e_3.0.bin 網線版本
  
  electricitymeter-pro.ota_w_3.0.bin  WIFI 版本
  
![Mosquitto_broker](/electricity_meter_pro_20way/image/p123.jpg)

* 新增的實體說明

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
