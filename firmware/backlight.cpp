#include "backlight.h"

Backlight::Backlight() {
    this->tlc = nullptr;
    this->keyboard = nullptr;
}

void Backlight::init(Tlc5940* tlc, Ze::Board* keyboard) {
    this->tlc = tlc;
    this->keyboard = keyboard;
    
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            LED l;
            l.port = LED_GRID[row][col];
            leds[row][col] = l;
        }
    }
}



bool LED::is_dummy() const {
    return this->port == LED_DUMMY;
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

