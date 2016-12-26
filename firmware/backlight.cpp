#include "backlight.h"

Backlight::Backlight() {
    this->keyboard = nullptr;
    this->ledstrip = nullptr;
    this->style = BacklightStyle::STANDARD;
}

void Backlight::init(Ze::Board* keyboard, CRGB* ledstrip) {
    this->keyboard = keyboard;
    this->ledstrip = ledstrip;
    this->brightness = 1.0;
    this->it = 0;

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
            uint16_t b = leds[row][col].r;
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

    this->it++;

    switch (style) {
        case STANDARD:
            standard_update(this->leds, this->keyboard, this->it);
            break;
    }

    // update the leds
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            LED curr = leds[row][col];
            if (!curr.is_dummy()) {
                // set the color
                ledstrip[translate_grid_to_strip(row, col)] = curr.get_hex_code();
            }
        }
    }
    FastLED.show();
}

uint8_t Backlight::translate_grid_to_strip(uint8_t row, uint8_t col) {
    return LED_GRID[row][col];
}
