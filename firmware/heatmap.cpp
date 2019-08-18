#include "standard.h"
#include "config.h"
#include <Arduino.h>

void heatmap_setup(LED leds[][Ze::NUM_COLS], uint8_t count_map[][Ze::NUM_COLS], 
        bool previously_pressed[][Ze::NUM_COLS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
            count_map[row][col] = 0;
            previously_pressed[row][col] = false;
        }
    }
}

void heatmap_update(LED leds[][Ze::NUM_COLS], uint8_t count_map[][Ze::NUM_COLS],
        bool previously_pressed[][Ze::NUM_COLS],
        Ze::Board* board, uint64_t it) {

    Ze::Key* pressed = board->get_curr_pressed_keys();
    for (uint8_t i = 0; i < board->get_num_keys_pressed(); ++i) {
        Ze::Key k = pressed[i];
        if (count_map[k.row][k.col] < 255) {
            count_map[k.row][k.col] += 1;
        }
    }

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {

        }
    }
}


