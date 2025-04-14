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

## HA 實體到轉到 esphome觸控板內 再改變ha實體的三角關係圖
### - HA 先要有個有效的實體，然後在esphome裡面建立一個與之連動state的id，透過這個id狀態的變化改變lvgl畫面id的狀態。(見dashboard_one/lights.yaml)
### - 當觸摸指定的button 轉化成on_click:的指令執行 homeassistant.action: 的一連串動作達到改變ha實體的狀態

 ![Mosquitto_broker](/dashboard_one_tw/image/174735.jpg)




## 以下為實際頁面內容
 ![Mosquitto_broker](/dashboard_one_tw/image/180844.jpg)


            
              # -------------------------------------------------
              # -   頁腳#永遠放在最上層 首層 導航頁腳畫面   -
              # -------------------------------------------------
              top_layer: !include { file: dashboard_one/lvgl/top_layer.yaml }   # 永遠放在最上層，導航到pages頁面都靠他，右下較時間也是這裡定義的
 
              #--------------------------------------------
              #  宣告main_page_type_a頁面
              #--------------------------------------------
              pages:  #定義多個頁面（類似畫面、Tab 或分頁）。  
               - id: main_page_type_a    #這個頁面的 ID，稍後可以用來跳轉或引用。
                 bg_image_src: my_background_image
                 widgets:   #宣告 "小部件" widgets
                    - obj:       ##小部件下建立"容器" obj 的定義繼承 pages 的定義
                        styles: regular_page # align: CENTER  #把這個容器在螢幕上置中對齊。
                        layout:  # 版面配置
                          type: flex  #使用 Flex 排列方式，讓內部 widgets 自動依照順序排列。
                          flex_flow: COLUMN_WRAP  #主軸為縱向（從上而下），若內容寬度超過，則會換行（wrap）。
                          flex_align_cross: CENTER #在交叉軸（水平方向）居中對齊每一列。

## 天氣預報小部件
   ![Mosquitto_broker](/dashboard_one_tw/image/13762B9.jpg)

            widgets:   
              - button:   
                  styles: button_A  ## 統一調用Button A的風格參數 (免去本button 長寬圓腳顏色等等宣告)
                  #-------------------------------------------------------------------------------------
                  # 天氣預告小部件內容 請見esphome lvgl https://esphome.io/components/lvgl/widgets.html 
                  #-------------------------------------------------------------------------------------
                  widgets:
                    - label:
                        text: "\U000F14E4"  #氣象預報icon 來自於fonts.yaml 的 id icons_100 的宣告
                        id: lvgl_label_weather_forecast_condition_icon  #來源是 weather_forecast.yaml 的建立
                        text_font: icons_100  # 來自於fonts.yaml 的宣告
                        align: TOP_LEFT #放置的位置  (上左)
                        text_color: 0x3182b7  # 文字顏色宣告
                    - label:
                        text: "--°"  #體感溫度
                        id: lvgl_label_weather_forecast_tempap  #內容由這個id反饋而來
                        align: TOP_RIGHT #(上右)
                        y: 10  #偏移y軸10像素 正負直端看 align: TOP_RIGHT 位置而定
                        text_font: weather_forecast_50 # 引用的自型庫id
                        text_color: 0xf5f8fa #顏色
                    - label:
                        text: "--" 
                        y: 5
                        id: lvgl_label_weather_forecast_condition_name
                        text_font: weather_forecast_24
                        align: BOTTOM_MID
                        text_color: 0xa4abb1  # 文字顏色
                        long_mode: dot
                
## 四宮格自動化或場景觸發button說明
   ![Mosquitto_broker](/dashboard_one_tw/image/E89FB4C5855B.jpg)
   
              - obj:  ## 用obj包裹四 button 
                  styles: four_grids # align: CENTER  #把這個容器在螢幕上置中對齊。
                  layout:  # 版面配置
                    type: flex  #使用 Flex 排列方式，讓內部 widgets 自動依照順序排列。
                    flex_flow: COLUMN_WRAP  #主軸為縱向（從上而下），若內容寬度超過，則會換行（wrap）。
                    flex_align_cross: CENTER #在交叉軸（水平方向）居中對齊每一列。
                  widgets:      
                    - button:   ## 鬧鐘按鈕 後期由user 在HA建立自動化或場景使用
                        styles: button_D #調用button_D的風格
                        id: lvgl_button_scene_trigger_home_page_a
                        checkable: true #依據id的on/off 反饋button顏色
                        widgets:
                          - label:   
                              # checkable: true 
                              align: CENTER
                              text_font: font_icon_medium
                              text: "\U000F0021" # 鬧鐘
                              text_color: 0x8b3333
                        on_click:
                          then:
                            - switch.turn_on: scene_trigger_a  # 當按下button時觸發  scene_trigger_a 這個id

                    - button:   ## 睡覺按鈕 後期由user 在HA建立自動化或場景使用
                        styles: button_D
                        id: lvgl_button_scene_trigger_home_page_b                  
                        checkable: true
                        widgets:
                          - label:   
                              checkable: true
                              align: CENTER
                                :
                                :
                                :
