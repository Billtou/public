# ESPHome LVGL v8 → v9 Migration Guide

> **Applies to:** ESPHome 2026.4.0+  
> **LVGL version change:** v8.4.0 → v9.5.0  
> **Symptom:** Layout breaks after upgrading ESPHome — content shifts to corner, flex columns lose centering, buttons squish together or overflow

---

## Quick Summary

| # | Breaking Change | Symptom | Fix |
|---|---|---|---|
| 1 | `pad_all` no longer includes `pad_row` / `pad_column` | Flex gap unexpected (from theme default) | Explicitly set `pad_row` and `pad_column` |
| 2 | `flex_align_cross: CENTER` no longer centers tracks | Layout shifts to top-left corner | Add `flex_align_track: CENTER` |
| 3 | LVGL v9 theme adds default `margin` to buttons | Buttons overflow flex container → only 1 per column | Add `margin_*: 0` to button styles |
| 4 | Vertical centering requires `flex_align_main` | Content stacks at top of column | Add `flex_align_main: CENTER` |

---

## Change 1 — `pad_all` does NOT include `pad_row` / `pad_column`

### What changed

In LVGL v8, the theme set a unified `pad_gap` that controlled flex item spacing.  
In LVGL v9, `pad_row` and `pad_column` are **separate** properties — `pad_all: 0` does **not** clear them.

The LVGL v9 default theme applies `pad_all: 8` to all `lv_obj_t`, which sets:
- `pad_top`, `pad_bottom`, `pad_left`, `pad_right` → 8px
- `pad_row`, `pad_column` → **also 8px** (but NOT overridden by `pad_all: 0` in your style!)

### Symptom

- Asymmetric left/right spacing on flex containers  
  (e.g. left side = 8px, right side = 480 − 440 − 8 − 8 = 24px)
- Flex items unexpectedly overflow their container

### Before (broken in v9)

```yaml
style_definitions:
  - id: regular_page
    width: 480
    height: 405
    bg_opa: TRANSP
    border_opa: TRANSP
    scrollbar_mode: "OFF"
    align: TOP_MID
    # ← missing pad_all: 0  →  gets theme pad_left/right = 8px

  - id: four_grids
    width: 220
    height: 215
    pad_left: 0px
    pad_top: 0px
    pad_bottom: 0px
    pad_right: 0px
    # ← individual pads only; pad_row / pad_column = 8px from theme
```

### After (fixed for v9)

```yaml
style_definitions:
  - id: regular_page
    width: 480
    height: 405
    bg_opa: TRANSP
    border_opa: TRANSP
    scrollbar_mode: "OFF"
    align: TOP_MID
    pad_all: 0          # clears pad_top/bottom/left/right from theme

  - id: four_grids
    width: 220
    height: 215
    pad_all: 0          # clears directional padding
    pad_row: 6          # explicit gap between rows (must fit: 2 × height + gap ≤ container height)
    pad_column: 5       # explicit gap between columns (must fit: 2 × width + gap ≤ container width)
```

> **Important:** Always calculate whether your gap fits.  
> `four_grids` (220 × 215) with buttons (104 × 101):  
> - Max `pad_column` = 220 − 104 − 104 = **12 px**  
> - Max `pad_row`    = 215 − 101 − 101 = **13 px**

---

## Change 2 — `flex_align_cross: CENTER` no longer centers tracks

### What changed

In LVGL v8, `flex_align_cross: CENTER` on a `COLUMN_WRAP` container had a side effect of centering the column tracks across the container width.

In LVGL v9, the two concepts are separated:

| Property | Controls |
|---|---|
| `flex_align_cross` | Alignment of **items within** a single track |
| `flex_align_track` | Distribution of **tracks** across the container |

### Symptom

- Entire layout shifts to the **top-left corner**
- Both columns left-aligned, with blank space on the right

### Before (broken in v9)

```yaml
- obj:
    styles: regular_page
    layout:
      type: flex
      flex_flow: COLUMN_WRAP
      flex_align_cross: CENTER   # in v8: also centered tracks; in v9: only items within track
    widgets:
      ...
```

### After (fixed for v9)

```yaml
- obj:
    styles: regular_page
    layout:
      type: flex
      flex_flow: COLUMN_WRAP
      flex_align_cross: CENTER
      flex_align_track: CENTER   # ← new: explicitly center column tracks in v9
    widgets:
      ...
```

> **Rule of thumb:** Wherever you had `flex_align_cross: CENTER` on a `COLUMN_WRAP` (or `flex_align_cross: CENTER` on a `ROW_WRAP`), add the matching `flex_align_track: CENTER`.

---

## Change 3 — LVGL v9 theme adds default `margin` to button widgets

### What changed

The LVGL v9 simple theme applies default margins to `lv_btn_t` (button widgets). `pad_all: 0` only clears **padding** — it does **not** affect **margin**.

If button margins are not explicitly zeroed, each button's effective size in the flex layout becomes larger than its declared `width` / `height`, causing only 1 button per column instead of 2.

### Symptom

- A `COLUMN_WRAP` flex container that should show a 2×2 grid shows only 2 buttons visible (the 2 middle columns after `flex_align_track: CENTER` centering)
- Other buttons are clipped off-screen

### Diagnosis

If your `four_grids` (220 × 215) has 4 buttons of 104 × 101 but only 2 are visible, button margin is the cause:

```
effective button height = 101 + margin_top + margin_bottom
if 2 × effective_height > 215 → only 1 per column → 4 columns → 2 visible after centering
```

### Before (broken in v9)

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
    # ← no margin zeroing → v9 theme adds margin → button occupies > 101px in flex
```

### After (fixed for v9)

```yaml
style_definitions:
  - id: button_D
    width: 104
    height: 101
    pad_all: 0
    margin_top: 0        # ← must explicitly zero all four margins
    margin_bottom: 0
    margin_left: 0
    margin_right: 0
    shadow_width: 0
```

> **Note:** `margin_all` does not exist in LVGL. All four margins must be set individually.

---

## Change 4 — Vertical centering requires `flex_align_main`

### What changed

In LVGL v8, flex columns in a `COLUMN_WRAP` container may have appeared vertically balanced due to default theme behavior. In LVGL v9, items default to `flex_align_main: START` — stacking at the top.

### Symptom

- Content appears flush to the **top** of the container
- Visible blank space at the bottom of each column

### Fix

```yaml
- obj:
    styles: regular_page
    layout:
      type: flex
      flex_flow: COLUMN_WRAP
      flex_align_main: CENTER    # ← vertically centers items within each column
      flex_align_cross: CENTER
      flex_align_track: CENTER
    widgets:
      ...
```

---

## Change 5 — `scrollable` must be explicitly disabled

### What changed

In LVGL v9, `lv_obj_t` containers are **scrollable by default**. Setting `scrollbar_mode: "OFF"` only hides the scrollbar indicator — it does **not** disable scrolling.

If flex items overflow (even slightly), the user can drag/scroll the container.

### Fix

Add `scrollable: false` directly on the widget (not in the style):

```yaml
- obj:
    styles: four_grids
    scrollable: false     # ← widget property, not a style property
    layout:
      type: flex
      ...
```

---

## Complete Before / After Example

### style_definitions.yaml

```yaml
# ─── BEFORE (LVGL v8) ───────────────────────────────────────────────────────

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
# ─── AFTER (LVGL v9 / ESPHome 2026.4+) ─────────────────────────────────────

style_definitions:
  - id: regular_page
    bg_opa: TRANSP
    border_opa: TRANSP
    width: 480
    height: 405
    scrollbar_mode: "OFF"
    align: TOP_MID
    pad_all: 0              # fix #1: clear theme pad_left/right = 8px

  - id: four_grids
    width: 220
    height: 215
    border_opa: TRANSP
    scrollbar_mode: "OFF"
    align: TOP_MID
    bg_opa: TRANSP
    radius: 15
    pad_all: 0              # fix #1: clear directional padding
    pad_row: 6              # fix #1: explicit gap (≤ 13px for this container)
    pad_column: 5           # fix #1: explicit gap (≤ 12px for this container)

  - id: button_D
    width: 104
    height: 101
    pad_all: 0
    margin_top: 0           # fix #3: zero theme-provided margins
    margin_bottom: 0
    margin_left: 0
    margin_right: 0
    shadow_width: 0
```

### page layout (dashboard yaml)

```yaml
# ─── BEFORE (LVGL v8) ───────────────────────────────────────────────────────

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
# ─── AFTER (LVGL v9 / ESPHome 2026.4+) ─────────────────────────────────────

- obj:
    styles: regular_page
    layout:
      type: flex
      flex_flow: COLUMN_WRAP
      flex_align_main: CENTER       # fix #4: vertical centering
      flex_align_cross: CENTER
      flex_align_track: CENTER      # fix #2: center column tracks
    widgets:
      - obj:
          styles: four_grids
          scrollable: false          # fix #5: disable scroll
          layout:
            type: flex
            flex_flow: COLUMN_WRAP
            flex_align_cross: CENTER
            flex_align_track: CENTER # fix #2
          widgets:
            - button:
                styles: button_D
                ...
```

---

## Checklist

Use this checklist when upgrading to ESPHome 2026.4.0:

- [ ] Every `lv_obj_t` style used as a flex container: add `pad_all: 0` if you need zero outer padding
- [ ] Every flex container style: explicitly set `pad_row` and `pad_column` to your desired gap value (do not rely on theme defaults)
- [ ] Every `COLUMN_WRAP` / `ROW_WRAP` layout that used `flex_align_cross: CENTER` for centering: add `flex_align_track: CENTER`
- [ ] Every button style used inside a tightly-packed flex grid: add `margin_top/bottom/left/right: 0`
- [ ] Every flex container that must not be draggable: add `scrollable: false` on the widget (not in the style)
- [ ] Optional: add `flex_align_main: CENTER` to outer COLUMN_WRAP containers for vertical centering

---

## Reference

- [ESPHome LVGL Layouts](https://esphome.io/components/lvgl/layouts/)  
- [ESPHome 2026.4.0 Changelog](https://esphome.io/changelog/2026.4.0/)  
- [LVGL v9 Flex Documentation](https://docs.lvgl.io/master/common-widget-features/layouts/flex.html)
