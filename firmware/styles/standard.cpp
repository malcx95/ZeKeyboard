#include "standard.h"

void standard_setup(LED leds[][Ze::NUM_COLS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col] = DEFAULT_BRIGHTNESS;
        }
    }
}

void standard_update(LED leds[][Ze::NUM_COLS], Ze::Board* board) {
    Key pressed[MAX_NUM_KEYS] = board->get_curr_pressed_keys();
}

