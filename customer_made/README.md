# 客製化產品yaml保留檔

# #--eth------------------------
# ethernet:
#   type: W5500
#   clk_pin: GPIO14
#   mosi_pin: GPIO13
#   miso_pin: GPIO12
#   cs_pin: GPIO15
#   interrupt_pin: GPIO4
#   clock_speed: 40Mhz

# # text_sensor:
# #   - platform: ethernet_info
# #     ip_address:
# #       name: "Ethernet IP Address"
# #       icon: mdi:ethernet
# #     mac_address:
# #       name: Ethernet MAC
# #       icon: mdi:identifier

# ota:
#   - platform: esphome
#     id: ota_esphome
#   - platform: web_server
#     id: web_server_managed  

# web_server:
#   port: 80
#   version: 3
