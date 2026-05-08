# AirCube · AUTOMATE 智能空氣品質感測器
> Matter over Wi-Fi · 跨生態相容 · 三款型號可選 · 1.3" OLED 顯示
>
> 重點影片介紹> [重置進入連網模式](https://youtu.be/fF8eUW6vTzo)
>
> 跨平臺接入智能生態> [接入 Home Assistant 後轉入 Apple Homekit](https://youtu.be/oOZLfkmxRx8)
>
> 跨平臺接入智能生態> [接入 Apple Homekit 後轉入 Home Assistant ](https://youtu.be/dLEspzmaiJI)
>
> Web UI 調整參數說明> [Web UI](https://youtu.be/b8adlsMMleI)
---

## 📑 目錄

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

6. [接入智能生態(初次配對)](#6-接入智能生態初次配對)
   - 6.1 [配對前確認](#61-配對前確認)
   - 6.2 [Apple Home(iOS)](#62-apple-home)
   - 6.3 [Home Assistant](#63-home-assistant)
   - 6.4 [Google Home](#64-google-home)
   - 6.5 [Amazon Alexa](#65-amazon-alexa)

7. [跨生態接入(Matter Multi-Admin)](#7-跨生態接入matter-multi-admin)
   - 7.1 [機制說明](#71-機制說明)
   - 7.2 [從 Apple Home 分享給其他生態](#72-從-apple-home-分享給其他生態)
   - 7.3 [從 Home Assistant 分享給其他生態](#73-從-home-assistant-分享給其他生態)
   - 7.4 [常見誤區](#74-常見誤區)

8. [Web UI:首頁(日常設定)](#8-web-ui首頁日常設定)
   - 8.1 [連線方式](#81-連線方式)
   - 8.2 [即時狀態與門檻設定](#82-即時狀態與門檻設定)
   - 8.3 [溫濕度偏移校正](#83-溫濕度偏移校正)
   - 8.4 [CO2 與 TVOC 歸零校正](#84-co2-與-tvoc-歸零校正)
   - 8.5 [指示燈睡眠模式](#85-指示燈睡眠模式)

9. [Web UI:工程模式(硬體規格)](#9-web-ui工程模式硬體規格)
   - 9.1 [進入工程模式](#91-進入工程模式)
   - 9.2 [產品變體切換](#92-產品變體切換)
   - 9.3 [LED 提示變體切換](#93-led-提示變體切換)

10. [睡眠模式自動化(進階)](#10-睡眠模式自動化進階)

11. [TVOC 在 Apple Home 的限制與 Bridge 解法](#11-tvoc-在-apple-home-的限制與-bridge-解法)

12. [OTA 韌體更新](#12-ota-韌體更新)
    - 12.1 [更新流程](#121-更新流程)
    - 12.2 [更新會保留 / 清除什麼](#122-更新會保留--清除什麼)

13. [工廠重置](#13-工廠重置)
    - 13.1 [硬體重置](#131-硬體重置)
    - 13.2 [Web UI 重置](#132-web-ui-重置)
    - 13.3 [重置會清除什麼](#133-重置會清除什麼)

14. [故障排除](#14-故障排除)
    - 14.1 [配對相關](#141-配對相關)
    - 14.2 [感測器相關](#142-感測器相關)
    - 14.3 [OLED 螢幕相關](#143-oled-螢幕相關)
    - 14.4 [OTA 相關](#144-ota-相關)

15. [安全使用](#15-安全使用)

16. [規格表](#16-規格表)

---

## 1. 產品簡介

AirCube 是 AUTOMATE 推出的智能室內空氣品質感測器,**直接接入 Apple Home / Google Home / Home Assistant / SmartThings / Alexa**,不需專屬 Hub。

### 1.1 三款型號

三款共用同一塊主板,差別在 UART2 上接的模組與多出的 Matter 端點:

| 型號 | 名稱 | 額外感測 | Matter 額外端點 | 適合場景 |
|---|---|---|---|---|
| **AirCube Ultra** | 全配甲醛版 | 甲醛 ZE08-CH2O | EP1 加 Formaldehyde cluster | 新裝潢 / 新家具 / 化學氣味監控 |
| **AirCube Pro** | 人在偵測版 | 24 GHz 雷達 LD2410 | EP4 OccupancySensor | 房間佔用 / 自動化燈控 / 冷氣節能 |
| **AirCube Plus** | 觸控版 | TTP223 觸控感測 | EP4-EP6 OnOff(單擊/雙擊/長按)| 場景按鈕 / 一鍵情境切換 |

> 三款都有共用感測器:HDC1080 溫濕度、CM1106 CO2、SGP30 TVOC、PM2105/PM2005 PM2.5(自動辨識)。
> 變體可在 Web UI **工程模式**現場切換(章節 9.2)。

### 1.2 規格速覽

| 項目 | 內容 |
|---|---|
| 通訊協定 | Matter 1.x over Wi-Fi |
| Wi-Fi | 2.4 GHz 802.11 b/g/n(不支援 5 GHz)|
| BLE | 5.0(僅配對用)|
| 處理器 | ESP32(雙核 Xtensa LX6, 240 MHz, 4 MB Flash)|
| 供電 | DC 5V / USB-C,建議 ≥ 1 A |
| 工作環境 | 0–50 °C / 10–90% RH(無凝結) |
| 顯示螢幕(可選)| 1.3" SH1106 OLED 128×64 mono |

### 1.3 包裝內容

- AirCube 主機 × 1(視型號內含對應感測模組)
- USB-C 電源線 × 1
- 快速入門卡(含 Matter QR Code 與 11 碼配對碼)× 1

---

## 2. 硬體說明

### 2.1 外觀與接口

- **狀態 LED 群**:依 LED 變體不同(章節 3),反映系統 + 空品狀態
- **重置鈕**:長按 10 秒進入工廠重置(章節 13)
- **USB-C**:供電(資料線無作用,單純取電)
- **PM2.5 進氣口**:正面下方百葉,**請勿封閉**
- **OLED 接口**:I2C(可選配,接 SH1106 模組)

### 2.2 配對碼資訊

| 項目 | 數值 |
|---|---|
| Matter QR Code | 機身底部標籤 |
| 11 碼手動配對碼 | `3497-0112-332` |
| 預設裝置名稱 | `automate-aircube-{ultra/pro/plus}-XXXXXX` |
| 顯示名稱 | `AirCube-Ultra-XXXXXX` / `AirCube-Pro-XXXXXX` / `AirCube-Plus-XXXXXX` |

XXXXXX 為機身 Wi-Fi MAC 後 6 碼。

> AirCube 用 CHIP 標準測試碼,**跟 Motion / LT 系列那組 `3642-630-6820` 不同**。配對碼遺失時可在 Web UI(章節 8)首頁查看。

### 2.3 內建感測器列表

| 感測項 | 元件 | 範圍 | 介面 | 變體 |
|---|---|---|---|---|
| 溫度 | HDC1080 | -40 ~ 125 °C | I2C | 全部 |
| 濕度 | HDC1080 | 0 ~ 100 %RH | I2C | 全部 |
| CO2 | CM1106 NDIR | 400 ~ 5000 ppm | UART | 全部 |
| TVOC | SGP30 MOX | 0 ~ 60000 ppb(顯示為 µg/m³) | I2C | 全部 |
| PM2.5 | PM2105 / PM2005(自動辨識) | 0 ~ 999 µg/m³ | I2C | 全部 |
| **CH2O 甲醛** | ZE08-CH2O 電化學 | 0 ~ 6553 ppb | UART | **僅 Ultra** |
| **人在偵測** | HLK-LD2410 24 GHz 雷達 | 0.75 ~ 6 m | UART | **僅 Pro** |
| **觸控** | TTP223 電容感測 | 單擊 / 雙擊 / 長按 | GPIO | **僅 Plus** |

---

## 3. LED 狀態指示

### 3.1 兩種 LED 配置

AirCube 主板支援兩種 LED 配置,在 Web UI 工程模式切換(章節 9.3):

| 配置 | LED 數量 | 適用 |
|---|---|---|
| **標準版**(預設)| 4 顆 LED | 標準 PCB,有四顆獨立指示燈 |
| **AirMac** | 1 顆 LED(GPIO 32)| AirMac 精簡 PCB,所有提示集中一顆 |

### 3.2 標準版 — 4 LED 行為

| LED | 觸發條件 |
|---|---|
| **CO2-LED**(GPIO 4)| CO2 > 設定門檻時亮起 |
| **TVOC-LED**(GPIO 32)| TVOC **或** CH2O 任一超標時亮起(共用) |
| **PM2.5-LED**(GPIO 33)| PM2.5 > 設定門檻時亮起 |
| **Status-LED**(GPIO 25)| 系統狀態(WiFi / Matter 配對 / 工廠重置警告) |

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
| 慢閃 | 沒設定過 / 重置後 | 用手機 App 配對流程加入 |
| 雙閃 | 配對流程進行中 | 等 30 秒;超過 1 分鐘還在雙閃 → App 重新加入 |
| 恆亮(AirMac) | 已上線 + 空品正常 | 無需處理 |
| 慢閃 ~2 秒(AirMac) | 有空品項超標 | 看 OLED / Web UI 確認哪一項 |
| 全暗(標準版常態) | 已上線 + 空品正常 | 無需處理 |
| 5 Hz 快閃 | 你正在長按重置鈕 | 想取消重置就放開;想重置就按到 10 秒 |

---

## 4. 按鍵操作

| 操作 | 功能 |
|---|---|
| **短按**(< 5 秒) | 無功能(防誤觸) |
| **長按 5–10 秒**(警告期) | LED 5 Hz 快閃,放手取消 |
| **長按 ≥ 10 秒** | **工廠重置觸發**(清 Matter 配對),用戶設定保留 |

> CO2 / TVOC 校正、產品變體切換等敏感動作,**只能透過 Web UI** 操作,避免實體鈕誤觸。詳見章節 8 與 9。

---

## 5. OLED 顯示螢幕(可選配)

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

> 開啟「指示燈睡眠模式」時,OLED 整片熄滅(0xAE display off,GDDRAM 保留),關閉模式自動點亮。

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

## 6. 接入智能生態(初次配對)

### 6.1 配對前確認

- [ ] 路由器 **Wi-Fi 2.4 GHz** 可用(AirCube 不支援 5 GHz)
- [ ] 手機 **藍牙開啟**,跟 AirCube 距離 < 1 公尺
- [ ] 手機**已加入** Matter 平台(Apple Home / Google Home / Home Assistant / Alexa)
- [ ] 至少有一台 Matter Controller 在線:
  - **Apple**:iPhone / iPad / HomePod / Apple TV(iOS 16.1+)
  - **Google**:Nest Hub / Android 14+ 手機
  - **Home Assistant**: 主機 / iPhone / Android 14+ 手機
  - **Alexa**:Echo Hub / Echo (4th gen) / Echo Show

### 6.2 Apple Home

1. 通電 AirCube,等 LED 進入慢閃(等待 Wi-Fi)
2. iPhone 開「家庭」App → 右上角 **+** → **加入配件**
3. 對準 QR Code 掃描;或選「沒有代碼/無法掃描」→ 輸入 `3497-0112-332`
4. iPhone 自動傳 Wi-Fi 憑證 → LED 變雙閃(配對中)
5. 配對完成 → 會出現「**空氣品質感測器**」配件
   - 點開可看到 CO2、PM2.5、AQI 等級
   - 溫度 / 濕度為獨立配件
   - 詳見[章節 11](#11-tvoc-在-apple-home-的限制與-bridge-解法) 關於 TVOC / CH2O 在 Apple Home 的顯示限制

### 6.3 Home Assistant

1. 通電 AirCube,等 LED 慢閃
2. 開 Home Assistant App → 設定 → 整合 → Matter → 新增裝置 → **全新的裝置**
3. 掃 QR 或輸入 `3497-0112-332`
4. App 自動完成
5. HA 會建立 7 個 entity(Ultra 變體):溫度、濕度、CO2、PM2.5、TVOC、CH2O、Sleep Mode 開關

### 6.4 Google Home

1. 通電 AirCube,等 LED 慢閃
2. 開「Google Home」App → 右上 **+** → **設定裝置** → **新裝置** → 選擇家庭
3. App 自動偵測 Matter 裝置 → 點擊 → 掃 QR 或輸入 `3497-0112-332`
4. 依 App 指示完成 Wi-Fi 設定
5. 配對完成,可在「感測器」分類找到

### 6.5 Amazon Alexa

1. 通電 AirCube,等 LED 慢閃
2. 開 Alexa App → 裝置 → **+** → **新增裝置** → **其他** → **Matter**
3. 掃 QR 或輸入 `3497-0112-332`
4. 完成

---

## 7. 跨生態接入(Matter Multi-Admin)

### 7.1 機制說明

Matter 規範允許**同一台 AirCube 同時加入多個生態**,最多 **5 個 Fabric**。例如同時被 Apple Home 與 Home Assistant 控制,空品數值會同步出現在兩個 App。

**關鍵原則**:第二個生態起,**不能用出廠那組 `3497-0112-332`** — 必須由**第一個已配對的生態**產生一組「分享配對碼」(每次新的、有時效)。

### 7.2 從 Apple Home 分享給其他生態

1. 家庭 App → 長按裝置 → **設定**(齒輪圖示)
2. 滑到底,找 **「開啟配對模式」**
3. App 顯示一組 11 碼**拷貝代碼**(15 分鐘內有效)
4. 在第二個生態 App「加入配件」流程輸入這組新碼

### 7.3 從 Home Assistant 分享給其他生態

1. Home Assistant App → 設定 → Matter → 指定 AirCube → **複製代碼 / 分享裝置**
2. 複製代碼
3. 在第二個生態 App「加入配件」流程輸入這組新碼

### 7.4 常見誤區

| 誤操作 | 後果 | 正確做法 |
|---|---|---|
| 第二個生態用出廠 `3497-0112-332` | 配對失敗 | 用第一個生態生出來的「分享碼」 |
| 用 Apple 重置裝置後再加入 Google | Apple 那邊也會掉 | 不要重置,用「Multi-Admin 分享」流程 |
| 已加入 5 個生態還想加 | 失敗 | 移除其中一個再加 |
| Wi-Fi 不通就嘗試多 admin | 失敗 | 先確認原配對生態正常,Wi-Fi 通才能分享 |

---

## 8. Web UI:首頁(日常設定)

### 8.1 連線方式

配對成功後,AirCube 在區網提供 Web UI。打開瀏覽器,網址兩種擇一:

- **直接 IP**:在生態 App 內查看裝置 IP(例 `http://192.168.1.123`)
- **主機名稱**(依變體):
  - Ultra:`http://automate-aircube-ultra-XXXXXX.local`
  - Pro:`http://automate-aircube-pro-XXXXXX.local`
  - Plus:`http://automate-aircube-plus-XXXXXX.local`

> 手機與 AirCube 必須在**同一個 Wi-Fi 網段**。

### 8.2 即時狀態與門檻設定

| 區塊 | 內容 |
|---|---|
| **裝置資訊** | 韌體版本、可用記憶體、運行時間、連線狀態、製造日期 |
| **即時狀態** | 溫度、濕度、CO2、TVOC、PM2.5(+ 變體相關項) |
| **門檻設定** | 4 個滑桿(CO2 / PM2.5 / TVOC / CH2O,僅 Ultra)|

**門檻說明**:超過設定值時對應 LED 亮起(睡眠模式關閉時不亮)。

| 門檻 | 預設值 | 範圍 |
|---|---|---|
| CO2 超標 | 1000 ppm | 400 – 3000 ppm |
| PM2.5 超標 | 50 µg/m³ | 0 – 200 µg/m³ |
| **TVOC 超標** | **2000 µg/m³** | **0 – 3000 µg/m³** |
| CH2O 超標(Ultra) | 500 ppb | 0 – 2000 ppb |

### 8.3 溫濕度偏移校正

如果你的 AirCube 跟其他溫度計差幾度,可調 ±20 °C / ±50 %RH 偏移。**偏移直接加在原始讀值上**,即時生效不需重啟。

### 8.4 CO2 與 TVOC 歸零校正

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

歸零後,Web UI 「校正狀態」會顯示「N 秒前 · TVOC 零點 X µg/m³」。

### 8.5 指示燈睡眠模式

預設**關閉**。開啟後:
- **OLED 螢幕**完全熄滅
- **超標 LED**(標準版三顆 / AirMac 慢閃)強制 OFF
- **系統狀態 LED**(WiFi / 配對 / factory reset 警告)不受影響

睡眠模式可透過:
- Web UI 首頁 → 校正卡片 → 「指示燈睡眠模式」toggle
- **Matter 開關**(同時暴露給智能生態,詳見章節 10)

---

## 9. Web UI:工程模式(硬體規格)

> ⚠️ 此區為硬體變更類進階設定,部分變更後**會自動清除 Matter 配對並重啟**,需重新加入智能生態。一般使用者不需碰。

### 9.1 進入工程模式

底部 nav bar → **工程模式** → 輸入帳號密碼解鎖(此分頁開啟期間有效)。

### 9.2 產品變體切換

如果你有同一塊 PCB 想轉換用途(例如把 Ultra 換成 Pro 拿去做別的房間),可在工程模式切變體 — **不用重燒韌體,單一 firmware 支援三變體**。

| 變體 | UART2(GPIO 5/18)接的 |
|---|---|
| Ultra | ZE08-CH2O 甲醛模組 |
| Pro | LD2410 24GHz 雷達模組 |
| Plus | (UART2 不用,GPIO 5 接 TTP223 觸控) |

> ⚠️ **切換變體會清除 Matter 配對**(端點結構改變,舊 commissioner 看到的 EP 圖會錯位),要重新加入所有智能生態。同時必須**確認硬體實際接的模組對得上選擇的變體**,否則該變體的 sensor 會 init 失敗。

### 9.3 LED 提示變體切換

兩種 LED 配置軟體切換,適配不同 PCB:

| 變體 | LED 配置 |
|---|---|
| **標準版** | GPIO 4 / 32 / 33 各自一顆超標燈;GPIO 25 系統狀態 |
| **AirMac** | GPIO 32 一顆 LED 全包(系統狀態 + 任一超標慢閃 + 正常恆亮) |

> 切 LED 變體**不會清 Matter 配對**(只重啟以重配 GPIO),配件仍在生態裡。

---

## 10. 睡眠模式自動化(進階)

AirCube 把「指示燈睡眠模式」**暴露為 Matter OnOff 開關**(EP-last),所有生態都能控制這顆開關 → 進階自動化:

| 場景 | 自動化規則範例 |
|---|---|
| 日落自動進睡眠 | Apple Home / HA「日落 30 分鐘後,開啟 AirCube Sleep Mode」 |
| 主臥室人在感應後解除 | Pro 變體:「OccupancySensor=有人 → 關閉 Sleep Mode」 |
| 早晨日出醒來自動恢復 | 「日出觸發 → Sleep Mode OFF → OLED 重新點亮」 |
| 場景一鍵切換 | 在「晚安」場景中加入「AirCube Sleep Mode = ON」 |

> 在 Apple Home / HA 中,這顆 switch 顯示為「**AirCube Plug**」或「**AirCube 開關**」(可重命名為「空品燈光」)。

---

## 11. TVOC 在 Apple Home 的限制與 Bridge 解法

**Apple Home 對 Matter AirQualitySensor 的支援不完整** — 只展示:

- ✅ Carbon Dioxide(CO2)
- ✅ PM2.5 Density
- ✅ Air Quality(整體等級 enum)
- ❌ **TVOC**(Apple 沒寫 Matter→HAP mapping)
- ❌ **Formaldehyde / 甲醛**(同上)

AirCube 韌體確實有送出 TVOC + CH2O 的 Matter cluster 資料(可在 HA 看到),只是 Apple Home UI 不展示。**這是 Apple 端限制,跟認證、感測器、韌體都無關**。

### 解法:HA HomeKit Bridge

如果你想在 Apple Home 看到 TVOC,標準做法是讓 HA 當中介:

1. AirCube → Matter → HA(看到所有 entity)
2. HA → HomeKit Bridge(內建 integration)→ Apple Home
3. Apple Home 看到的是 HA 偽裝的「HAP 原生配件」,**繞過 Matter mapping 限制**

設定步驟(HA 端):

```yaml
# configuration.yaml
homekit:
  - name: AirCube Bridge
    port: 21063
    filter:
      include_entities:
        - sensor.aircube_ultra_xxxxxx_carbon_dioxide
        - sensor.aircube_ultra_xxxxxx_pm25_density
        - sensor.aircube_ultra_xxxxxx_volatile_organic_compounds  # ← TVOC
        - sensor.aircube_ultra_xxxxxx_temperature
        - sensor.aircube_ultra_xxxxxx_humidity
```

把 `xxxxxx` 換成你 HA 實際的 entity ID 後綴,儲存後重啟 HA。HA log 會給 8 碼 HomeKit pairing code,iPhone 「家庭」App 加入該 pairing code 即可。

> AirCube 韌體 TVOC 已宣告為 **µg/m³**(SGP30 ppb 在源頭 × 4.57 換算),HA + HomeKit 兩邊都用同一個原生單位,bridge 不需做任何單位轉換。

---

## 12. OTA 韌體更新

### 12.1 更新流程

1. 連線 Web UI → 底部 **版更** Tab
2. 系統自動向官方檢查最新版本
3. 若有新版,顯示「有新版本可更新」+ 「開始更新」按鈕
4. 點擊「開始更新」→ 確認對話框 → 自動下載
5. 下載完成自動重啟,Web UI 自動 reload 回首頁

整個過程約 1–2 分鐘,期間裝置會暫時離線。

### 12.2 更新會保留 / 清除什麼

| 項目 | 是否保留 |
|---|---|
| Matter 配對(所有生態) | ✅ 保留 |
| Wi-Fi 帳密 | ✅ 保留 |
| 門檻設定 / 偏移校正 / TVOC 零點 | ✅ 保留 |
| 產品變體 / LED 變體 | ✅ 保留 |
| 睡眠模式狀態 | ✅ 保留 |
| 韌體版本 | ❌ 換新版 |

---

## 13. 工廠重置

### 13.1 硬體重置

- 按住重置鈕 **10 秒以上**
- LED 從快閃變熄滅 → 鬆開 → 自動重啟
- 重啟後 LED 慢閃,等待重新配對

### 13.2 Web UI 重置

- 版更頁 → 「裝置資料清除」card → 「**清除 NVS(出廠重置)**」
- 確認對話框 → 自動重啟

### 13.3 重置會清除什麼

| 項目 | 是否清除 |
|---|---|
| Matter 配對(所有生態) | ✅ 清除 |
| Wi-Fi 帳密 | ✅ 清除 |
| 門檻設定 / 偏移校正 / TVOC 零點 | ❌ **保留**(在 fctry partition,重置只清 nvs) |
| 產品變體 / LED 變體 | ❌ 保留 |
| 製造日期(mfg-info) | ❌ 保留 |
| OEM 品牌設定(白標) | ❌ 保留 |
| 韌體版本 | ❌ 不變 |
| 裝置認證資料 / DAC | ❌ 不變(內建出廠憑證,不會掉) |

> AirCube 把用戶設定放在 fctry partition,**長按重置不會清掉**。如果要恢復成「全新出廠」(連門檻偏移都歸預設),需用版更頁的「清除 NVS」並另外從 Web UI 觸發「重置設定」。

---

## 14. 故障排除

### 14.1 配對相關

| 現象 | 原因 | 處理 |
|---|---|---|
| LED 一直慢閃,App 找不到裝置 | 配對流程沒走完 / 手機藍牙關閉 / 距離太遠 | 確認手機藍牙開、距離 < 1 m、Wi-Fi 是 2.4 GHz |
| 雙閃很久最後又回慢閃 | 裝置中途重啟(供電不足) | 換較粗 USB 線 / 機殼後方 USB 3.0 直連、不走 hub |
| App 顯示「無法加入」 | 配對碼錯誤 / Fabric 已滿 | 重新輸入 `3497-0112-332`;若已用 5 個生態,先移除其一 |
| 第二個生態加不進 | 用了出廠那組碼 | 改用第一個生態的「分享碼」(章節 7) |
| Apple Home 顯示「未認證配件」警告 | 預期行為(AirCube 用 Matter 測試 VID/PID) | 點繼續即可,功能不受影響 |

### 14.2 感測器相關

| 現象 | 原因 | 處理 |
|---|---|---|
| CO2 永遠顯示 414 ppm 不變 | 感測器卡住 / 校正基準偏低 | 戶外靜置 20 分鐘 → Web UI 「CO2 & TVOC 歸零校正」 |
| PM2.5 偶爾跳 "—" | I2C 讀取 timeout(沒插好 / 電供不穩) | 檢查 PM2.5 模組 cable 是否鬆動;1.2.x 起韌體有 retry 機制可吃下偶發失敗 |
| TVOC 一直 0 µg/m³ | SGP30 暖機需 15 秒,且新出廠的需要連續通電一段時間養老 | 通電靜置 30 分鐘以上;每次斷電重開都要重新暖機 |
| CH2O 數值偏高(Ultra) | ZE08 預熱 ~3 分鐘,新空氣直接接觸時短暫偏高 | 通電後等 5 分鐘讀數才穩定 |
| 人在感應永遠顯示「有人」(Pro) | 雷達內背景未校正 | 進 HLK Radar Tool app 做動態背景校正 |
| 觸控按了沒反應(Plus) | 觸控感測過於靈敏 / 過於遲鈍 | 用 HLK app 調感度;或重新插拔 USB 重新校正基線 |

### 14.3 OLED 螢幕相關

| 現象 | 原因 | 處理 |
|---|---|---|
| OLED 沒文字一片黑 | 接線錯誤 / VCC 沒接到 / I2C 位址不對 | 檢查 SDA/SCL 是否互換;模組背面 ADD_SELECT 跳線確認 0x78(對應 `0x3C`) |
| OLED 開機亮 2 秒後就不動 | 自我測試完成但 carousel 沒接資料 | 看 monitor log 是否有 `OLED.Pages: rendered page X` |
| OLED 顯示時間是 `--:--:--` | SNTP 還沒同步成功 | 等 30 秒;確認 WiFi 通網際網路 |
| 切到 AirMac LED 變體後 OLED 變黑 | OLED 跟 AirMac LED 共用 GPIO 32 | OLED 跟 AirMac LED 變體互斥,擇一使用 |

### 14.4 OTA 相關

| 現象 | 原因 | 處理 |
|---|---|---|
| 版更頁顯示「無法取得版本」 | 裝置連不到 GitHub | 檢查網路,可能是 DNS / 網路 / 防火牆問題 |
| 「開始更新」後一直 0% | 下載卡住 | 等 5 分鐘;不行就重啟裝置再試 |
| 更新失敗 | 韌體損毀 / 供電不足 | 重啟裝置(會走舊版),確認供電後重試 |

---

## 15. 安全使用

- 請勿拆殼 / 改裝 — 內含無線電路,改裝會違反電信法規
- 請勿用水或溶劑清潔 PM2.5 進氣口,可能損壞雷射粒子感測器
- 工作環境溫度 0–50 °C,**勿放置於暖氣 / 廚房灶台 / 浴室高溼處**
- 戶外或高灰塵環境請另購防護殼
- CO2 / TVOC 歸零校正務必在戶外清新空氣,**勿在剛抽完菸 / 剛烹飪 / 剛刷油漆的室內進行** — 會把高污染當作「零點」
- 雷達 24 GHz 訊號功率極低(僅 Pro 變體),**長時間使用對人體無害**(符合 FCC / NCC / CE 標準)

---

## 16. 規格表

| 項目 | 規格 |
|---|---|
| 產品名稱 | AirCube Ultra / Pro / Plus |
| 品牌 | AUTOMATE |
| 通訊協定 | Matter 1.x over Wi-Fi |
| Wi-Fi | 2.4 GHz 802.11 b/g/n |
| 藍牙 | BLE 5.0(僅配對) |
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
| 供電 | DC 5V / USB-C(建議 ≥ 1 A) |
| 待機功耗 | < 1 W |
| 工作溫度 | 0 °C – 50 °C |
| 工作濕度 | 10% – 90% RH(無凝結) |

---

> AUTOMATE · AirCube · 韌體 v1.7.7(2026-05-08 上市)
