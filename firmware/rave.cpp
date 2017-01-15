#include "rave.h"
#include <Arduino.h>

void rave_setup(LED leds[][Ze::NUM_COLS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
            leds[row][col].aux = nullptr;
        }
    }
}

void rave_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it) {

    if (it % 10 < 5) {
        for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
            for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
                leds[row][col].r = 0;
                leds[row][col].g = 1;
            }
        }
    } else {
        for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
            for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
                leds[row][col].r = 1;
                leds[row][col].g = 0;
            }
        }
    
    }

    Ze::Key* pressed = board->get_curr_pressed_keys();

    for (uint8_t i = 0; i < board->get_num_keys_pressed(); ++i) {

        float r = 1.0 - (leds[pressed[i].row][pressed[i].col].r);
        float g = 1.0 - (leds[pressed[i].row][pressed[i].col].g);
        float b = 1.0 - (leds[pressed[i].row][pressed[i].col].b);
        leds[pressed[i].row][pressed[i].col].r = r;
        leds[pressed[i].row][pressed[i].col].g = g;
        leds[pressed[i].row][pressed[i].col].b = b;

        if (pressed[i].code == KEY_SPACE) {
            // Light up the left and right leds of the space bar
            // Only light these up a third as much

            leds[pressed[i].row][pressed[i].col + 1].r = r / 3;
            leds[pressed[i].row][pressed[i].col + 1].g = g / 3;
            leds[pressed[i].row][pressed[i].col + 1].b = b / 3; 

            leds[pressed[i].row][pressed[i].col - 1].r = r / 3; 
            leds[pressed[i].row][pressed[i].col - 1].g = g / 3;
            leds[pressed[i].row][pressed[i].col - 1].b = b / 3; 
        }
    }
}

void rave_destroy() {}

