### 外觀介紹
![a重置](image/lt-cw-a.JPG)
### 如何接線與走線規劃建議
![a重置](image/lt-cw-b.JPG)
![a重置](image/lt-cw-c.JPG)
![a重置](image/lt-cw-d.JPG)
### 啟動連網模式
![a重置](image/lt-cw-01.JPG)
### 接入自家網路(WIFI)
 * 重置後手機靠近設備找wifi熱點 automate-lt-cw-xxxxxx，接入後等待數秒手機自動跳轉引導畫面選擇wifi名城與密碼存檔完成。(若沒自動切換可瀏覽器輸入192.168.4.1)。


### Homekit 版本自適應燈光設置
* 依據太陽的位置自適應調整燈光色溫、亮度的功能。
* 日出日落以台灣地區為主。
* 打開自適應開關調整最高(白天)與最低(夜晚)的亮度、色溫參數，燈具會根據太陽角度自適應變化；另外有個睡眠模式(小夜燈)適合浴室廁所場景，例如設置半夜2點開始啟動亮度5%色溫調最黃，一旦過了這個時間打開燈具就變成了小夜燈直到隔天日出，非常好用不怕半夜上廁所燈光亮瞎了睡意。

![自適應](image/自適應.JPG)
### Homekit版本自適應畫面說明
* 掃描產品二維條碼或輸入 IP:8080 即可進入設置頁面

![自適應](image/lt-cw.JPG)

### ESPHome版本自適應燈光設置
* 請安裝HA的自適應燈光插件，並按說明設置即可。

[![OPEN HACS REPOSITORY ON MY](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/hacs_repository/?owner=basnijholt&repository=adaptive-lighting&category=integration)
