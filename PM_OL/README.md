# PM-OL OverLoad 自動偵測電流過載保護
![重啟](/PM_OL/image/reset.JPG)
## 接入自家網路(WIFI)
* 上電稍待1~2分鐘手機靠近設備找wifi熱點 automate-pm-ol-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。
## 接入自家網路(網線)
* 上電插上網線即可。
## 接線方式
![接線](/PM_OL/image/overload.JPG)
## ESPHone 實體說明
![entity](/PM_OL/image/entity_1.JPG)
## 注意事項
- 以上說明範例默認環境設置繼電器常閉(通電狀態)，若偵測到電流超標繼電器會ON變成常開狀態(不通電)，這樣電磁開關(或稱接觸開關)就會跳閘。
- 依據以上的說明，首次安裝時請先按下紅色"切"按鈕，SW紅燈亮起，接上必要電線與參數設置完成後再次按下紅色按鈕(SW紅燈熄滅)開始使用。
- ESPHome實體說明:
  * Default Relay State - 重開機或停電後來電指定繼電器為ON or OFF
  * Overload Protect - 是否開啟過載保護
  * Overload Protect Auto Recovery 跳閘後是否自動恢復通電模式開關
  * Overload Recovery Timing 若 Auto Recovery ON， 跳閘後幾秒後再次通電。
  * Overload Trigger Timing 電流持續超過秒數後過載條件成立。 避免用電設備啟動時會有瞬間大電流導致誤判的機制。
  * Voltage Type - 默認偵測220V，若用電備為110V請更改。
  * 請注意上圖接線說明裡交流互感器CT偵測的110V L線要與產品用電的L線同一條，偵測到的用電數據才是最準確的。
 
