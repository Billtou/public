### Air Cube pro mmwave 靈敏度調適畫面範例
請下載air_cube_pro_mmwave_ui_basic.yaml , air_cube_pro_mmwave_chart_move.yaml , air_cube_pro_mmwave_chart_still.yaml檔案，在HA用新增面板方式把三個檔案分別做出三個面板，第一個是各項感應器的偵測數據，最後兩行是靈敏度調整，分別是靜態與動態各三個，1靈敏度最低3最高；另外兩個檔案是基於HASC Plotly Graph Card 插件，請先安裝此插件再新增面板。https://github.com/dbuezas/lovelace-plotly-graph-card
### HA面板說明 感應器的偵測數據
air_cube_pro_mmwave_ui_basic.yaml

![080744](/air_cube_pro/080744.png)


### HA面板說明 實時偵測數據回饋

air_cube_pro_mmwave_chart_move.yaml

air_cube_pro_mmwave_chart_still.yaml

![083817](/air_cube_pro/083817.png)
![081733](/air_cube_pro/081733.png)


### HA面板說明 手動調整畫面

air_cube_pro_mmwave_manual_setup.yaml

![084944](/air_cube_pro/084944.png)


