# MotionOne Plus — 毫米波人體存在感測器(matter協議版本)

**MotionOne Plus** 搭載 24GHz FMCW 毫米波雷達 (LD2412)，能精準偵測**靜止人體存在**（不只是移動），支援 **Matter** 標準協議，可無縫接入 Apple Home、Google Home、Home Assistant 等主流智慧家庭平台。

---

## 目錄

- [產品特色](#產品特色)
- [開箱與首次配對](#開箱與首次配對)
- [接入 Apple Home (HomeKit)](#接入-apple-home-homekit)
- [接入 Home Assistant](#接入-home-assistant)
- [接入 Google Home](#接入-google-home)
- [按鈕與指示燈說明](#按鈕與指示燈說明)
- [mmWave 感測器調教](#mmwave-感測器調教)
- [韌體更新 OTA](#韌體更新-ota)
- [常見問題](#常見問題)

---

## 產品特色

| 功能 | 說明 |
|---|---|
| 感測技術 | 24GHz 毫米波雷達，偵測靜止人體與微動作 |
| 協議 | Matter over Wi-Fi（2.4GHz，WPA2/WPA3） |
| 相容平台 | Apple Home、Google Home、Home Assistant、Amazon Alexa |
| 配網方式 | 藍牙 BLE — 免開 App 直接掃 QR Code 配對 |
| 更新方式 | 本地網頁 OTA（連上網路後自動啟動，Port 8080） |
| 電源 | USB-C 5V |

---

## 開箱與首次配對

### 所需準備

- MotionOne Plus 本體 × 1
- USB-C 電源線（5V 1A 以上）
- 2.4GHz Wi-Fi 路由器
- 支援 Matter 的手機 App（Apple Home / Google Home / HA Companion）

### 首次上電

1. 接上 USB-C 電源
2. 指示燈**慢閃（1 秒閃 1 次）**，表示裝置已進入配對模式
3. 選擇您的平台進行配對（見下方各平台說明）

> **配對碼（Manual Code）：`3642-630-6820`**
> 若掃描 QR Code 失敗，可手動輸入此配對碼

---

## 接入 Apple Home (HomeKit)

MotionOne Plus 透過 **Matter** 協議接入 Apple Home，**不需要額外的 Home Hub 橋接器**（HomePod mini 或 Apple TV 4K 可選配以獲得遠端控制）。

### 配對步驟

1. 開啟 **「家庭」App**
2. 點擊右上角 **「+」→「新增配件」**
3. 對準裝置上的 **Matter QR Code** 掃描，或選擇「更多選項」手動輸入配對碼
4. 依畫面指示命名裝置並加入房間
5. 配對完成後，Apple Home 會顯示「**mmWave**」感測器

### 自動化建議

| 觸發條件 | 建議動作 |
|---|---|
| 偵測到有人在場 | 開燈、開冷氣 |
| 離開後延遲 5 分鐘 | 關燈、關冷氣 |
| 深夜偵測到人 | 開走廊小夜燈（調低亮度） |

> **提示**：Apple Home 會將本感測器歸類為「佔用感測器（Occupancy Sensor）」，支援設定延遲與自動化條件。

---

## 接入 Home Assistant

### 前置條件

- Home Assistant 2023.2 以上
- 已安裝 **Matter（BETA）** 整合
- HA 主機需支援 Thread 或 Wi-Fi Matter（多數 HA Yellow / Green / 安裝有 Matter Server 的主機均可）

### 配對步驟

1. 確認 Matter Server Add-on 已安裝並啟動
   - 前往 **設定 → 附加元件 → Matter Server → 啟動**
2. 前往 **設定 → 裝置與服務 → 新增整合 → Matter**
3. 點擊「**新增 Matter 裝置**」
4. 選擇「使用 QR Code 或配對碼」，輸入 `3642-630-6820`
5. 等待配對完成（約 30–60 秒）
6. 裝置出現在 **整合 → Matter → 裝置**，狀態為 `binary_sensor.mmwave_occupancy`

### 推薦自動化範例（YAML）

```yaml
automation:
  - alias: "有人在場開燈"
    trigger:
      platform: state
      entity_id: binary_sensor.mmwave_occupancy
      to: "on"
    action:
      service: light.turn_on
      target:
        entity_id: light.living_room

  - alias: "離開 5 分鐘後關燈"
    trigger:
      platform: state
      entity_id: binary_sensor.mmwave_occupancy
      to: "off"
      for: "00:05:00"
    action:
      service: light.turn_off
      target:
        entity_id: light.living_room
```

---

## 接入 Google Home

1. 開啟 **Google Home App**
2. 點擊右上角 **「+」→「設定裝置」→「新裝置」**
3. 選擇您的家庭 → 搜尋新裝置
4. 掃描 QR Code 或輸入配對碼 `3642-630-6820`
5. 配對完成後感測器出現於 Google Home 裝置列表

---

## 按鈕與指示燈說明

### 指示燈（狀態 LED）

| 燈號狀態 | 代表意義 |
|---|---|
| 慢閃（1 Hz） | 等待配對中（未加入任何平台） |
| 恆滅 | 已配對，正常運作中 |
| 快閃（10 Hz） | 長按重置中，即將恢復出廠設定 |

> 配對完成後若開啟「LED 跟隨感測」模式，燈光會在偵測到人時亮起

### 重置按鈕操作

| 操作方式 | 效果 |
|---|---|
| 單擊 | 切換「LED 跟隨感測」開/關 |
| 雙擊（間隔 80–600ms） | 切換蜂鳴器聲音回饋開/關 |
| 長按 5–10 秒 | 進入重置預備狀態（LED 快閃） |
| 長按 10 秒以上 | **恢復出廠設定**（清除配對資料，裝置重啟） |

---

## mmWave 感測器調教

MotionOne Plus 使用 **Hi-Link LD2412** 24GHz 毫米波雷達模組，出廠參數已適合一般居家使用。若您需要針對特定空間進行優化，可透過手機 App 進行調整。

### 使用 Hi-Link App 調參

#### 下載 App

| 平台 | 連結 |
|---|---|
| iOS | App Store 搜尋「**Hi-Link**」|
| Android | Google Play 搜尋「**Hi-Link**」|

#### 連接方式

LD2412 模組透過 UART 輸出調參介面，需使用 **USB-UART 轉接器**（CH340 / CP2102 均可）連接電腦或手機 OTG。

**接線說明：**

| LD2412 接腳 | 轉接器接腳 |
|---|---|
| TX | RX |
| RX | TX |
| GND | GND |
| VCC | 3.3V 或 5V（依模組規格） |

#### App 主要調參項目

連上後在 Hi-Link App 中可調整以下參數：

**1. 偵測距離（Detection Range）**

- **最大偵測距離**：設定雷達偵測的最遠距離（0.75 m – 6 m）
- **最小偵測距離**：忽略過近的物體（避免誤觸）
- 建議從 **4 m** 開始，依實際空間縮短

**2. 靈敏度（Sensitivity）**

每個距離區間（Gate，每格 0.75 m）可獨立設定靜止與移動靈敏度：

| 情境 | 靜止靈敏度建議 | 移動靈敏度建議 |
|---|---|---|
| 客廳（大空間） | 50–70 | 40–60 |
| 書房（靜態工作） | 70–85 | 50–70 |
| 廁所（短暫停留） | 30–50 | 30–50 |
| 睡眠偵測（臥室） | 80–90 | 60–75 |

> 數值越高越靈敏，越容易誤觸；越低越不靈敏，可能漏報

**3. 無人確認時間（No-One Duration）**

- 偵測不到人體後，延遲多久才回報「無人」
- 建議設定 **5–30 秒**，避免人短暫不動被誤判離開

**4. 工程模式（Engineering Mode）**

開啟後可即時看到各距離 Gate 的能量值，協助判斷干擾源：

- 若某個 Gate 持續有高能量但實際無人 → 降低該 Gate 靈敏度
- 若感測距離不夠遠 → 提高遠距 Gate 靈敏度
- 完成調教後記得**關閉工程模式**以降低功耗

### 常見調教場景

**臥室睡眠偵測**
```
最大距離：3 m
靜止靈敏度：Gate 1–4 調至 80
無人確認時間：30 秒
```

**客廳大範圍偵測**
```
最大距離：6 m
靜止靈敏度：Gate 1–8 調至 60
移動靈敏度：Gate 1–8 調至 50
無人確認時間：10 秒
```

**辦公桌定點偵測（防誤觸）**
```
最大距離：2.25 m（Gate 1–3）
最小偵測距離：0.75 m
靜止靈敏度：Gate 1–3 調至 75，其餘設為 0
無人確認時間：15 秒
```

---

## 韌體更新 OTA

MotionOne Plus 連上 Wi-Fi 後會自動在 **Port 8080** 啟動本地更新伺服器。

### 更新步驟

1. 確認手機與裝置連接**同一 Wi-Fi 網路**
2. 開啟瀏覽器，輸入：
   ```
   http://MotionOne-Plus-XXXXXX.local:8080/update
   ```
   （XXXXXX 為裝置 MAC 地址末 6 碼，可在路由器 DHCP 列表查詢 IP）
3. 點擊「選擇檔案」，上傳最新的 `.bin` 韌體檔案
4. 點擊「更新」，等待重啟完成（約 30 秒）

> 更新期間請勿斷電，LED 快閃為正常現象

---

## 常見問題

**Q：配對時找不到裝置？**
> 確認裝置 LED 為慢閃狀態；確認手機藍牙已開啟；靠近裝置 1 公尺以內再試。

**Q：偵測到人但 App 沒有更新狀態？**
> 檢查 Wi-Fi 連線；確認裝置與手機在同一網段；嘗試移除並重新配對。

**Q：感測器太靈敏，沒有人也觸發？**
> 使用 Hi-Link App 降低各 Gate 靈敏度，或縮短最大偵測距離；排查風扇、窗簾等會移動的物體。

**Q：如何確認目前韌體版本？**
> Apple Home：點擊裝置 → 設定 → 韌體版本
> Home Assistant：裝置頁面 → 韌體欄位

**Q：忘記配對碼？**
> 配對碼印在裝置底部貼紙，或參考本頁上方的 Manual Code。

**Q：需要重新配對？**
> 長按重置按鈕 10 秒以上恢復出廠設定，再重新執行配對流程。

---

*MotionOne Plus — AUTOMATE*
*Firmware v1.2.0 | Matter 1.3*
