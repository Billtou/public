# Dashboard one 中文版說明頁面
## 首次連網說明 上電 手機搜尋ap熱點 接入熱點手機切換到瀏覽器輸入 192.168.4.1 指定自家wifi後 ha會自動發現。
## 預置檔案，將檔案放置於相對位置

    < esphome >
        |  dashboard-one-XXXXXX.yaml
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


    ## dashboard-one-XXXX.yaml 檔案說明
    
            substitutions:
              name: "dashboard-one-XXXXXX"  修改為自家的 id
              friendly_name: "Dashboard One XXXXXX"   修改為自家的 id
              device_description: "Panlee ZX3D95CE01S-TR-4848 480*480 Smart Screen"
              project_name: "Panlee.ZX3D95CE01S-TR-4848"
              project_version: "2025.4"
            
              livingroom_climate: "climate.livingroom"   修改為自家的 id
              livingroom_curtain: "cover.curtain_29ae50_curtain"  修改為自家的 id
              livingroom_smart_light: "light.livingroom_big_light"  修改為自家的 id
              livingroom_switch_light: "light.study_wall_light_2"  修改為自家的 id
              livingroom_smart_fan: "fan.livingroom_fan"  修改為自家的 id
              balcony_switch_fan: "fan.balcony_esp01_convulsions"  修改為自家的 id           

              count_light_entity: "sensor.count_light_turn_on"    # packages 裡面 count_turn_on.yaml 產生
              count_switch_entity: "sensor.count_switch_turn_on"  #同上 
              count_climate_entity: "sensor.count_climate_turn_on"  #同上
              count_fan_entity: "sensor.count_fan_turn_on"   #同上
              count_cover_entity: "sensor.count_cover_turn_open"   #同上
              
              count_power_entity: "sensor.entrance_home_power_meter_power_monitor_energy"  修改為自家的 id
            
            external_components:  
              - source: github://sEbola76/gc9503v  # 驅動外掛別動
            
            packages:
              basic_device_in: !include dashboard_one/base/esphome_basic.yaml  # 必須  依據 預置檔案，將檔案放置於相對位置  見首頁說明
              display_and_tou1chscreen_in: !include dashboard_one/base/touchscreen.yaml  #必須
              weather_forecast_in: !include dashboard_one/weather_forecast.yaml  #天氣預報外掛
              climate_in: !include dashboard_one/climates.yaml #冷氣空調外掛
              scenes_in: !include dashboard_one/sceness.yaml #自帶4個自動化場景外掛
              fonts_in: !include dashboard_one/fonts.yaml #字體外掛
              fan_in: !include dashboard_one/fans.yaml   #風扇外掛
              cover_in: !include dashboard_one/covers.yaml  #窗簾、車門外掛
              light_in: !include dashboard_one/lights.yaml #電燈外掛
              count_entity: !include dashboard_one/count_entity.yaml  #計數 entity 開啟狀態外掛


            
              
            # --------------------------------------
            # -            背景圖
            # --------------------------------------            
            image: !include { file: dashboard_one/lvgl/image.yaml }   # 調用 image.yaml 定義背景圖的檔案名稱 以及開機圖名稱
            # --------------------------------------
            # -            GUI                     -
            # --------------------------------------
            lvgl:     #  以下開始lvgl 圖形化頁面宣告
              displays:
                - my_display
              touchscreens:
                - my_touchscreen
              # -------------------------------------------------
              # -   超時關螢幕 (正常使用打開，開發編譯時可以註解掉)   -
              # -------------------------------------------------
              on_idle:
                timeout: !lambda "return (id(display_timeout).state * 1000);"
                then:
                  - logger.log: "LVGL is idle"
                  - light.turn_off: display_backlight
                  - lvgl.pause:
              # -------------------------------------------------
              # -   # 小部件預設參數  -
              # -------------------------------------------------
              theme: !include { file: dashboard_one/lvgl/theme.yaml }    # 這是小部件 button，lcabel，widgets等預設格式後期都會引用達到統一化管理的目的
            
              # -------------------------------------------------
              # -   # 風格預設   -
              # -------------------------------------------------
              style_definitions: !include { file: dashboard_one/lvgl/style_definitions.yaml }    # 這是風格預設的檔案，後期所有的小部件都會引用達到統一化管理的目的
            
              # -------------------------------------------------
              # -   頁腳#永遠放在最上層 首層 導航頁腳畫面   -
              # -------------------------------------------------
              top_layer: !include { file: dashboard_one/lvgl/top_layer.yaml }   # 永遠放在最上層，導航到pages頁面都靠他，右下較時間也是這裡定義的
 
