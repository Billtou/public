# Dashboard one 中文版說明頁面
## 首次連網說明 上電 手機搜尋ap熱點 接入熱點手機切換到瀏覽器輸入 192.168.4.1 指定自家wifi後 ha會自動發現。
## 預置檔案，將檔案放置於相對位置

    < esphome >
        |  dashboard-one-XXXXXX.yaml
        |
        |  -- < fonts >
        |        |  GenJyuuGothic-Bold.ttf
        |        |  GenJyuuGothic-Medium.ttf
        |        |  SFProDisplay-BoldItalic.ttf
        |        |  FProDisplay-HeavyItalic.ttf
        |        |  SFProDisplay-RegularItalic.ttf
        |        |  materialdesignicons-webfont.ttf
        |
        |  --< dashboard_one >
                |  < base >
                |      |  esphome_basic.yaml
                |      |  touchscreen.yaml
                |
                |  < lvgl >
                      |
                      |  image.yaml
                      |  style_definitions.yaml
                      |  theme.yaml
                      |  top_layer.yaml
                      |  < image >
                            |
                            |  background_1.png
                            |  background_2.png
                            |  background_3.png
                            |  boot_logo.png
                            |  ha_logo.svg
