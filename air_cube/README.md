# Air Cube 使用說明
## 硬體規格 
  - Wifi Module
    ESPRESSIF ESP32-WROOM
  - CO2 Sensor
    四方光電 CM1106
  - PM2.5 Sensor
    四方光電 PM2005 or PM2105
  - Temperature and Humidity sensor
    TEXAS HDC1080
  - TVOC/eCO2 sensor
    SENSIRION SGP30

## 建議接入HA方式 
  - 通電wifi燈閃爍，手機靠近本設備找wifi熱點 air-cube-xxxxxx，指定自家wifi名稱與密碼(若沒跳出輸入自家wifi畫面，手機打開瀏覽器輸入192.168.4.1即可)，wifi指示燈常滅即完成，HA會自動找到設備。(要稍微等待一下wifi熱點才會出現)
  
  - ** 建議正式使用前先進入HA的裝置與服務 > ESPHome > Air Cube-xxxx > 1個裝置 > 右上角筆的圖案 > 將名稱改為有意義的名稱例如Livingroom Cube > 確定同意修改實體名稱 > 完成，提高實體名稱辨識度，2台以上實體名稱不容易混淆 **
  
  - ** 若想重置實體名稱，先記住設備IP > 刪除設備 > 新增設備 > 填入剛剛紀錄的設備IP > 完成。 > 重複上一個步驟即可 ** 

## 面板LED燈 
  - wifi 狀態燈 斷網閃爍 連線常滅
  - CO2指數超過臨界值(Threshold Co2)常亮 低於 常滅
  - pm2.5指數超過臨界值(Threshold PM2.5)常亮 低於 常滅
  - TVOC/甲醛燈指數超過臨界值(Threshold TVOC) or (Threshold HO2C)常亮 低於 常滅
  - LED Sleep Mode = 超標不亮燈。 
