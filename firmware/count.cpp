#include "count.h"
#include <Arduino.h>

void count_setup(LED leds[][Ze::NUM_COLS], uint16_t keyboard_freq[][Ze::NUM_COLS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
            keyboard_freq[row][col] = 0;
        }
    }
}

void count_update(LED leds[][Ze::NUM_COLS], uint16_t keyboard_freq[][Ze::NUM_COLS], Ze::Board* board, uint64_t it) {

    Ze::Key* pressed = board->get_curr_pressed_keys();

    for (uint8_t i = 0; i < board->get_num_keys_pressed(); ++i) {

        Ze::Key* k = &pressed[i];
        uint16_t v = keyboard_freq[k->row][k->col];
        keyboard_freq[k->row][k->col] = min(v + COUNT_AMOUNT, (uint16_t)MAX_VAL);
    }

    if (it % FADE_FREQ == 0) {
        for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
            for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
                uint16_t v = keyboard_freq[row][col];
                keyboard_freq[row][col] = max(0, v - 1);
            }
        }
    }

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            uint16_t v = keyboard_freq[row][col];
            LED* l = &leds[row][col];
            float val = ((float)v) / MAX_VAL;
            l->r = val;
            l->g = 1.0 - val;
        }
    }
}

void count_destroy() {}

