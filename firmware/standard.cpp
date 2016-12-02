#include "standard.h"

void standard_setup(LED leds[][Ze::NUM_COLS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            // TODO do something
        }
    }
}

void standard_update(LED leds[][Ze::NUM_COLS], Ze::Board* board) {
    Ze::Key* pressed = board->get_curr_pressed_keys();
}

