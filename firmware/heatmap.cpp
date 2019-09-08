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

void heatmap_setup(LED leds[][Ze::NUM_COLS],
        uint32_t count_map[][Ze::NUM_COLS][Ze::NUM_ROWS][Ze::NUM_COLS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;

            for (uint8_t row2 = 0; row < Ze::NUM_ROWS; ++row) {
                for (uint8_t col2 = 0; col < Ze::NUM_COLS; ++col) {
                    count_map[row][col][row2][col2] = 0;
                }
            }
        }
    }
}

void heatmap_update(LED leds[][Ze::NUM_COLS],
        uint32_t count_map[][Ze::NUM_COLS][Ze::NUM_ROWS][Ze::NUM_COLS],
        Ze::Board* board, uint64_t it) {
    for (uint8_t row1 = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col1 = 0; col < Ze::NUM_COLS; ++col) {
            bool pressed = board->is_just_pressed[row][col];
            // TODO you need to somehow figure out which key was pressed
            // prior to this

            for (uint8_t row2 = 0; row < Ze::NUM_ROWS; ++row) {
                for (uint8_t col2 = 0; col < Ze::NUM_COLS; ++col) {
                    
                }
            }
        }
    }

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            //Color c;
            //jet_color_map(count_map[row][col], c);
            bool pressed = board->is_just_pressed[row][col];
            if (pressed) {
                leds[row][col].r = 1.0;
                Serial.print(row);
                Serial.print(", ");
                Serial.print(col);
                Serial.println("");
            } else {
                leds[row][col].r = 0;
            }
            //leds[row][col].b = c.b;
            //leds[row][col].g = c.g;
        }
    }
}

