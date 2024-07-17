# 7.5in 紅黑白三色電子紙使用說明

## 使用前準備事項

![Mosquitto_broker](/e_ink_display/image/161812.png)

![Mosquitto_broker](/e_ink_display/image/161954.png)

### 必須搭配網友撰寫的中央氣象局擴充插件才能正常使用。
先申請帳號
https://opendata.cwa.gov.tw/index
進去這裡取得api授權碼
https://opendata.cwa.gov.tw/user/authkey
HACS 搜尋 Opendata CWA 並安裝它； HA 重開機 ； 設定 > 裝置與服務  > 新增整合 > 填入API密鑰以及鄉鎮區名稱並選擇所需的更新模式，默認daily，若選hourly相關的配套yaml內容也要一起改。

![Mosquitto_broker](/e_ink_display/image/142722.png)

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
    
    template:
      - trigger:
          - platform: time_pattern
            minutes: /30
          - platform: homeassistant
            event: start
        action:
          - delay: "00:01:00"
          - service: weather.get_forecasts
            data:
              type: daily      # 搭配cwa集成使用 與下一行二擇一
              # type: hourly   # 搭配cwa集成使用 與上一行二擇一
            target:
              entity_id: weather.opencwb
            response_variable: daily  # 搭配cwa集成使用 與下一行二擇一
            # response_variable: hourly  # 搭配cwa集成使用 與上一行二擇一
    
        sensor:
          - name: Weather Interval
            unique_id: 08128e00-6b12-443a-9e9c-ad3f57ec2da9
            state: "{{ states('weather.opencwb') }}"
            attributes:
              temperature: "{{ state_attr('weather.opencwb', 'temperature') }}"
              templow: "{{state_attr('weather.opencwb', 'templow')}}"
              dew_point: "{{ state_attr('weather.opencwb', 'dew_point') }}"
              temperature_unit: "{{ state_attr('weather.opencwb', 'temperature_unit') }}"
              humidity: "{{ state_attr('weather.opencwb', 'humidity') }}"
              cloud_coverage: "{{ state_attr('weather.opencwb', 'cloud_coverage') }}"
              pressure: "{{ state_attr('weather.opencwb', 'pressure') }}"
              pressure_unit: "{{ state_attr('weather.opencwb', 'pressure_unit') }}"
              wind_bearing: "{{ state_attr('weather.opencwb', 'wind_bearing') }}"
              wind_speed: "{{ state_attr('weather.opencwb', 'wind_speed') }}"
              wind_speed_unit: "{{ state_attr('weather.opencwb', 'wind_speed_unit') }}"
              visibility_unit: "{{ state_attr('weather.opencwb', 'visibility_unit') }}"
              precipitation_unit: "{{ state_attr('weather.opencwb', 'precipitation_unit') }}"
              forecast: "{{ daily['weather.opencwb'].forecast }}"
              # forecast: "{{ hourly['weather.opencwb'].forecast }}"
      - sensor:
          - name: "eink_sensors"
            unique_id: 7d4a5b29-70c3-4fd0-9b8e-a79a3a3165d2
            state: >
              {{ states('weather.opencwb') }}
            attributes:
              today_temperature: >
                {{ states('sensor.opencwb_temperature') | round }}°C  # 若溫溼度與體感要改自家的，與下一行二擇一
              # {{states('sensor.outside_temperature') | round }}°C   # 若溫溼度與體感要改自家的，與上一行二擇一
              today_humidity: >
                {{ states('sensor.opencwb_humidity')}}                # 若溫溼度與體感要改自家的，與下一行二擇一
              # {{states('sensor.outside_humidity')| round}}          # 若溫溼度與體感要改自家的，與上一行二擇一
              today_feel_like: >
                {{ states('sensor.opencwb_feels_like_temperature') | round }}°    # 若溫溼度與體感要改自家的，與下一行二擇一
              # {{states('sensor.my_feels_like')| round}}°                        # 若溫溼度與體感要改自家的，與上一行二擇一
              today_uv_index: >
                {{states('sensor.opencwb_uv_index')| round }}

## 接入HA
設備上電手機搜尋熱點並指定自家wifi與密碼HA會自動發現，直接點選 "設定" 按紐並指定區域即完成。
         
## HA的ESPHome entity選項說明
![Mosquitto_broker](/e_ink_display/image/150554.png)

默認更新時間同氣象署，會偏移5分鐘更新(流程為氣象局更新，HA的自製預報entity每30分鐘+60秒更新，故電子紙偏移5分鐘update)

    Manual Refresh
        | 立即手動更新按紐
    
    Sidebar Type
        |  nothing (不顯示額外訊息) **默認**    
        |  sun_and_moon  (日出日落時間以及月像)
        |  time (顯示更新時間)
    
    Forcast Type
        |  daily_high_low (搭配daily集成，當日最高、低溫預測) **默認**
        |  daily_high_rain (搭配daily集成，當日最高溫以及下雨機率)
        |  hourly (搭配hourly集成分小時最高溫以及下雨機率)

    Refash Time
        |  on_cwb (與氣象署時間一致每天 05:30、11:30、17:30、23:30自動更新) **默認**
        |  one_hour (每小時更新一次)
        |  thirty_minutes (30分鐘一次)
        
    show last updated
        打開後下次更新時會在右上角顯示最近的更新時間。 

