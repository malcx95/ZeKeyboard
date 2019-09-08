#include "snake.h"
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

void snake_setup(LED leds[][Ze::NUM_COLS], SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
        }
    }
}

void snake_update(LED leds[][Ze::NUM_COLS], SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS],
        Ze::Board* board, uint64_t it) {
}

