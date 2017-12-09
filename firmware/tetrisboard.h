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

    void spawn_tetromino(Tetromino* falling_tetromino, uint64_t it);

    /*
     * Ticks one step of the game. Returns false
     * if the game is over, true otherwise.
     */
    bool tick(SquareType tetris_board[][NUM_COLS], 
            Tetromino* falling_tetromino, uint64_t it);

    void try_move(SquareType tetris_board[][NUM_COLS], 
            Tetromino* falling_tetromino, bool left);

    void try_rotate(SquareType tetris_board[][NUM_COLS], 
            Tetromino* falling_tetromino, bool left);

    void rush_down(Tetromino* falling_tetromino);

    void increment_rush(SquareType tetris_board[][NUM_COLS], 
            Tetromino* falling_tetromino);

    /*
     * Finds which rows to eliminate because they are filled with
     * squares of the same color. Returns true if any were found,
     * false otherwise. Puts the fund row in the given array.
     */
    bool find_rows_to_eliminate(SquareType tetris_board[][NUM_COLS],
            bool rows_to_eliminate[tetris::NUM_ROWS]);

    void eliminate_rows(SquareType tetris_board[][NUM_COLS],
            bool rows_to_eliminate[tetris::NUM_ROWS]);

};

#endif /* ifndef TETRISBOARD_H */
