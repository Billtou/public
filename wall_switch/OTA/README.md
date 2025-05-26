# 2025/5/26 Update 說明
  - 2.0版本
  - 新增按壓任一鍵超過5秒即會重置wifi功能 "回到出廠值"
  - 具斷線自動重啟功能
  - 若裝潢期間現場沒有 wifi 或 HA 請保持在 "出廠值" 就不會啟動重啟自救模式 (電燈會定期閃一下或關閉的困擾)
  - 當第一次引導接入wifi後靜待超過10秒重新上電才會寫入wifi SSID 與密碼
  - 更新時請注意有兩個版本，看一下 HA 的 entity 有 CUB CHP 的差別。
    
# 出貨固件為 "使用期" 版本，若裝潢期(現場沒wif請預先刷 "裝潢期" 完再安裝到現場，待入住後再刷回 "使用期"即可)
# 2024/10/28 Update 1.2.1
  - Update內容
  - 1.新增可指定開機relay on or off by select
  - 2.新增wifi狀態燈與綠色led並存且具斷電記憶功能
  - 3.新增解偶斷電記憶功能
  - 4.esphome entity type 調理
  - 5.timeout 設為 0s 避免裝潢時期現場沒有wifi設備會15分鐘重置的困擾
# 2024/12/22 Update 1.2.x
  - 新增 d 與 n 版本，可以分別用在不同場景的需求
# OTA 檔案說明 請特別注意別搞錯檔案，不確定時可諮詢賣家   Line ID 0988057325
# 主板是芯片規格適用 
  - wall-switch-1-CBU-ota-1.2d.uf2  1路開關(適用裝潢期，若15分鐘沒找到WIFI "不會" 重開機設備)
  - wall-switch-1-CBU-ota-1.2n.uf2  1路開關(適用使用期，若15分鐘沒找到WIFI "會" 重開機設備)
  - wall-switch-2-CBU-ota-1.2d.uf2  2路開關(適用裝潢期，若15分鐘沒找到WIFI "不會" 重開機設備)
  - wall-switch-2-CBU-ota-1.2n.uf2  2路開關(適用使用期，若15分鐘沒找到WIFI "會" 重開機設備)
  - wall-switch-3-CBU-ota-1.2d.uf2  3路開關(適用裝潢期，若15分鐘沒找到WIFI "不會" 重開機設備)
  - wall-switch-3-CBU-ota-1.2n.uf2  3路開關(適用使用期，若15分鐘沒找到WIFI "會" 重開機設備)
# 主板是模組規格適用
  - wall-switch-1-CHP-ota-1.2d.uf2  1路開關(適用裝潢期，若15分鐘沒找到WIFI "不會" 重開機設備)
  - wall-switch-1-CHP-ota-1.2n.uf2  1路開關(適用使用期，若15分鐘沒找到WIFI "會" 重開機設備)
  - wall-switch-2-CHP-ota-1.2d.uf2  2路開關(適用裝潢期，若15分鐘沒找到WIFI "不會" 重開機設備)
  - wall-switch-2-CHP-ota-1.2n.uf2  2路開關(適用使用期，若15分鐘沒找到WIFI "會" 重開機設備)
  - wall-switch-3-CHP-ota-1.2d.uf2  3路開關(適用裝潢期，若15分鐘沒找到WIFI "不會" 重開機設備)
  - wall-switch-3-CHP-ota-1.2n.uf2  3路開關(適用使用期，若15分鐘沒找到WIFI "會" 重開機設備)
# OTA 刷機方法
- ![Mosquitto_broker](/wall_switch/image/ota.png)
