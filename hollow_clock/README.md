# 自動校正版的 hollow clock 4
## 接入自家wifi
  設備上電手機搜尋設備發出的wifi AP(熱點) "AutoConnectAP" 並指定自家2.4G wifi 與密碼。
## 自動校正
  手機瀏覽器輸入 http://wifi-clock.local/  就會跳出自動校正頁面，若家裡有兩台以上，可以透過路由器Router的管理頁面找到接入的IP位置(Active Host Name 應該是 "ESP-XXXXXX")，於瀏覽器輸入該IP即可進入。P.S 實測每天只能自動校正一次，若測試階段當天已用完額度，參考下列手動對時方法。

![Mosquitto_broker](/hollow_clock/image/083921.png)

## 手動校正
  進入下列網站，點選Real Time按鍵出現現在時間的方位，將空心鐘放在螢幕上對準中心點，再調整時針與分針的角度(調整底部齒輪改變指針角度)，簡單粗暴。
  
https://www.visnos.com/demos/clock

![Mosquitto_broker](/hollow_clock/image/2DDA1AE4D405.jpg)
