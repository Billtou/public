# EspHome版本
![Mosquitto_broker](/motion_mmWave/esphome/image/S__45424644_1.JPG)
## 接入自家wifi
-  上電靜待超過1-2分鐘，手機靠近設備找wifi熱點 motionone-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。(有時候要稍微等待一下wifi熱點才會出現，強烈建議自家wifi要設定一個2.4G Only的SSID專供智能設備使用)
## 後台調整參數說明
  ![Mosquitto_broker](/motion_mmWave/esphome/image/235731.png)
  ![Mosquitto_broker](/motion_mmWave/esphome/image/25_212632.png)
  ![Mosquitto_broker](/motion_mmWave/esphome/image/235904.png)

## 雷達調整最佳角度說明
## 固定好MotionOne，打開蜂鳴器開關 >  設定延遲1秒 離開偵測範圍，等待無人提示音響 > 走進涵蓋範圍 > 有人聲音響起 > 必要時調整雷達角度與偵測距離倍數直到最佳方位後測定回延遲60秒或更久，關閉蜂鳴器。
### 涵蓋範圍(官方裸版數據必須打折扣)
  ![Mosquitto_broker](/motion_mmWave/image/B8AD097F334_1.JPG)
  ![Mosquitto_broker](/motion_mmWave/image/B8AD097F334_2.JPG)
  ![Mosquitto_broker](/motion_mmWave/esphome/image/000928.png)

  ![Mosquitto_broker](/motion_mmWave/esphome/image/000834.png)

