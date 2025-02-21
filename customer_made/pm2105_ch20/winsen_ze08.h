#include "esphome.h"

// https://www.winsen-sensor.com/sensors/ch2o-gas-sensor/ze08-ch2o.html

// Pinouts on page 4 of datasheet:
// https://www.winsen-sensor.com/d/files/PDF/Gas%20Sensor%20Module/Formaldehyde%20Detection%20Module/ZE08-CH2O%20V1.0.pdf

static const char *TAG = "custom";
static const uint8_t ZE08_SET_QA_MODE[] = {0xFF, 0x01, 0x78, 0x41, 0x00, 0x00, 0x00, 0x00, 0x46};
//static const uint8_t ZE08_SET_ACTIVE_MODE[] = {0xFF, 0x01, 0x78, 0x40, 0x00, 0x00, 0x00, 0x00, 0x47};
static const uint8_t ZE08_QUESTION[] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
static const char *ZE08_MODE_QA = "QA";
//static const char *ZE08_MODE_ACTIVE = "ACTIVE";
static const char *ZE08_MODE = ZE08_MODE_QA;

class WinsenZE08Sensor : public PollingComponent, public UARTDevice {
  Sensor *ch2o_ppb_ {nullptr};

  public:
    WinsenZE08Sensor(UARTComponent *parent, Sensor *ch2o_ppb) : UARTDevice(parent), ch2o_ppb_(ch2o_ppb) {}
    void setup() override {
      this->set_update_interval(5000);

      if (ZE08_MODE == ZE08_MODE_QA) {
        write_array(ZE08_SET_QA_MODE, sizeof(ZE08_SET_QA_MODE));
      }
    }

    void loop() override {

    }

    void update() override {
      write_array(ZE08_QUESTION, sizeof(ZE08_QUESTION));
      unsigned char buf[9];
      if (this->available() != sizeof(buf)) {
        ESP_LOGE(TAG, "Bad response from ZE08! received %d bytes.", this->available());
        //this->mark_failed();
        return;
      }
      read_array(buf, sizeof(buf));
      // message of 9 bytes, same reading two units:
      //       ug/m3            ppb
      // st cm high low res res high low ch
      unsigned short concentration_ugm3 = (buf[2] << 8) | buf[3];
      unsigned short concentration_ppb = (buf[6] << 8) | buf[7];
      ESP_LOGD(TAG, "Received %d %d.", concentration_ugm3, concentration_ppb);
      unsigned char checksum_calc = ~(buf[1] + buf[2] + buf[3] + buf[4] + buf[5] + buf[6] + buf[7]) + 1;
      if (buf[8] != checksum_calc) {
        ESP_LOGE(TAG, "Bad checksum from ZE08! received %d != %d.", buf[8], checksum_calc);
      }
      ch2o_ppb_->publish_state(concentration_ppb);
    }
};
