from esphome import pins
import esphome.codegen as cg
from esphome.components import display
from esphome.components.esp32 import const, only_on_variant
from esphome.components.rpi_dpi_rgb.display import (
    CONF_PCLK_FREQUENCY,
    CONF_PCLK_INVERTED,
)

import esphome.config_validation as cv
from esphome.const import (
    CONF_BLUE,
    CONF_COLOR_ORDER,
    CONF_DATA_PINS,
    CONF_DIMENSIONS,
    CONF_ENABLE_PIN,
    CONF_GREEN,
    CONF_HEIGHT,
    CONF_HSYNC_PIN,
    CONF_ID,
    CONF_IGNORE_STRAPPING_WARNING,
    CONF_INVERT_COLORS,
    CONF_LAMBDA,
    CONF_MODEL,
    CONF_NUMBER,
    CONF_OFFSET_HEIGHT,
    CONF_OFFSET_WIDTH,
    CONF_RED,
    CONF_RESET_PIN,
    CONF_VSYNC_PIN,
    CONF_WIDTH,
)
from esphome.core import TimePeriod

CONF_DE_PIN = "de_pin"
CONF_PCLK_PIN = "pclk_pin"
CONF_SCLK_PIN = "sclk_pin"
CONF_MOSI_PIN = "mosi_pin"

CONF_HSYNC_FRONT_PORCH = "hsync_front_porch"
CONF_HSYNC_PULSE_WIDTH = "hsync_pulse_width"
CONF_HSYNC_BACK_PORCH = "hsync_back_porch"
CONF_VSYNC_FRONT_PORCH = "vsync_front_porch"
CONF_VSYNC_PULSE_WIDTH = "vsync_pulse_width"
CONF_VSYNC_BACK_PORCH = "vsync_back_porch"
CONF_PCLK_FREQUENCY = "pclk_frequency"
CONF_PCLK_INVERTED = "pclk_inverted"

DEPENDENCIES = ["esp32"]

gc9503v_ns = cg.esphome_ns.namespace("gc9503v")
GC9503V = gc9503v_ns.class_("GC9503V", display.Display, cg.Component)
# GC9503V = gc9503v_ns.class_(
#     "GC9503V",
#     cg.PollingComponent,
#     # spi.SPIDevice,
#     display.Display,
#     display.DisplayBuffer,
# )

ColorOrder = display.display_ns.enum("ColorMode")

COLOR_ORDERS = {
    "RGB": ColorOrder.COLOR_ORDER_RGB,
    "BGR": ColorOrder.COLOR_ORDER_BGR,
}
DATA_PIN_SCHEMA = pins.internal_gpio_output_pin_schema

MODELS = {
    "PANLEE": gc9503v_ns.class_("GC9503VPANLEE", GC9503V),
    "VIEWE": gc9503v_ns.class_("GC9503VVIEWE", GC9503V),
}

def data_pin_validate(value):
    """
    It is safe to use strapping pins as RGB output data bits, as they are outputs only,
    and not initialised until after boot.
    """
    if not isinstance(value, dict):
        try:
            return DATA_PIN_SCHEMA(
                {CONF_NUMBER: value, CONF_IGNORE_STRAPPING_WARNING: True}
            )
        except cv.Invalid:
            pass
    return DATA_PIN_SCHEMA(value)


def data_pin_set(length):
    return cv.All(
        [data_pin_validate],
        cv.Length(min=length, max=length, msg=f"Exactly {length} data pins required"),
    )

CONFIG_SCHEMA = cv.All(
    display.FULL_DISPLAY_SCHEMA.extend(
            {
                cv.GenerateID(): cv.declare_id(GC9503V),
                cv.Required(CONF_MODEL): cv.enum(MODELS, upper=True, space="_"),
                cv.Required(CONF_DIMENSIONS): cv.Any(
                    cv.dimensions,
                    cv.Schema(
                        {
                            cv.Required(CONF_WIDTH): cv.int_,
                            cv.Required(CONF_HEIGHT): cv.int_,
                            cv.Optional(CONF_OFFSET_HEIGHT, default=0): cv.int_,
                            cv.Optional(CONF_OFFSET_WIDTH, default=0): cv.int_,
                        }
                    ),
                ),
                cv.Optional(CONF_PCLK_FREQUENCY, default="15MHz"): cv.All(
                    cv.frequency, cv.Range(min=4e6, max=30e6)
                ),
                cv.Optional(CONF_PCLK_INVERTED, default=True): cv.boolean,
                cv.Required(CONF_DATA_PINS): cv.Any(
                    data_pin_set(16),
                    cv.Schema(
                        {
                            cv.Required(CONF_RED): data_pin_set(5),
                            cv.Required(CONF_GREEN): data_pin_set(6),
                            cv.Required(CONF_BLUE): data_pin_set(5),
                        }
                    ),
                ),
                cv.Optional(CONF_COLOR_ORDER): cv.one_of(
                    *COLOR_ORDERS.keys(), upper=True
                ),
                cv.Optional(CONF_INVERT_COLORS, default=False): cv.boolean,
                cv.Required(CONF_DE_PIN): pins.internal_gpio_output_pin_schema,
                cv.Required(CONF_PCLK_PIN): pins.internal_gpio_output_pin_schema,
                cv.Required(CONF_SCLK_PIN): pins.internal_gpio_output_pin_schema,
                cv.Required(CONF_MOSI_PIN): pins.internal_gpio_output_pin_schema,
                cv.Required(CONF_HSYNC_PIN): pins.internal_gpio_output_pin_schema,
                cv.Required(CONF_VSYNC_PIN): pins.internal_gpio_output_pin_schema,
                cv.Required(CONF_ENABLE_PIN): pins.internal_gpio_output_pin_schema,
                cv.Required(CONF_RESET_PIN): pins.internal_gpio_output_pin_schema,
                cv.Optional(CONF_HSYNC_PULSE_WIDTH, default=10): cv.int_,
                cv.Optional(CONF_HSYNC_BACK_PORCH, default=10): cv.int_,
                cv.Optional(CONF_HSYNC_FRONT_PORCH, default=20): cv.int_,
                cv.Optional(CONF_VSYNC_PULSE_WIDTH, default=10): cv.int_,
                cv.Optional(CONF_VSYNC_BACK_PORCH, default=10): cv.int_,
                cv.Optional(CONF_VSYNC_FRONT_PORCH, default=10): cv.int_,
            }
    ),
    only_on_variant(supported=[const.VARIANT_ESP32S3]),
    cv.only_on_esp32,
)

async def to_code(config):
    rhs = MODELS[config[CONF_MODEL]].new()
    var = cg.Pvariable(config[CONF_ID], rhs)
    await display.register_display(var, config)

    cg.add(var.set_color_mode(COLOR_ORDERS[config[CONF_COLOR_ORDER]]))
    cg.add(var.set_invert_colors(config[CONF_INVERT_COLORS]))
    cg.add(var.set_hsync_pulse_width(config[CONF_HSYNC_PULSE_WIDTH]))
    cg.add(var.set_hsync_back_porch(config[CONF_HSYNC_BACK_PORCH]))
    cg.add(var.set_hsync_front_porch(config[CONF_HSYNC_FRONT_PORCH]))
    cg.add(var.set_vsync_pulse_width(config[CONF_VSYNC_PULSE_WIDTH]))
    cg.add(var.set_vsync_back_porch(config[CONF_VSYNC_BACK_PORCH]))
    cg.add(var.set_vsync_front_porch(config[CONF_VSYNC_FRONT_PORCH]))
    cg.add(var.set_pclk_inverted(config[CONF_PCLK_INVERTED]))
    cg.add(var.set_pclk_frequency(config[CONF_PCLK_FREQUENCY]))
    index = 0
    dpins = []
    if CONF_RED in config[CONF_DATA_PINS]:
        red_pins = config[CONF_DATA_PINS][CONF_RED]
        green_pins = config[CONF_DATA_PINS][CONF_GREEN]
        blue_pins = config[CONF_DATA_PINS][CONF_BLUE]
        if config[CONF_COLOR_ORDER] == "BGR":
            dpins.extend(red_pins)
            dpins.extend(green_pins)
            dpins.extend(blue_pins)
        else:
            dpins.extend(blue_pins)
            dpins.extend(green_pins)
            dpins.extend(red_pins)
        # swap bytes to match big-endian format
        dpins = dpins[8:16] + dpins[0:8]
    else:
        dpins = config[CONF_DATA_PINS]
    for pin in dpins:
        data_pin = await cg.gpio_pin_expression(pin)
        cg.add(var.add_data_pin(data_pin, index))
        index += 1

    enable = await cg.gpio_pin_expression(config[CONF_ENABLE_PIN])
    cg.add(var.set_enable_pin(enable))

    reset = await cg.gpio_pin_expression(config[CONF_RESET_PIN])
    cg.add(var.set_reset_pin(reset))
    
    sclk = await cg.gpio_pin_expression(config[CONF_SCLK_PIN])
    cg.add(var.set_sclk_pin(sclk))
    mosi = await cg.gpio_pin_expression(config[CONF_MOSI_PIN])
    cg.add(var.set_mosi_pin(mosi))

    if CONF_DIMENSIONS in config:
        dimensions = config[CONF_DIMENSIONS]
        if isinstance(dimensions, dict):
            cg.add(var.set_dimensions(dimensions[CONF_WIDTH], dimensions[CONF_HEIGHT]))
            cg.add(
                var.set_offsets(
                    dimensions[CONF_OFFSET_WIDTH], dimensions[CONF_OFFSET_HEIGHT]
                )
            )
        else:
            (width, height) = dimensions
            cg.add(var.set_dimensions(width, height))

    if lamb := config.get(CONF_LAMBDA):
        lambda_ = await cg.process_lambda(
            lamb, [(display.DisplayRef, "it")], return_type=cg.void
        )
        cg.add(var.set_writer(lambda_))

    pin = await cg.gpio_pin_expression(config[CONF_DE_PIN])
    cg.add(var.set_de_pin(pin))
    pin = await cg.gpio_pin_expression(config[CONF_PCLK_PIN])
    cg.add(var.set_pclk_pin(pin))
    pin = await cg.gpio_pin_expression(config[CONF_HSYNC_PIN])
    cg.add(var.set_hsync_pin(pin))
    pin = await cg.gpio_pin_expression(config[CONF_VSYNC_PIN])
    cg.add(var.set_vsync_pin(pin))
