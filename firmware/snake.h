#ifndef SNAKE_H
#define SNAKE_H 

#include "constants.h"
#include "led.h"
#include "keyboard.h"
#include <math.h>
#include "util.h"

struct SnakeSegment {
    Color color;
    uint8_t row;
    uint8_t col;
    bool active;
};

void snake_segment_copy(SnakeSegment* from, SnakeSegment* to);

void snake_setup(LED leds[][Ze::NUM_COLS], SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS]);

void snake_update(LED leds[][Ze::NUM_COLS], SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS],
        Ze::Board* board, uint64_t it);

#endif /* ifndef SNAKE_H */
