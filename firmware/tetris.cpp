#include "tetris.h"

// TODO implement
void draw_tetris_board(LED leds[][tetris::NUM_COLS],
        tetris::SquareType tetris_board[][tetris::NUM_COLS]);

void tetris_setup(LED leds[][Ze::NUM_COLS], 
        tetris::SquareType tetris_board[][tetris::NUM_COLS],
        tetris::Tetromino* falling_tetromino) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
            leds[row][col].aux = nullptr;
        }
    }
}

void tetris_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it,
        tetris::SquareType tetris_board[][tetris::NUM_COLS],
        tetris::Tetromino* falling_tetromino) {
    // TODO implement and add more params
}


