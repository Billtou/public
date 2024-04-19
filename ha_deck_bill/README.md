這裡著重如何自己規劃撰寫專屬的操作頁面。

##螢幕解析度480*480

先說一下自帶的按鈕定位點，以正方形畫面區分16區
![Mosquitto_broker](/ha_deck_bill/image/143924.png)


    1-1  1-2  1-3  1-4
    2-1  2-2  2-3  2-4
    3-1  3-2  3-3  3-4
    4-1  4-2  4-3  4-4

    1-1定位點:8,8
    1-2定位點:126,8
    1-3定位點:244,8
    1-4定位點:362,8
    2-1定位點:8,127
    2-2定位點:126,127
    2-3定位點:244,127
    2-4定位點:362,127
    3-1定位點:8,246
    3-2定位點:126,246
    3-3定位點:244,246
    3-4定位點:362,246
    4-1定位點:8,365
    4-2定位點:126,365
    4-3定位點:244,365
    4-4定位點:362,365

指定"button"定位點後若沒特別參數，自帶默認大小，若加上dimensions參數，可以自訂button大小。

        - type: button #元件類別 
          position: 126, 8  #定位點  1-2 
          dimensions: 228x96  #指定元件大小(兩個默認大小的參數) 位置涵蓋1-2~1-3 (刪掉這行變常規正方形大小)
          text: "Livingroom"  #顯示文字(只能用英文)
          icon: 󰀛   # 只能用HA自帶，稍後說明
          # toggle: true  #是否要觸發
          enabled: return true;  #狀態顏色是否顯示
          checked: |-  #狀態判斷程序碼
            if(id(climate_state).state != "off") { return 1; }
            else { return 0; }
            
![Mosquitto_broker](/ha_deck_bill/image/152844.png)

解析一下整個畫面說明。
    substitutions:
      SCREEN_MAIN: main
      SCREEN_ROOMS: rooms
      SCREEN_KITCHEN: kitchen
      SCREEN_LED: led
      SCREEN_MEDIA: media
      SCREEN_LIVCLIMATE: livclimate
指定頁面名稱，一個SCREEN一個參數，例如要增加一格臥室頁面如下。
    SCREEN_BEDROOM: bedroom






參考網站

https://github.com/strange-v/ha_deck

https://www.youtube.com/watch?v=NPr9ryyTVB4&ab_channel=strange_v

https://github.com/ivan-rio/ha_deck_cyd

https://www.youtube.com/watch?v=NtF0wyf12DM&t=317s&ab_channel=%D0%86%D0%B2%D0%B0%D0%BDRIO
