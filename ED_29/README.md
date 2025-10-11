# 2.9" 電子紙箱對應的藍圖簡易使用說明
- 新版本請直接用以下對應產品的藍圖做自動化同步數據即可

![081733](/ED_29/image/enger_12.JPG)


## 簡易日曆與氣象預報
[![Import Blueprint](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/blueprint_import/?blueprint_url=https://raw.githubusercontent.com/Billtou/public/blob/main/BluePrint/automate-es-29-forecast.yaml)

![081733](/ED_29/image/B8AD097F.jpg)



## 簡易傳感器顯示螢幕  

[![Import Blueprint](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/blueprint_import/?blueprint_url=https://github.com/Billtou/public/blob/main/BluePrint/automate-ed-29-mult_sensor.yaml)

![081733](/ED_29/image/834866CA.jpg)



## 能耗顯示螢幕 

[![Import Blueprint](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/blueprint_import/?blueprint_url=https://github.com/Billtou/public/blob/main/BluePrint/automate-ed-29-energy.yaml)

![081733](/ED_29/image/enger_1.jpg)

能耗顯示需要製作相關的實體，請把 my_energy.yaml 拷貝到HA裡面 \config\packages\ 裡面。
若原本沒有 \packages\ 資料夾，請自行建立，並在configuration.yaml 放入以下代碼。
    
    homeassistant:
      packages: !include_dir_named packages
      customize_domain:
        automation:
          initial_state: true
      allowlist_external_dirs:
        - /config
