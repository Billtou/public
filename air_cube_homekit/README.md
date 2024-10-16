# Air Cube Homekit版本說明文件
## 第一次使用讓設備發出ap熱點方式

用牙籤搓背後的erset孔超過10秒後放開，手機搜尋發出的AP熱點。

![081733](/air_cube_homekit/image/220144.png)


## 連上自家2.4G wifi 
![081733](/air_cube_homekit/image/080352.png)

![081733](/air_cube_homekit/image/080423.png)

## 接入homekit

連覽器輸入設備IP， 選單選<<控制>> 選 <<啟用Homekit>> apple 家庭 app 輸入PIN 碼或點選二維碼掃描接入apple 家庭 app。

若QRCode無法讀取，請輸入PIN碼接入AppleKit。

![081733](/air_cube_homekit/image/081740.png)

## 接入HA

![081733](/air_cube_homekit/image/083411.png)


## 偵測數據校準

![081733](/air_cube_homekit/image/084850.png)

![081733](/air_cube_homekit/image/084923.png)


## 關於甲醛與TVOC接入Homekit問題

目前apple 家庭 app 尚未支持以上兩種偵測數據，若在沒有HA的環境下需另外下載 https://apps.apple.com/tw/app/eve-for-matter-homekit/id917695792

![081733](/air_cube_homekit/image/085717.png)

eve app會同步你的apple家庭app內容，目前支持這兩種偵測訊號，可在這裡設置自動化，即可在apple家庭間接使用這兩種偵測數據了。

