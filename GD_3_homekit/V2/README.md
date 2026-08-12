# AUTOMATE GD3 HomeKit 版本說明

> 適用韌體 v0.1.x。GD-3 為傳統鐵捲門 / 快速門 HomeKit 控制器(ESP32-S3,網線 + Wi-Fi 雙網路),支援雷射防夾、開門行程模擬、MQTT 接入 Home Assistant。

---

# 1. 接入網路

## 1.1 接入自家網路(WiFi)
- 上電稍待超過 30 秒,手機靠近設備找 Wi-Fi 熱點 **`Garage-GD3-XXXXXX`**(XXXXXX = 設備編號),接入後手機會自動跳出設定頁面(沒有自動跳出時,用瀏覽器開 `http://192.168.4.1/`),指定好自家 Wi-Fi 與密碼,設備會自動重啟並連上。

## 1.2 接入自家網路(網線)
- 上電插上網線即可,**免任何設定**。網線優先,拔掉網線會自動改走 Wi-Fi(若已設定)。

### 注意:系統開機會搜尋網線與 WiFi。若已接入 WiFi 但要切換為網線連接,請接入網線後依下方「重置設備方式」清除 WiFi 記憶即可。

## 1.3 接入 Apple Home
Apple 家庭 App 掃描 QR-Code,或輸入引導號碼 **11188999** 即可。

![homekit_QR_code](/GD_3_homekit/image/qr-11188999-AUTM.png)

---

# 2. 重置設備方式(清除 WiFi)

![081733](/GD_3_homekit/image/image13.JPG)

設備上的**多功能按鍵**:

| 按法 | 動作 |
|---|---|
| 短按 | 雷射手動測試 **開/關切換**(見下方雷射章節)|
| 長按 5 秒 | LED 開始急閃 = 重置警告(此時放開不會重置)|
| 長按滿 **10 秒** | **恢復出廠**:清除 HomeKit 配對 + WiFi 記憶 + MQTT 設定,重啟回配網模式 |

---

# 3. 安裝

## 安裝位置示意圖
![081733](/GD_3/image/20250519_10.JPG)

## 接線端口功能介紹
![081733](/GD_3_homekit/image/S__133849093_1.JPG)

## 接快速門
![081733](/GD_3/image/20250519_3.JPG)

## 傳統鐵捲門(需斷電施作)
![081733](/GD_3/image/20250519_5.JPG)

## 遙控器改裝
![081733](/GD_3_homekit/image/S__133849093_2.JPG)

---

# 4. 雷射(防夾)感應器

### *注意:請保持雷射感應器通電時紅綠燈都會亮,反之訊號會不正常*
- 在通電的狀態下可按下切換鍵進行切換。

![081733](/GD_3/image/gr-laser.JPG)
![081733](/GD_3/image/image1345.JPG)

### 設備提供兩組雷射訊號端口,原則上只要並聯訊號線,防夾感應器數量是可以超過 2 台以上的。

## 4.1 雷射電源與手動測試
- 雷射平常**不通電**,只在**關門中**自動通電偵測(省電、延長雷射壽命)。
- 安裝對位時可手動開啟雷射:
  - **Web UI 首頁**「鐵卷門狀態判斷」卡 → 按「**開啟雷射**」(常亮,再按「關閉雷射」恢復)
  - 或**短按設備多功能鍵**(同樣是開/關切換)
- ⚠️ 手動測試模式中,光柵訊號只顯示**不會**觸發防夾動作;**測完請記得關閉**,恢復自動防護。

## 4.2 防夾自動化說明
按下關門後雷射自動通電偵測,直到門磁感應反饋關閉為止。期間若有異物遮擋:

1. 立即**停止關門**,約 3 秒後**自動反向開門**(把門打開,方便移除障礙物)
2. Apple Home 畫面出現**障礙物警示**
3. 障礙物存在期間,關門指令會被擋下(防止夾傷)
4. 移除障礙物後再按關閉即可;若關門中又被遮擋,會再次自動反向,直到通道淨空

---

# 5. Apple 實體說明

### 車庫門開關 = 可開/關車庫門
- 按「開」後會顯示「**開門中**」,經過設定的**開門時間**後轉為「**已開啟**」(模擬實際開門過程,見第 6 章)
- 按「關」後顯示「**關門中**」,門到底(門磁感應)才轉為「**已關閉**」

### 停止開關 = 車庫門行程中可停止該門動作
- 點一下即停止,開關會自動彈回;停止後門視為「已開啟」,要關門再按關閉即可

---

# 6. 開門時間調整(Web UI)

因為鐵捲門**沒有上極限感應器**,系統以「開門時間」模擬開門過程:按開門後 Apple Home 顯示「開門中」,滿設定秒數後轉「已開啟」。

## 6.1 進入 Web UI
配對成功後,同一區網用瀏覽器開:
- `http://automate-gd3-XXXXXX.local`,或
- 設備 IP(路由器管理頁可查)

## 6.2 設定方式
首頁「**開門行程**」卡片:

| 項目 | 內容 |
|---|---|
| 行程時間 | 0 ~ 120 秒(預設 10 秒)|
| 量測方式 | 用碼錶量門**完全打開所需秒數 + 1~2 秒安全餘量** |
| 生效 | 按「儲存並套用」立即生效並寫入設備(重啟、韌體更新都保留)|

> 💡 若按開門後 UI 已顯示「已開啟」但門其實還在動 → 把秒數調大;反之門早就到頂 UI 還在「開門中」→ 調小。

---

# 7. MQTT 接入 Home Assistant(進階選用)

本機內建 MQTT bridge,**Apple Home 與 Home Assistant 可同時使用**(狀態雙向同步)。只用 Apple Home 的使用者可跳過本章。

## 7.1 事前準備

| 你是 | 用不用得到 |
|---|---|
| 只用 Apple Home,沒 HA | 跳過本章,Apple Home 功能完整不缺 |
| 已有 Home Assistant + Mosquitto broker | 跟著本章設定,可在 HA 看到鐵捲門 entity |
| 沒裝 Mosquitto | 先在 HA 裝 `Mosquitto broker` [add-on](https://my.home-assistant.io/redirect/supervisor_addon/?addon=core_mosquitto),設帳密再回來 |
| 沒有建立 mqtt 使用者 | HA > 設定 > 人員 > 使用者 > 增加使用者 > 名稱填 mqtt-user > 密碼填 mqtt-pass > 儲存 |

## 7.2 設定步驟

1. 用瀏覽器打開 **`http://<裝置-IP>`**
2. 到工程模式頁面「**MQTT / Home Assistant**」卡片
3. 填入:

   | 欄位 | 範例 | 說明 |
   |---|---|---|
   | Broker IP | `192.168.1.10` | Mosquitto 主機 IP(一般填 HA 的 IP)|
   | Port | `1883` | 預設 1883 |
   | Username | `mqtt-user` | broker 帳號(在 HA 建立)|
   | Password | `********` | broker 密碼(在 HA 建立)|

4. 按「**連線測試**」— 必須看到綠色「✓ 連線成功」才能繼續
5. 按「**儲存並啟用**」— 裝置自動連 broker 並推送 HA discovery
6. 開 Home Assistant → **設定 → 裝置與服務 → MQTT** → 應看到新裝置(Garage-GD3,XXXXXX = 設備編號)

## 7.3 HA 看得到的功能

| HA Entity | 類型 | 內容 |
|---|---|---|
| 鐵捲門 | `cover`(device_class=`garage`)| 開 / 關 / 停;狀態 Open / Opening / Closed / Closing / Stopped |
| 障礙物 | `binary_sensor`(device_class=`safety`)| 雷射偵測到障礙物時 ON(紅色警示)|

按 HA 的按鈕後 Apple Home 也會即時同步顯示(雙向同步),反之亦然。

## 7.4 MQTT Topic Schema(進階)

```
automate/gd3/{mac6}/state          ← 裝置狀態 (JSON,retained)
automate/gd3/{mac6}/set            ← 控制指令 (payload: OPEN / CLOSE / STOP)
automate/gd3/{mac6}/availability   ← LWT (online / offline)
homeassistant/cover/gd3_{mac6}/config           ← HA Auto-Discovery (retained)
homeassistant/binary_sensor/gd3_{mac6}_obstruction/config
```

State payload 範例:
```json
{ "state": "closed", "obstruction": false }
```

> 進階使用者可用 `mosquitto_sub` / Node-RED 等自製 dashboard,不一定要走 HA。

## 7.5 停用 / 移除

| 操作 | 結果 |
|---|---|
| 「停用」按鈕 | 中斷 MQTT 連線,設定保留 — 之後可重新啟用 |
| 「刪除設定」按鈕 | 清掉 broker IP / 帳密,HA 端 entity 一併移除(不留孤兒 entity)|
| 工廠重置(長按 10 秒)| 一併清掉 MQTT 設定 |

---

# 8. OTA 韌體更新

1. Web UI 底部「**版更**」分頁(或直接開 `http://<裝置-IP>/update`)
2. 系統自動檢查最新版本 → 點「**開始更新**」
3. 約 1–2 分鐘完成自動重啟;HomeKit 配對、WiFi、開門時間等設定**全部保留**

---

<div align="center">
<b>AUTOMATE</b> · GD-3 · 適用韌體 v0.1.x
</div>
