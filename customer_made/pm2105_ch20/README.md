    uart:
    - id: cm1106_uart
      rx_pin: 16
      tx_pin: 17
      baud_rate: 9600
    - id: uart_ze08
      tx_pin: 5
      rx_pin: 18
      baud_rate: 9600
    
    i2c:
      - id: pm25_bus
        sda: 23
        scl: 22
        scan: true
      - id: th_bus
        sda: 19
        scl: 21
        scan: true
    
    
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
