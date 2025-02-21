    includes:
      - "cm1106.h"
      - "winsen_ze08.h"
      # - "pm2005.h"
      - "pm2105.h"

    custom_component:
      - lambda: |-
          auto ze08 = new WinsenZE08Sensor(id(uart_ze08), id(ze08_ch2o));
          App.register_component(ze08);
          return {ze08};
    
    sensor:    
    # Winsen CH2O SENSOR
      - platform: template
        name: "CH2O"
        id: ze08_ch2o
        unit_of_measurement: ppb
        accuracy_decimals: 0
        icon: mdi:chemical-weapon
