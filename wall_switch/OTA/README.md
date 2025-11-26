## 2025/11/27 v3.1 Update說明
* 取消找不到wifi就跳出AP熱點的功能，改由長按任一鍵超過10秒才跳出AP熱點。
## 2025/10/22 v3.1 Update說明
* 延長短按的判斷時間，低於5秒都算。
## 2025-09-8 V 3.0 Update說明
* 新增可設置持續wifi斷網秒數後重啟。
# 2025/5/26 Update 說明
  - 2.1版本
  - 新增按壓任一鍵持續5~9秒放開會 "重啟" 設備，超過10秒以上會 "重置" 設備 (重置WIFI與其他開關記憶狀態 "回到出廠值")
  - 間現場沒有 wifi 或 HA 請保持在 "出廠值" 不會定期重啟的困擾
  - 當第一次引導接入wifi後靜待超過10秒並重新上電才會寫入wifi SSID 與密碼 ，HA才會發現。
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
