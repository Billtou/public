# 7.5in 紅黑白三色電子紙使用說明

## 接入HA
上電手機搜尋熱點並指定自家wifi與密碼HA會自動發現，直接點選 "設定" 按紐並指定區域即完成。


## 必須搭配網友撰寫的中央氣象局擴充插件才能正常使用。
先申請帳號
https://opendata.cwa.gov.tw/index
進去這裡取得api授權碼
https://opendata.cwa.gov.tw/user/authkey
HACS 搜尋 Opendata CWA 並安裝它； HA 重開機 ； 設定 > 裝置與服務  > 新增整合 > 填入API密鑰以及鄉鎮區名稱並選擇onecall_daily按傳送。

![Mosquitto_broker](/e_ink_display/124729.png)

## 手動建立模板實體 (可以放在HA的configuration.yaml裡面，建議用packages方式管理手動建立模板實體的方式，方法如下: 在config(或homeassistant)資料夾中建立一個packages資料夾，並在configuration.yaml內增加以下代碼後重開機即可。

    homeassistant:
      packages: !include_dir_named packages
