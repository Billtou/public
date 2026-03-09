* 取消絕對值與線上更新，kWh能接受負數

### 3/9 update 
* state_class: measurement 改成 total
* 使用 total 是最正確的做法，它既符合能量面板規範，又支援負值（淨計量）。
* 調整測電芯片的特性讓kWh顯示負數
* ch1、ch2 and sum 只累加不累減 反應未接入台電饋線的實際計價邏輯。
