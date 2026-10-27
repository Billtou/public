<!-- AirCube HomeKit README — Argon-style(同 air_cube/matter 版面;2026-10-27 套版)-->

<div align="center" style="padding:48px 24px 36px">

<!-- AUTOMATE Logo (inline SVG,height 64px) -->
<svg width="320" height="55" viewBox="0 0 1412.26 241.88" xmlns="http://www.w3.org/2000/svg" aria-label="AUTOMATE">
  <g fill="none" stroke-miterlimit="10">
    <g stroke="#ff6f48" stroke-width="8">
      <circle cx="21.02" cy="86.69" r="17.02"/>
      <polyline points="77.94 240.38 77.94 155.97 31.96 100.72"/>
      <circle cx="72.84" cy="21.02" r="17.02"/>
      <polyline points="101.21 240.38 101.21 145.93 72.92 117.64 72.92 38.03"/>
      <circle cx="124.98" cy="73.74" r="17.02"/>
      <line x1="124.98" y1="240.38" x2="124.98" y2="90.75"/>
      <circle cx="178.3" cy="94.21" r="17.02"/>
      <polyline points="147.26 240.38 147.26 191.36 178.56 160.07 178.56 111.23"/>
    </g>
    <g><line stroke="#33506d" stroke-width="3" x1="207.25" y1="240.38" x2="1411.2" y2="240.38"/></g>
  </g>
  <g fill="#33506d" stroke-width="0">
    <path d="M426.04,209.58c-20.58,0-36.67-6.59-48.27-19.77-11.6-13.18-17.4-32.08-17.4-56.69V39.98h33.77v92.18c0,15.72,2.83,27.12,8.49,34.18,5.66,7.07,13.53,10.6,23.62,10.6s18.16-3.53,23.83-10.6c5.66-7.06,8.49-18.46,8.49-34.18V39.98h32.94v93.14c0,24.62-5.8,43.51-17.4,56.69-11.6,13.18-27.62,19.77-48.06,19.77Z"/>
    <path d="M552.37,206.72V71.42h-41.04v-31.44h111.76v31.44h-41.04v135.3h-29.68Z"/>
    <path d="M718.05,209.58c-11.9,0-22.87-2.14-32.9-6.43-10.04-4.29-18.78-10.32-26.23-18.1-7.45-7.78-13.22-16.91-17.31-27.39-4.09-10.48-6.13-21.91-6.13-34.3s2.04-24.02,6.13-34.42c4.08-10.4,9.85-19.49,17.31-27.27,7.45-7.78,16.16-13.82,26.13-18.1,9.96-4.29,20.89-6.43,32.79-6.43s22.82,2.11,32.79,6.31c9.96,4.21,18.67,10.21,26.12,17.98,7.45,7.78,13.22,16.91,17.31,27.39,4.08,10.48,6.13,22,6.13,34.54s-2.04,23.86-6.13,34.42c-4.09,10.56-9.86,19.73-17.31,27.51-7.45,7.78-16.16,13.78-26.12,17.98-9.97,4.21-20.82,6.31-32.58,6.31ZM717.83,176.95c6.74,0,12.93-1.31,18.6-3.93,5.66-2.62,10.64-6.35,14.94-11.2,4.3-4.84,7.63-10.48,10-16.91,2.36-6.43,3.55-13.61,3.55-21.56s-1.18-15.13-3.55-21.56c-2.37-6.43-5.7-12.07-10-16.91-4.3-4.84-9.28-8.57-14.94-11.19-5.66-2.62-11.86-3.93-18.6-3.93s-12.98,1.31-18.71,3.93c-5.73,2.62-10.72,6.35-14.94,11.19-4.23,4.85-7.53,10.48-9.89,16.91-2.37,6.43-3.55,13.62-3.55,21.56s1.18,15.12,3.55,21.56c2.36,6.43,5.66,12.07,9.89,16.91,4.23,4.84,9.21,8.57,14.94,11.2,5.73,2.62,11.97,3.93,18.71,3.93Z"/>
    <path d="M813,206.72l20.27-166.74h40.42l32.87,125.81h0l32.73-125.81h40.49l20.34,166.74h-31.96l-8.86-136.97h0l-37.53,138.33h-31.44l-35.59-138.33h0l-11.07,136.97h-30.67Z"/>
    <path d="M1215.57,206.72V71.42h-41.04v-31.44h111.76v31.44h-41.04v135.3h-29.68Z"/>
    <path d="M1312.96,206.72V39.98h96.92v30.97h-67.42v104.81h69.8v30.97h-99.3ZM1340.26,132.23v-30.25h61.74v30.25h-61.74Z"/>
    <path d="M1017.77,207.4l51.06-166.74h41.71l51.06,166.74h-31.15l-47.09-147.21h11.91l-47.09,147.21h-30.41ZM1046.54,171.67l7.51-29.3,64.54-10.65,7.63,27.36-79.68,12.59Z"/>
    <path d="M206.19,206.72l51.06-166.74h41.71l51.06,166.74h-31.15l-47.09-147.21h11.91l-47.09,147.21h-30.41ZM234.95,170.99l7.51-29.3,64.54-10.65,7.63,27.36-79.68,12.59Z"/>
  </g>
</svg>

<h1 style="font-size:42px;font-weight:800;margin:24px 0 6px 0;letter-spacing:-0.025em;color:#1c3d5a">AirCube</h1>
<p style="font-size:17px;color:#5a6a7a;margin:0;font-weight:500">智能空氣品質感測器 · Apple HomeKit over Wi-Fi · CO2 異常推播 · 三款型號 · 1.3" OLED 顯示</p>

<!-- QR + 配對碼 並排 -->
<table align="center" style="margin:28px auto 0;border-collapse:collapse;border:none">
<tr>
<td align="center" style="border:none;padding:0 20px;vertical-align:middle">
  <img src="https://raw.githubusercontent.com/Billtou/public/main/QR_CODE/qr-11188999-AUTM.png" width="160" height="160" alt="HomeKit 配對 QR Code" style="border:1px solid #dde3ec;border-radius:12px;background:#fff;padding:8px">
  <p style="margin:8px 0 0;font-size:11px;color:#8a96a3">HomeKit 配對 QR</p>
</td>
<td align="left" style="border:none;padding:0 20px;vertical-align:middle">
  <p style="margin:0 0 8px;color:#5a6a7a;font-size:13px;font-weight:600;letter-spacing:0.04em;text-transform:uppercase">8 碼配對碼</p>
  <p style="margin:0;font-size:28px;font-weight:800;color:#ff6f48;font-family:'SF Mono',Consolas,monospace;letter-spacing:0.04em">111-88-999</p>
  <p style="margin:14px 0 0;font-size:12px;color:#8a96a3;line-height:1.5">可直接掃描左側 QR 配對,<br>或手動輸入 8 碼</p>
</td>
</tr>
</table>

</div>

<!-- 影片區:YouTube thumbnail 點擊播放 -->
<p align="center" style="margin:32px 0 12px">
<a href="https://youtu.be/fF8eUW6vTzo" title="重置進入連網模式(點擊在 YouTube 開啟)">
  <img src="https://img.youtube.com/vi/fF8eUW6vTzo/mqdefault.jpg" width="220" alt="重置進入連網模式" style="border-radius:12px;margin:6px">
</a>
<a href="https://youtu.be/b8adlsMMleI" title="Web UI 操作(點擊在 YouTube 開啟)">
  <img src="https://img.youtube.com/vi/b8adlsMMleI/mqdefault.jpg" width="220" alt="Web UI 操作" style="border-radius:12px;margin:6px">
</a>
</p>
<p align="center" style="margin:-12px 0 32px;font-size:12px;color:#5a6a7a">
  ⬆️ 重置進入連網模式 · Web UI 操作 ⬆️
</p>

> 📌 **這是 HomeKit(HAP)版本**。裝置以 Apple 原生 HomeKit 協定直接接入 Apple Home,
> **無需 Matter、無需 Hub**,並支援 CO2「偵測到二氧化碳」異常推播與自動化。
> 若要接入 Home Assistant,本版透過 **MQTT** 橋接(章節 7),不走 Matter。
> (另有 Matter 版本,見 `air_cube/matter`。)

---

<details>
<summary><b>📑 目錄</b></summary>

1. [產品簡介](#1-產品簡介)
   - 1.1 [三款型號](#11-三款型號)
   - 1.2 [規格速覽](#12-規格速覽)
   - 1.3 [包裝內容](#13-包裝內容)

2. [硬體說明](#2-硬體說明)
   - 2.1 [外觀與接口](#21-外觀與接口)
   - 2.2 [配對碼資訊](#22-配對碼資訊)
   - 2.3 [內建感測器列表](#23-內建感測器列表)

3. [LED 狀態指示](#3-led-狀態指示)
   - 3.1 [兩種 LED 配置](#31-兩種-led-配置)
   - 3.2 [標準版 — 4 LED 行為](#32-標準版--4-led-行為)
   - 3.3 [AirMac — 單顆 LED 行為](#33-airmac--單顆-led-行為)
   - 3.4 [快速判斷對照表](#34-快速判斷對照表)

4. [按鍵操作](#4-按鍵操作)

5. [OLED 顯示螢幕(可選配)](#5-oled-顯示螢幕可選配)
   - 5.1 [4 頁輪播內容](#51-4-頁輪播內容)
   - 5.2 [AQI 色彩等級對照](#52-aqi-色彩等級對照)

6. [接入 Apple Home(初次配對)](#6-接入-apple-home初次配對)
   - 6.1 [配對前確認](#61-配對前確認)
   - 6.2 [Apple Home 配對步驟](#62-apple-home-配對步驟)
   - 6.3 [配對後看到的配件](#63-配對後看到的配件)

7. [接入 Home Assistant(MQTT)](#7-接入-home-assistantmqtt)
   - 7.1 [機制說明](#71-機制說明)
   - 7.2 [設定步驟](#72-設定步驟)
   - 7.3 [HA 會探索到的實體](#73-ha-會探索到的實體)

8. [CO2 異常推播與自動化](#8-co2-異常推播與自動化)

9. [Web UI:首頁(日常設定)](#9-web-ui首頁日常設定)
   - 9.1 [連線方式](#91-連線方式)
   - 9.2 [即時狀態與門檻設定](#92-即時狀態與門檻設定)
   - 9.3 [溫濕度偏移校正](#93-溫濕度偏移校正)
   - 9.4 [CO2 與 TVOC 歸零校正](#94-co2-與-tvoc-歸零校正)
   - 9.5 [指示燈睡眠模式](#95-指示燈睡眠模式)

10. [甲醛在 Apple Home 的顯示(Ultra)](#10-甲醛在-apple-home-的顯示ultra)

11. [OTA 韌體更新](#11-ota-韌體更新)
    - 11.1 [更新流程](#111-更新流程)
    - 11.2 [更新會保留 / 清除什麼](#112-更新會保留--清除什麼)

12. [工廠重置](#12-工廠重置)
    - 12.1 [硬體重置](#121-硬體重置)
    - 12.2 [Web UI 重置](#122-web-ui-重置)
    - 12.3 [重置會清除什麼](#123-重置會清除什麼)

13. [故障排除](#13-故障排除)

14. [安全使用](#14-安全使用)

15. [規格表](#15-規格表)

</details>

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">1. 產品簡介</h2>

AirCube(HomeKit 版)是 AUTOMATE 推出的智能室內空氣品質感測器,**以 Apple 原生 HomeKit 協定直接接入 Apple Home**,不需專屬 Hub、不需 Matter。除了完整空品數據,還能在 **CO2 濃度異常時主動推播通知並觸發自動化**;要接入 Home Assistant 則透過內建 MQTT 橋接。

### 1.1 三款型號

| 型號 | 名稱 | 額外感測 | HomeKit 額外服務 | 適合場景 |
|---|---|---|---|---|
| **AirCube Ultra** | 全配甲醛版 | 甲醛 ZE08-CH2O | 甲醛(以「二氧化氮」欄位顯示,見章節 10) | 新裝潢 / 新家具 / 化學氣味監控 |
| **AirCube Pro** | 人在偵測版 | 24 GHz 雷達 LD2410 | OccupancySensor(佔用感測) | 房間佔用 / 自動化燈控 / 冷氣節能 |
| **AirCube Plus** | 觸控版 | TTP223 觸控感測 | StatelessProgrammableSwitch(單擊/雙擊/長按) | 場景按鈕 / 一鍵情境切換 |

> 三款都有共用感測器:HDC1080 溫濕度、CM1106 CO2、SGP30 TVOC、PM2105/PM2005 PM2.5。
> CO2 在所有型號都是**獨立的「二氧化碳偵測器」**,可做濃度異常推播與自動化(章節 8)。

### 1.2 規格速覽

| 項目 | 內容 |
|---|---|
| 通訊協定 | Apple HomeKit(HAP)over Wi-Fi |
| 智能生態 | Apple Home(原生)/ Home Assistant(MQTT 橋接) |
| Wi-Fi | 2.4 GHz 802.11 b/g/n(不支援 5 GHz)|
| BLE | 不使用(HomeKit 走 Wi-Fi 配對)|
| 處理器 | ESP32(雙核 Xtensa LX6, 240 MHz, 4 MB Flash)|
| 供電 | DC 5V / 必須使用原廠豆腐頭 |
| 工作環境 | 0–50 °C / 10–90% RH(無凝結) |
| 顯示螢幕(可選)| 1.3" SH1106 OLED 128×64 mono |

### 1.3 包裝內容

- AirCube 主機 × 1(視型號內含對應感測模組)
- USB 電源線 × 1
- 快速入門貼紙(含 HomeKit QR Code 與 8 碼配對碼)× 1

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">2. 硬體說明</h2>

### 2.1 外觀與接口

- **狀態 LED 群**:依 LED 變體不同(章節 3),反映系統 + 空品狀態
- **重置鈕**:背後有小孔長按 10 秒進入工廠重置(章節 12)
- **USB**:供電(資料線無作用,單純取電)

### 2.2 配對碼資訊

| 項目 | 數值 |
|---|---|
| HomeKit QR Code | 機身底部標籤 |
| 8 碼手動配對碼 | `111-88-999` |
| 預設主機名稱 | `automate-aircube-{ultra/pro/plus}-XXXXXX` |
| 顯示名稱 | `AirCube-Ultra-XXXXXX` / `AirCube-Pro-XXXXXX` / `AirCube-Plus-XXXXXX` |

XXXXXX 為機身 Wi-Fi MAC 後 6 碼。

> AirCube HomeKit 版採 AUTOMATE 品牌統一 HomeKit 配對碼 `111-88-999`,與其他 HomeKit 產品一致。配對碼遺失時可在機身底部標籤或 Web UI(章節 9)首頁查看。

### 2.3 內建感測器列表

| 感測項 | 元件 | 範圍 | 介面 | 變體 |
|---|---|---|---|---|
| 溫度 | HDC1080 | -40 ~ 125 °C | I2C | 全部 |
| 濕度 | HDC1080 | 0 ~ 100 %RH | I2C | 全部 |
| CO2 | CM1106 NDIR | 400 ~ 5000 ppm | UART | 全部 |
| TVOC | SGP30 MOX | 0 ~ 60000 ppb(顯示為 µg/m³) | I2C | 全部 |
| PM2.5 | PM2105 / PM2005 | 0 ~ 999 µg/m³ | I2C | 全部 |
| **CH2O 甲醛** | ZE08-CH2O 電化學 | 0 ~ 6553 ppb | UART | **僅 Ultra** |
| **人在偵測** | HLK-LD2410 24 GHz 雷達 | 0.75 ~ 6 m | UART | **僅 Pro** |
| **觸控** | TTP223 電容感測 | 單擊 / 雙擊 / 長按 | GPIO | **僅 Plus** |

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">3. LED 狀態指示</h2>

### 3.1 兩種 LED 配置

AirCube 主板支援兩種 LED 配置:

| 配置 | LED 數量 | 適用 |
|---|---|---|
| **標準版**(預設)| 4 顆 LED | 標準 PCB,有四顆獨立指示燈 |
| **AirMac** | 1 顆 LED| AirMac 精簡 PCB,所有提示集中一顆 |

### 3.2 標準版 — 4 LED 行為

| LED | 觸發條件 |
|---|---|
| **CO2-LED**| CO2 > 設定門檻時亮起 |
| **TVOC-LED**| TVOC **或** CH2O 任一超標時亮起(共用) |
| **PM2.5-LED**| PM2.5 > 設定門檻時亮起 |
| **Status-LED**| 系統狀態(WiFi / HomeKit 配對 / 工廠重置警告) |

> 開啟「指示燈睡眠模式」時,三顆超標 LED 強制熄滅(系統狀態 LED 不受影響)。

### 3.3 AirMac — 單顆 LED 行為

優先級從高到低,只執行最高優先項:

| 優先級 | 狀態 | LED 行為 |
|---|---|---|
| 1 | 工廠重置警告 | 5 Hz 快閃(亮 0.1s 暗 0.1s) |
| 2 | 等待 Wi-Fi | 1 Hz 慢閃(亮 0.5s 暗 0.5s) |
| 3 | 配對中 | 雙閃(快兩下停一下) |
| 4 | 任一空品超標 | 慢閃 ~2 秒週期 |
| 5 | **正常運作 + 全 OK** | **恆亮**(綠燈意涵:裝置活著 + 空品正常) |

> 「指示燈睡眠模式」開啟時,**優先 4 + 5 都熄滅**;系統狀態類(優先 1-3)仍正常運作以利夜間故障排查。

### 3.4 快速判斷對照表

| 看到 LED | 通常代表 | 該做什麼 |
|---|---|---|
| 慢閃 | 沒設定過 / 重置後 | 用 iPhone「家庭」App 配對加入 |
| 雙閃 | 配對流程進行中 | 等 30 秒;超過 1 分鐘還在雙閃 → App 重新加入 |
| 恆亮(AirMac) | 已上線 + 空品正常 | 無需處理 |
| 慢閃 ~2 秒(AirMac) | 有空品項超標 | 看 OLED / Web UI 確認哪一項 |
| 全暗(標準版常態) | 已上線 + 空品正常 | 無需處理 |
| 5 Hz 快閃 | 你正在長按重置鈕 | 想取消重置就放開;想重置就按到 10 秒 |

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">4. 按鍵操作</h2>

| 操作 | 功能 |
|---|---|
| **短按**(< 5 秒) | 無功能(防誤觸) |
| **長按 5–10 秒**(警告期) | LED 5 Hz 快閃,放手取消 |
| **長按 ≥ 10 秒** | **工廠重置觸發**(清 HomeKit 配對),用戶設定保留 |

> CO2 / TVOC 校正、門檻設定等動作,**只能透過 Web UI** 操作,避免實體鈕誤觸。詳見章節 9。

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">5. OLED 顯示螢幕(可選配)</h2>

外接 1.3" SH1106 OLED 128×64(I2C 介面接 PM2.5 cable 上的 Y-splitter)後,自動偵測並啟用 4 頁輪播,每頁 5 秒。**沒接 OLED 的單機也能正常運作,韌體會跳過螢幕邏輯**。

### 5.1 4 頁輪播內容

```
頁 1 — 溫濕度          頁 2 — CO2 + PM2.5/AQI    頁 3 — TVOC + 變體區     頁 4 — 系統狀態
┌──────────────┐      ┌──────────────────┐      ┌──────────────┐         ┌──────────────┐
│ Temperature  │      │ Co2  AQI:GREEN   │      │ TVOC         │         │   AirMac     │
│              │      │                  │      │              │         │   ──────     │
│  27.5°C      │      │   542 ppm        │      │  85 ug       │         │ 10.0.1.152   │
│              │      │                  │      │              │         │              │
│ Humidity     │      │ PM2.5     12 ug  │      │ CH2O / 人在  │         │  15:30:01    │
│ 56.2 %       │      │   GREEN          │      │ 16 ppb 等    │         │  2026/5/8    │
└──────────────┘      └──────────────────┘      └──────────────┘         └──────────────┘
```

頁 3 的下半區自動依**產品變體**切換內容:

| 變體 | 頁 3 下半 |
|---|---|
| Ultra | `CH2O / 16 ppb` |
| Pro | `Occupancy / OCCUPIED` 或 `EMPTY` |
| Plus | `Touch / Single 12s`(最近觸發類型 + 經過時間)|

> 開啟「指示燈睡眠模式」時,OLED 整片熄滅(display off,GDDRAM 保留),關閉模式自動點亮。

### 5.2 AQI 色彩等級對照

頁 2 下半的 AQI 文字採用 **EPA 標準色名**(black-and-white OLED 沒色彩,但色名語意足夠):

| PM2.5 (µg/m³) | OLED 顯示 | 真實顏色 | 對應行動 |
|---|---|---|---|
| 0 ~ 12 | **GREEN** | 🟢 綠 | 空品優良 |
| 12 ~ 35 | **YELLOW** | 🟡 黃 | 普通,敏感族群留意 |
| 35 ~ 55 | **ORANGE** | 🟠 橘 | 不健康(敏感族群) |
| 55 ~ 150 | **RED** | 🔴 紅 | 不健康,建議關窗 |
| 150 ~ 250 | **PURPLE** | 🟣 紫 | 非常不健康 |
| 250+ | **MAROON** | 🟫 暗紅 | 危險,室外勿活動 |

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">6. 接入 Apple Home(初次配對)</h2>

### 6.1 配對前確認

- [ ] 路由器 **Wi-Fi 2.4 GHz** 可用(AirCube 不支援 5 GHz)
- [ ] iPhone / iPad 已登入 iCloud 並啟用「家庭」
- [ ] 建議家中有一台 **家庭中樞**(HomePod / Apple TV),自動化與遠端存取才會生效

### 6.2 Apple Home 配對步驟

1. 通電 AirCube,等 LED 進入慢閃(等待 Wi-Fi)
2. iPhone 開「家庭」App → 右上角 **+** → **加入配件**
3. 對準機身 QR Code 掃描;或選「更多選項…」→ 手動輸入 `111-88-999`
4. 出現「**尚未通過認證的配件**」提示 → 點「**仍要加入**」(自製配件的正常提示,功能不受影響)
5. 選擇房間、命名 → 完成
6. LED 轉恆亮 / 全暗即代表上線

### 6.3 配對後看到的配件

配對完成後,Apple「家庭」會出現以下配件(依型號):

| 配件 | 全型號 | 說明 |
|---|---|---|
| 空氣品質感測器 | ✅ | PM2.5、TVOC(Ultra 另含甲醛,以「二氧化氮」呈現) |
| **二氧化碳偵測器** | ✅ | CO2 濃度 + 「偵測到二氧化碳」異常狀態(可推播/自動化,章節 8) |
| 溫度感測器 | ✅ | |
| 濕度感測器 | ✅ | |
| 佔用感測器 | 僅 Pro | 有人 / 無人 |
| 可程式化按鈕 | 僅 Plus | 單擊 / 雙擊 / 長按事件 |

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">7. 接入 Home Assistant(MQTT)</h2>

### 7.1 機制說明

HomeKit 版**不走 Matter**,接入 Home Assistant 是透過裝置內建的 **MQTT 用戶端 + Home Assistant Discovery**。連上你的 MQTT Broker 後,HA 會自動探索出各個感測器實體。**HA 端沒有 Apple 那些限制,所有數值(含 CO2、甲醛)都能直接拿來做任何自動化**。

> 需要一台 MQTT Broker(例如 HA 的 Mosquitto add-on)。

### 7.2 設定步驟

1. 配對並上線後,進 AirCube 的 **Web UI 工程頁**(章節 9 的連線方式)
2. 找到「**MQTT / Home Assistant**」卡片
3. 填入 Broker IP、Port(預設 1883)、Username、Password
4. 按「**連線測試**」→ 成功後按「**儲存並啟用**」
5. 到 Home Assistant → 設定 → 裝置與服務 → **MQTT**,即可看到自動探索的 AirCube 裝置與實體

### 7.3 HA 會探索到的實體

| 實體 | 全型號 | 額外 |
|---|---|---|
| 空氣品質 / CO2 / PM2.5 / TVOC / 溫度 / 濕度 | ✅ | |
| 甲醛(真實甲醛值,非借殼) | 僅 Ultra | HA 支援甲醛,直接顯示 |
| 佔用(binary_sensor) | 僅 Pro | |

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">8. CO2 異常推播與自動化</h2>

HomeKit 版把 CO2 做成獨立的「**二氧化碳偵測器**」,除了顯示濃度(ppm),還有一個「**偵測到二氧化碳**」狀態:當 CO2 **超過設定門檻**(Web UI 首頁「CO2 超標門檻」,預設 1000 ppm)即觸發。

- **主動推播**:Apple「家庭」對這類安全感測器會**主動推「二氧化碳濃度異常」通知**到 iPhone。
- **自動化觸發**:可在「家庭」App 建立自動化,例如:
  - 「偵測到二氧化碳 → 開啟新風機 / 循環扇」
  - 「偵測到二氧化碳 → 推播提醒開窗通風」

> 觸發門檻跟著 Web UI 的「CO2 超標門檻」走(400–3000 ppm 可調),改一次兩邊(通知 + LED)同步。
> 若透過 MQTT 接 Home Assistant,也可直接用 CO2 濃度數值做更細的門檻自動化。

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">9. Web UI:首頁(日常設定)</h2>

### 9.1 連線方式

配對成功後,AirCube 在區網提供 Web UI。打開瀏覽器,網址兩種擇一:

- **直接 IP**:在 Apple「家庭」配件設定或路由器查裝置 IP(例 `http://192.168.1.123`)
- **主機名稱**(依變體):
  - Ultra:`http://automate-aircube-ultra-XXXXXX.local`
  - Pro:`http://automate-aircube-pro-XXXXXX.local`
  - Plus:`http://automate-aircube-plus-XXXXXX.local`

> 手機與 AirCube 必須在**同一個 Wi-Fi 網段**。

### 9.2 即時狀態與門檻設定

| 區塊 | 內容 |
|---|---|
| **裝置資訊** | 韌體版本、WiFi 訊號、運行時間、連線狀態、製造日期 |
| **即時狀態** | 溫度、濕度、CO2、TVOC、PM2.5(+ 變體相關項) |
| **門檻設定** | 4 個滑桿(CO2 / PM2.5 / TVOC / CH2O,僅 Ultra)|

**門檻說明**:超過設定值時對應 LED 亮起(睡眠模式關閉時不亮);其中 **CO2 超標門檻同時是「二氧化碳偵測器」的推播觸發點**(章節 8)。

| 門檻 | 預設值 | 範圍 |
|---|---|---|
| CO2 超標 | 1000 ppm | 400 – 3000 ppm |
| PM2.5 超標 | 50 µg/m³ | 0 – 200 µg/m³ |
| **TVOC 超標** | **2000 µg/m³** | **0 – 3000 µg/m³** |
| CH2O 超標(Ultra) | 500 ppb | 0 – 2000 ppb |

### 9.3 溫濕度偏移校正

如果你的 AirCube 跟其他溫度計差幾度,可調 ±20 °C / ±50 %RH 偏移。**偏移直接加在原始讀值上**,即時生效不需重啟。

### 9.4 CO2 與 TVOC 歸零校正

> **建議:每 6 個月做一次,或感覺數值偏移時**

#### 操作步驟

1. 把 AirCube 拿到**戶外窗邊**(或開窗讓清新空氣灌入室內)
2. **靜置 20 分鐘以上**,讓感測器穩定接觸戶外空氣
3. 進 Web UI 首頁 → **校正卡片** → 按「**CO2 & TVOC 歸零校正**」
4. 確認對話框 → 等 30~60 秒,CO2 應收斂到 ~400 ppm

#### 校正會做兩件事

| 動作 | 對應感測器 |
|---|---|
| 送 CM1106 強制 400 ppm 命令 | CM1106 CO2 sensor |
| 把當下 SGP30 讀值記為 TVOC 零點 | SGP30 TVOC sensor |

> 歸零後,Web UI「校正狀態」會顯示「N 秒前 · TVOC 零點 X µg/m³」。
> 若顯示「尚未校正」,通常是裝置時鐘還沒同步(剛開機)—— 等連網幾秒 SNTP 對時後再按一次即可。

### 9.5 指示燈睡眠模式

預設**關閉**。開啟後:
- **OLED 螢幕**完全熄滅
- **超標 LED**(標準版三顆 / AirMac 慢閃)強制 OFF
- **系統狀態 LED**(WiFi / 配對 / factory reset 警告)不受影響

> HomeKit 版的睡眠模式為 **Web UI 本地控制**(不佔用 HomeKit 配件)。

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">10. 甲醛在 Apple Home 的顯示(Ultra)</h2>

HomeKit 協定**沒有「甲醛」這個特徵值**,所以 Apple「家庭」無法直接顯示甲醛。AirCube Ultra 的做法是**借用「二氧化氮(NO2)」欄位**呈現甲醛濃度(µg/m³):

- 在 Apple「家庭」的空氣品質配件裡,你會看到一行「**二氧化氮**」,其數值**實際上就是甲醛濃度**。
- 此功能**預設開啟**,可在 Web UI 參數頁的開關關閉(重啟生效)。
- 換算:µg/m³ = 甲醛 ppb × 1.23。

> 若透過 MQTT 接 Home Assistant,HA 端顯示的是**真實的甲醛實體**(不借殼),因為 HA 支援甲醛。

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">11. OTA 韌體更新</h2>

### 11.1 更新流程

1. 連線 Web UI → 底部 **版更** Tab
2. 系統自動向官方檢查最新版本(HomeKit 頻道)
3. 若有新版,顯示「有新版本可更新」+「開始更新」按鈕
4. 點擊「開始更新」→ 確認對話框 → 自動下載
5. 下載完成自動重啟,Web UI 自動 reload 回首頁

整個過程約 1–2 分鐘,期間裝置會暫時離線。

> HomeKit 版只會抓 HomeKit 頻道的韌體(`air_cube/homekit/firmware-w`),不會誤抓到 Matter 版本。

### 11.2 更新會保留 / 清除什麼

| 項目 | 是否保留 |
|---|---|
| HomeKit 配對 | ✅ 保留 |
| Wi-Fi 帳密 | ✅ 保留 |
| 門檻設定 / 偏移校正 / TVOC 零點 | ✅ 保留 |
| MQTT 設定 | ✅ 保留 |
| 產品變體 / LED 變體 | ✅ 保留 |
| 韌體版本 | ❌ 換新版 |

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">12. 工廠重置</h2>

### 12.1 硬體重置

- 按住重置鈕 **10 秒以上**
- LED 從快閃變熄滅 → 鬆開 → 自動重啟
- 重啟後 LED 慢閃,等待重新配對

### 12.2 Web UI 重置

- 版更頁 → 「裝置資料清除」card → 「**清除 NVS(出廠重置)**」
- 確認對話框 → 自動重啟

### 12.3 重置會清除什麼

| 項目 | 是否清除 |
|---|---|
| HomeKit 配對 | ✅ 清除 |
| Wi-Fi 帳密 | ✅ 清除 |
| MQTT 設定 | ✅ 清除 |
| 門檻設定 / 偏移校正 / TVOC 零點 | ❌ **保留**(在 fctry partition,重置只清 nvs) |
| 產品變體 / LED 變體 | ❌ 保留 |
| 製造日期(mfg-info) | ❌ 保留 |
| 韌體版本 | ❌ 不變 |

> AirCube 把用戶設定放在 fctry partition,**長按重置不會清掉**。如需恢復成「全新出廠」(連門檻偏移都歸預設),需另從 Web UI 觸發「重置設定」。

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">13. 故障排除</h2>

### 配對相關

| 現象 | 原因 | 處理 |
|---|---|---|
| LED 一直慢閃,App 找不到裝置 | 沒進配對 / Wi-Fi 非 2.4 GHz | 確認路由器 2.4 GHz 可用、手機在同網段 |
| 雙閃很久最後又回慢閃 | 裝置中途重啟(供電不足) | 換較粗 USB 線 / 直連牆插不走 hub |
| Apple 顯示「未認證配件」 | 預期行為(自製 HomeKit 配件) | 點「仍要加入」即可,功能不受影響 |
| 配對輸入碼失敗 | 配對碼錯 | 重新輸入 `111-88-999` |

### 感測器相關

| 現象 | 原因 | 處理 |
|---|---|---|
| CO2 永遠 ~414 ppm 不變 | 感測器卡住 / 校正基準偏低 | 戶外靜置 20 分鐘 → Web UI「CO2 & TVOC 歸零校正」 |
| CO2 校正後顯示「尚未校正」 | 裝置時鐘未同步(剛開機) | 等連網幾秒 SNTP 對時,再按一次校正 |
| PM2.5 偶爾跳 "—" | I2C 讀取 timeout(沒插好 / 電供不穩) | 檢查 PM2.5 模組 cable 是否鬆動 |
| TVOC 一直 0 µg/m³ | SGP30 暖機需 15 秒~數分鐘 | 通電靜置 30 分鐘以上;斷電重開要重新暖機 |
| CH2O 數值偏高(Ultra) | ZE08 預熱 ~3 分鐘 | 通電後等 5 分鐘讀數才穩定 |
| 甲醛在「家庭」找不到(Ultra) | HomeKit 沒有甲醛特徵值 | 看空氣品質配件的「二氧化氮」欄位(章節 10) |

### Web UI / MQTT / OTA 相關

| 現象 | 原因 | 處理 |
|---|---|---|
| Web UI 載入慢 / 常進不去 | Wi-Fi 訊號差 / 省電睡眠 | 靠近路由器;工程頁「WiFi 微調」設強制不睡眠 |
| 工程頁沒有 MQTT 卡片 | 韌體版本較舊 | OTA 更新到最新 HomeKit 版 |
| HA 探索不到裝置 | MQTT Broker 設定錯 / 未連上 | 檢查 Broker IP/帳密,狀態膠囊要顯示「已連線」 |
| 版更頁「無法取得版本」 | 連不到 GitHub | 檢查網路 / DNS / 防火牆 |

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">14. 安全使用</h2>

- 請勿拆殼 / 改裝 — 內含無線電路,改裝會違反電信法規
- 請勿用水或溶劑清潔 PM2.5 進氣口,可能損壞雷射粒子感測器
- 工作環境溫度 0–50 °C,**勿放置於暖氣 / 廚房灶台 / 浴室高溼處**
- 戶外或高灰塵環境請另購防護殼
- CO2 / TVOC 歸零校正務必在戶外清新空氣,**勿在剛抽完菸 / 剛烹飪 / 剛刷油漆的室內進行** — 會把高污染當作「零點」
- 雷達 24 GHz 訊號功率極低(僅 Pro 變體),**長時間使用對人體無害**(符合 FCC / NCC / CE 標準)

---

<h2 style="color:#1c3d5a;border-bottom:3px solid #ff6f48;padding-bottom:8px;margin-top:48px;font-size:28px">15. 規格表</h2>

| 項目 | 規格 |
|---|---|
| 產品名稱 | AirCube Ultra / Pro / Plus(HomeKit 版) |
| 品牌 | AUTOMATE |
| 通訊協定 | Apple HomeKit(HAP)over Wi-Fi |
| 智能生態 | Apple Home(原生)/ Home Assistant(MQTT) |
| Wi-Fi | 2.4 GHz 802.11 b/g/n |
| 處理器 | ESP32(雙核 Xtensa LX6, 240 MHz) |
| Flash | 4 MB |
| 溫度感測 | HDC1080(±0.2 °C) |
| 濕度感測 | HDC1080(±2 %RH) |
| CO2 感測 | CM1106 NDIR(±50 ppm + 5%) |
| TVOC 感測 | SGP30 MOX(顯示為 µg/m³) |
| PM2.5 感測 | PM2105 / PM2005(自動辨識,±10 µg/m³) |
| 甲醛(Ultra) | ZE08-CH2O 電化學(±5%) |
| 人在感應(Pro) | HLK-LD2410 24GHz 雷達(0.75–6 m) |
| 觸控(Plus) | TTP223 電容(單擊/雙擊/長按) |
| 顯示螢幕 | 1.3" SH1106 OLED 128×64 mono(可選配) |
| LED 數量 | 4 顆(標準版)/ 1 顆(AirMac) |
| 供電 | DC 5V / USB(建議 ≥ 1 A) |
| 待機功耗 | < 1 W |
| 工作溫度 | 0 °C – 50 °C |
| 工作濕度 | 10% – 90% RH(無凝結) |

---

> AUTOMATE · AirCube · HomeKit 版
