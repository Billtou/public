# ESPHome LVGL v8 → v9 遷移指南

> **適用版本：** ESPHome 2026.4.0+  
> **LVGL 版本變更：** v8.4.0 → v9.5.0  
> **症狀：** 升級 ESPHome 後版面跑掉 — 內容跑到角落、flex 欄位失去置中、按鈕擠在一起或溢出容器

---

## 快速摘要

| # | 破壞性變更 | 症狀 | 修正方式 |
|---|---|---|---|
| 1 | `pad_all` 不再包含 `pad_row` / `pad_column` | Flex 間距異常（來自主題預設值） | 明確設定 `pad_row` 和 `pad_column` |
| 2 | `flex_align_cross: CENTER` 不再置中 tracks | 版面跑到左上角 | 新增 `flex_align_track: CENTER` |
| 3 | LVGL v9 主題對按鈕加入預設 `margin` | 按鈕溢出 flex 容器 → 每欄只剩 1 個 | 在按鈕樣式加入 `margin_*: 0` |
| 4 | 垂直置中需要 `flex_align_main` | 內容堆疊在欄位頂端 | 新增 `flex_align_main: CENTER` |

---

## 變更 1 — `pad_all` 不包含 `pad_row` / `pad_column`

### 發生了什麼

在 LVGL v8 中，主題設定統一的 `pad_gap` 控制 flex 項目間距。  
在 LVGL v9 中，`pad_row` 和 `pad_column` 是**獨立屬性** — `pad_all: 0` **不會**清除它們。

LVGL v9 預設主題對所有 `lv_obj_t` 套用 `pad_all: 8`，設定：
- `pad_top`、`pad_bottom`、`pad_left`、`pad_right` → 8px
- `pad_row`、`pad_column` → **也是 8px**（但你樣式中的 `pad_all: 0` **不會**覆蓋它們！）

### 症狀

- flex 容器左右間距不對稱  
  （例如左側 = 8px，右側 = 480 − 440 − 8 − 8 = 24px）
- flex 項目意外溢出容器

### 修正前（在 v9 中壞掉）

```yaml
style_definitions:
  - id: regular_page
    width: 480
    height: 405
    bg_opa: TRANSP
    border_opa: TRANSP
    scrollbar_mode: "OFF"
    align: TOP_MID
    # ← 缺少 pad_all: 0 → 繼承主題 pad_left/right = 8px

  - id: four_grids
    width: 220
    height: 215
    pad_left: 0px
    pad_top: 0px
    pad_bottom: 0px
    pad_right: 0px
    # ← 只設定方向性 padding；pad_row / pad_column 從主題繼承 8px
```

### 修正後（v9 正確寫法）

```yaml
style_definitions:
  - id: regular_page
    width: 480
    height: 405
    bg_opa: TRANSP
    border_opa: TRANSP
    scrollbar_mode: "OFF"
    align: TOP_MID
    pad_all: 0          # 清除主題的 pad_top/bottom/left/right

  - id: four_grids
    width: 220
    height: 215
    pad_all: 0          # 清除方向性 padding
    pad_row: 6          # 明確設定列間距（需滿足：2 × 高度 + 間距 ≤ 容器高度）
    pad_column: 5       # 明確設定欄間距（需滿足：2 × 寬度 + 間距 ≤ 容器寬度）
```

> **注意：** 請計算間距是否合理。  
> `four_grids`（220 × 215）搭配按鈕（104 × 101）：  
> - `pad_column` 最大值 = 220 − 104 − 104 = **12 px**  
> - `pad_row` 最大值    = 215 − 101 − 101 = **13 px**

---

## 變更 2 — `flex_align_cross: CENTER` 不再置中 tracks

### 發生了什麼

在 LVGL v8 中，`COLUMN_WRAP` 容器上的 `flex_align_cross: CENTER` 有個副作用：會將多個欄位 tracks 置中於容器寬度。

在 LVGL v9 中，這兩個概念被分開：

| 屬性 | 控制範圍 |
|---|---|
| `flex_align_cross` | 單一 track 內**項目**的對齊方式 |
| `flex_align_track` | **tracks** 在容器中的分佈方式 |

### 症狀

- 整個版面跑到**左上角**
- 兩欄都靠左對齊，右側留有空白

### 修正前（在 v9 中壞掉）

```yaml
- obj:
    styles: regular_page
    layout:
      type: flex
      flex_flow: COLUMN_WRAP
      flex_align_cross: CENTER   # v8：同時置中 tracks；v9：只對齊 track 內的項目
    widgets:
      ...
```

### 修正後（v9 正確寫法）

```yaml
- obj:
    styles: regular_page
    layout:
      type: flex
      flex_flow: COLUMN_WRAP
      flex_align_cross: CENTER
      flex_align_track: CENTER   # ← 新增：v9 中明確置中各欄 tracks
    widgets:
      ...
```

> **原則：** 凡是 `COLUMN_WRAP`（或 `ROW_WRAP`）上有 `flex_align_cross: CENTER`，都要補上對應的 `flex_align_track: CENTER`。

---

## 變更 3 — LVGL v9 主題對按鈕加入預設 `margin`

### 發生了什麼

LVGL v9 simple 主題對 `lv_btn_t`（按鈕元件）套用預設 margin。`pad_all: 0` 只清除 **padding** — **不影響 margin**。

若未明確將按鈕 margin 歸零，每個按鈕在 flex 版面中的實際佔用大小會超過宣告的 `width` / `height`，導致每欄只放得下 1 個按鈕（而非 2 個）。

### 症狀

- `COLUMN_WRAP` flex 容器應顯示 2×2 方格，卻只看到 2 個按鈕（`flex_align_track: CENTER` 置中後，中間 2 欄可見）
- 其餘按鈕被裁切到畫面外

### 診斷方式

若你的 `four_grids`（220 × 215）有 4 個 104 × 101 的按鈕，卻只看到 2 個，原因是 margin：

```
按鈕實際高度 = 101 + margin_top + margin_bottom
若 2 × 實際高度 > 215 → 每欄只放 1 個 → 產生 4 欄 → 置中後只見中間 2 欄
```

### 修正前（在 v9 中壞掉）

```yaml
style_definitions:
  - id: button_D
    width: 104
    height: 101
    pad_left: 0px
    pad_top: 0px
    pad_bottom: 0px
    pad_right: 0px
    shadow_width: 0
    # ← 未歸零 margin → v9 主題加入 margin → 按鈕在 flex 中佔用 > 101px
```

### 修正後（v9 正確寫法）

```yaml
style_definitions:
  - id: button_D
    width: 104
    height: 101
    pad_all: 0
    margin_top: 0        # ← 必須個別歸零四個方向的 margin
    margin_bottom: 0
    margin_left: 0
    margin_right: 0
    shadow_width: 0
```

> **注意：** LVGL 沒有 `margin_all` 屬性，四個方向必須分別設定。

---

## 變更 4 — 垂直置中需要 `flex_align_main`

### 發生了什麼

在 LVGL v8 中，`COLUMN_WRAP` 容器的 flex 欄位可能因主題預設行為而看起來垂直平衡。在 LVGL v9 中，項目預設為 `flex_align_main: START` — 堆疊在頂端。

### 症狀

- 內容緊貼容器**頂端**
- 每欄底部有明顯空白

### 修正方式

```yaml
- obj:
    styles: regular_page
    layout:
      type: flex
      flex_flow: COLUMN_WRAP
      flex_align_main: CENTER    # ← 將每欄的項目垂直置中
      flex_align_cross: CENTER
      flex_align_track: CENTER
    widgets:
      ...
```

---

## 變更 5 — 必須明確停用 `scrollable`

### 發生了什麼

在 LVGL v9 中，`lv_obj_t` 容器**預設可滾動**。設定 `scrollbar_mode: "OFF"` 只是隱藏捲軸指示器 — **不會停用滾動功能**。

若 flex 項目有任何溢出（即使很輕微），使用者仍可拖曳/滾動容器。

### 修正方式

在 widget 上直接加入 `scrollable: false`（不是在 style 裡）：

```yaml
- obj:
    styles: four_grids
    scrollable: false     # ← widget 屬性，不是 style 屬性
    layout:
      type: flex
      ...
```

---

## 完整修正前後對照範例

### style_definitions.yaml

```yaml
# ─── 修正前（LVGL v8）───────────────────────────────────────────────────────

style_definitions:
  - id: regular_page
    bg_opa: TRANSP
    border_opa: TRANSP
    width: 480
    height: 405
    scrollbar_mode: "OFF"
    align: TOP_MID

  - id: four_grids
    width: 220
    height: 215
    border_opa: TRANSP
    scrollbar_mode: "OFF"
    align: TOP_MID
    bg_opa: TRANSP
    radius: 15
    pad_left: 0px
    pad_top: 0px
    pad_bottom: 0px
    pad_right: 0px

  - id: button_D
    width: 104
    height: 101
    pad_left: 0px
    pad_top: 0px
    pad_bottom: 0px
    pad_right: 0px
    shadow_width: 0
```

```yaml
# ─── 修正後（LVGL v9 / ESPHome 2026.4+）─────────────────────────────────────

style_definitions:
  - id: regular_page
    bg_opa: TRANSP
    border_opa: TRANSP
    width: 480
    height: 405
    scrollbar_mode: "OFF"
    align: TOP_MID
    pad_all: 0              # 修正 #1：清除主題 pad_left/right = 8px

  - id: four_grids
    width: 220
    height: 215
    border_opa: TRANSP
    scrollbar_mode: "OFF"
    align: TOP_MID
    bg_opa: TRANSP
    radius: 15
    pad_all: 0              # 修正 #1：清除方向性 padding
    pad_row: 6              # 修正 #1：明確設定間距（≤ 13px）
    pad_column: 5           # 修正 #1：明確設定間距（≤ 12px）

  - id: button_D
    width: 104
    height: 101
    pad_all: 0
    margin_top: 0           # 修正 #3：歸零主題加入的 margin
    margin_bottom: 0
    margin_left: 0
    margin_right: 0
    shadow_width: 0
```

### 頁面版面（dashboard yaml）

```yaml
# ─── 修正前（LVGL v8）───────────────────────────────────────────────────────

- obj:
    styles: regular_page
    layout:
      type: flex
      flex_flow: COLUMN_WRAP
      flex_align_cross: CENTER
    widgets:
      - obj:
          styles: four_grids
          layout:
            type: flex
            flex_flow: COLUMN_WRAP
            flex_align_cross: CENTER
          widgets:
            - button:
                styles: button_D
                ...
```

```yaml
# ─── 修正後（LVGL v9 / ESPHome 2026.4+）─────────────────────────────────────

- obj:
    styles: regular_page
    layout:
      type: flex
      flex_flow: COLUMN_WRAP
      flex_align_main: CENTER       # 修正 #4：垂直置中
      flex_align_cross: CENTER
      flex_align_track: CENTER      # 修正 #2：置中各欄 tracks
    widgets:
      - obj:
          styles: four_grids
          scrollable: false          # 修正 #5：停用滾動
          layout:
            type: flex
            flex_flow: COLUMN_WRAP
            flex_align_cross: CENTER
            flex_align_track: CENTER # 修正 #2
          widgets:
            - button:
                styles: button_D
                ...
```

---

## 升級檢查清單

升級至 ESPHome 2026.4.0 時，請逐項確認：

- [ ] 每個用作 flex 容器的 `lv_obj_t` 樣式：若需要零外邊距，加入 `pad_all: 0`
- [ ] 每個 flex 容器樣式：明確設定 `pad_row` 和 `pad_column` 為所需間距值（不要依賴主題預設）
- [ ] 每個用 `flex_align_cross: CENTER` 置中的 `COLUMN_WRAP` / `ROW_WRAP` 版面：補上 `flex_align_track: CENTER`
- [ ] 每個在緊湊 flex 格狀版面中使用的按鈕樣式：加入 `margin_top/bottom/left/right: 0`
- [ ] 每個不應被拖曳的 flex 容器：在 widget 上（不是 style）加入 `scrollable: false`
- [ ] 選用：在外層 `COLUMN_WRAP` 容器加入 `flex_align_main: CENTER` 實現垂直置中

---

## 參考資料

- [ESPHome LVGL 版面配置](https://esphome.io/components/lvgl/layouts/)  
- [ESPHome 2026.4.0 更新日誌](https://esphome.io/changelog/2026.4.0/)  
- [LVGL v9 Flex 說明文件](https://docs.lvgl.io/master/common-widget-features/layouts/flex.html)
