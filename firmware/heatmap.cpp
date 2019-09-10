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

bool get_position_of_pressed_key(Position* p, Ze::Board* board) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            if (board->is_just_pressed[row][col]) {
                p->row = row;
                p->col = col;
                return true;
            }
        }
    }
    return false;
}

void heatmap_setup(LED leds[][Ze::NUM_COLS],
        Position* previously_pressed,
        uint32_t count_map[][Ze::NUM_COLS][Ze::NUM_ROWS][Ze::NUM_COLS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 1;

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
        Position* previously_pressed,
        Ze::Board* board, uint64_t it) {
    Position p;
    bool pressed = get_position_of_pressed_key(&p, board);
    if (!pressed) return;

    uint8_t pr = previously_pressed->row;
    uint8_t pc = previously_pressed->col;

    uint8_t r = p.row;
    uint8_t c = p.col;

    count_map[pr][pc][r][c]++;

    previously_pressed->row = r;
    previously_pressed->col = c;

    uint32_t max = 0;
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            if (count_map[r][c][row][col] > max) {
                max = count_map[r][c][row][col];
                Serial.println(count_map[r][c][row][col]);
            }
        }
    }

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            uint8_t intensity;
            float count = (float)count_map[r][c][row][col];
            if (max == 0) {
                intensity = 0;
            } else {
                float intensity_f = (count/((float)max))*255.0;
                intensity = ((uint8_t)intensity_f);
                Serial.print(count);
                Serial.print(", ");
                Serial.print(intensity_f);
                Serial.print(", ");
                Serial.print(intensity);
                Serial.print(", ");
                Serial.println(max);
            }
            if (intensity == 0) {
                leds[row][col].r = 0;
                leds[row][col].g = 0;
                leds[row][col].b = 0;
            } else {
                Color c;
                jet_color_map(intensity, c);

                leds[row][col].r = c.r;
                leds[row][col].g = c.g;
                leds[row][col].b = c.b;
            }
        }
    }
}

