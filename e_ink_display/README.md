# 7.5in 紅黑白三色電子紙使用說明

## 使用前準備事項
### 必須搭配網友撰寫的中央氣象局擴充插件才能正常使用。
先申請帳號
https://opendata.cwa.gov.tw/index
進去這裡取得api授權碼
https://opendata.cwa.gov.tw/user/authkey
HACS 搜尋 Opendata CWA 並安裝它； HA 重開機 ； 設定 > 裝置與服務  > 新增整合 > 填入API密鑰以及鄉鎮區名稱並選擇所需的更新模式，默認daily，若選hourly相關的配套yaml內容也要一起改。

![Mosquitto_broker](/e_ink_display/124729.png)

## 手動建立模板實體 
可以放在HA的configuration.yaml裡面，建議用packages方式管理手動建立模板實體的方式，方法如下: 在config(或homeassistant)資料夾中建立一個packages資料夾，並在configuration.yaml內增加以下代碼後重開機即可。

    homeassistant:
      packages: !include_dir_named packages

若是放在configuration.yaml裡面可以把整個e_ink_template_with_weather.yaml 內容貼入即可，若是用packages方式管理就把該檔案copy到此資料夾裡面然後都HA需重開機。注意若自家HA已經有以下這段程序碼的話請自行刪除或註解掉即可。

      - sensor:
          - platform: time_date
            display_options:
              - "time"
              - "date"
              - "date_time"
              - "date_time_utc"
              - "date_time_iso"
              - "time_date"
              - "time_utc"

默認溫溼度以及體感度是抓中央氣象局資料，若想改為自家的戶外溫溼度可以修改e_ink_template_with_weather.yaml以下內容，改為自家的entity以及把 my_feels_like的內容取消註解，存檔然後快速重開機即可。

          ...
          ...
          today_temperature: >
            {{states('sensor.outside_multi_sensor_bme280_temperature') | round }}°C    
          today_humidity: >
             {{states('sensor.outside_multi_sensor_bme280_humidity')| round}}
          today_feel_like: >
            {{states('sensor.my_feels_like')| round}}°          
          ...
          ...


         ...
         ...
          # - name: my_feels_like
          #   unique_id: 5e0e6fc9-d463-4f5e-9cac-1e9f0a57ee8d
          #   state: >
          #     {% set T = ((states.sensor.outside_multi_sensor_bme280_temperature.state|float)*1.8)+32 %}
          #     {% set RH = states.sensor.outside_multi_sensor_bme280_humidity.state|float %}
          #     {% set STEADMAN_HI = 0.5 * (T + 61.0 + ((T-68.0)*1.2) + (RH*0.094)) %}
          #     {% if STEADMAN_HI >= 80 %}
          #       {% set ROTHFUSZ_HI = -42.379 + 2.04901523*T + 10.14333127*RH - 0.22475541*T*RH - 0.00683783*T*T - 0.05481717*RH*RH + 0.00122874*T*T*RH + 0.00085282*T*RH*RH - 0.00000199*T*T*RH*RH %}
          #       {% set HI = ROTHFUSZ_HI %}
          #       {% if RH < 13 and 80 < T < 112 %}
          #         {% set ADJUSTMENT = ((13-RH)/4)*((17-(T-95)|abs)/17)**0.5 %}
          #         {% set HI = HI - ADJUSTMENT %}
          #       {% elif RH > 85 and 80 < T < 87 %}
          #         {% set ADJUSTMENT = ((RH-85)/10) * ((87-T)/5) %}
          #         {% set HI = HI + ADJUSTMENT %}
          #       {% endif %}
          #     {% else %}
          #       {% set HI = STEADMAN_HI %}
          #     {% endif %}
          #     {% set HI_C = (HI-32)/1.8 %}
          #     {{- HI_C|round(1) -}}


## 接入HA
設備上電手機搜尋熱點並指定自家wifi與密碼HA會自動發現，直接點選 "設定" 按紐並指定區域即完成。
         
## HA的ESPHome entity選項說明
![Mosquitto_broker](/e_ink_display/133557.png)

默認一小時更新一次，會在整點偏移2分鐘更新(預計氣象局會整點更新，自製模板會偏移一分鐘擷取氣象局資訊，所以面板更新設定偏移2分鐘update)

    Manual Refresh
        | 立即手動更新按紐
    
    
    Options Windows
        |  nothing (不顯示額外訊息) **默認**    
        |  sun_and_moon  (日出日落時間以及月像)
        |  half_hour (改每半小時更新一次並顯示更新時間)
    
        
    Weekly Forcast Mode
        |  high_low (當日最高、低溫預測) **默認**
        |  high_rain (當日最高溫以及下雨機率)
        |  low_rain (當日最低溫以及下雨機率)

    show last updated
        打開後下次更新時會在右上角顯示最近的更新時間。

