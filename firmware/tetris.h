#ifndef TETRIS_H
#define TETRIS_H

#include "led.h"
#include "keyboard.h"
#include "tetromino.h"
#include "tetrisboard.h"

const uint8_t TETRIS_DELAY = 20;
const uint8_t RUSH_DELAY = 5;

void tetris_setup(LED leds[][Ze::NUM_COLS],
        tetris::SquareType tetris_board[][tetris::NUM_COLS],
        tetris::Tetromino* falling_tetromino);

void tetris_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it,
        tetris::SquareType tetris_board[][tetris::NUM_COLS],
        tetris::Tetromino* falling_tetromino);

#endif /* ifndef TETRIS_H */
