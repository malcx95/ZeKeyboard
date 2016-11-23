#include "backlight.h"

Backlight::Backlight(Tlc5940* tlc, Ze::Keyboard* keyboard) {
    this->tlc = tlc;
    this->keyboard = keyboard;

    for (uint8_t row = 0; row < NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < NUM_COLS; ++col) {
            leds[row][col] = LED
        }
    }
}

LED::LED(led_t port) {
    this->port = port;
    this->brightness = 0;
}

bool LED::is_dummy() {
    return this->port = LED_DUMMY;
}

