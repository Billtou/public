<div align="center">
  <svg width="280" height="60" viewBox="0 0 280 60" xmlns="http://www.w3.org/2000/svg">
    <circle cx="30" cy="30" r="14" fill="none" stroke="#ff6f48" stroke-width="3"/>
    <circle cx="30" cy="30" r="6" fill="#ff6f48"/>
    <text x="60" y="38" font-family="Arial, sans-serif" font-size="26" font-weight="bold" fill="#1c3d5a" letter-spacing="2">AUTOMATE</text>
  </svg>

  <h1 style="color:#1c3d5a; border:none; margin-top:8px;">智能氣象面板 · WP-475 / WP-375</h1>

  <p style="color:#5a6878; font-size:1.1em; max-width:760px;">
    7.5" 電子紙 · <b>Matter 版 / HomeKit 版</b>兩種韌體 · Wi-Fi<br/>
    中央氣象署(CWA)即時天氣 · 7 日預報 · 3 日逐 3 小時細部 · 日出日落 · 月相 · 節氣
  </p>

  <p>
    <img src="https://img.shields.io/badge/Matter-1.x-1c3d5a?style=flat-square" alt="Matter 1.x"/>
    <img src="https://img.shields.io/badge/Apple_HomeKit-Yes-1c3d5a?style=flat-square" alt="Apple HomeKit"/>
    <img src="https://img.shields.io/badge/Wi--Fi-2.4_GHz-1c3d5a?style=flat-square" alt="Wi-Fi 2.4 GHz"/>
    <img src="https://img.shields.io/badge/E--paper-800×480-ff6f48?style=flat-square" alt="800×480"/>
  </p>
</div>

---

<div align="center" style="background:#f8f9fb; border:1px solid #dde3ec; border-radius:8px; padding:14px 18px; max-width:820px; margin:0 auto;">
<b style="color:#1c3d5a;">📦 兩種韌體版本(硬體相同,依你的智能家庭生態選一種)</b><br/><br/>

<table>
<tr>
<th align="left" style="background:#1c3d5a; color:white;">版本</th>
<th align="left" style="background:#1c3d5a; color:white;">接入生態</th>
<th align="left" style="background:#1c3d5a; color:white;">配對碼</th>
</tr>
<tr>
<td><b>Matter 版</b></td>
<td>Apple Home · Google Home · SmartThings · Home Assistant · Alexa(跨生態,最多 5 個)</td>
<td>11 碼 <code>3642-630-6820</code></td>
</tr>
<tr>
<td><b>HomeKit 版</b></td>
<td>Apple 家庭(原生 HomeKit)· Home Assistant(HomeKit 控制器)</td>
<td>8 碼 <code>111-88-999</code></td>
</tr>
</table>

功能、CWA 氣象、電子紙顯示、Web UI 全部相同 — 差別只在<b>配對方式與可接入的生態</b>。看機身標籤 / 快速入門卡的 QR Code 即可分辨。
</div>

---

<details open>
<summary><b>📑 目錄</b></summary>

1. [產品簡介](#1-產品簡介)
2. [硬體說明](#2-硬體說明)
3. [LED 狀態指示](#3-led-狀態指示)
4. [按鍵操作](#4-按鍵操作)
5. [接入智能生態(初次配對)](#5-接入智能生態初次配對)
6. [跨生態接入(僅 Matter 版 · Multi-Admin)](#6-跨生態接入僅-matter-版--multi-admin)
7. [Web UI 進階設定](#7-web-ui-進階設定)
8. [CWA 氣象抓取與顯示](#8-cwa-氣象抓取與顯示)
9. [OTA 韌體更新](#9-ota-韌體更新)
10. [工廠重置](#10-工廠重置)
11. [故障排除](#11-故障排除)
12. [安全使用](#12-安全使用)
13. [規格表](#13-規格表)

</details>

---

<h2 id="1-產品簡介" style="color:#1c3d5a;">1 · 產品簡介</h2>

🔴 **快速入門:首次上電,手機打開智能家庭 App「加入配件」掃描機身 QR Code 即可。每次上電畫面會出現「調參 QR」約 30 秒,方便手機連進 Web UI 調參數。Home Assistant(Matter 版)使用者請先進入 設定 > 應用程式 > Matter Server > 設定,把 Enable test-net DCL usage 打開。**

WeatherPanel 系列是 AUTOMATE 推出的智能氣象面板,搭載 **7.5" 電子紙顯示**,抓取**中央氣象署(CWA)開放資料平台**的官方氣象預報並渲染成精美版面。零按鈕、低耗電、室內室外都看得清,放桌上 / 掛牆上都合適。

**兩種機型,共用一套軟體 + 預報資料:**

<table>
<tr>
<th align="left" style="background:#1c3d5a; color:white;">機型</th>
<th align="left" style="background:#1c3d5a; color:white;">顯示色</th>
<th align="left" style="background:#1c3d5a; color:white;">整刷時間</th>
</tr>
<tr><td><b>WP-475</b></td><td>黑 · 白 · 紅 · 黃(4 色)</td><td>~17 秒</td></tr>
<tr><td><b>WP-375</b></td><td>黑 · 白 · 紅(3 色)</td><td>~16 秒</td></tr>
</table>

> 機型分辨:看面板右上角顯示 **WP-475**(4 色)或 **WP-375**(3 色)。

### 主要特性

| 特性 | 說明 |
|---|---|
| 🇹🇼 **官方資料源** | 中央氣象署 OpenData,7 日 + 3 日逐 3 小時逐時細部 |
| 🖼️ **電子紙顯示** | 反光技術,光線越強越清楚,無背光不傷眼 |
| 🔗 **智能家庭接入** | Matter 版跨生態(Apple / Google / SmartThings / HA / Alexa);HomeKit 版原生接入 Apple 家庭 |
| ⏰ **自動排程更新** | 7 個固定時刻 + 3 個自訂時刻,亦可手動觸發 |
| 🌑 **節氣 / 月相 / 日出日落** | 內建天文計算,不需聯網就能算 |

### 1.1 規格速覽

| 項目 | 內容 |
|---|---|
| 顯示器 | 7.5" e-paper 480 × 800 |
| 顯示色 | WP-475:黑 / 白 / 紅 / 黃(4 色)· WP-375:黑 / 白 / 紅(3 色)|
| 顯示更新時間 | ~16-17 秒(整張重畫) |
| 通訊協定 | **Matter 1.x** 版　或　**Apple HomeKit** 版(兩種韌體,over Wi-Fi) |
| Wi-Fi | 2.4 GHz 802.11 b/g/n(⚠️ **不支援 5 GHz**)|
| BLE | 5.0(僅配對用) |
| 處理器 | ESP32-S3(雙核, 160 MHz) |
| Flash | 8 MB · PSRAM 2 MB |
| 供電 | DC 5V / USB-C,建議 ≥ 1 A |
| 工作環境 | 0–50 °C / 10–90% RH(無凝結) |

### 1.2 包裝內容

- WP-475 或 WP-375 主機 × 1(出貨依訂單)
- 台式桌面底座 / 110V 開關暗孔上牆式(選購)
- 快速入門卡(含配對 QR Code 與配對碼)× 1

---

<h2 id="2-硬體說明" style="color:#1c3d5a;">2 · 硬體說明</h2>

### 2.1 外觀與接口

- **7.5" 電子紙** — 主顯示,正面唯一可視元件
- **狀態 LED** — 機身後側 LED,顯示 Wi-Fi / 配對 / 重置狀態(章節 3)
- **多功能按鍵** — 機身後側細孔,需用迴紋針 / 細針戳;只負責工廠重置(章節 4)
- **USB-C** — 供電(資料線無作用,單純取電)

### 2.2 配對碼資訊

依你手上的韌體版本使用對應配對碼(機身底部標籤 / 快速入門卡):

**Matter 版**

| 項目 | 數值 |
|---|---|
| Matter QR Code | 機身底部標籤 |
| 11 碼手動配對碼 | `3642-630-6820`(WP-475 與 WP-375 共用) |
| 預設 Hostname | `automate-wp475-XXXXXX.local` |

**HomeKit 版**

| 項目 | 數值 |
|---|---|
| HomeKit QR Code | 機身底部標籤 |
| 8 碼 HomeKit 設定碼 | `111-88-999` |
| 預設 Hostname | `automate-ahp-wp475-XXXXXX.local` |
| 設定用熱點 SSID | `automate-wp475-XXXXXX` |

> 兩版預設裝置名皆為 `WP475-XXXXXX`(WP-375 為 `WP375-XXXXXX`,XXXXXX = MAC 後 6 碼)。配對碼遺失時可從 Web UI(章節 7)首頁查裝置 MAC,或看快速入門卡 QR Code。

---

<h2 id="3-led-狀態指示" style="color:#1c3d5a;">3 · LED 狀態指示</h2>

依優先級從高到低:

| 優先級 | 狀態 | LED 行為 | 含義 |
|---|---|---|---|
| **1** | 重置警告 | 🔴 紅色 5 Hz 快閃(亮 0.1s 暗 0.1s） | 按鍵已按 5 秒,再 5 秒就執行工廠重置 |
| **2** | 等待 Wi-Fi | 🔵 藍色閃 1 下 + 停 1.8s | 尚未設定 Wi-Fi / Wi-Fi 連不上 |
| **3** | 未配對 / 配對中 | 🟠 橘色雙閃 + 停 1.4s | Wi-Fi 已連,配對進行中或還沒加入任何家庭 |
| **4** | 正常運作 | ⚫ 熄滅 | 一切就緒 |

| 看到 LED | 通常代表 | 該做什麼 |
|---|---|---|
| 🔵 藍色閃 1 下 | 沒設定過 Wi-Fi / 重置後 | 用手機 App 配對流程加入 |
| 🟠 橘色雙閃 | 配對流程進行中 | 等 30 秒;超過 1 分鐘還在雙閃 → App 重新加入 |
| ⚫ 熄滅 | 已上線運作中 | 無需處理 |
| 🔴 紅色快閃 | 你正在長按重置鍵 | 想取消重置就放開;想重置就按到 10 秒 |

---

<h2 id="4-按鍵操作" style="color:#1c3d5a;">4 · 按鍵操作</h2>

背後細孔重置鍵,需用迴紋針 / 細針戳。**僅負責工廠重置**,日常使用無其他功能。

| 動作 | 結果 |
|---|---|
| 持續按住 0–5 秒 | 無反應(放開不做事) |
| 持續按住達 5 秒 | LED 開始 **🔴 紅色快閃**(警告中,放開可取消) |
| 持續按住達 10 秒 | **工廠重置觸發**,LED 熄滅,裝置自動重啟 |

> 重置範圍見 [章節 10](#10-工廠重置)。

---

<h2 id="5-接入智能生態初次配對" style="color:#1c3d5a;">5 · 接入智能生態(初次配對)</h2>

**配對前確認(兩版通用)**

- [ ] 路由器 **Wi-Fi 2.4 GHz** 可用(不支援 5 GHz)
- [ ] 手機藍牙開啟,跟裝置距離 < 1 公尺(HomeKit 版設 Wi-Fi 走熱點,詳見 5B)

---

### 5A · Matter 版

支援 **Apple Home / Google Home / SmartThings / Home Assistant / Amazon Alexa**。

1. 通電,等 LED **🔵 藍色閃 1 下 + 停**
2. 開智能家庭 App →「加入配件 / 加入裝置」
3. 掃機身 **Matter QR Code**;或手動輸入 `3642-630-6820`
4. App 自動傳 Wi-Fi 憑證 → LED **🟠 橘色雙閃**
5. 配對完成 → LED **熄滅**,出現裝置「**WP475-XXXXXX**」+ 一顆「**立即重抓天氣**」按鈕(可在自動化中當 trigger)

> Home Assistant 使用者:先到 設定 > 應用程式 > Matter Server > 設定,打開 **Enable test-net DCL usage**,再加入。

### 5B · HomeKit 版

原生 **Apple 家庭**。採兩步驟:先用設定熱點設 Wi-Fi,再加入家庭。

**① 先設定 Wi-Fi(SoftAP)**
1. 通電,LED **🔵 藍色閃 1 下**(尚未設 Wi-Fi)
2. 手機 Wi-Fi 連上熱點 **`automate-wp475-XXXXXX`**(無密碼)
3. 手機通常自動彈出設定頁;若無,瀏覽器開 `http://192.168.4.1/`
4. 選家用 Wi-Fi(2.4 GHz)→ 輸入密碼 → 儲存,裝置自動重啟連網

**② 加入 Apple 家庭**
1. iPhone 開「家庭」App → **+** → **加入配件**
2. 掃機身 **HomeKit QR Code**;或手動輸入設定碼 `111-88-999`
3. 完成 → 出現「**WP475-XXXXXX**」配件 + 一顆「**立即重抓天氣**」開關

**進階:Home Assistant(HomeKit 控制器)**
HA → 設定 → 裝置與服務 → 新增整合 → **HomeKit Controller** → 選 `WP475-XXXXXX` → 輸入 `111-88-999`。

> ⚠️ HomeKit 版一次只綁定一個 HomeKit 家庭。要同時被多個平台控制,請改用 **Matter 版**(章節 6)。

---

<h2 id="6-跨生態接入僅-matter-版--multi-admin" style="color:#1c3d5a;">6 · 跨生態接入(僅 Matter 版 · Multi-Admin)</h2>

> 本章僅適用 **Matter 版**。HomeKit 版為單一家庭綁定,無此功能。

Matter 規範允許**同一台裝置同時加入多個生態**,最多 **5 個 Fabric**。例如同時被 Apple Home 與 Home Assistant 控制,在任一生態觸發「立即重抓天氣」,e-paper 都會立刻重畫。

<div style="background:#fff8f0; border-left:4px solid #ff6f48; padding:10px 16px; border-radius:6px;">
<b>關鍵原則</b>:第二個生態起,<b>不能用出廠那組 <code>3642-630-6820</code></b> — 必須由<b>第一個已配對的生態</b>產生一組「分享配對碼」(每次新的、有時效)。
</div>

- **從 Apple Home 分享**:家庭 App → 長按裝置 → 設定 → **「開啟配對模式」** → 得一組 15 分鐘有效的拷貝碼 → 在第二個生態輸入。
- **從 Home Assistant 分享**:設定 → Matter → 指定裝置 → **分享裝置** → 複製代碼 → 在第二個生態輸入。

| 誤操作 | 後果 | 正確做法 |
|---|---|---|
| 第二個生態用出廠 `3642-630-6820` | 配對失敗 | 用第一個生態生出來的「分享碼」 |
| 用 Apple 重置裝置後再加入 Google | Apple 那邊也會掉 | 不要重置,用「Multi-Admin 分享」流程 |
| 已加入 5 個生態還想加 | 失敗 | 移除其中一個再加 |

---

<h2 id="7-web-ui-進階設定" style="color:#1c3d5a;">7 · Web UI 進階設定</h2>

### 7.1 連線方式

配對成功後在區網提供 Web UI。瀏覽器網址兩種擇一:
- **直接 IP**:在生態 App 內查看裝置 IP(例 `http://192.168.1.123`)
- **主機名稱**:Matter 版 `http://automate-wp475-XXXXXX.local`　/　HomeKit 版 `http://automate-ahp-wp475-XXXXXX.local`

> 手機 / 電腦與裝置必須在**同一個 Wi-Fi 網段**。

### 7.2 首頁:裝置資訊 + CWA 設定 + 排程

| 區塊 | 內容 |
|---|---|
| **裝置資訊** | 韌體版本、可用記憶體、運行時間、連線狀態、製造日期 |
| **CWA 氣象署抓取設定** | API Key 輸入、縣市下拉、鄉鎮區下拉 |
| **預報內容與顯示調整** | 預報模式(7 日 / 3 日 8 種版型)+ 顯示方向(橫式 / 直式) |
| **自動更新排程** | 7 個固定時刻可勾選 + 3 個自訂時刻 + 主總開關 |
| **儲存按鈕** | 橘色「**儲存參數 + 更新與刷新**」— 一鍵存全部 + 立刻重抓 CWA + 重畫 e-paper |

### 7.3 版更頁:OTA 韌體更新

目前版本 / 最新版本 / 「開始更新」/ 「裝置資料清除」/ 系統日誌(見章節 9)。

---

<h2 id="8-cwa-氣象抓取與顯示" style="color:#1c3d5a;">8 · CWA 氣象抓取與顯示</h2>

### 8.1 註冊 CWA API Key

WeatherPanel 抓的是**中央氣象署官方資料**,需要免費 API Key:

1. 開 [中央氣象署開放資料平台](https://opendata.cwa.gov.tw/index)
2. 註冊個人帳號(免費,可即時取得)
3. 登入後 → 會員專區 → 取得授權碼 → **複製整串 `CWA-XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX`**
4. 貼進 Web UI 首頁「CWA 氣象署抓取設定」card 的 API Key 欄位
5. 按底部橘色「儲存參數 + 更新與刷新」 — 約 5-15 秒後 e-paper 重畫

<div style="background:#fff8f0; border-left:4px solid #ff6f48; padding:10px 16px; border-radius:6px;">
API Key 每分鐘限速,內建排程不會打爆;但若手動連點「儲存」亂試,可能 5 分鐘內被暫時擋。
</div>

### 8.2 選擇縣市鄉鎮

「CWA 氣象署抓取設定」card 內選**縣市**(22 縣市)→ **鄉鎮區**下拉自動更新 → 選所在地 → 按橘色「儲存參數 + 更新與刷新」。

> 鄉鎮別名稱可查:[氣象局鄉鎮名稱一覽表](https://github.com/Billtou/public/blob/main/e_ink_display/%E6%B0%A3%E8%B1%A1%E5%B1%80%E9%84%89%E9%8E%AE%E5%90%8D%E7%A8%B1%E4%B8%80%E8%A6%BD%E8%A1%A8.pdf)。預設值:臺中市 南屯區,重置後恢復此預設。

### 8.3 預報模式(8 種版型)

**7 日 daily(每天 1 列)**:最高/最低溫 · 體感高/低 · 平均溫+濕度 · 平均溫+降雨機率 · 平均溫+UV
**3 日 3 小時 hourly(每 3 小時 1 列)**:溫度+濕度 · 溫度+降雨 · 體感+降雨

<div style="background:#f8f9fb; border-left:4px solid #1c3d5a; padding:10px 16px; border-radius:6px;">
<b>「降雨機率」顯示「-」:</b>中央氣象署一週預報的降雨機率<b>只保證前 3 天有具體百分比</b>,第 4 天以後氣象署本身就不公布(顯示「-」)。WeatherPanel 忠實照氣象署資料呈現,不是故障。
</div>

### 8.4 自動更新排程

- **自動化總開關**(關掉所有自動更新都停)
- **固定時刻**(對齊 CWA 發布時間):`00:15` / `06:15` / `09:15` / `12:15` / `15:15` / `18:15` / `21:15`(各自可勾選)
- **自訂時刻 × 3 組**(例如出門前、回家前)

### 8.5 顯示方向 · 8.6 手動立即更新

出廠**橫式 800×480**,可切**直式 480×800**(壁掛 / 桌立)。手動更新兩法:① Web UI 橘色「儲存參數 + 更新與刷新」② 生態 App 內找「立即重抓天氣」開關點一下。等 5–15 秒 e-paper 自動重畫。

---

<h2 id="9-ota-韌體更新" style="color:#1c3d5a;">9 · OTA 韌體更新</h2>

1. 連線 Web UI → 底部 **版更** Tab
2. 系統自動向官方 GitHub 檢查最新版本
   （Matter 版 → `WP_475/matter/475/firmware-w`；HomeKit 版 → `WP_475/homekit/475/firmware-w`）
3. 若有新版 →「開始更新」→ 自動下載 + 安裝 + 重啟(約 1–2 分鐘)

期間裝置暫時離線,e-paper 維持上一張畫面。

| 項目 | 是否保留 |
|---|---|
| 配對(Matter 所有生態 / HomeKit 家庭)| ✅ 保留 |
| Wi-Fi 帳密 | ✅ 保留 |
| CWA API Key / 縣市 / 鄉鎮 / 排程 / 顯示設定 | ✅ 保留 |
| 韌體版本 | ❌ 換新版 |

> ⚠️ 更新中請勿斷電。異常時雙分區設計會自動回上一版。

---

<h2 id="10-工廠重置" style="color:#1c3d5a;">10 · 工廠重置</h2>

**硬體重置**:迴紋針戳機身背面重置小圓孔,按住 5 秒(LED 紅快閃)→ 續按到 **10 秒** → 重置觸發、自動重啟。5–10 秒間放手 = 取消。
**Web UI 重置**:版更頁 →「裝置資料清除」→ 確認。

| 項目 | 是否清除 |
|---|---|
| 配對(所有生態 / 家庭)| ✅ 清除 |
| Wi-Fi 帳密 | ✅ 清除 |
| CWA API Key / 縣市 / 鄉鎮 | ✅ 重置為預設(臺中市 南屯區、出廠 API Key)|
| 預報模式 / 顯示方向 / 排程 | ✅ 重置為預設 |
| 機型變體(WP-475 / WP-375)| ❌ 保留(出廠寫入,不被清)|
| 韌體版本 / 裝置憑證 | ❌ 不變 |

> 重置後跟全新開封一樣,需重新配對。

---

<h2 id="11-故障排除" style="color:#1c3d5a;">11 · 故障排除</h2>

**配對相關**

| 現象 | 原因 | 處理 |
|---|---|---|
| LED 一直藍色閃,App 找不到裝置 | 配對流程沒走完 / 藍牙關 / 太遠 | 確認藍牙開、距離 < 1 m、Wi-Fi 是 2.4 GHz;HomeKit 版先完成 5B ① 設 Wi-Fi |
| 橘色雙閃很久最後又回藍色 | 供電不足中途重啟 | 換較粗 USB 線 / USB 3.0 直連、不走 hub |
| App 顯示「無法加入」 | 配對碼錯 / Fabric 已滿(Matter)/ 已被綁定(HomeKit) | 重輸碼;Matter 5 個生態已滿先移除其一;HomeKit 曾配對過先重置 |
| Matter 第二個生態加不進 | 用了出廠碼 | 改用第一個生態的「分享碼」(章節 6) |

**顯示相關**

| 現象 | 原因 | 處理 |
|---|---|---|
| 畫面停在「設定 QR」沒切到天氣 | 還沒抓到 CWA 資料 | 確認 API Key 已設(章節 8.1),等 30 秒 |
| 畫面有殘影 / 線條 | 電子紙特性 | 按一下「儲存參數 + 更新與刷新」整刷即清 |
| 更新時畫面變花 16-17 秒 | 電子紙整刷正常現象 | 等完即可,別拔電源 |
| 時間顯示不對 | 沒同步 NTP | 確認可達 pool.ntp.org / time.google.com |

**CWA 抓取相關**

| 現象 | 原因 | 處理 |
|---|---|---|
| 預報整片「—」 | API Key 沒設 / 過期 / 拼錯 | Web UI 重貼 API Key 存檔 |
| 鄉鎮下拉沒選項 | 縣市還沒選 / 載入失敗 | 重新整理 Web UI |
| 4 天以後降雨機率「-」| 氣象署只給前 3 天 | 正常現象 |

**OTA 相關**

| 現象 | 原因 | 處理 |
|---|---|---|
| 版更頁「無法取得版本」| 連不到 GitHub | 檢查網路 / DNS |
| 「開始更新」後一直 0% | 下載卡住 | 等 5 分鐘;不行就重啟再試 |

---

<h2 id="12-安全使用" style="color:#1c3d5a;">12 · 安全使用</h2>

- ⚡ **供電必須穩定** — 電子紙整刷瞬間耗電大,USB 線太細 / hub 供電不足會 brownout 重啟
- 🔌 拆殼 / 改裝會違反電信法規(內含 BLE / Wi-Fi 無線電路)
- 🌡 工作環境 0–50 °C,**勿放暖氣 / 廚房灶台旁**(電子紙 > 60 °C 會永久損壞)
- 🌧 戶外使用請另購防水殼
- ☀ **電子紙怕長時間直曬** — 紫外線會讓彩色顏料褪色
- 🧊 結霜 / 低於 0 °C 別開機(電子紙冰點以下更新會壞)

---

<h2 id="13-規格表" style="color:#1c3d5a;">13 · 規格表</h2>

| 項目 | 規格 |
|---|---|
| 產品名稱 | WP-475(4 色版)/ WP-375(3 色版) |
| 品牌 | AUTOMATE |
| 顯示器 | 7.5" e-paper 480 × 800 |
| 顯示色 | WP-475:黑 / 白 / 紅 / 黃 · WP-375:黑 / 白 / 紅 |
| 顯示更新時間 | ~16-17 秒(整張重畫)|
| 通訊協定 | **Matter 1.x 版** 或 **Apple HomeKit 版**(兩種韌體,over Wi-Fi) |
| Matter 配對碼 | `3642-630-6820`（Matter 版）|
| HomeKit 設定碼 | `111-88-999`（HomeKit 版）|
| Wi-Fi | 2.4 GHz 802.11 b/g/n |
| 藍牙 | BLE 5.0(僅配對) |
| 處理器 | ESP32-S3(雙核, 160 MHz) |
| Flash / PSRAM | 8 MB / 2 MB |
| 供電 | DC 5V / USB-C(建議 ≥ 1 A) |
| 待機功耗 | < 0.5 W(更新瞬間 ~1.5 W) |
| 工作溫度 / 濕度 | 0–50 °C / 10–90% RH(無凝結) |
| 資料源 | 中央氣象署 OpenData(F-D0047 系列) |
| 預報範圍 | 7 日 daily + 3 日 hourly(3 小時間隔) |
| 內建天文 | 日出日落、月相、24 節氣 |
| Matter VID / PID | `0xFFF1` / `0x8011`(WP-475 / WP-375 共用) |

---

<div align="center" style="color:#5a6878; font-size:0.9em; margin-top:30px;">
<b style="color:#1c3d5a;">AUTOMATE</b> · WP-475 / WP-375 智能氣象面板 · Matter 版 / HomeKit 版
</div>
