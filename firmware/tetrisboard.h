#ifndef TETRISBOARD_H
#define TETRISBOARD_H 

#include "tetromino.h"
#include "keyboard.h"

namespace tetris {

    const uint8_t NUM_ROWS = Ze::NUM_COLS;
    const uint8_t NUM_COLS = Ze::NUM_ROWS;

    void clear_board(SquareType tetris_board[][NUM_COLS]);

    SquareType get_square(SquareType tetris_board[][NUM_COLS], 
            uint8_t x, uint8_t y);

    void spawn_tetromino(SquareType tetris_board[][NUM_COLS],
            Tetromino* falling_tetromino);

    void tick(SquareType tetris_board[][NUM_COLS], 
            Tetromino* falling_tetromino);

    void try_move(SquareType tetris_board[][NUM_COLS], 
            Tetromino* falling_tetromino, bool up);

    void try_rotate(SquareType tetris_board[][NUM_COLS], 
            Tetromino* falling_tetromino, bool up);

    void rush_down(SquareType tetris_board[][NUM_COLS], 
            Tetromino* falling_tetromino);

};

#endif /* ifndef TETRISBOARD_H */
