# 第一步連接自家WIFI
  - ## 上電等待1-2分鐘，手機靠近設備找wifi熱點 automate-wp475-xxxxxx，接入後手機切換到瀏覽器輸入192.168.4.1即可指定自家wifi與密碼(wifi 僅支持 2.4G)。若連接成功靜待1-2分鐘，畫面就會自動更新。

# 申請氣象署授權碼
  - ## 申請氣象署api授權碼取代出廠值
  - https://opendata.cwa.gov.tw/index  註冊並登入後選擇取得授權碼，複製  CWA-XXXXXXXXXXXXXXXXXXXXXXX...  備用。
# 查詢鄉鎮區正確名稱
  - ## 鄉鎮別名稱一覽表
  - https://github.com/Billtou/public/blob/main/e_ink_display/%E6%B0%A3%E8%B1%A1%E5%B1%80%E9%84%89%E9%8E%AE%E5%90%8D%E7%A8%B1%E4%B8%80%E8%A6%BD%E8%A1%A8.pdf
# 調整參數
  - ## 畫面右上方會有設備的ip位置，手機或電腦的瀏覽器輸入後會跳出後台管理頁面。
    - ### 按照調整頁面選項說明替換氣象署的授權碼、縣市別、鄉鎮名稱。
    - ### 刷新後台管理頁面，若欄位顯示新的內容代表修改成功。
    - ### 按下 "Refresh Panel 更新頁面" 的按鈕會重新抓以新的授權碼、縣市別、鄉鎮名稱的天氣預報。
   
![Mosquitto_broker](/weatherpanel-auto/image/456.JPG)

# 每天自動更新數據時間
  - ## 00:15、06:15、09:15、12:15、15:15、18:15、21:15 

# 使用注意事項
  - 不管自動更新或手動更新，都會先抓取雲端氣象署的最新訊息，故避免連續按壓更新按鈕。
  - 若發現畫面全部都是 -- 的數據代表授權碼、鄉鎮名稱錯誤或者是氣象署雲端短時間掛點了，修正授權碼等數據或靜待氣象署恢復即可。
  - 若自家有智能環境例如 home assistant ， 可以關閉自動更新開關，由HA的自動化自由定義每日更新時間。
  - 當下雨機率超過30% 背光LED燈會亮紅燈提醒，也可以通過調整參數頁面關閉紅燈提示。
  - 若調整值亂掉可以按下 "Defaul 恢復出廠值" 即可。
# icon說明
![Mosquitto_broker](/weatherpanel-auto/image/123.JPG)

# 預報選單說明
  - daily_temp_high_low   一週 最高溫與最低
  - daily_feel_high_low   一週 最高體感溫度與最低
  - daily_avg_temp_humid  一週 平均溫度與濕度 
  - daily_avg_temp_rainy  一週 平均溫度與下雨機率 
  - daily_avg_temp_uv     一週 平均溫度與紫外線指數
  - hourly_temp_humid     小時 溫度與濕度
  - hourly_temp_rainy     小時 溫度與下雨機率
  - hourly_feel_rainy     小時 體感溫度與下雨機率
