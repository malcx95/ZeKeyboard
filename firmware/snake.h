#ifndef SNAKE_H
#define SNAKE_H 

#include "constants.h"
#include "led.h"
#include "keyboard.h"
#include <math.h>
#include "util.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

const Color COLORS[6] {
    {1., 0., 0.},
    {0., 1., 0.},
    {0., 0., 1.},
    {1., 0., 1.},
    {1., 1., 0.},
    {0., 1., 1.}
};

struct SnakeSegment {
    uint8_t color_index;
    uint8_t row;
    uint8_t col;
    bool active;
    Direction dir;
};

void update_snake(SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS],
        SnakeSegment* food, uint64_t it);

void snake_segment_copy(SnakeSegment* from, SnakeSegment* to);

void snake_setup(LED leds[][Ze::NUM_COLS],
        SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS], SnakeSegment* food);

void snake_update(LED leds[][Ze::NUM_COLS], SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS],
        Ze::Board* board, uint64_t it, SnakeSegment* food);

void draw_snake(SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS],
        LED leds[][Ze::NUM_COLS], SnakeSegment* food);

void update_snake_direction(Ze::Board* board,
    SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS]);

#endif /* ifndef SNAKE_H */
