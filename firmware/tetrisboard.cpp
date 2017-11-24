#include "tetrisboard.h"

using namespace tetris;

// TODO implement
void transfer_tetromino_to_board(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino);

// TODO implement
bool can_rotate(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, bool up);

// TODO implement
bool can_move_to(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, uint8_t dx, uint8_t dy);


void clear_board(SquareType tetris_board[][NUM_COLS]) {
    for (uint8_t row = 0; row < NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < NUM_COLS; ++col) {
            tetris_board[row][col] = SQUARE_EMPTY;
        }
    }
}

SquareType get_square(SquareType tetris_board[][NUM_COLS],
        uint8_t x, uint8_t y) {
    return tetris_board[x][y];
}

void spawn_tetromino(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino) {
    tetromino_init(falling_tetromino, TETROMINO_I);
    // TODO finish implementation
}

void tick(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino) {
    // TODO implement

}

void try_move(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, bool up) {
    // TODO implement

}

void try_rotate(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, bool up) {
    // TODO implement

}

void rush_down(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino) {
    // TODO implement

}

