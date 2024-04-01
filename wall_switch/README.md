### 一定要注意須按順序修改否則會死，須回廠上機器重燒

0.先進入"裝置" > "裝置與服務" > "ESPHome" > 找到 "wall-switch-x-xxx"  把正確的設備名稱copy到剪貼簿備用。(x-xxx)每個開關都有不同編號。
0.下載相對應的yaml 文件
0.必須安裝附加元件ESPHome

1.進入ESPHome 右下 "+ NEW DEVICE"。
2.選擇 "CONTINUE"。
3.把剪貼簿的名稱貼上後 > "NEXT" > "ESP32" > SKIP。 出現就正確 "ONLINE"


4.會出現一個設備 > "EDIT" 進入編輯模式。
5.依據下圖替換正確的yaml程序碼。

6.畫面右上 "SAVE" > "INSTALL"
7.沒意外燒寫完成顯示on-line了可以開始編譯程序碼了，目前堤供1~3鍵標準版以及解偶後想把案鍵變成多功能點動開關。

wall-switch-1-xxxx.yaml (一路開關)

wall-switch-2-xxxx.yaml (二路開關)

wall-switch-3-xxxx.yaml (三路開關)

wall-switch-1-xxxx-multi_click.yaml (一路點動開關 模擬作為雙開的第二個開關運用)




這是一路開關標準版ESPHome yaml檔，須注意
