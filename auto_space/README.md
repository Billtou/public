# Auot Space ESPHome 版本說明

## bathroom 浴室版本

解決台灣常見浴室自動化方案，吸頂式人在傳感器涵蓋乾、溼分離區域，自帶兩個繼電器分別可控制電燈與抽風機，人來開燈開抽風機，離開關燈並持續抽風5分鐘後關閉，濕度達標開抽風扇濕度下降關閉，並可擴展至多2個紅外線人體感測器達到浴室門打開路過不開燈，一踏進浴室瞬間開燈的精準控制。

## kitchen 廚房版本

解決台灣常見廚房格局自動化方案(廚房有兩個入門口進廚房與通後陽台)，吸頂式人在傳感器涵蓋廚房區域，自帶兩個繼電器分別可控制電燈以及一個備用，人來開燈，離開關燈，並可擴展至多2個紅外線人體感測器達到路過不開燈，一踏進廚房瞬間開燈的精準控制。

## entrance 玄關版本

解決玄關、通道、樓梯間等自動化方案，吸頂式人在傳感器涵蓋該區域，自帶一個繼電器可控制，人來開燈，離開關燈。

## 規格與此尺寸表

![Mosquitto_broker](/auto_space/image/134954.png)



## 紅線與白線分別接入市電的L/N(火線/中性線)

第一步: 上電後手機搜尋設備發出的AP熱點(auto-space-xxxxxx) 點選接入這個名稱的wifi後會自動跳轉到指定自家wifi的頁面，輸入後儲存即可，若沒跳轉到指定頁面，手機切換到瀏覽器輸入192.168.4.1 即可序填入自家wifi資訊。

第二步A: 家裡沒有home assistant智能環境適用 > 掃描設備的二維條碼(QR Code)會跳轉到網頁版的設置頁面，依序設定毫米波雷達感應的距離、靈敏度等級，找到最合適現場環境的參數即可。也可以透過家裡的路由器得知被分配到的IP，直接在電腦的瀏覽器輸入IP也可以進入設置頁面。

第二步B: 有Home assistant智能環適用 > 接入自家wifi HA會自動發現設備。

第三步設置功能說明:

bathroom 浴室版本 [https://github.com/Billtou/public/tree/main/auto_space/bathroom_%20version]

kitchen 廚房版本 [https://github.com/Billtou/public/tree/main/auto_space/kitchen_version]

entrance 玄關版本 [https://github.com/Billtou/public/tree/main/auto_space/entrance_%20version]


![Mosquitto_broker](/auto_space/image/165548.png)

![Mosquitto_broker](/auto_space/image/165724.png)

![Mosquitto_broker](/auto_space/image/170029.png)
