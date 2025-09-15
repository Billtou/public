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

## 5. 設備自帶自動化計費週期歸零 
一般家用計費期間約2個月為一個週期，可以看一下繳費通知單上有寫，下圖是我家的範例
![Mosquitto_broker](/wt32_electricity/image/68D1224C2C0A.jpg)

可以看出來我家可能是雙月的月初抄表的，所以在esphome裡面的設定內打開自動歸零模式並選擇雙月以及日期1即可。
** 注意若家裡是雙月份月底抄表的，日期要選28號。 **
* 搭配台電計價週期設定方式奇數月"Odd_Months" 偶數月 "Even_Months"，若每月要更新選 "Every_Month" (2、3階段計價模式適用見下方備註)


### 備註:
 * 針對營業用2段式或3段式計價模式請自行將 count_kwh_cost_storefront_2.yaml 或 count_kwh_cost_storefront_2.yaml
 * 複製到HA的 \config\packages 裡面(若沒有用過packages請自行建立並將以下程序碼新增於configuration.yaml檔案中然後重新載入yaml或重開機生效。)然後重新載入yaml或重開機生效。
 * 在設備後台歸零的選單請選擇每月，然後依據上述程序 "5.設定HA能源面板-電網把單價改成新生成的計價單位id即可"

         homeassistant:
           packages: !include_dir_named packages
           customize_domain:
             automation:
               initial_state: true
           allowlist_external_dirs:
             - /config
    
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
