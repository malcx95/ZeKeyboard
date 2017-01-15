#include "standard.h"
#include <Arduino.h>

void standard_setup(LED leds[][Ze::NUM_COLS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
            leds[row][col].aux = nullptr;
        }
    }
}

void standard_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it) {
    float fade_dir_row = sin(ROW_DIR_CHANGE_SPEED * it / GLOBAL_SPEED_DIVISOR);
    float fade_dir_col = sin(COL_DIR_CHANGE_SPEED * it / GLOBAL_SPEED_DIVISOR);
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = DEFAULT_BRIGHTNESS * 
                (cos(RED_SPEED * it / GLOBAL_SPEED_DIVISOR +
                        (row * fade_dir_row - col * fade_dir_col) *
                        PHASE_DIFFERENCE) + 1) / 2;
            leds[row][col].g = DEFAULT_BRIGHTNESS * 
                (sin(GREEN_SPEED * it / GLOBAL_SPEED_DIVISOR +
                        (row * fade_dir_row - col * fade_dir_col) *
                        PHASE_DIFFERENCE) + 1) / 2;
            leds[row][col].b = DEFAULT_BRIGHTNESS * 
                (sin(BLUE_SPEED * it / GLOBAL_SPEED_DIVISOR +
                        (row * fade_dir_row - col * fade_dir_col) *
                        PHASE_DIFFERENCE) + 1) / 2;
        }
    }

    Ze::Key* pressed = board->get_curr_pressed_keys();

    for (uint8_t i = 0; i < board->get_num_keys_pressed(); ++i) {

        float r = 1.0 - (leds[pressed[i].row][pressed[i].col].r / 
                DEFAULT_BRIGHTNESS);
        float g = 1.0 - (leds[pressed[i].row][pressed[i].col].g / 
                DEFAULT_BRIGHTNESS);
        float b = 1.0 - (leds[pressed[i].row][pressed[i].col].b /
                DEFAULT_BRIGHTNESS);
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

void standard_destroy() {}

