<div align="center">
  <svg width="280" height="60" viewBox="0 0 280 60" xmlns="http://www.w3.org/2000/svg">
    <circle cx="30" cy="30" r="14" fill="none" stroke="#ff6f48" stroke-width="3"/>
    <circle cx="30" cy="30" r="6" fill="#ff6f48"/>
    <text x="60" y="38" font-family="Arial, sans-serif" font-size="26" font-weight="bold" fill="#1c3d5a" letter-spacing="2">AUTOMATE</text>
  </svg>

  <h1 style="color:#1c3d5a; border:none; margin-top:8px;">智能氣象面板 · WP-475 / WP-375</h1>

  <p style="color:#5a6878; font-size:1.1em; max-width:760px;">
    7.5" 電子紙 · Matter over Wi-Fi · 跨生態相容<br/>
    中央氣象署(CWA)即時天氣 · 7 日預報 · 3 日逐 3 小時細部 · 日出日落 · 月相 · 節氣
  </p>

  <p>
    <img src="https://img.shields.io/badge/Matter-1.x-1c3d5a?style=flat-square" alt="Matter 1.x"/>
    <img src="https://img.shields.io/badge/Wi--Fi-2.4_GHz-1c3d5a?style=flat-square" alt="Wi-Fi 2.4 GHz"/>
    <img src="https://img.shields.io/badge/E--paper-800×480-ff6f48?style=flat-square" alt="800×480"/>
    <img src="https://img.shields.io/badge/Multi--Admin-5_Fabrics-ff6f48?style=flat-square" alt="5 Fabrics"/>
  </p>
</div>

---

<details open>
<summary><b>📑 目錄</b></summary>

1. [產品簡介](#1-產品簡介)
2. [硬體說明](#2-硬體說明)
3. [LED 狀態指示](#3-led-狀態指示)
4. [按鍵操作](#4-按鍵操作)
5. [接入智能生態(初次配對)](#5-接入智能生態初次配對)
6. [跨生態接入(Matter Multi-Admin)](#6-跨生態接入matter-multi-admin)
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

<table>
<tr>
<td width="60%">

WeatherPanel 系列是 AUTOMATE 推出的智能氣象面板,搭載 **7.5" 電子紙顯示**,抓取**中央氣象署(CWA)開放資料平台**的官方氣象預報並渲染成精美版面。零按鈕、低耗電、室內室外都看得清,放桌上 / 掛牆上都合適。

**兩種機型,共用一套軟體 + 預報資料:**

</td>
<td>

<div style="background:#f8f9fb; border-left:4px solid #ff6f48; padding:12px 16px; border-radius:6px;">
<b style="color:#1c3d5a;">機型分辨</b><br/>
看面板右上角:<br/>
🔴 顯示 <b>WP-475</b> = 4 色機型<br/>
🟠 顯示 <b>WP-375</b> = 3 色機型
</div>

</td>
</tr>
</table>

<table>
<tr>
<th align="left" style="background:#1c3d5a; color:white;">機型</th>
<th align="left" style="background:#1c3d5a; color:white;">顯示色</th>
<th align="left" style="background:#1c3d5a; color:white;">整刷時間</th>
</tr>
<tr><td><b>WP-475</b></td><td>黑 · 白 · 紅 · 黃(4 色)</td><td>~17 秒</td></tr>
<tr><td><b>WP-375</b></td><td>黑 · 白 · 紅(3 色)</td><td>~16 秒</td></tr>
</table>

### 主要特性

| 特性 | 說明 |
|---|---|
| 🇹🇼 **官方資料源** | 中央氣象署 OpenData,7 日 + 3 日逐 3 小時逐時細部 |
| 🖼️ **電子紙顯示** | 反光技術,光線越強越清楚,無背光不傷眼 |
| 🔗 **Matter 標準協定** | 不需專屬 Hub,直接加入 Apple Home / Google Home / SmartThings / Home Assistant / Amazon Alexa |
| 🌐 **跨生態同步** | 同一台裝置可同時加入多個生態(最多 5 個 Fabric) |
| ⏰ **自動排程更新** | 7 個固定時刻 + 3 個自訂時刻,亦可手動觸發 |
| 🌑 **節氣 / 月相 / 日出日落** | 內建天文計算,不需聯網就能算 |

### 1.1 規格速覽

| 項目 | 內容 |
|---|---|
| 顯示器 | 7.5" e-paper 480 × 800 |
| 顯示色 | WP-475:黑 / 白 / 紅 / 黃(4 色)· WP-375:黑 / 白 / 紅(3 色)|
| 顯示更新時間 | ~16-17 秒(整張重畫) |
| 通訊協定 | Matter 1.x over Wi-Fi |
| Wi-Fi | 2.4 GHz 802.11 b/g/n(⚠️ **不支援 5 GHz**)|
| BLE | 5.0(僅配對用) |
| 處理器 | ESP32-S3(雙核 RISC-V, 160 MHz) |
| Flash | 8 MB |
| PSRAM | 2 MB |
| 供電 | DC 5V / USB-C,建議 ≥ 1 A |
| 工作環境 | 0–50 °C / 10–90% RH(無凝結) |

### 1.2 包裝內容

- WP-475 或 WP-375 主機 × 1(出貨依訂單)
- USB-C 電源線 × 1
- 壁掛 / 桌立兩用底座 × 1
- 快速入門卡(含 Matter QR Code 與 11 碼配對碼)× 1

---

<h2 id="2-硬體說明" style="color:#1c3d5a;">2 · 硬體說明</h2>

### 2.1 外觀與接口

- **7.5" 電子紙** — 主顯示,正面唯一可視元件
- **狀態 LED** — 機身側邊小孔,顯示 Wi-Fi / 配對 / 重置狀態(章節 3)
- **多功能按鍵** — 機身側邊細孔,需用迴紋針 / 細針戳;只負責工廠重置(章節 4)
- **USB-C** — 供電(資料線無作用,單純取電)

### 2.2 配對碼資訊

| 項目 | 數值 |
|---|---|
| Matter QR Code | 機身底部標籤 |
| 11 碼手動配對碼 | `3642-630-6820`(WP-475 與 WP-375 共用) |
| 預設裝置名稱 | WP-475:`WP475-XXXXXX`(後 6 碼為 MAC)· WP-375:`WP375-XXXXXX` |
| 預設 Hostname | `automate-wp475-XXXXXX.local` |

> 配對碼遺失時,可從 Web UI(章節 7)首頁查詢裝置 MAC,或從原廠快速入門卡查 QR Code。

<div style="background:#fff8f0; border-left:4px solid #ff6f48; padding:10px 16px; border-radius:6px;">
<b>提示</b>:同網路有兩台不同機型時,Apple Home / Google Home 顯示的裝置名前綴會自動帶 <code>WP475-</code> 或 <code>WP375-</code>,一眼就能分辨。
</div>

---

<h2 id="3-led-狀態指示" style="color:#1c3d5a;">3 · LED 狀態指示</h2>

### 3.1 4 種運作狀態

依優先級從高到低:

| 優先級 | 狀態 | LED 行為 | 含義 |
|---|---|---|---|
| **1** | 重置警告 | 🔴 紅色 5 Hz 快閃(亮 0.1s 暗 0.1s) | 按鍵已按 5 秒,再 5 秒就執行工廠重置 |
| **2** | 等待 Wi-Fi | 🔵 藍色閃 1 下 + 停 1.8s | 尚未設定 Wi-Fi / Wi-Fi 連不上 |
| **3** | 未配對 / 配對中 | 🟠 橘色雙閃 + 停 1.4s | Wi-Fi 已連,Matter commissioning 進行中或還沒加入任何生態 |
| **4** | 正常運作 | ⚫ 熄滅 | 一切就緒 |

### 3.2 快速判斷對照表

| 看到 LED | 通常代表 | 該做什麼 |
|---|---|---|
| 🔵 藍色閃 1 下 | 沒設定過 Wi-Fi / 重置後 | 用手機 App 配對流程加入 |
| 🟠 橘色雙閃 | Matter 配對流程進行中 | 等 30 秒;超過 1 分鐘還在雙閃 → App 重新加入 |
| ⚫ 熄滅 | 已上線運作中 | 無需處理 |
| 🔴 紅色快閃 | 你正在長按重置鍵 | 想取消重置就放開;想重置就按到 10 秒 |

---

<h2 id="4-按鍵操作" style="color:#1c3d5a;">4 · 按鍵操作</h2>

### 4.1 工廠重置

側邊細孔重置鍵,需用迴紋針 / 細針戳。**僅負責工廠重置**,日常使用無其他功能。

| 動作 | 結果 |
|---|---|
| 持續按住 0–5 秒 | 無反應(放開不做事) |
| 持續按住達 5 秒 | LED 開始 **🔴 紅色快閃**(警告中,放開可取消) |
| 持續按住達 10 秒 | **工廠重置觸發**,LED 熄滅,裝置自動重啟 |

> 重置範圍見 [章節 10.3](#103-重置會清除什麼)。

---

<h2 id="5-接入智能生態初次配對" style="color:#1c3d5a;">5 · 接入智能生態(初次配對)</h2>

### 5.1 配對前確認

- [ ] 路由器 **Wi-Fi 2.4 GHz** 可用(WeatherPanel 不支援 5 GHz)
- [ ] 手機 **藍牙開啟**,跟裝置距離 < 1 公尺
- [ ] 手機**已加入** Matter 平台(Apple Home / Google Home / SmartThings / HA / Alexa)
- [ ] 至少有一台 Matter Controller 在線:
  - **Apple**:iPhone / iPad / HomePod / Apple TV(iOS 16.1+)
  - **Google**:Nest Hub / Android 14+ 手機
  - **Home Assistant**:主機 + iPhone / Android 14+ 手機
  - **Alexa**:Echo Hub / Echo (4th gen) / Echo Show

### 5.2 Apple Home

1. 通電,等狀態 LED 開始 **🔵 藍色閃 1 下 + 停**
2. iPhone 開「家庭」App → 右上角 **+** → **加入配件**
3. 對準 QR Code 掃描;或選「沒有代碼/無法掃描」→ 輸入 `3642-630-6820`
4. iPhone 自動傳 Wi-Fi 憑證 → LED 變 **🟠 橘色雙閃**
5. 配對完成 → LED **熄滅**,出現裝置「**WP475-XXXXXX**」或「**WP375-XXXXXX**」+ 一顆「立即重抓天氣」按鈕(可在 Apple Home 自動化中當 trigger)

### 5.3 Home Assistant

1. 通電,等 LED 藍色閃 1 下
2. 開 Home Assistant App → 設定 → 裝置與服務 → Matter → **加入 Matter 裝置**
3. 掃 QR 或輸入 `3642-630-6820`
4. App 自動完成 commissioning
5. 在「裝置」清單會看到 **WP475-XXXXXX / WP375-XXXXXX**,內含一顆「立即重抓天氣」switch(觸發後可串自動化)

### 5.4 Google Home

1. 通電,等 LED 藍色閃 1 下
2. 開「Google Home」App → 右上 **+** → **設定裝置** → **新裝置** → 選擇家庭
3. App 自動偵測「Matter 裝置」→ 點擊 → 掃 QR 或輸入 `3642-630-6820`
4. 依 App 指示完成 Wi-Fi 設定
5. 配對完成,可在「開關」分類找到

### 5.5 Amazon Alexa

1. 通電,等 LED 藍色閃 1 下
2. 開 Alexa App → 裝置 → **+** → **新增裝置** → **其他** → **Matter**
3. 掃 QR 或輸入 `3642-630-6820`
4. 完成

---

<h2 id="6-跨生態接入matter-multi-admin" style="color:#1c3d5a;">6 · 跨生態接入(Matter Multi-Admin)</h2>

### 6.1 機制說明

Matter 規範允許**同一台裝置同時加入多個生態**,最多 **5 個 Fabric**。例如同時被 Apple Home 與 Home Assistant 控制,在任一生態觸發「立即重抓天氣」,e-paper 都會立刻重畫。

<div style="background:#fff8f0; border-left:4px solid #ff6f48; padding:10px 16px; border-radius:6px;">
<b>關鍵原則</b>:第二個生態起,<b>不能用出廠那組 <code>3642-630-6820</code></b> — 必須由<b>第一個已配對的生態</b>產生一組「分享配對碼」(每次新的、有時效)。
</div>

### 6.2 從 Apple Home 分享給其他生態

1. 家庭 App → 長按裝置 → **設定**(齒輪圖示)
2. 滑到底,找 **「開啟配對模式」**
3. App 顯示一組 11 碼**拷貝代碼**(15 分鐘內有效)
4. 在第二個生態 App「加入配件」流程輸入這組新碼

### 6.3 從 Home Assistant 分享給其他生態

1. Home Assistant App → 設定 → Matter → 指定轉出裝置 → **分享裝置**
2. **複製代碼**
3. 在第二個生態 App「加入配件」流程輸入這組新碼

### 6.4 常見誤區

| 誤操作 | 後果 | 正確做法 |
|---|---|---|
| 第二個生態用出廠 `3642-630-6820` | 配對失敗 | 用第一個生態生出來的「分享碼」 |
| 用 Apple 重置裝置後再加入 Google | Apple 那邊也會掉 | 不要重置,用「Multi-Admin 分享」流程 |
| 已加入 5 個生態還想加 | 失敗 | 移除其中一個再加 |
| Wi-Fi 不通就嘗試多 admin | 失敗 | 先確認原配對生態正常,Wi-Fi 通才能分享 |

---

<h2 id="7-web-ui-進階設定" style="color:#1c3d5a;">7 · Web UI 進階設定</h2>

### 7.1 連線方式

配對成功後,WeatherPanel 在區網提供 Web UI。打開瀏覽器,網址兩種擇一:

- **直接 IP**:在生態 App 內查看裝置 IP(例 `http://192.168.1.123`)
- **主機名稱**:`http://automate-wp475-XXXXXX.local`(XXXXXX 為機身 MAC 後 6 碼)

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

| 區塊 | 內容 |
|---|---|
| **韌體資訊** | 目前版本、最新版本、檢查狀態 |
| **開始更新按鈕** | 點擊後自動下載 + 安裝 + 重啟(約 1–2 分鐘) |
| **裝置資料清除** | 紅色危險操作,等同硬體長按 10 秒重置 |
| **系統日誌** | 即時 log + RAM / CPU 溫度 |

---

<h2 id="8-cwa-氣象抓取與顯示" style="color:#1c3d5a;">8 · CWA 氣象抓取與顯示</h2>

### 8.1 註冊 CWA API Key

WeatherPanel 抓取的是**中央氣象署官方資料**,需要免費 API Key:

1. 開 [中央氣象署開放資料平台](https://opendata.cwa.gov.tw/index)
2. 註冊個人帳號(免費,可以即時取得)
3. 登入後 → 會員專區 → 取得授權碼 → **複製整串 `CWA-XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX`**
4. 貼進 Web UI 首頁「CWA 氣象署抓取設定」card 的 API Key 欄位
5. 按底部橘色「儲存參數 + 更新與刷新」 — 約 5-15 秒後 e-paper 重畫

<div style="background:#fff8f0; border-left:4px solid #ff6f48; padding:10px 16px; border-radius:6px;">
API Key 每分鐘限速,WeatherPanel 內建排程不會打爆;但若你手動連點「儲存」按鈕亂試,可能 5 分鐘內被暫時擋。
</div>

### 8.2 選擇縣市鄉鎮

| 步驟 | 動作 |
|---|---|
| 1 | 在「CWA 氣象署抓取設定」card 內選**縣市**下拉(22 縣市)|
| 2 | **鄉鎮區**下拉會自動更新成該縣市的所有鄉鎮 |
| 3 | 選擇你的所在地 |
| 4 | 按橘色「儲存參數 + 更新與刷新」 |

> 預設值:臺中市 南屯區。重置後恢復此預設值。

### 8.3 預報模式

「預報內容與顯示調整」card 的**預報模式**下拉有 8 種版型:

**7 日 daily(每天 1 列):**
- 每日最高/最低溫
- 每日體感最高/最低
- 平均溫 + 濕度
- 平均溫 + 降雨機率
- 平均溫 + UV 指數

**3 日 3 小時 hourly(每 3 小時 1 列):**
- 每時 溫度 + 濕度
- 每時 溫度 + 降雨
- 每時 體感 + 降雨

選完按橘色「儲存參數 + 更新與刷新」即時生效。

<div style="background:#f8f9fb; border-left:4px solid #1c3d5a; padding:10px 16px; border-radius:6px;">
<b>關於「降雨機率」欄位顯示「-」:</b>中央氣象署一週預報的降雨機率<b>只保證前 3 天有具體百分比</b>,第 4 天以後氣象署本身就不公布數字(顯示「-」)。WeatherPanel 忠實照氣象署資料呈現,不是裝置故障。
</div>

### 8.4 自動更新排程

「自動更新排程」card:
- **自動化開關**(總開關,關掉所有自動更新都停)
- **固定時刻**(對齊 CWA 預報發布時間):`00:15` / `06:15` / `09:15` / `12:15` / `15:15` / `18:15` / `21:15`(各自可勾選)
- **自訂時刻 × 3 組**:可以設定例如「08:30 我出門前看天氣」、「17:00 我回家前看天氣」

設定完按橘色「儲存參數 + 更新與刷新」。下次排程器 20 秒檢查週期會套用新設定。

### 8.5 顯示方向(橫式 / 直式)

WeatherPanel 出廠預設**橫式 800×480**。可在「預報內容與顯示調整」card 切到**直式 480×800**(直立壁掛 / 桌立)。

兩種方向會用不同版型(內容相同,排版重新計算)。

### 8.6 手動立即更新

兩種方法:
1. **Web UI** — 按底部橘色「儲存參數 + 更新與刷新」(會順便存 NVS)
2. **生態 App** — 在 Apple Home / HA / Google Home 等找到 **WP475-XXX / WP375-XXX** 的「立即重抓天氣」按鈕點一下(只觸發重抓,不存設定)

兩個方法都是觸發同一條 CWA 重抓路徑,等 5–15 秒 e-paper 自動重畫。

---

<h2 id="9-ota-韌體更新" style="color:#1c3d5a;">9 · OTA 韌體更新</h2>

### 9.1 更新流程

1. 連線 Web UI → 底部 **版更** Tab
2. 系統自動向官方 GitHub 檢查最新版本
3. 若有新版,顯示「有新版本可更新」+ 「開始更新」按鈕
4. 點擊「開始更新」→ 確認對話框 → 自動下載
5. 下載完成自動重啟,Web UI 自動 reload 回首頁

整個過程約 1–2 分鐘,期間裝置會暫時離線,e-paper 維持上一張畫面不變。

### 9.2 更新會保留 / 清除什麼

| 項目 | 是否保留 |
|---|---|
| Matter 配對(所有生態)| ✅ 保留 |
| Wi-Fi 帳密 | ✅ 保留 |
| CWA API Key / 縣市 / 鄉鎮 | ✅ 保留 |
| 預報模式 / 顯示方向 | ✅ 保留 |
| 自動更新排程設定 | ✅ 保留 |
| 機型變體設定(WP-475 / WP-375)| ✅ 保留 |
| 韌體版本 | ❌ 換新版 |

---

<h2 id="10-工廠重置" style="color:#1c3d5a;">10 · 工廠重置</h2>

### 10.1 硬體重置

- 用迴紋針 / 細針戳機身背面重置小圓孔
- 按住 5 秒 → LED 紅色快閃(警告階段)
- 繼續按住到 **10 秒** → **工廠重置觸發**,LED 熄滅,裝置自動重啟
- 重啟後 LED 變藍色閃 1 下,等待重新配對

> 5–10 秒之間放手 = 取消(LED 回原狀態,不重置)。

### 10.2 Web UI 重置

- 版更頁 → 「裝置資料清除」card → 「清除 NVS(出廠重置)」
- 確認對話框 → 自動重啟

### 10.3 重置會清除什麼

| 項目 | 是否清除 |
|---|---|
| Matter 配對(所有生態)| ✅ 清除 |
| Wi-Fi 帳密 | ✅ 清除 |
| CWA API Key / 縣市 / 鄉鎮 | ✅ 重置為預設(臺中市 南屯區、出廠 API Key)|
| 預報模式 / 顯示方向 | ✅ 重置為預設(daily 每日高低溫 / 橫式)|
| 自動更新排程設定 | ✅ 重置為預設(7 個固定時刻全開、3 個自訂時刻全關)|
| 機型變體設定(WP-475 / WP-375)| ❌ 保留(原廠出貨時已寫入,不會被重置清掉) |
| 韌體版本 | ❌ 不變 |
| 裝置認證資料 / DAC | ❌ 不變(內建出廠憑證,不會掉)|

> 重置後跟全新開封一樣,需重新配對。

---

<h2 id="11-故障排除" style="color:#1c3d5a;">11 · 故障排除</h2>

### 11.1 配對相關

| 現象 | 原因 | 處理 |
|---|---|---|
| LED 一直藍色閃,App 找不到裝置 | 配對流程沒走完 / 手機藍牙關閉 / 距離太遠 | 確認手機藍牙開、距離 < 1 m、Wi-Fi 是 2.4 GHz |
| 橘色雙閃很久最後又回藍色 | 裝置中途重啟(供電不足) | 換較粗 USB 線 / 機殼後方 USB 3.0 直連、不走 hub |
| App 顯示「無法加入」 | 配對碼錯誤 / Fabric 已滿 | 重新輸入碼;若已用 5 個生態,先移除其一 |
| 第二個生態加不進 | 用了出廠那組碼 | 改用第一個生態的「分享碼」(章節 6) |

### 11.2 顯示相關

| 現象 | 原因 | 處理 |
|---|---|---|
| 畫面停在「設定 QR」沒切到天氣 | 還沒抓到 CWA 資料 | 確認 API Key 已設(章節 8.1),等 30 秒 |
| 畫面有殘影 / 線條 | 電子紙特性,長期不刷會輕微殘影 | 不影響使用;按一下「儲存參數 + 更新與刷新」整刷一次即清 |
| 更新時畫面變花 16-17 秒 | 電子紙整刷過程的正常現象 | 等完即可,不要拔電源 |
| 時間顯示不對 | 沒同步到 NTP / 時區設定異常 | 確認網路可達 pool.ntp.org / time.google.com |

### 11.3 CWA 抓取相關

| 現象 | 原因 | 處理 |
|---|---|---|
| 預報資料整片「—」 | API Key 沒設 / 過期 / 拼錯 | Web UI 重貼 API Key,按儲存 |
| 預報資料只更新一部分 | 7 日跟 3 日資料源不同,可能其中一條暫時失敗 | 等下一個排程時刻自動重試 |
| 鄉鎮下拉沒選項 | 縣市還沒選 / 載入失敗 | 重新整理 Web UI 頁面 |
| 抓取一直卡 5 秒以上 | CWA 伺服器暫時忙 | 等 1 分鐘自動 timeout 重試 |
| 4 天以後的降雨機率顯示「-」| 氣象署一週預報只給前 3 天具體降雨機率 | 正常現象,4 天以後氣象署不公布 |

### 11.4 OTA 相關

| 現象 | 原因 | 處理 |
|---|---|---|
| 版更頁顯示「無法取得版本」/「unknown」 | 裝置連不到 GitHub | 檢查網路,可能是 DNS / 防火牆問題 |
| 「開始更新」後一直 0% | 下載卡住 | 等 5 分鐘;不行就重啟裝置再試 |
| 更新失敗 | 韌體損毀 / 供電不足 | 重啟裝置(會回到舊版),確認供電後重試 |

---

<h2 id="12-安全使用" style="color:#1c3d5a;">12 · 安全使用</h2>

<table>
<tr>
<td width="50%" valign="top">

- ⚡ **供電必須穩定** — 電子紙整刷瞬間耗電大,USB 線太細 / hub 供電不足會 brownout 重啟
- 🔌 拆殼 / 改裝會違反電信法規(內含 BLE / Wi-Fi 無線電路)
- 🌡 工作環境溫度 0–50 °C,**勿放置於暖氣 / 廚房灶台旁**(電子紙 > 60 °C 會永久損壞)

</td>
<td width="50%" valign="top">

- 🌧 戶外使用請另購防水殼
- ☀ **電子紙怕長時間直曬太陽** — 紫外線會讓彩色顏料褪色,壽命縮短
- 🧊 結霜 / 低於 0 °C 也別開機(電子紙在冰點以下更新會壞)

</td>
</tr>
</table>

---

<h2 id="13-規格表" style="color:#1c3d5a;">13 · 規格表</h2>

| 項目 | 規格 |
|---|---|
| 產品名稱 | WP-475(4 色版)/ WP-375(3 色版) |
| 品牌 | AUTOMATE |
| 顯示器 | 7.5" e-paper 480 × 800 |
| 顯示色 | WP-475:黑 / 白 / 紅 / 黃 · WP-375:黑 / 白 / 紅 |
| 顯示更新時間 | ~16-17 秒(整張重畫)|
| 通訊協定 | Matter 1.x over Wi-Fi |
| Wi-Fi | 2.4 GHz 802.11 b/g/n |
| 藍牙 | BLE 5.0(僅配對) |
| 處理器 | ESP32-S3(雙核 RISC-V, 160 MHz) |
| Flash | 8 MB |
| PSRAM | 2 MB |
| 供電 | DC 5V / USB-C(建議 ≥ 1 A) |
| 待機功耗 | < 0.5 W(更新瞬間 ~1.5 W) |
| 工作溫度 | 0 °C – 50 °C |
| 工作濕度 | 10% – 90% RH(無凝結) |
| 資料源 | 中央氣象署 OpenData(F-D0047 系列) |
| 預報範圍 | 7 日 daily + 3 日 hourly(3 小時間隔) |
| 內建天文 | 日出日落、月相、24 節氣 |
| Matter VID | `0xFFF1` |
| Matter PID | `0x8011`(WP-475 / WP-375 共用) |

---

<div align="center" style="color:#5a6878; font-size:0.9em; margin-top:30px;">
<b style="color:#1c3d5a;">AUTOMATE</b> · WP-475 / WP-375 智能氣象面板 · 韌體 v1.0.4<br/>
<sub>本文件 2026-06-05 版</sub>
</div>
