#include "att.h"
#include "config.h"
#include <Arduino.h>

void att_setup(LED leds[][Ze::NUM_COLS], uint8_t data[][Ze::NUM_COLS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
            data[row][col] = 0;
        }
    }
}

void att_update(
        LED leds[][Ze::NUM_COLS],
        uint8_t data[][Ze::NUM_COLS],
        Ze::Board* board, uint64_t it
    ) {


    // update
    for (int8_t row = Ze::NUM_ROWS - 1; row >= 0; --row) {
        int8_t dir = row % 2 == 0 ? -1 : 1;
        int8_t start = row % 2 == 0 ? Ze::NUM_COLS - 1 : 0;
        int8_t end = row % 2 == 0 ? -1 : Ze::NUM_COLS;

        for (int8_t col = start; col != end; col += dir) {
            if (data[row][col] == 1) {
                if (col > 0 && col < Ze::NUM_COLS - 1) {
                    data[row][col - dir] = 1;
                } else if (col == start && row < Ze::NUM_ROWS - 1) {
                    data[row + 1][start + dir] = 1;
                }
                data[row][col] = 0;
            }
        }
    }

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            if (data[row][col] == 1) {
                leds[row][col].r = 1.;
            } else {
                leds[row][col].r = 0.;
            }
        }
    }

    Ze::Key* pressed = board->get_curr_pressed_keys();

    for (uint8_t i = 0; i < board->get_num_keys_pressed(); ++i) {

        Ze::Key* k = &pressed[i];
        
        data[k->row][k->col] = 1;

    }
}

