# AUTOMATE PM-3F (單路3相,測總入戶含台電計價公式)
![Mosquitto_broker](/PM_3F/image/3F-2-1.JPG)
# 接入自家網路(WIFI)
* 上電稍待1~2分鐘手機靠近設備找wifi熱點 automate-pm-3F-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼，HA會自動找到設備。
# 接入自家網路(網線)
* 上電插上網線即可。
# 接線說明
## 三相三線主機接 3 根線分別對應 R、S、T 端子，與三相四線少一條 N 線的差別。
* 主機供電100~240V 交流寬電壓(建議一定要用電表量過)，接線順序為 供電後接入CT端子先插上，最後最後才勾上CT卡扣。 切記切記。
![Mosquitto_broker](/PM_3F/image/3F-2-.JPG)

### 本產品有自動存儲耗電量的功能，在HA的entity有清零的button後期自行透過HA自動化歸零即可。
### 以下範例為計算電費單價的yaml，可以自行修改為想要的條件。

    
    
    template:
      - sensor:
          - name: realtime_hour_cost  #建立一個及時計算每小時電費的sensor
            unique_id: 239010d0-fd00-4615-ab05-b8964563370e
            state: "{{((states.sensor.power_sum.state|float)/1000 *(states.sensor.count_kwh_cost.state|float))|round(1)}}"
            unit_of_measurement: "$"
    
          - name: count_kwh_cost   # 建立台電兩個月計算一次的電費收費的一度電單價
            unique_id: 2ca5f2b9-edb4-4b2a-b1aa-50607618df7c
            state: >
              {% set energy = states("sensor.taipower_energy") | float(0) %}
              {% set is_summer = now().month in [6,7,8,9] %}
    
              {% if energy < 120 %}
                {{ 1.68 }}
              {% elif energy < 330 %}
                {{ 2.45 if is_summer else 2.16 }}
              {% elif energy < 500 %}
                {{ 3.7 if is_summer else 3.03 }}
              {% elif energy < 700 %}
                {{ 5.04 if is_summer else 4.14 }}
              {% elif energy < 1000 %}
                {{ 6.24 if is_summer else 5.07 }}
              {% else %}
                {{ 8.46 if is_summer else 6.63 }}
              {% endif %}
            unit_of_measurement: "TWD/kWh"
            device_class: monetary
    
          - name: count_kwh_cost_storefront_3_bata  # 三段式時間電價每度用電成本
            unique_id: 40d73652-9231-4af6-85d9-d8c458dfc46e
            state: >
              {% set now_month = now().month %}
              {% set now_weekday = now().isoweekday() %}
              {% set now_hour = now().hour %}
              {% set is_summer = now_month in [6,7,8,9] %}
              {% set is_weekday = now_weekday in [1,2,3,4,5] %}
              
              {% if is_summer %}
                {% if is_weekday %}
                  {% if now_hour < 8 %} 1.96
                  {% elif now_hour < 16 %} 4.54
                  {% elif now_hour < 22 %} 6.92
                  {% else %} 4.54
                  {% endif %}
                {% else %}
                  1.96
                {% endif %}
              {% else %}
                {% if is_weekday %}
                  {% if now_hour < 6 %} 1.89
                  {% elif now_hour < 11 %} 4.43
                  {% elif now_hour < 14 %} 1.89
                  {% else %} 4.33
                  {% endif %}
                {% else %}
                  1.89
                {% endif %}
              {% endif %}
            unit_of_measurement: "TWD/kWh"
            device_class: monetary
    
          - name: count_kwh_cost_storefront_2_bata # 二段式時間電價每度用電成本
            unique_id: 6f06b6bf-8434-4812-8cd4-464296ed7e9b
            state: >
              {% set now_month = now().month %}
              {% set now_weekday = now().isoweekday() %}
              {% set now_hour = now().hour %}
              {% set is_summer = now_month in [6,7,8,9] %}
              {% set is_weekday = now_weekday in [1,2,3,4,5] %}
    
              {% if is_summer %}
                {% if is_weekday %}
                  {% if now_hour < 9 %} 1.96
                  {% else %} 5.01
                  {% endif %}
                {% else %}
                  1.96
                {% endif %}
              {% else %}
                {% if is_weekday %}
                  {% if now_hour < 6 %} 1.89
                  {% elif now_hour < 11 %} 4.78
                  {% elif now_hour < 14 %} 1.89
                  {% else %} 4.78
                  {% endif %}
                {% else %}
                  1.89
                {% endif %}
              {% endif %}
            unit_of_measurement: "TWD/kWh"
            device_class: monetary
