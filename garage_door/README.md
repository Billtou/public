# Garage Door
這是一款全方位的車庫鐵捲門解決方案，能接WIFI也能接網線連接HA，你可以把車庫遙控器焊接在這裡做遙控，也可以接到鐵捲門主機板上直接控制，另外有堤供一路的外接門磁，這可以反饋鐵捲門的開或關的狀態，安全可靠。

## 接入自家網路 - 網線方法

網路線若是通的(網路口綠橘指示燈有亮)HA就會自動發現；設定 > 裝置與服務 > 會自動出現一個garage-door-XXXXXX 的 ESPHome接入點，按下設定指定空間位置即可接入HA。

## 接入自家網路 - WIFI方法

上電手機靠近本設備找wifi熱點 garage-door-XXXXXX，指定自家wifi名稱與密碼(若沒跳出輸入自家wifi畫面，手機切換到瀏覽器輸入192.168.4.1即可)(要稍微等待一下wifi熱點才會出現) 後續接入HA請參考網線方法。

## 接口介紹

![Mosquitto_broker](/garage_door/image/100445.png)

![Mosquitto_broker](/garage_door/image/100344.png)


## 遙控器接線方式 ##

![Mosquitto_broker](/garage_door/image/100550.png)







## OTA 切換WIFI連線或網線 ##

garage-door_ETH_4way_version.ota.bin        網線版本 "4路" 點動開關

garage-door_ETH_garge_version.ota.bin       網線版本 "車庫" 鐵捲門

garage-door_WIFI_4way_version.ota.bin       WIFI版本 "4路" 點動開關

garage-door_WIFI_garge_version.ota.bin       WIFI版本 "車庫" 鐵捲門

瀏覽器輸入garage-door被分配到的ip

![Mosquitto_broker](/garage_door/image/201829.png)

** PS. OTA後原本被分配的IP會變更，建議斷電重開機，若從WIFI變更為網線，重開機後請按上文 "接入自家網路 - WIFI方法" 設定連網。

