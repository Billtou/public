# ESPHome 版本
## 紅線與白線分別接入市電的L/N(火線/中性線)

第一步: 上電後手機搜尋設備發出的AP熱點(auto-space-xxxxxx) 點選接入這個名稱的wifi後會自動跳轉到指定自家wifi的頁面，輸入後儲存即可，若沒跳轉到指定頁面，手機瀏覽器輸入192.168.4.1 即可依序填入自家wifi資訊。

第二步A: 家裡沒有home assistant智能環境適用 > 掃描設備的二維條碼(QR Code)會跳轉到網頁版的設置頁面，依序設定毫米波雷達感應的距離、靈敏度等級，找到最合適現場環境的參數即可。也可以透過家裡的路由器得知被分配到的IP，直接在電腦的瀏覽器輸入IP也可以進入設置頁面。

第二步B: 有Home assistant智能環適用 > 接入自家wifi HA會自動發現設備。

第三步設置功能說明:

![Mosquitto_broker](/auto_space/image/165548.png)

![Mosquitto_broker](/auto_space/image/165724.png)

![Mosquitto_broker](/auto_space/image/170029.png)
