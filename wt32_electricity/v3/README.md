# Electricity Meter v3.0 使用說明

* 本版本主要功能是自帶HA能源面板所需兩個必需entity，以及本期累計電費跟及時小時能耗成本。另外日後台電若電價調整，直接修改默認的計價參數即可。
## . 接入自家網路(WIFI)
* 上電稍待1~2分鐘手機靠近設備找wifi熱點 automate-pm-20-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。
## . 接入自家網路(網線)
* 上電插上網線即可。
# 安裝線路與順序
### 1. 斷電施作
### 2. 接上L，N線
* 上電連接網線或WIFI (若要切換連線方式請見下方說明)
### 3. 安裝順序
* 所有線路都連接完成接入HA之後，最後最後才鉤CT鉤環 (順序不對會有高頻聲音)
![Mosquitto_broker](/wt32_electricity/image/213920.png)
* 若不熟悉水電方面，建議諮詢專業水電師傅**

* 首先打開家裡台電入戶電箱，會有很多的通斷器(俗稱"不累尬")通常體積最大上面數字最大的就是入戶總開關，(橫式排列通常在左側，新款直式排列在最上方)先把所有的線先接好並固定好設備最後再將兩個CT鉤環分別確實勾住即可(壓緊扣環確實扣住)。設備必續接網路線以及供電，紅線接L，白線接N。最後理一下線路盡量靠兩旁用束線帶固定即可。

  *所有線路都連接完成後，最後最後才鉤CT鉤環*

![Mosquitto_broker](/wt32_electricity/image/103927.png)


### 4. 導入HA裡面的entity運用介紹
![Mosquitto_broker](/PM_02/image/p48.JPG)
![Mosquitto_broker](/PM_02/image/p47.JPG)
## 計費週期歸零

## 設備自帶自動化計費週期歸零 
一般家用計費期間約2個月為一個週期，可以看一下繳費通知單上有寫，下圖是我家的範例
![Mosquitto_broker](/wt32_electricity/image/68D1224C2C0A.jpg)


可以看出來我家可能是雙月的月初抄表的，所以在esphome裡面的設定內打開自動歸零模式並選擇雙月以及日期1即可。
** 此功能還沒經過長期間的驗證，目前是bate版本，若有發現問題或錯誤請告知修改程序碼。
** 注意若家裡是雙月份月底抄表的，日期要選28號。 **

*奇數月"Odd_Months" 偶數月 "Even_Months"，若每月要更新選 "Every_Month" (2、3階段計價模式適用)*
### 備註:
 * 針對營業用電2段式或3段式計價模式請自行將 count_kwh_cost_storefront_2.yaml 或 count_kwh_cost_storefront_2.yaml 複製到HA的 \config\packages 裡面，若沒有請自行建立並將以下程序碼新增於configuration.yaml檔案中然後重新載入yaml或重開機生效。在設備後台歸零的選單請選擇每月，然後依據上述程序 5.設定HA能源面板-電網把單價改成新生成的計價單位id即可。



          homeassistant:
          packages: !include_dir_named packages
          customize_domain:
           automation:
             initial_state: true
          allowlist_external_dirs:
           - /config
