#include "heatmap.h"
#include "config.h"
#ifdef SIXTY_PERCENT
    #include "sixty_layout.h"
#elif defined FULLSIZE
    #include "fullsize_layout.h"
#elif defined V2
    #include "v2_layout.h"
#endif
#include "util.h"
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
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            bool is_pressed = false;
            Ze::Key this_key = Ze::KEYS[row][col];
            for (uint8_t i = 0; i < board->get_num_keys_pressed(); ++i) {
                Ze::Key k = pressed[i];
                if (this_key.code == k.code) {
                    is_pressed = true;
                    break;
                }
            }
            if (is_pressed && !previously_pressed[row][col]) {
                if (count_map[row][col] < 255) {
                    count_map[row][col] += 1;
                }
                previously_pressed[row][col] = true;
            } else {
                previously_pressed[row][col] = false;
            }
        }
    }

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            Color c;
            jet_color_map(count_map[row][col], c);
            leds[row][col].r = c.r;
            leds[row][col].b = c.b;
            leds[row][col].g = c.g;
        }
    }
}

