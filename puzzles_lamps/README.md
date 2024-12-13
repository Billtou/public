#  拼圖燈罩使用說明

## 文字說明網頁

https://www.puzzleslamps.com/manual-instructions-puzzles-lamps.html

## 影片版說明

[![Watch the video](/puzzles_lamps/image/193625.png)](https://www.youtube.com/watch?v=Eu-heqvuD7I&t=11s&ab_channel=CompanyJulai)

## 最後燈座安裝提醒

### 有孔的零件最後安裝，在安裝到最後1片的時候先把燈泡鎖上燈座放入燈罩中，電線穿過孔洞鎖上帽套即可，**注意勿所過緊能固定不搖晃即可**。


![081733](/puzzles_lamps/image/200555.png)

![081733](/puzzles_lamps/image/200525.png)

![081733](/puzzles_lamps/image/200625.png)

![081733](/puzzles_lamps/image/200656.png)

# 2024/12/13 Update

## wifi+藍芽 塗鴉智能燈泡安裝說明(手機須打開藍芽方便配對用)

* 手機安裝Smart Lift App
* 手機連接自家wifi 2.4G 網路 
* 設備上電
* app 右上 + 添加設備自動掃描燈泡指定自家wifi名稱與密碼完成配對

## 接入 HA 

* Smart Lift App > 我 > 右上6角形 icon > 帳號與安全 > 用戶 Code 內容記錄下來備用
* HA 安裝 local tuya  https://my.home-assistant.io/redirect/hacs_repository/?owner=make-all&repository=tuya-local&category=integration
* 安裝local tuya 集成 https://my.home-assistant.io/redirect/config_flow_start/?domain=tuya_local
* 選擇 Smart Life雲端輔助設備設定 > 下一步 出現QRcode  > 用手機Smart Lift App 掃描一下配對即可接入HA
