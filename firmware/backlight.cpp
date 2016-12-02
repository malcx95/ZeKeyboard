#include "backlight.h"

Backlight::Backlight() {
    this->keyboard = nullptr;
    this->rows = nullptr;
    this->style = BacklightStyle::STANDARD;
}

void Backlight::init(Ze::Board* keyboard, CRGB** rows) {
    this->keyboard = keyboard;
    this->rows = rows;

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            LED l;
            l.init();
            l.port = LED_GRID[row][col];
            leds[row][col] = l;
        }
    }
}

void Backlight::print_grid() {
    Serial.println("-------------------------");

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            uint16_t b = leds[row][col].brightness;
            Serial.print(b);
            if (b < 10) {
                Serial.print(" ");
            }
        }
        Serial.println("");
    }
    Serial.println("");
}

void Backlight::setup(BacklightStyle style) {
    this->style = style;
    switch (style) {
        case STANDARD:
            standard_setup(this->leds);
            break;
    }
}

void Backlight::update() {

    switch (style) {
        case STANDARD:
            standard_update(this->leds, this->keyboard);
            break;
    }

    // update the leds
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            LED curr = leds[row][col];
            if (!curr.is_dummy()) {
                // set the color
                uint32_t color = curr.get_hex_code();
                rows[row][curr.port] = color;
            }
        }
    }
    FastLED.show();
}

