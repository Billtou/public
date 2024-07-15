# wt32-electricity
## 接線方式
MCU        ZEM-004T

TX(GPIO17) ----    RX

RX(GPIO5) ----    TX

GND       ---    GND

3V3       ---    5V


2台ZEM-004T以串接方式連接 GPIO，使用上位機設定不同的address 1, 2

並透過按下 button 累計歸零，搭配台電的抄表日計算電費與電價。
