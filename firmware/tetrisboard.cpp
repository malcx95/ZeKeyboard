#include "tetrisboard.h"
#include <Arduino.h>

using namespace tetris;

/*
 * Transfers the falling tetromino to the board and resets it.
 */
void transfer_tetromino_to_board(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino);

/*
 * Returns whether the tetromino rotate (left if left is true, otherwise right)
 * without hitting something.
 */
bool can_rotate(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, bool left);

/*
 * Returns whether the tetromino can move in dx and dy steps
 * in the x and y directions respectively without hitting something.
 */
bool can_move_to(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, uint8_t dx, uint8_t dy);


// void tetris::print_tetris_board(SquareType tetris_board[][NUM_COLS], 
//         Tetromino* falling_tetromino) {
//     for (uint8_t row = 0; row < NUM_ROWS; ++row) {
//         for (uint8_t col = 0; col < NUM_COLS; ++col) {
//             Serial.print(tetrominotype_to_char(tetris_board[row][col]));
//         }
//         Serial.println("");
//     }
//     Serial.println("");
// }

void tetris::clear_board(SquareType tetris_board[][NUM_COLS]) {
    for (uint8_t row = 0; row < NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < NUM_COLS; ++col) {
            tetris_board[row][col] = SQUARE_EMPTY;
        }
    }
}

SquareType tetris::get_square(SquareType tetris_board[][NUM_COLS],
        uint8_t x, uint8_t y) {
    return tetris_board[x][y];
}

void tetris::spawn_tetromino(Tetromino* falling_tetromino, uint64_t it) {
    tetromino_init(falling_tetromino, generate_random_tetromino_type(it));
}

void tetris::tick(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, uint64_t it) {
    if (!is_tetromino_falling(falling_tetromino)) {
        spawn_tetromino(falling_tetromino, it);
    } else if (can_move_to(tetris_board, falling_tetromino, 0, 1)) {
        falling_tetromino->y += 0;
    } else {
        transfer_tetromino_to_board(tetris_board, falling_tetromino);
    }

}

void tetris::try_move(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, bool left) {
    // TODO implement

}

void tetris::try_rotate(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, bool left) {
    // TODO implement

}

void tetris::rush_down(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino) {
    // TODO implement

}

void transfer_tetromino_to_board(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino) {
    // TODO implement
    Serial.println("Transfer tetromino to board!");
}

// TODO implement
bool can_rotate(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, bool left) {
    return true;
}

// TODO implement
bool can_move_to(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, uint8_t dx, uint8_t dy) {
    return true;
}

