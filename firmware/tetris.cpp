#include "tetris.h"

void handle_keyboard_input(Ze::Board* board, 
        tetris::SquareType tetris_board[][tetris::NUM_COLS], 
        tetris::Tetromino* falling_tetromino);

/*
 * Resets the game
 */
void game_over(LED leds[][Ze::NUM_COLS],
        tetris::SquareType tetris_board[][tetris::NUM_COLS],
        tetris::Tetromino* falling_tetromino);

/*
 * Lights up the rows about to be removed
 */
void mark_rows_to_eliminate(LED leds[][Ze::NUM_COLS],
        bool rows_to_eliminate[tetris::NUM_ROWS]) {
    for (uint8_t row = 0; row < tetris::NUM_ROWS; ++row) {

        if (rows_to_eliminate[row]) {
            for (uint8_t col = 0; col < tetris::NUM_COLS; ++col) {
                // flipping cols and rows since we need 
                // to transpose the thing and flip left to right
                leds[col][Ze::NUM_COLS - 1 - row].r = ELIMINATION_COLOR.r;
                leds[col][Ze::NUM_COLS - 1 - row].g = ELIMINATION_COLOR.g;
                leds[col][Ze::NUM_COLS - 1 - row].b = ELIMINATION_COLOR.b;
            }
        }
    }
}

void game_over(LED leds[][Ze::NUM_COLS],
        tetris::SquareType tetris_board[][tetris::NUM_COLS],
        tetris::Tetromino* falling_tetromino) {
    tetris::clear_board(tetris_board);
    tetris::tetromino_deinit(falling_tetromino);

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 1.0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
        }
    }
    
}

void draw_tetris_board(LED leds[][Ze::NUM_COLS],
        tetris::SquareType tetris_board[][tetris::NUM_COLS],
        tetris::Tetromino* falling_tetromino) {

    tetris::SquareType rendered_board[Ze::NUM_ROWS][Ze::NUM_COLS];

    // transfer the board, transposing it
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            rendered_board[row][col] = tetris_board[col][row];
        }
    }


    if (is_tetromino_falling(falling_tetromino)) {

        // transfer the falling tetromino, transposing it
        tetris::SquareType type = tetris::tetromino_type_to_square_type(
                falling_tetromino->type);
        int8_t tx = falling_tetromino->x;
        int8_t ty = falling_tetromino->y;

        for (int8_t row = 0; row < tetris::TETROMINO_SIZE; ++row) {
            for (int8_t col = 0; col < tetris::TETROMINO_SIZE; ++col) {
                if (falling_tetromino->body[row][col] != 0) {
                    rendered_board[col + tx][row + ty] = type;
                }
            }
        }

    }

    // for debugging
    Serial.println("................");
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        Serial.print(".");
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            Serial.print(tetris::squaretype_to_char(rendered_board[row][col]));
        }
        Serial.print(".");
        Serial.println("");
    }
    Serial.println("................");
    Serial.println("");

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            Color c = tetris::square_type_to_color(
                    rendered_board[row][Ze::NUM_COLS - 1 - col]);
            leds[row][col].r = c.r;
            leds[row][col].g = c.g;
            leds[row][col].b = c.b;
        }
    }
}

void tetris_setup(LED leds[][Ze::NUM_COLS], 
        tetris::SquareType tetris_board[][tetris::NUM_COLS],
        tetris::Tetromino* falling_tetromino) {
    
    tetris::clear_board(tetris_board);
    tetris::tetromino_deinit(falling_tetromino);
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
            leds[row][col].aux = nullptr;
        }
    }
}

void handle_keyboard_input(Ze::Board* board, 
        tetris::SquareType tetris_board[][tetris::NUM_COLS], 
        tetris::Tetromino* falling_tetromino) {

    if (!falling_tetromino->rushing_down) {
        Ze::Key* released = board->get_just_released_keys();

        for (uint8_t i = 0; i < board->get_num_released_keys(); ++i) {
            if (released[i].code == KEY_H) {
                tetris::try_rotate(tetris_board, falling_tetromino, true);
            } else if (released[i].code == KEY_L) {
                tetris::try_rotate(tetris_board, falling_tetromino, false);
            } else if (released[i].code == KEY_J) {
                tetris::try_move(tetris_board, falling_tetromino, false);
            } else if (released[i].code == KEY_K) {
                tetris::try_move(tetris_board, falling_tetromino, true);
            } else if (released[i].code == KEY_SPACE) {
                tetris::rush_down(falling_tetromino);
            }
        }
    }
}

void tetris_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it,
        tetris::SquareType tetris_board[][tetris::NUM_COLS],
        tetris::Tetromino* falling_tetromino) {

    handle_keyboard_input(board, tetris_board, falling_tetromino);

    if (falling_tetromino->rushing_down && it % RUSH_DELAY) {

        tetris::increment_rush(tetris_board, falling_tetromino);
        draw_tetris_board(leds, tetris_board, falling_tetromino);

    } else if (it % TETRIS_DELAY == 0) { // normal iteration

        // the rows to eliminate from the board (if any)
        bool rows_to_eliminate[tetris::NUM_ROWS];

        bool eliminate = tetris::find_rows_to_eliminate(tetris_board,
                rows_to_eliminate);

        if (eliminate) {

            mark_rows_to_eliminate(leds, rows_to_eliminate);
            eliminate_rows(tetris_board, rows_to_eliminate);
            
        } else {

            bool game_is_over = 
                !tetris::tick(tetris_board, falling_tetromino, it);
            if (game_is_over) {
                game_over(leds, tetris_board, falling_tetromino);
            } else {
                draw_tetris_board(leds, tetris_board, falling_tetromino);
            }
        }
    }
}

