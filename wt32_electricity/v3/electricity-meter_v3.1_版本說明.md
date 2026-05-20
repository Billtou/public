# AUTOMATE Electricity Meter v3.1 版本說明

**發布日期**:2026-05-17
**對應台電費率公告**:114 年 10 月電價公告(114/10/1 施行)
**硬體**:WT32-ETH01(ESP32 + 內建 W5500)+ PZEM-004T × 2(雙路 100A AC/DC),當前設定走 WiFi(板上 ETH 已 commented,需要時取消註解)

## 一句話摘要

把 electricity-meter 補齊台電計費基礎設施,接上共享 `auto_count.yaml` 新階梯邏輯,**首次**讓這台 WT32 老板支援精準計費。

## 為什麼要更新

v3.0 時 `auto_count.yaml` 處於 include 狀態,共享檔升級到 v3.8 後新加了硬依賴 `id(taipower_reset_date)`,但 electricity-meter 自己沒這個 global → **compile fail**。

要修有兩條路:
1. 把 `auto_count.yaml` 註解掉 → 維持「無電價」狀態(類似 PM-02b)
2. 補齊 PM-02a 那套計費基礎設施 → 讓 electricity-meter 也能精準算台電帳單

v3.1 走第 2 條路。

## 變更內容

### 1. 接上共享計費邏輯

`auto_count.yaml` 取消註解後自動繼承:

- 雙月抄表級距(threshold ×2 預設值 240/660/1000/1400/2000)
- 跨季日數比例切割
- 事件驅動的日數重算 script

(詳細費率與演算法見 `automate-pm-20d_v3.8.0_版本說明.md`)

### 2. 新增「計費歸零」基礎設施

`wt32_code.yaml` 原本只有單通道硬體歸零按鈕(`ch1_kwh_reset` / `ch2_kwh_reset`),沒記錄計費週期起日。v3.1 新增:

- **`taipower_reset_date` global**(`std::string`,`restore_value: true`)
- **`taipower_reset_date_sensor` text_sensor**(HA 介面顯示週期起日)
- **`taipower_energy` 統一歸零按鈕** —— 按下時:
  1. 寫入今日日期到 `taipower_reset_date`
  2. 呼叫 `pzemac.reset_energy: pzemac_1` 與 `pzemac_2`(同時清兩路硬體寄存器)
  3. `script.execute: recompute_billing_period_days`(重算夏/非夏日數比例)
- **自動歸零行為調整**:00:00 的 auto-reset 從原本呼叫 `ch1_kwh_reset.press() + ch2_kwh_reset.press()`,改為呼叫 `taipower_energy.press()`(連同寫日期 + script 一氣呵成)

`ch1_kwh_reset` / `ch2_kwh_reset` 保留,使用者要單獨清某一路仍可用(只是不會更新計費日期)。

### 3. 事件驅動的日數重算

`publice_code.yaml` 的 `sntp_time` 新增:

- **`on_time_sync`** — 開機 SNTP 對時成功時觸發 script
- **`on_time(00:00:30)`** — 每日午夜後 30 秒觸發 script

## 影響檔案

- `project/power/auto_count.yaml`(**共享,與 PM-20 / PM-02 家族同步**,本次未變更內容)
- `project/power/electricity-meter/wt32_code.yaml`
  - 新增 `globals.taipower_reset_date`
  - 新增 `text_sensor.taipower_reset_date_sensor`
  - 新增 `button.taipower_energy`(統一歸零)
  - 自動歸零 trigger 改呼叫 `taipower_energy.press()`
- `project/power/electricity-meter/publice_code.yaml`
  - `sntp_time` 新增 `on_time_sync` 與 `on_time(00:00:30)`
- `electricity-meter.yaml`
  - 取消 `auto_count.yaml` 註解
  - `project_version`:`3.0` → `3.1`

`http_request_wifi.yaml` / `wifi_auto_ap.yaml` / `bluetooth_proxy.yaml`(已 comment)/ `firmware_info.yaml`(已 comment)未變動。

## 部署備忘

### 新燒錄裝置
- 直接吃 240/660/1000/1400/2000 預設值。
- 開機 SNTP 對時成功後,script 立即計算當期日數。
- **首次需在實際抄表日按一次 `TaiPower Count Manual Reset`** 才會把 `taipower_reset_date` 從 `"1970-01-01"` 改成今天,之後就交給自動歸零。

### 已部署裝置(由 v3.0 升級)
- 5 個 threshold 因 `optimistic: true` 會從 flash restore 舊值 120/330/500/700/1000(若 v3.0 時有更動過)。
- **務必到 Home Assistant 介面手動把 5 個 threshold ×2**(或保留舊值將造成金額偏高約 1.5–2×)。
- 新增的 `taipower_reset_date_sensor` 與 `taipower_energy` 按鈕會在 HA 自動出現。
- HA Energy Dashboard 的成本來源若之前用「Static price」,**改抓 `(Taipower) Count Power Cost` entity** 才會吃新邏輯。

### PZEM 硬體歸零延遲
- 按下 `TaiPower Count Manual Reset` 後,PZEM-004T 硬體寄存器立即被清,但 ESPHome 端的 `total_energy_sum` sensor 要等下一次 PZEM 輪詢(`electricity_update_interval = 20s`)才反映歸零值。
- 中間 ≤ 20 秒視窗內,HA 顯示的金額會殘留舊值。屬正常 UI 殘影,計費 lambda 內部 `taipower_reset_date` 已是新值,**對下期實際計算無影響**。

### 對時與歸零依賴
- `taipower_reset_date` global 是「週期起日」資料源,格式 `YYYY-MM-DD`,在 `wt32_code.yaml` 內已定義並 `restore_value: true`。
- 若週期內 SNTP 無法對時(WiFi 斷線開機 + 無 RTC 備援),script 不會跑,`g_billing_period_valid = false`,sensor lambda 自動 fallback 為「今日月份一刀切」。

### electricity-meter 特殊取捨
- **無 `publice_bluetooth_proxy`**:`electricity-meter.yaml` L33 註解掉,刻意不開藍芽代理 / OTA progress 通知 → 比 PM-02 / PM-02a 少了這些 entity,需要時自行取消註解。
- **無 `publice_firmware_info`**:L34 註解掉,沒有韌體資訊 entity。
- **目前走 WiFi**:雖然 WT32-ETH01 板上有 W5500,但 yaml L36-37 ETH includes 已註解,實際走 WiFi(L39-40 active)。要切回 Ethernet 把 L36-37 取消註解、L39-40 註解掉即可。

## 數學自驗

**情境**:5/15–7/13 共 60 天,夏月 43 天 / 冬月 17 天,期間用電 500 kWh

| 邏輯 | 計算 | 結果 |
|---|---|---|
| 舊版(用 7 月當夏月一刀切) | 240×1.78 + 260×2.55 | 1090.2 TWD |
| 新版(按日數比例切割) | 夏月 781.2 + 冬月 287.6 | **1068.8 TWD** |

差異 21 TWD,新版更貼近台電實際帳單。

## 未涵蓋

以下項目目前 **不在** 計費邏輯內,如需請另行加入:

- 燃料費調整(台電不時公告)
- 節電獎勵 / 用電折扣
- 銷項稅、公共電費分攤、轉供電費等帳單附加項

純度數階梯電費部分已完整。

## 與其他產品的關係

electricity-meter 在硬體上等同「PM-02 + WT32-ETH01 老主控板」,軟體上 v3.1 後與 PM-02 / PM-02a / PM-20 共用同一份 `auto_count.yaml` 計費邏輯。差異點僅在:

| 項目 | electricity-meter | PM-02 / PM-02a |
|---|---|---|
| 主控 | WT32-ETH01(舊版 ESP32) | ESP32-S3 |
| 板載網路晶片 | 內建 W5500 | 外掛 W5500 |
| code 檔 | `wt32_code.yaml` | `pm-02_a_code.yaml` |
| Bluetooth proxy / firmware info | ❌(刻意不開) | ✅ |

未來可考慮把 `wt32_code.yaml` 與 `pm-02_a_code.yaml` 合併,只留 `wt32_overrides.yaml` 處理腳位差異;但目前保持兩條獨立分支。
