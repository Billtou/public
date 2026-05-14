# AUTOMATE PM-20d v3.8.0 版本說明

**發布日期**:2026-05-13
**對應台電費率公告**:114 年 10 月電價公告(114/10/1 施行)

## 一句話摘要

把度數電費計算對齊到台電住宅用電非時間電價的實際帳單規則 —— **雙月抄表級距** + **跨季日數比例切割**。

## 為什麼要更新

舊版本(≤ v3.7.5)的計費邏輯有兩個與台電帳單不一致的地方:

1. **級距用「單月」120/330/500/700/1000**,但台電住宅是雙月抄表,實際應為加倍級距 240/660/1000/1400/2000 → 同度數提早跳級,**金額會偏高**。
2. **夏冬月切換用「今日月份」一刀切**,跨季月份(5/15–7/14 之類)沒按日數比例分配 → **誤差約 ±10%**。

v3.8.0 後與台電帳單誤差通常 < 1%。

## 變更內容

### 1. 級距預設值改為雙月

`auto_count.yaml` 內的 5 個 threshold initial_value:

| Threshold | 舊(單月) | 新(雙月) |
|---|---|---|
| `threshold1` | 120 | **240** |
| `threshold2` | 330 | **660** |
| `threshold3` | 500 | **1000** |
| `threshold4` | 700 | **1400** |
| `threshold5` | 1000 | **2000** |

費率(rate1 ~ rate6_summer/winter)維持不變,與 114/10/1 台電公告一致。

### 2. 跨季日數比例切割

當計費週期(`taipower_reset_date` ~ 今日)橫跨夏月(6/1–9/30)與非夏月時:

- 總度數按日數比例切成 `E_summer` 與 `E_winter`
- 級距(threshold)也按相同比例切成 `thr_summer[5]` 與 `thr_winter[5]`
- 兩段分別跑階梯費率,結果加總

完全同季時 fallback 單一階梯;未對時 / 未歸零過時 fallback 為「今日月份一刀切」。

### 3. 事件驅動的日數重算

新增 `script: recompute_billing_period_days`(在 `auto_count.yaml`),由以下時機觸發:

- **SNTP 首次對時成功** — `sntp_time.on_time_sync`(開機後)
- **每日 00:00:30** — `sntp_time.on_time`(過午夜重算)
- **手動 / 自動歸零按鈕觸發後** — `taipower_energy.on_press` 結尾

從原本 1440 次/天的週期計算,降到 2–3 次/天。

## 影響檔案

- `project/power/auto_count.yaml`
  - 新增 `globals`(`g_billing_total_days` / `g_billing_summer_days` / `g_billing_period_valid`)
  - 新增 `script.recompute_billing_period_days`
  - 重寫 `count_kwh_cost` lambda(邊際費率支援切割)
  - 重寫 `count_power_cost` lambda(跨季按比例分配)
  - 5 個 threshold `initial_value` × 2
- `project/power/pm_20/pm_20_code.yaml`
  - `sntp_time` 新增 `on_time_sync` 與 `on_time(00:00:30)`
  - `taipower_energy.on_press` 結尾追加 `script.execute: recompute_billing_period_days`

`pm_20d_basic.yaml` / `lcd_dispaly.yaml` / `http_request_eth_20d.yaml` 等其他檔案 **未變動**。

## 部署備忘

### 新燒錄裝置
- 直接吃 240/660/1000/1400/2000 預設值。
- 開機 SNTP 對時成功後,script 立即計算當期日數。

### 已部署裝置(由 ≤ v3.7.5 升級)
- 5 個 threshold 因 `optimistic: true` 會從 flash restore 舊值 120/330/500/700/1000。
- **務必到 Home Assistant 介面手動把 5 個 threshold ×2**(或保留舊值將造成金額偏高約 1.5–2×)。

### 對時與歸零依賴
- `taipower_reset_date` global 是「週期起日」資料源,格式 `YYYY-MM-DD`,在 `pm_20_code.yaml` 內已定義並 `restore_value: true`。
- 若週期內 SNTP 無法對時(離線開機 + 無 RTC 備援),script 不會跑,`g_billing_period_valid = false`,sensor lambda 自動 fallback。

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
