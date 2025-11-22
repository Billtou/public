# 2025-11-22 Update 3.1
  - 1.升級ESPHome v2025.10.0
  - 2.增加 Firmware Info
# 2025-11-18 Update 3.0
  - 1.新增持續按壓10秒重開機
  - 2.斷網30S重啟。
# 2025-07-20 Update 2.0
  - 1.接傳統開關訊號delayed on/off 100ms (避免電子雜訊誤判開關電燈)
# 2024/10/28 Update 1.1
  - 1.新增可指定開機relay on or off by select
  - 2.新增解偶斷電記憶功能
  - 3.timeout 設為 0s 避免裝潢時期現場沒有wifi設備會15分鐘重置的困擾
  - 4.接傳統開關訊號delayed on/off 50ms (避免電子雜訊誤判開關電燈)
# 2024/12/22 Update 1.x.x
  - 新增 d 與 n 版本，可以分別用在不同場景的需求
# 檔案說明分1路與兩路確定好即可
  - module-1e-ota-1.0d.uf2   1路具耗電模組(適用裝潢期，若15分鐘沒找到WIFI "不會" 重開機設備)
  - module-1e-ota-1.0n.uf2   1路具耗電模組(適用使用期，若15分鐘沒找到WIFI "會" 重開機設備)
  - module-2e-ota-1.1d.uf2   2路具耗電模組(適用裝潢期，若15分鐘沒找到WIFI "不會" 重開機設備)
  - module-2e-ota-1.1n.uf2   2路具耗電模組(適用使用期，若15分鐘沒找到WIFI "會" 重開機設備)
# OTA 刷機方法 刷機完會重開，若遲遲沒連線斷電在給電即可
- ![Mosquitto_broker](/wall_switch/image/ota.png)  
