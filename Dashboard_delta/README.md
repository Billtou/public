# Deshboard delta 使用說明
#### ESPHome LVGL 說明請見Dashboard one
## delta熱交換 yaml檔案結構說明
* 請在 HA 的 esphome 資料夾內建立以下檔案結構
esphome
    | air-panel.yaml
    | <air_penel>
          | my_main_page_air.yaml 
          | my_main_page_delta.yaml
          | my_main_page_light.yaml
          | my_main_page_livingroom.yaml
          | my_top_layer.yaml
    | <publice>
          |
          | <background>
              | image.yaml
              | background_1.png
              | background_2.png
              | background_3.png
              | boot_logo.png
              | ha_logo.svg
          | <basic>
              | basic_and_touchscreen.yaml
              | setup_page.yaml
          | <fonts>
              | fonts.yaml
              | GenJyuuGothic-Bold.ttf
              | GenJyuuGothic-Medium.ttf
              | materialdesignicons-webfont.ttf
              | SFProDisplay-BoldItalic.ttf
              | SFProDisplay-HeavyItalic.ttf
              | SFProDisplay-RegularItalic.ttf
          | <style>
              | my_style.yaml
          | <theme>
              | my_theme.yaml

*  my_main_page_delta.yaml 主控頁面說明
    
    substitutions:
      name: air-panel
      friendly_name: Air Panel
      device_description: "Panlee ZX3D95CE01S-TR-4848 480*480 Smart Screen"
      project_name: "Panlee.ZX3D95CE01S-TR-4848"
      project_version: "1.0"
    
    esphome:
      name: "${name}"
      friendly_name: "${friendly_name}"
      project:
        name: "${project_name}"
        version: "${project_version}"
      min_version: 2024.11.0
      name_add_mac_suffix: false
      platformio_options:
        board_build.flash_mode: dio
        board_build.arduino.memory_type: qio_opi
        build_flags: "-DBOARD_HAS_PSRAM"
        board_upload.maximum_ram_size: 524288
    
    esp32:
      board: esp32-s3-devkitc-1
      flash_size: 16MB
      framework:
        type: esp-idf
        version: recommended
        sdkconfig_options:
          CONFIG_ESP32S3_DEFAULT_CPU_FREQ_240: y
          CONFIG_ESP32S3_DATA_CACHE_64KB: y
          CONFIG_SPIRAM_FETCH_INSTRUCTIONS: y
          CONFIG_SPIRAM_RODATA: y
    
    # --------------------------------------
    # -            背景圖 可自行修改對應的圖檔
    # --------------------------------------            
    image: !include { file: project/touch_panel/public/background/image.yaml }
    # --------------------------------------
    # -            以下是觸控螢幕內容 UI                     -
    # --------------------------------------
    lvgl:
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
      # -   # 小部件預設參數  -air_panel$0
      # -------------------------------------------------
      theme: !include { file: project/touch_panel/public/theme/my_theme.yaml }  
      # -------------------------------------------------
      # -   # 風格預設   -
      # -------------------------------------------------
      style_definitions: !include { file: project/touch_panel/public/style/my_style.yaml }    
      # -------------------------------------------------
      # -   頁腳#永遠放在最上層 首層 導航頁腳畫面   -
      # -------------------------------------------------
      top_layer: !include { file: project/touch_panel/air_penel/my_top_layer.yaml }        
    
    packages:
      fonts_in: !include project/touch_panel/public/fonts/fonts.yaml
      basic_in: !include project/touch_panel/public/basic/basic_and_touchscreen.yaml
      setup_page_in: !include project/touch_panel/public/basic/setup_page.yaml
      #-------------------------以下為自己定義的page頁面--------
      main_page_type_a_in: !include project/touch_panel/air_penel/my_main_page_delta.yaml
      main_page_type_b_in: !include project/touch_panel/air_penel/my_main_page_livingroom.yaml
      main_page_type_c_in: !include project/touch_panel/air_penel/my_main_page_light.yaml
      main_page_type_d_in: !include project/touch_panel/air_penel/my_main_page_air.yaml    
  
