# v3.0 beta 版新增內容(不需要安裝Taipower插件的版本)
* 本版本主要功能是自帶HA能源面板所需兩個必需entity，以及本期累計電費跟及時小時能耗成本。另外日後台電若電價調整，直接修改默認的計價參數即可。

![Mosquitto_broker](/PM_20/PM_20_v2/image/重置紐.jpg)
## 接入自家網路(WIFI)
* 上電稍待1~2分鐘手機靠近設備找wifi熱點 automate-pm-20-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。
## 接入自家網路(網線)
* 上電插上網線即可。
## 匯流排式電箱介紹
![Mosquitto_broker](/PM_20/PM_20_v2/image/image10.JPG)
## 一般式電箱介紹
![Mosquitto_broker](/PM_20/PM_20_v2/image/a_15.JPG)
## 1.接線說明
* (ch1-L,N 與ch2-L各接在兩邊匯流排110V NFB 上，別裝在220V的NFB上，建議左邊接紅色110V，右邊裝黑色)

   ![Mosquitto_broker](/PM_20/PM_20_v2/image/S__51159045-3.JPG)
   
## 2.設備硬體安裝順序
* (entity ID 名稱視個別略為不同請自行調整)
* 請先將電源接上並連接網路後，CT線路先接好插入設備接口，最後再依順序將CT一一勾上電線並檢查鉤環卡扣是否正確扣住。
## 3.賦予本設備能自動雙月份歸零功能
![Mosquitto_broker](/PM_20/PM_20_v2/image/S__49905668_2.JPG)
## 4. 在HA建立18個迴路CT的功耗表(有幾個小CT就做幾個)
* 設定 > 裝置與服務 > 輔助工具 > 新增輔助工具 > 功耗表 ，名稱為 ct_01_energy 輸入感測器為Beraker Energy 01 依此類推，有幾個迴路CT就做幾個自訂功耗表。
* 做完後到 開發工具 > 狀態 > 在實體篩選器輸入sensor.ct_  應該要能看到剛剛建立的emtity才對。
* 有經驗者可參考文末備註說明，手動作出18個迴路功號表，較為快速。
![Mosquitto_broker](/PM_20/PM_20_v2/image/p946.JPG)
## 5. 設定HA能源面板-電網
* 設定  >  儀錶板  > 能源  依序填入必要entity即可。
![Mosquitto_broker](/PM_20/PM_20_v2/image/p941.JPG)
## 6. 設定HA能源面板-個別裝置
* 接入18個迴路，其他個別裝置(例如s31能耗插頭)必須指定其中一個迴路為上游以避免重複計算能耗
![Mosquitto_broker](/PM_20/PM_20_v2/image/洗衣機迴路.JPG)
![Mosquitto_broker](/PM_20/PM_20_v2/image/洗衣機能耗.JPG)

## 7. 實體說明
* (瀏覽器輸入ip位置即可顯示本頁面)
  
![Mosquitto_broker](/PM_20/PM_20_v2/image/a1.JPG)

![Mosquitto_broker](/PM_20/PM_20_v2/image/a2.JPG)

![Mosquitto_broker](/PM_20/PM_20_v2/image/a4.JPG)

* 搭配台電計價週期設定方式奇數月"Odd_Months" 偶數月 "Even_Months"，若每月要更新選 "Every_Month" (2、3階段計價模式適用)
  
![Mosquitto_broker](/wt32_electricity/image/歸零選單.JPG)
## 7. 切換聯網方式
* 先選擇"聯網方式"選單，再按"版本更新" log會出現0%~100%完成後因為連網方式變更IP也會跟著變動，若原本是網線變更為WIFI導致HA找不到設備，請手機搜尋再一次引導接入自家Wifi即可。

### 備註:
* 手動製作18個CT功耗表餵給HA能源面板中的個別裝置的方法。
* 將 energy_template.yaml 複製到HA的 \config\packages 裡面，若沒有自行建立並將以下程序碼新增於configuration.yaml檔案中然後重新載入yaml或重開機生效。
  
      homeassistant:
        packages: !include_dir_named packages
        customize_domain:
          automation:
            initial_state: true
        allowlist_external_dirs:
          - /config
  
 * 針對營業用電2段式或3段式計價模式請自行將 count_kwh_cost_storefront_2.yaml 或 count_kwh_cost_storefront_2.yaml 複製到HA的 \config\packages 裡面，然後重新載入yaml或重開機生效。在設備後台歸零的選單請選擇每月，然後依據上述程序 5.設定HA能源面板-電網把單價改成新生成的計價單位id即可。

