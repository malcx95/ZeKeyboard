#ifndef TETRIS_H
#define TETRIS_H

#include "led.h"
#include "keyboard.h"
#include "tetromino.h"
#include "tetrisboard.h"
#include "util.h"

const uint8_t TETRIS_DELAY = 25;
const uint8_t RUSH_DELAY = 5;
const Color ELIMINATION_COLOR = {1.0, 1.0, 1.0};

void tetris_setup(LED leds[][Ze::NUM_COLS],
        tetris::SquareType tetris_board[][tetris::NUM_COLS],
        tetris::Tetromino* falling_tetromino);

void tetris_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it,
        tetris::SquareType tetris_board[][tetris::NUM_COLS],
        tetris::Tetromino* falling_tetromino);

#endif /* ifndef TETRIS_H */
