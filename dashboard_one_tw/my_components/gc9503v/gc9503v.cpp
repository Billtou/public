#include "gc9503v.h"
#include "esphome/core/log.h"

namespace esphome {
namespace gc9503v {

void GC9503V::setup() {
	esph_log_config(TAG, "Setting up GC9503V");
	if (this->reset_pin_ != nullptr) {
		esph_log_config(TAG, "reset pin INIT");
		this->reset_pin_->setup();
		this->reset_pin_->digital_write(true);
		delay(10);
		this->reset_pin_->digital_write(false);
		delay(50);
		this->reset_pin_->digital_write(true);
		delay(100);
	}

	spi_bus_config_t buscfg = {};
	buscfg.sclk_io_num = this->sclk_pin_->get_pin();
	buscfg.mosi_io_num = this->mosi_pin_->get_pin();
	buscfg.miso_io_num = -1;
	buscfg.quadwp_io_num = -1;
	buscfg.quadhd_io_num = -1;
	buscfg.max_transfer_sz = 10 * 1024;

	ESP_ERROR_CHECK(spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO));

	spi_device_interface_config_t devcfg = {};
	devcfg.clock_speed_hz = SPI_MASTER_FREQ_10M;   		//Clock out at 10 MHz
	devcfg.mode = 0;                               		//SPI mode 0
	devcfg.spics_io_num = this->enable_pin_->get_pin();	//CS pin
	devcfg.queue_size = 7;                         		//We want to be able to queue 7 transactions at a time

	ESP_ERROR_CHECK(spi_bus_add_device(SPI2_HOST, &devcfg, &g_screen_spi));
	esph_log_config(TAG, "rgb_driver_init");
	this->rgb_driver_init(this->init_sequence_);

	spi_bus_remove_device(g_screen_spi);
	spi_bus_free(SPI2_HOST);
	esph_log_config(TAG, "spi removed");
	if (this->enable_pin_ != nullptr) {
		esph_log_config(TAG, "enable pin INIT");
		this->enable_pin_->setup();
		this->enable_pin_->digital_write(true);
	}

	esp_lcd_rgb_panel_config_t config{};
	config.flags.refresh_on_demand = 0;   // Mannually control refresh operation

	config.flags.fb_in_psram = 1;
#if ESP_IDF_VERSION_MAJOR >= 5
 	config.bounce_buffer_size_px = this->width_ * 10;
	config.num_fbs = 1;
#endif  // ESP_IDF_VERSION_MAJOR
	config.timings.h_res = this->width_;
	config.timings.v_res = this->height_;
	config.timings.hsync_pulse_width = this->hsync_pulse_width_;
	config.timings.hsync_back_porch = this->hsync_back_porch_;
	config.timings.hsync_front_porch = this->hsync_front_porch_;
	config.timings.vsync_pulse_width = this->vsync_pulse_width_;
	config.timings.vsync_back_porch = this->vsync_back_porch_;
	config.timings.vsync_front_porch = this->vsync_front_porch_;
	config.timings.flags.pclk_active_neg = this->pclk_inverted_;
	config.timings.pclk_hz = this->pclk_frequency_;
	config.clk_src = LCD_CLK_SRC_PLL160M;
	size_t data_pin_count = sizeof(this->data_pins_) / sizeof(this->data_pins_[0]);
	for (size_t i = 0; i != data_pin_count; i++) {
		config.data_gpio_nums[i] = this->data_pins_[i]->get_pin();
	}
	config.data_width = data_pin_count;
	config.disp_gpio_num = -1;
	config.hsync_gpio_num = this->hsync_pin_->get_pin();
	config.vsync_gpio_num = this->vsync_pin_->get_pin();
	config.de_gpio_num = this->de_pin_->get_pin();
	config.pclk_gpio_num = this->pclk_pin_->get_pin();
// 	esp_err_t err = esp_lcd_new_rgb_panel(&config, &this->handle_);
// 	if (err != ESP_OK) {
// 		ESP_LOGE(TAG, "lcd_new_rgb_panel failed: %s", esp_err_to_name(err));
// 		this->mark_failed();
// 		return;
// 	}
//   ESP_ERROR_CHECK(esp_lcd_panel_reset(this->handle_));
//   ESP_ERROR_CHECK(esp_lcd_panel_init(this->handle_));

    ESP_ERROR_CHECK(esp_lcd_new_rgb_panel(&config, &this->handle_));
    ESP_ERROR_CHECK(esp_lcd_panel_reset(this->handle_));
    ESP_ERROR_CHECK(esp_lcd_panel_init(this->handle_));
	
	esph_log_config(TAG, "GC9503V setup complete");
}

void GC9503V::send_command_and_data(uint8_t command_byte, const uint8_t *data_bytes, uint8_t num_data_bytes) {
	this->__spi_send_cmd(command_byte);  // Send the command byte
	for (size_t offset = 0; offset < num_data_bytes; offset++) {
		this->__spi_send_data(*(data_bytes + offset));
	}
}

void GC9503V::__spi_send_cmd(uint8_t cmd)
{
    uint16_t tmp_cmd = (cmd | 0x0000);;
    spi_transaction_ext_t trans = (spi_transaction_ext_t)
    {
        .base =
        {
            .flags = SPI_TRANS_VARIABLE_CMD,
            .cmd = tmp_cmd,
        },
        .command_bits = 9,
    };
    spi_device_transmit(g_screen_spi, (spi_transaction_t *)&trans);
}

void GC9503V::__spi_send_data(uint8_t data)
{
    uint16_t tmp_data = (data | 0x0100);
    spi_transaction_ext_t trans = (spi_transaction_ext_t){
        .base = {
            .flags = SPI_TRANS_VARIABLE_CMD,
            .cmd = tmp_data,
        },
        .command_bits = 9,
    };
    spi_device_transmit(g_screen_spi, (spi_transaction_t *)&trans);
}

void GC9503V::loop() {
#if ESP_IDF_VERSION_MAJOR >= 5
	if (this->handle_ != nullptr)
		esp_lcd_rgb_panel_restart(this->handle_);
#endif  // ESP_IDF_VERSION_MAJOR
}

void GC9503V::draw_pixels_at(int x_start, int y_start, int w, int h, const uint8_t *ptr, display::ColorOrder order, display::ColorBitness bitness, bool big_endian, int x_offset, int y_offset, int x_pad) {
	if (w <= 0 || h <= 0)
		return;
	// if color mapping is required, pass the buck.
	// note that endianness is not considered here - it is assumed to match!
	if (bitness != display::COLOR_BITNESS_565) {
		return display::Display::draw_pixels_at(x_start, y_start, w, h, ptr, order, bitness, big_endian, x_offset, y_offset, x_pad);
	}
	x_start += this->offset_x_;
	y_start += this->offset_y_;
	esp_err_t err = ESP_OK;
    // x_ and y_offset are offsets into the source buffer, unrelated to our own offsets into the display.
	if (x_offset == 0 && x_pad == 0 && y_offset == 0) {
    	// we could deal here with a non-zero y_offset, but if x_offset is zero, y_offset probably will be so don't bother
		err = esp_lcd_panel_draw_bitmap(this->handle_, x_start, y_start, x_start + w, y_start + h, ptr);
	} else {
		// draw line by line
		auto stride = x_offset + w + x_pad;
		for (int y = 0; y != h; y++) {
			err = esp_lcd_panel_draw_bitmap(this->handle_, x_start, y + y_start, x_start + w, y + y_start + 1, ptr + ((y + y_offset) * stride + x_offset) * 2);
			if (err != ESP_OK)
				break;
		}
	}
	if (err != ESP_OK)
	ESP_LOGE(TAG, "lcd_lcd_panel_draw_bitmap failed: %s", esp_err_to_name(err));
}

int GC9503V::get_width() {
	switch (this->rotation_) {
		case display::DISPLAY_ROTATION_90_DEGREES:
		case display::DISPLAY_ROTATION_270_DEGREES:
			return this->get_height_internal();
		default:
			return this->get_width_internal();
	}
}

int GC9503V::get_height() {
	switch (this->rotation_) {
		case display::DISPLAY_ROTATION_90_DEGREES:
		case display::DISPLAY_ROTATION_270_DEGREES:
			return this->get_width_internal();
		default:
			return this->get_height_internal();
	}
}

void GC9503V::draw_pixel_at(int x, int y, Color color) {
	if (!this->get_clipping().inside(x, y))
		return;  // NOLINT

	switch (this->rotation_) {
		case display::DISPLAY_ROTATION_0_DEGREES:
			break;
		case display::DISPLAY_ROTATION_90_DEGREES:
			std::swap(x, y);
			x = this->width_ - x - 1;
			break;
		case display::DISPLAY_ROTATION_180_DEGREES:
			x = this->width_ - x - 1;
			y = this->height_ - y - 1;
			break;
		case display::DISPLAY_ROTATION_270_DEGREES:
			std::swap(x, y);
			y = this->height_ - y - 1;
			break;
	}
	auto pixel = convert_big_endian(display::ColorUtil::color_to_565(color));

	this->draw_pixels_at(x, y, 1, 1, (const uint8_t *) &pixel, display::COLOR_ORDER_RGB, display::COLOR_BITNESS_565, true, 0, 0, 0);
	App.feed_wdt();
}

void GC9503V::dump_config() {
	ESP_LOGCONFIG("", "GC9503V RGB LCD");
	ESP_LOGCONFIG(TAG, "  Height: %u", this->height_);
	ESP_LOGCONFIG(TAG, "  Width: %u", this->width_);
	LOG_PIN("  DE Pin: ", this->de_pin_);
	LOG_PIN("  Enable Pin: ", this->enable_pin_);
	LOG_PIN("  Reset Pin: ", this->reset_pin_);
	size_t data_pin_count = sizeof(this->data_pins_) / sizeof(this->data_pins_[0]);
	for (size_t i = 0; i != data_pin_count; i++) {
		char pin_buf[64];
		(this->data_pins_[i])->dump_summary(pin_buf, sizeof(pin_buf));
		ESP_LOGCONFIG(TAG, "  Data pin %d: %s", i, pin_buf);
	}
}

void GC9503V::reset_display_() const {
	esph_log_config(TAG, "reset display");
	if (this->reset_pin_ != nullptr) {
		this->reset_pin_->setup();
		this->reset_pin_->digital_write(false);
		delay(1);
		this->reset_pin_->digital_write(true);
	}
}

void GC9503V::rgb_driver_init(const uint8_t *addr) {
	if (addr == nullptr)
		return;
	uint8_t cmd, x, num_args;
	while ((cmd = *addr++) != 0) {
		x = *addr++;
		if (x == GC9503V_DELAY_FLAG) {
			cmd &= 0x7F;
			ESP_LOGV(TAG, "Delay %dms", cmd);
			delay(cmd);
		} else {
			num_args = x & 0x7F;
			ESP_LOGV(TAG, "Command %02X, length %d, bits %02X", cmd, num_args, *addr);
			this->send_command_and_data(cmd, addr, num_args);
			addr += num_args;
		}
	}
}

}
}