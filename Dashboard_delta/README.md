# Deshboard delta 使用說明
#### ESPHome LVGL 見Dashboard one [說明網頁](https://github.com/Billtou/public/tree/main/dashboard_one_tw)
 
## delta熱交換 yaml檔案結構說明 (需搭max大的台達控制產品)
* 將本產品導入自家wifi HA自動發現後導入之
* 在HA裝置服務esphomes裡面打開"允許裝置執行HA動作"，"訂閱來自裝置的日誌"。
* HA 安裝 ESPHome Builder 應用程序
* 在ESPHome Builder 裡面建立 new device 項目  名稱為 "Air Panel"
* 稍待該項目紅色會變成白色的 ONLINE 第一階段就正式完成。
 
* 完成 ONLINE 之後依序在 HA 的 esphome 資料夾內建立以下檔案結構並將相對的檔案複製其中。

        esphome
            | air-panel.yaml
            | <project>    
                 | <air_penel>
                 |   my_main_page_air.yaml 
                 |   my_main_page_delta.yaml
                 |   my_main_page_light.yaml
                 |   my_main_page_livingroom.yaml
                 |   my_top_layer.yaml
                 | <publice>
                       |
                       | <background>
                       |   image.yaml
                       |   background_1.png
                       |   background_2.png
                       |   background_3.png
                       |   boot_logo.png
                       |   ha_logo.svg
                       | <basic>
                       |   basic_and_touchscreen.yaml
                       |   setup_page.yaml
                       | <fonts>
                       |   fonts.yaml
                       |   GenJyuuGothic-Bold.ttf
                       |   GenJyuuGothic-Medium.ttf
                       |   materialdesignicons-webfont.ttf
                       |   SFProDisplay-BoldItalic.ttf
                       |   SFProDisplay-HeavyItalic.ttf
                       |   SFProDisplay-RegularItalic.ttf
                       | <style>
                       |   my_style.yaml
                       | <theme>
                           my_theme.yaml

* 點選 UPDATE 選 Wirelessly 開始編譯，若其中出現紅色警告並終止時，可以將錯誤訊息貼ai幫忙分析原因並解決。
*  my_main_page_delta.yaml 主控頁面說明
*  替換 substitutions 自己的 entity id
        
                
                substitutions:
                    # 先把HA的entity抓過來後續面板使用
                
                    # 電源開關 switch.delta_erv_38432c_dian_yuan_kai_guan
                    # 風量模式 select.delta_erv_38432c_feng_liang_mo_shi
                    # 運轉時間 sensor.delta_erv_38432c_yun_zhuan_shi_jian
                    # 風量等級 sensor.delta_erv_38432c_feng_liang_deng_ji
                    delta_filter: "binary_sensor.auto_space_toilet_64f220_occupancy"
                    delta_fan_volume: "sensor.livingroom_ikea_absolute_humidity"
                    delta_fan_mode: "input_select.delta_state"
                    delta_runm_time: "input_datetime.delta_runm_time"
                    delta_power_switch: "switch.adaptive_lighting_cw_auto_test"
                    # 外氣溫度 sensor.delta_erv_38432c_wai_qi_wen_du
                    delta_out_temperature: "sensor.outside_sensor_ii_outside_temperature"
                    # 回風溫度 sensor.delta_erv_38432c_shi_nei_hui_feng_wen_du
                    delta_in_temperature: "sensor.livingroom_ikea_temperatur"
                    # 濕度 sensor.aircube_ultra_9d32e4_humidity
                    ha_humidity_sensor: "sensor.livingroom_ikea_humidity"    
                    # PM2.5 sensor.aircube_ultra_9d32e4_pm2_5
                    ha_pm_25_sensor: "sensor.livingroom_ikea_pm2_5"    
                    # CO2 sensor.aircube_ultra_9d32e4_co2
                    ha_co2_sensor: "sensor.livingroom_ikea_co2"
                    # CH2O sensor.aircube_ultra_9d32e4_ch2o
                    ha_ch20_sensor: "sensor.livingroom_ikea_aqi_range"
                
                # #----------------------------------------------------------------
                text_sensor:
                  - platform: homeassistant      # 運轉時間 
                    id: delta_runm_time_state
                    entity_id: ${delta_runm_time}
                    on_value:
                      then:
                      - lvgl.label.update:
                          id: lvgl_widget_delta_runm_time
                          text: !lambda |-
                            int total_min = atoi(x.c_str());
                
                            int hh = total_min / 60;
                            int mm = total_min % 60;
                
                            char buf[16];
                            sprintf(buf, "%02d:%02d", hh, mm);
                            return std::string(buf);
                
                
                  - platform: homeassistant      # 外氣溫度 
                    id: delta_out_temperature_state
                    entity_id: ${delta_out_temperature}
                    on_value:
                      then:
                        - lvgl.label.update:
                            id: lvgl_widget_delta_out_temperature
                            text: !lambda |-
                              float val = atof(x.c_str());            // 將字串轉成浮點數
                              char buf[16];                            // 足夠放文字
                              sprintf(buf, "%.1f°C", val);            // 保留1位小數 + °C
                              return std::string(buf);                 // 回傳給 label
                
                  - platform: homeassistant      # 回風溫度
                    id: delta_in_temperature_state
                    entity_id: ${delta_in_temperature}
                    on_value:
                      then:
                        - lvgl.label.update:
                            id: lvgl_widget_delta_in_temperature
                            text: !lambda |-
                              float val = atof(x.c_str());            // 將字串轉成浮點數
                              char buf[16];                            // 足夠放文字
                              sprintf(buf, "%.1f°C", val);            // 保留1位小數 + °C
                              return std::string(buf);                 // 回傳給 label
                
                  - platform: homeassistant      # 濕度 
                    id: ha_humidity_sensor_state
                    entity_id: ${ha_humidity_sensor}
                    on_value:
                      then:
                        - lvgl.label.update:
                            id: lvgl_widget_ha_humidity_sensor
                            text: !lambda |-
                              float val = atof(x.c_str());            // 將字串轉成浮點數
                              char buf[16];                            // 足夠放文字
                              sprintf(buf, "%.1f%%", val);            // 保留0位小數 +%
                              return std::string(buf);                 // 回傳給 label              
                
                  - platform: homeassistant      # PM2.5 
                    id: ha_pm_25_sensor_state
                    entity_id: ${ha_pm_25_sensor}
                    on_value:
                      then:
                        - lvgl.label.update:
                            id: lvgl_widget_ha_pm_25_sensor
                            text: !lambda |-
                              float val = atof(x.c_str());            // 將字串轉成浮點數
                              char buf[16];                            // 足夠放文字
                              sprintf(buf, "%.0fμ³", val);            // 保留0位小數 +m³
                              return std::string(buf);                 // 回傳給 label   
                
                  - platform: homeassistant      # co2
                    id: ha_co2_sensor_state
                    entity_id: ${ha_co2_sensor}
                    on_value:
                      then:
                        - lvgl.label.update:
                            id: lvgl_widget_ha_co2_sensor
                            text: !lambda |-
                              float val = atof(x.c_str());            // 將字串轉成浮點數
                              char buf[16];                            // 足夠放文字
                              sprintf(buf, "%.0f", val);            // 保留0位小數 
                              return std::string(buf);                 // 回傳給 label     
                
                  - platform: homeassistant      # 甲醛
                    id: ha_ch20_sensor_state
                    entity_id: ${ha_ch20_sensor}
                    on_value:
                      then:
                        - lvgl.label.update:
                            id: lvgl_widget_ch20_sensor
                            text: !lambda |-
                              float val = atof(x.c_str());            // 將字串轉成浮點數
                              char buf[16];                            // 足夠放文字
                              sprintf(buf, "%.0f", val);            // 保留0位小數
                              return std::string(buf);                 // 回傳給 label
                
                  - platform: homeassistant      # 風量等級
                    id: delta_fan_volume_state
                    entity_id: ${delta_fan_volume}
                    on_value:
                      then:
                        - lvgl.label.update:
                            id: lvgl_widget_delta_fan_volume
                            text: !lambda |-
                              float val = atof(x.c_str());            // 將字串轉成浮點數
                              char buf[16];                            // 足夠放文字
                              sprintf(buf, "%.0f", val);            // 保留0位小數
                              return std::string(buf);                 // 回傳給 label              
                
                  # - platform: homeassistant
                  #   id: input_select_state
                  #   entity_id: input_select.delta_state
                  #   name: "Input Select State"
                
                binary_sensor:
                  - platform: homeassistant
                    id: delta_power_switch_state
                    name: "delta_power_switch_state"
                    entity_id: ${delta_power_switch}
                    trigger_on_initial_state: true
                    on_state:
                      then:
                        # button / widget 狀態
                        - lvgl.widget.update:
                            id: lvgl_widget_delta_power_switch_state
                            state:
                              checked: !lambda return x;
                
                        # label 文字 + 顏色
                        - if:
                            condition:
                              lambda: return x;
                            then:
                              - lvgl.label.update:
                                  id: lvgl_label_delta_power_switch_state
                                  text: "ON"
                                  text_color: 0x8b3333
                            else:
                              - lvgl.label.update:
                                  id: lvgl_label_delta_power_switch_state
                                  text: "OFF"
                                  text_color: 0x38761D
                              
                
                  - platform: homeassistant
                    id: delta_filter_state
                    name: "delta_filter_state"
                    entity_id: ${delta_filter}
                    trigger_on_initial_state: true
                    on_state:
                      then:
                        # label 文字 + 顏色
                        - if:
                            condition:
                              lambda: return x;
                            then:
                              - lvgl.label.update:
                                  id: lvgl_label_delta_filter_state
                                  text: "清潔濾網"
                                  text_color: 0x8b3333                    
                            else:
                              - lvgl.label.update:
                                  id: lvgl_label_delta_filter_state
                                  text: "濾網正常"
                                  text_color: 0x38761D        
                
                lvgl:
                  pages:  #定義多個頁面（類似畫面、Tab 或分頁）。  
                   - id: main_page_type_a   #這個頁面的 ID，稍後可以用來跳轉或引用。
                     bg_image_src: my_background_image  
                     widgets:   #宣告 "小部件" widgets
                        - obj:       ##小部件下建立"容器" obj 的定義繼承 pages 的定義
                            styles: regular_page # align: CENTER  #把這個容器在螢幕上置中對齊。
                            layout:  # 版面配置
                              type: flex  #使用 Flex 排列方式，讓內部 widgets 自動依照順序排列。
                              flex_flow: COLUMN_WRAP  #主軸為縱向（從上而下），若內容寬度超過，則會換行（wrap）。
                              flex_align_cross: CENTER #在交叉軸（水平方向）居中對齊每一列。
                            widgets:
                              - button:
                                  styles: button_A
                                  checkable: true
                                  id: lvgl_button_delta_power_switch_state   #反饋給lvgl的"客廳風扇"字體顏色變換
                                  widgets:
                                      - label:
                                          text: "\U000F0FE2" #ICON
                                          id: lvgl_widget_delta_power_switch_state
                                          text_font: icons_100
                                          align: TOP_LEFT
                                          text_color: 0x38761D
                                          checked:  # 選中狀態設定
                                            bg_color: 0x38761D  # 選中時背景顏色
                                            text_color: 0x8b3333  # 選中時文字顏色                           
                                          checkable: true  
                                      - label:
                                          id: lvgl_label_delta_power_switch_state
                                          align: TOP_RIGHT
                                          y: 12
                                          text_font: weather_forecast_50
                                          text: "--"
                                      - label:
                                          id: lvgl_widget_delta_runm_time
                                          y: 5
                                          text_font: font_apple_Heavy_medium
                                          align: BOTTOM_RIGHT
                                          text_color: 0xa4abb1
                                          long_mode: dot
                                          checkable: true
                                          text: "--"
                                  on_click:
                                      then:
                                      - homeassistant.service:
                                          service: switch.toggle
                                          data:
                                              entity_id: ${delta_power_switch}
                
                                #-------------------------------------------------------------------------------------
                                #-------------------------------------------------------------------------------------    
                              - dropdown:
                                  styles: button_C_H
                                  id: lv_dropdown_19
                                  align: RIGHT_MID
                                  text_font: font_apple_Heavy_medium
                                  symbol: "▼"
                                  options:
                                  - "Speed 1"
                                  - "Speed 2"
                                  - "Speed 3"
                                  selected_index: 2
                                  on_value:
                                    then:
                                      - homeassistant.action:
                                          action: input_select.select_option ### 實際上若entity 是select.xxx  這裡要改一下。 
                                          data:
                                            entity_id: ${delta_fan_mode}
                                            option: !lambda |-
                                                switch (x) {
                                                case 0: return "1";
                                                case 1: return "2";
                                                case 2: return "3";
                                                default: return "2";
                                                }
                                  #-------------------------------------------------------------------------------------
                                #-------------------------------------------------------------------------------------    
                              - button:   #### Button C
                                  styles: button_C_H
                                #   checkable: true
                                  # id: lvgl_button_balcony_switch_fan_state
                                  widgets:
                                    - label:   
                                        align: LEFT_MID
                                        text_font: font_Medium_big
                                        # id: lvgl_widget_balcony_switch_fan_state
                                        checkable: true
                                        x: 5
                                        text: "風量等級"
                                        text_color: 0xa4abb1
                                        checked:  # 選中狀態設定
                                          bg_color: 0xf2f2f2  # 選中時背景顏色
                                          text_color: 0x3182b7  # 選中時文字顏色                                
                                    - label:
                                        align: RIGHT_MID
                                        text_font: font_apple_Heavy_medium
                                        text_color: 0xa4abb1
                                        id: lvgl_widget_delta_fan_volume
                                        text: "--"
                
                              - button:   #### Button C
                                  styles: button_C_H
                                  widgets:
                                    - label:   
                                        align: LEFT_MID
                                        text_font: font_icon_small
                                        # id: lvgl_button_delta_filter_state
                                        checkable: true
                                        x: 5
                                        text: "\U000F0D43"
                                        text_color: 0x38761D
                                        checked:  # 選中狀態設定
                                          bg_color: 0xf2f2f2  # 選中時背景顏色
                                          text_color: 0x3182b7  # 選中時文字顏色                                
                                    - label:
                                        align: RIGHT_MID
                                        text_font: font_Medium_big
                                        text_color: 0x38761D
                                        id: lvgl_label_delta_filter_state
                                        checkable: true
                                        text: "--"
                                #-------------------------------------------------------------------------------------
                                # 首頁右半部6個entity code
                                #-------------------------------------------------------------------------------------
                              - button:
                                  styles: button_F     
                                  radius: 35
                                  bg_opa: 40%                                
                                  widgets:
                                    - label:   
                                        x: +5
                                        y: -12
                                        align: TOP_LEFT
                                        text_font: font_icon_small
                                        text: "\U000F0F9B" # 外氣溫度
                                        text_color: 0xfc9d21 
                                    - label:   
                                        x: -10
                                        y: -2                        
                                        id: lvgl_widget_delta_out_temperature
                                        align: RIGHT_MID
                                        text_font: font_apple_Heavy_medium
                                        text: "--"
                
                              - button:
                                  styles: button_F   
                                  radius: 35
                                  bg_opa: 40%                                             
                                  widgets:
                                    - label:   
                                        checkable: true
                                        x: +5
                                        y: -10
                                        align: TOP_LEFT
                                        text_font: font_icon_small
                                        text: "\U000F0F9C" # 回風溫度
                                        text_color: 0x3182b7 
                                    - label:   
                                        x: -10
                                        y: -2                        
                                        id: lvgl_widget_delta_in_temperature
                                        align: RIGHT_MID
                                        text_font: font_apple_Heavy_medium
                                        text: "--"
                
                              - button:
                                  styles: button_F    
                                  radius: 35
                                  bg_opa: 40%                                         
                                  widgets:
                                    - label:   
                                        checkable: true
                                        x: +5
                                        y: -10
                                        align: TOP_LEFT
                                        text_font: font_icon_small
                                        text: "\U000F058E" #濕度
                                        text_color: 0x3182b7 
                                    - label:   
                                        x: -10
                                        y: -2                        
                                        id: lvgl_widget_ha_humidity_sensor
                                        align: RIGHT_MID
                                        text_font: font_apple_Heavy_medium
                                        text: "--"
                
                              - button:
                                  styles: button_F   
                                  radius: 35
                                  bg_opa: 40%                                       
                                  widgets:
                                    - label:   
                                        checkable: true
                                        x: +5
                                        y: -10
                                        align: TOP_LEFT
                                        text_font: font_icon_small
                                        text: "\U000F0BAC" # PM2.5
                                        text_color: 0x38761D
                                    - label:   
                                        x: -10
                                        y: -2                        
                                        id: lvgl_widget_ha_pm_25_sensor
                                        align: RIGHT_MID
                                        text_font: font_apple_Heavy_medium
                                        text: "--"
                
                              - button:
                                  styles: button_F   
                                  radius: 35
                                  bg_opa: 40%                           
                                  widgets:
                                    - label:   
                                        checkable: true
                                        x: +5
                                        y: -10
                                        align: TOP_LEFT
                                        text_font: font_icon_small
                                        text: "\U000F07E4"  # CO2    
                                        text_color: 0x8b3333                         
                                    - label:   
                                        x: -10
                                        y: -2                        
                                        id: lvgl_widget_ha_co2_sensor
                                        align: RIGHT_MID
                                        text_font: font_apple_Heavy_medium
                                        text: "--"
                
                              - button:
                                  styles: button_F   
                                  radius: 35
                                  bg_opa: 40%    
                                  widgets:
                                    - label:   
                                        checkable: true
                                        x: +5
                                        y: -10
                                        align: TOP_LEFT
                                        text_font: font_icon_small
                                        text: "\U000F013B" # 甲醛icon
                                        text_color: 0x8b3333                         
                                    - label:   
                                        x: -10
                                        y: -2                        
                                        id: lvgl_widget_ch20_sensor
                                        align: RIGHT_MID  
                                        text_font: font_apple_Heavy_medium
                                        text: "--"
                

      
