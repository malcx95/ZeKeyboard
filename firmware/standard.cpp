#include "standard.h"
#include <Arduino.h>

void standard_setup(LED leds[][Ze::NUM_COLS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
        }
    }
}

void standard_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = (sin(RED_SPEED * it / GLOBAL_SPEED_DIVISOR) + 1) / 2;
            leds[row][col].g = (sin(GREEN_SPEED * it / GLOBAL_SPEED_DIVISOR) + 1) / 2;
            leds[row][col].b = (sin(BLUE_SPEED * it / GLOBAL_SPEED_DIVISOR) + 1) / 2;
        }
    }

    Ze::Key* pressed = board->get_curr_pressed_keys();


    for (uint8_t i = 0; !pressed[i].is_dummy(); ++i) {
        float r = leds[pressed[i].row][pressed[i].col].r;
        leds[pressed[i].row][pressed[i].col].r = 1 - r;
        float g = leds[pressed[i].row][pressed[i].col].g;
        leds[pressed[i].row][pressed[i].col].g = 1 - g;
        float b = leds[pressed[i].row][pressed[i].col].b;
        leds[pressed[i].row][pressed[i].col].b = 1 - b;
    }
}

