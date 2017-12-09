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
        Tetromino* falling_tetromino, int8_t dx, int8_t dy);

/*
 * Returns whether a new tetromino can be spawned.
 */
bool can_spawn_tetromino(SquareType tetris_board[][NUM_COLS]);

bool is_within_bounds(int8_t row, int8_t col);

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
    TetrominoType type = generate_random_tetromino_type(it);
    Serial.print("Type: ");
    Serial.print(type);
    Serial.print(", it: ");
    Serial.println((long)it >> 1);
    tetromino_init(falling_tetromino, type);
}

bool tetris::tick(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, uint64_t it) {
    if (!is_tetromino_falling(falling_tetromino)) {
        if (can_spawn_tetromino(tetris_board)) {
            spawn_tetromino(falling_tetromino, it);
        } else {
            return false;
        }
    } else if (can_move_to(tetris_board, falling_tetromino, 0, 1)) {
        falling_tetromino->y += 1;
    } else {
        transfer_tetromino_to_board(tetris_board, falling_tetromino);
    }
    return true;
}

void tetris::try_move(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, bool left) {
    if (!is_tetromino_falling(falling_tetromino)) return;
    if (left && can_move_to(tetris_board, falling_tetromino, -1, 0)) {
        falling_tetromino->x -= 1;
    } else if (!left && can_move_to(tetris_board, falling_tetromino, 1, 0)) {
        falling_tetromino->x += 1;
    }

}

void tetris::try_rotate(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, bool left) {
    if (!is_tetromino_falling(falling_tetromino)) return;
    if (left && can_rotate(tetris_board, falling_tetromino, true)) {
        tetromino_rotate_left(falling_tetromino);
    } else if (!left && can_rotate(tetris_board, falling_tetromino, false)) {
        tetromino_rotate_right(falling_tetromino);
    }
}

void tetris::rush_down(Tetromino* falling_tetromino) {
    if (!is_tetromino_falling(falling_tetromino)) return;
    falling_tetromino->rushing_down = true;
}

bool tetris::find_rows_to_eliminate(SquareType tetris_board[][NUM_COLS],
        bool rows_to_eliminate[NUM_ROWS]) {

    bool found_any = false;

    for (uint8_t row = 0; row < tetris::NUM_ROWS; ++row) {

        bool should_eliminate = true;
        for (uint8_t col = 0; col < tetris::NUM_COLS; ++col) {
            if (tetris_board[row][col] == SQUARE_EMPTY) {
                should_eliminate = false;
                break;
            }
        }
        rows_to_eliminate[row] = should_eliminate;
        found_any = found_any || should_eliminate;
    }

    return found_any;
}

void tetris::increment_rush(SquareType tetris_board[][NUM_COLS],
        Tetromino* falling_tetromino) {
    if (can_move_to(tetris_board, falling_tetromino, 0, 1)) {
        falling_tetromino->y += 1;
    } else {
        falling_tetromino->rushing_down = false;
    }
}

void transfer_tetromino_to_board(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino) {
    int8_t tx = falling_tetromino->x;
    int8_t ty = falling_tetromino->y;
    for (int8_t row = 0; row < TETROMINO_SIZE; ++row) {
        for (int8_t col = 0; col < TETROMINO_SIZE; ++col) {
            if (falling_tetromino->body[row][col] != 0) {
                tetris_board[ty + row][tx + col] = 
                    tetromino_type_to_square_type(falling_tetromino->type);
            }
        }
    }
    tetromino_deinit(falling_tetromino);
}

void tetris::eliminate_rows(SquareType tetris_board[][NUM_COLS],
        bool rows_to_eliminate[tetris::NUM_ROWS]) {

    // set the squares of the rows to eliminate to SQUARE_EMPTY
    for (uint8_t i = 0; i < tetris::NUM_ROWS; ++i) {

        if (rows_to_eliminate[i]) {
            // shift every row above here one step down

            for (uint8_t row = i - 1; row < tetris::NUM_ROWS; --row) {
                for (uint8_t col = 0; col < tetris::NUM_COLS; ++col) {
                    tetris_board[row + 1][col] = tetris_board[row][col];
                }
            }


            // set the top row to SQUARE_EMPTY
            for (uint8_t col = 0; col < tetris::NUM_COLS; ++col) {
                tetris_board[0][col] = SQUARE_EMPTY;
            }
        }

    }
}

bool can_rotate(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, bool left) {
    Tetromino temp;
    tetromino_copy(falling_tetromino, &temp);

    if (left) {
        tetromino_rotate_left(&temp);
    } else {
        tetromino_rotate_right(&temp);
    }
    int8_t tx = falling_tetromino->x;
    int8_t ty = falling_tetromino->y;

    for (int8_t y = 0; y < TETROMINO_SIZE; ++y) {
        for (int8_t x = 0; x < TETROMINO_SIZE; ++x) {
            if (temp.body[y][x] != 0) {
                if (!is_within_bounds(ty + y, tx + x) || 
                        tetris_board[ty + y][tx + x] != SQUARE_EMPTY) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool is_within_bounds(int8_t row, int8_t col) {
    return 
        row < tetris::NUM_ROWS && 
        row >= 0 &&
        col >= 0 &&
        col < tetris::NUM_COLS;
}

bool can_move_to(SquareType tetris_board[][NUM_COLS], 
        Tetromino* falling_tetromino, int8_t dx, int8_t dy) {
    int8_t new_x = falling_tetromino->x + dx;
    int8_t new_y = falling_tetromino->y + dy;

    for (int8_t row = 0; row < TETROMINO_SIZE; ++row) {
        for (int8_t col = 0; col < TETROMINO_SIZE; ++col) {
            if (falling_tetromino->body[row][col] != 0) {
                if (!is_within_bounds(new_y + row, new_x + col) || 
                        tetris_board[new_y + row][new_x + col] != SQUARE_EMPTY) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool can_spawn_tetromino(SquareType tetris_board[][NUM_COLS]) {
    for (int8_t row = 0; row < TETROMINO_SIZE; ++row) {
        for (int8_t col = 0; col < TETROMINO_SIZE; ++col) {
            if (tetris_board[TETROMINO_START_Y + row][TETROMINO_START_X + col]
                    != SQUARE_EMPTY) {
                return false;
            }
        }
    }

    return true;
}

