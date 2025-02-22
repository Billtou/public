# 7.5in 紅黑白三色電子紙使用說明

## 使用前準備事項

![Mosquitto_broker](/e_ink_display/image/161812.png)

![Mosquitto_broker](/e_ink_display/image/161954.png)

### 必須搭配網友蔥大撰寫的中央氣象局整合插件才能正常使用。
- 先申請帳號
    https://opendata.cwa.gov.tw/index
- 進去這裡取得api授權碼
    https://opendata.cwa.gov.tw/user/authkey
- HACS 搜尋 Opendata CWA 並安裝它； HA 重開機 ； 設定 > 裝置與服務  > 新增整合 > 填入API密鑰以及 "鄉鎮區" 名稱並選擇所需的更新模式，默認daily，若選hourly相關的配套yaml內容也要一起改。

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

默認溫溼度以及體感度是抓中央氣象局資料，若想改為自家的戶外溫溼度可以修改e_ink_template_with_weather.yaml以下內容，改為自家的entity以及把 my_feels_like的內容取消註解，存檔然後快速重開機即可。默認氣象預報是以天為單位，可以改成以小時為單位，必須一併修改yaml檔案內容以及cwb集成改選hourly選項，等待30分鐘後可以看一下cwb的entity 預報部分以及自製的sensor.eink_sensors 是否已經都同步了，然後按下手動刷新即可。

![Mosquitto_broker](/e_ink_display/image/112708.png)

![Mosquitto_broker](/e_ink_display/image/112734.png)

    
    template:
      - trigger:
          - platform: time_pattern
            minutes: /1 # 剛開始設置可以改1分鐘，一切穩定後請改30分鐘update一次
          - platform: homeassistant
            event: start
        action:
          - delay: "00:01:00" #偏移1分鐘避免與CWB更新時間重疊
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
              # 搭配cwa集成使用 與下一行二擇一
              forecast: "{{ daily['weather.opencwb'].forecast }}" 
              # forecast: "{{ hourly['weather.opencwb'].forecast }}"  
          - sensor:
              - name: "eink_sensors"
                unique_id: 7d4a5b29-70c3-4fd0-9b8e-a79a3a3165d2
                state: >
                  {{ states('weather.opencwb') }}
                attributes:
                  # 若溫溼度與體感要改自家的，與下一行二擇一
                  today_temperature: >
                    {{ states('sensor.opencwb_temperature') | round }}°C
                  # {{states('sensor.outside_temperature') | round }}°C
                  today_humidity: >
                    {{ states('sensor.opencwb_humidity')}}
                  # {{states('sensor.outside_humidity')| round}}
                  today_feel_like: >
                    {{ states('sensor.opencwb_feels_like_temperature') | round }}°
                  # {{states('sensor.my_feels_like')| round}}°
                      today_uv_index: >
                        {{states('sensor.opencwb_uv_index')| round }}

                        ..
                        ..
                        ..
                        ..

## 接入HA
設備上電手機搜尋熱點並指定自家wifi與密碼HA會自動發現(若沒跳出指定自家wifi頁面，請手機切換到瀏覽器，輸入192.168.4.1即可)，接入wifi後HA會自動發現設備，直接點選 "設定" 按紐並指定區域即完成。

## 設定設備呼叫HA權限

![Mosquitto_broker](/e_ink_display/image/103348.png)

## HA的ESPHome entity選項說明
![Mosquitto_broker](/e_ink_display/image/150554.png)

![Mosquitto_broker](/e_ink_display/image/144320.png)

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
        |  on_cwb (與氣象署時間一致每天 05:30、6:30、11:30、17:30、23:30自動更新) **默認**
        |  one_hour (每小時更新一次)
        |  thirty_minutes (30分鐘一次)
        
    show last updated
        打開後下次更新時會在右上角顯示最近的更新時間。 


# 2024/12/13 Update
步驟
1.請更新cwb集成到最新版

2.選擇 onecall_hourly 或 onecall_daily 其中一個
    
3.由於新版cwb已不提供紫外線指數，請依以下步驟替換資訊源。

- A. 安裝OpenUV 集成，註冊此網頁 https://www.openuv.io/ 點選 "GET FREE API KEY OR SING IN" (默認用google帳號註冊，完成會看到以下畫面，copy API Key 備用)
  
- ![Mosquitto_broker](/e_ink_display/image/uv_api114139.png)
  
- B. 點選此網頁在HA安裝OpenUV整合 https://my.home-assistant.io/redirect/config_flow_start?domain=openuv
  
- C. 輸入API金鑰，確定一下經緯度以及海拔後按傳送。
  
- D. 修改eink_sensors 這個yaml檔的內容把原先的 {{states('sensor.opencwb_uv_index')| round }} 替換為以下內容(詳細見上方e_ink_template_with_weather.yaml 第65行內容)
  
        {{states('sensor.openuv_current_uv_index')| round }}


- E.重開機或重新載入YAML設定中的 "模板實體"，在下次Update畫面時就會把UV數據顯示出來。
      
# 2024/12/14 Update    
- 更新到最新版方法: 進入HA裡面的HACS 找到 Opendata CWA > 右上三點 > Download 這樣之前的日期錯誤就會修復
- 由於中央氣象局api改版，部分數據未放進去導致一週天氣與報請暫時全部改成以小時顯示。
- ESPHome裡面 Forcate Type deily_High_low 目前會不顯示最低溫度，因為中央氣象局API改版莫名的把這個資料取消了，我會反映請他家回來希望他會聽我的....

# 2024/12/16 Update
- 中央氣象局API entity 增加了地區名稱，導致氣象面板抓取的entity異常，緊急修復如下
- 有設定以天為預報基礎的都暫時改為以小時方式顯示。
- OpenCWA 整合重新安裝或版更一下。
- 原來的weather.opencwb entity b改a且後綴多了區域名稱例如南屯區如右 "_nan_tun_qu"
- 請修改yaml檔案，用搜尋與取代的方式把 weather.opencwb  >>  weather.opencwa_XXX_XXX_XXX
- 把sensor.opencwb_temperature 改成自家的 entity 例如 sensor.opencwa_XXX_XXX_XXX_temperature
- 手動更新看看就知道是否正確了。 以上。
  
# 2024/12/17 Update
- OpenCWA 整合版更一下或重新安裝(OpenCWA重新手動更新HACS>Opendata CWA>右上三點>redownload)。
- 參考新上傳的 e_ink_template_with_weather.yaml 並依據12/16 Update修改為自家的ID名稱。
- 把 yaml 檔案中 LOCATION_NAME 替換成自家的entity 後綴名稱即可。
- 手動更新看看就知道是否正確了。 以上。

# 2024/12/18 Update  
- 功能沒變更僅將e_ink_template_with_weather.yaml 的語法修改成新版本的結構。

# 2025/2/10 Update
- 更新固件版本為2025.01.25c為中文顯示搭配中文版的e_ink_template_with_weather_中文_2025_10_25.yaml 使用
- 取消esphome後台自動更新頁面時段選擇，改為在HA裡面透過自訂義自動化自由指定。
- 增加focast mode 計有 daily_high_low、deily_feel_rain、deily_feel_humidity、hourly_feel_rain and hourly_feel_humidity 五種選擇。
- 調整程序碼提升執行效率。
