# 2.9" 電子紙範本

## 簡易日曆與氣象預報
[![Import Blueprint](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/blueprint_import/?blueprint_url=https://raw.githubusercontent.com/Billtou/public/blob/main/BluePrint/automate-es-29-forecast.yaml)

![081733](/ED_29/image/B8AD097F.jpg)



## 簡易傳感器顯示螢幕  

[![Import Blueprint](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/blueprint_import/?blueprint_url=https://raw.githubusercontent.com/Billtou/public/blob/main/BluePrint/automate-ed-29-mult_sensor.yaml)

![081733](/ED_29/image/834866CA.jpg)



## 能耗顯示螢幕 

[![Import Blueprint](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/blueprint_import/?blueprint_url=https://raw.githubusercontent.com/Billtou/public/blob/main/BluePrint/automate-ed-29-energy.yaml)

![081733](/ED_29/image/enger_1.jpg)

    
    ---
    #-----------使用方法-------------------
    #  將下列的entity id 改為自己的id
    #
    #  sensor.entrance_powermeter_power_monitor_energy   >   改成自家的總耗電 kWh ID
    #  sensor.entrance_powermeter_power_monitor_power.state  >  改成自家的總耗瓦數 W ID
    
    utility_meter:
      # 每天0點歸零的當天用電度數
      today_energy_use:
        unique_id: f1be1584-4687-4208-872c-ebbce555f6de
        name: "Today Energy Use"
        source: sensor.entrance_powermeter_power_monitor_energy # << (這個entity要改成自己的ID)
        cycle: daily
    
    template:
      - sensor:
          # 複製來自一個會自動歸零的入戶能耗實體ID
          - name: "Total Energy Use"
            unique_id: 670ab181-e219-4b37-ae96-469415696451
            unit_of_measurement: "kWh"
            state: "{{ states('sensor.entrance_powermeter_power_monitor_energy') }}" # << (這個entity要改成自己的ID)
    
          #建立一個及時計算每小時電費的sensor
          - name: "Realtime Hour Cost"
            unique_id: 239010d0-fd00-4615-ab05-b8964563370e
            state: "{{((states.sensor.entrance_powermeter_power_monitor_power.state|float)/1000 *(states.sensor.count_kwh_cost.state|float))|round(1)}}"
            unit_of_measurement: "$"
    
          # 今天的用電成本
          - name: "Today Energy Cost"
            unique_id: a235bfb0-ec6a-4005-b030-293a00528d65
            unit_of_measurement: "NTD"
            state: >
              {% set energy = states('sensor.today_energy_use') | float(0) %}
              {% set price = states('sensor.count_kwh_cost') | float(0) %}
              {{ (energy * price) | round(2) }}
    
          # 台電累進計費的累計電費
          - name: "Total Energy Cost"
            unique_id: 5aaa1106-5124-40df-bd9e-d632f7933f8c
            state: >
              {% set kwh = states("sensor.total_energy_use") | float(0) %}
              {% set is_summer = now().month in [6,7,8,9] %}
              {% set summer_rate = [1.68, 2.45, 3.70, 5.04, 6.24, 8.46] %}
              {% set winter_rate = [1.68, 2.16, 3.03, 4.14, 5.07, 6.63] %}
              {% set rate = summer_rate if is_summer else winter_rate %}
              {% set tier_kwh = [120, 210, 170, 200, 300] %}  {# 各階段度數: 120, 330-120=210, 500-330=170, 700-500=200, 1000-700=300 #}
              {% set remain = kwh %}
              {% set cost = 0 %}
              {% for i in range(5) %}
                {% if remain > tier_kwh[i] %}
                  {% set cost = cost + tier_kwh[i] * rate[i] %}
                  {% set remain = remain - tier_kwh[i] %}
                {% else %}
                  {% set cost = cost + remain * rate[i] %}
                  {% set remain = 0 %}
                  {% break %}
                {% endif %}
              {% endfor %}
              {% if remain > 0 %}
                {% set cost = cost + remain * rate[5] %}
              {% endif %}
              {{ cost | round(2) }}
            unit_of_measurement: "NTD"
            device_class: monetary
    
          # 建立台電兩個月計算一次的電費收費的一度電單價(一般家庭使用)
          - name: "Count Kwh Cost"
            unique_id: 2ca5f2b9-edb4-4b2a-b1aa-50607618df7c
            state: >
              {% set energy = states("sensor.total_energy_use") | float(0) %}
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
            unit_of_measurement: "NTD/kWh"
            device_class: monetary
    
          # 三段式時間電價每度用電成本
          - name: "count_kwh_cost_storefront_3"
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
    
          # 二段式時間電價每度用電成本
          - name: "count_kwh_cost_storefront_2"
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
    
    input_number:
      yesterday_energy_use:
        name: "Yesterday Energy Use"
        min: 0
        max: 10000
        step: 1
        unit_of_measurement: "kWh"
    
      yesterday_energy_cost:
        name: "Yesterday Energy Cost"
        min: 0
        max: 10000
        step: 1
        unit_of_measurement: "NTD"
    
    automation:
      - alias: "每日儲存用電kw"
        id: save_kw_score_daily
        trigger:
          - trigger: time
            at: "23:59:55"
        actions:
          - action: input_number.set_value
            target: { entity_id: input_number.yesterday_energy_use }
            data:
              {
                value: "{{ states('sensor.today_energy_use') | float(0)  | round(2)}}",
              }
          - action: input_number.set_value
            target: { entity_id: input_number.yesterday_energy_cost }
            data:
              {
                value: "{{ (states('sensor.today_energy_use') | float(0) * states('sensor.count_kwh_cost') | float(0))|round(1)}}",
              }
