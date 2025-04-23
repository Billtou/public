#  ** 有些人的 config 資料夾可能是 homeassistant **)

----------------------------------------------
  本檔案請放置於ha的packages資料夾中，若第一次使用packages 方式管理yaml
  檢查一下configuration.yaml裡面有無下列內容

    homeassistant:
      packages: !include_dir_named packages
      customize_domain:
        automation:
          initial_state: true
      allowlist_external_dirs:
        - /config

---------------------------------------------

## weather.yaml 氣象預報資訊推播到dashboard one 的自動化yaml
## count_turn_on.yaml 產生計算類別entity的yaml檔案
