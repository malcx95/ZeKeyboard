#include "tetromino.h"

using namespace tetris;

void tetromino_init(Tetromino* t, 
        TetrominoType type) {
    t->type = type;
    t->x = 0;
    t->y = 0;
}

void tetromino_deinit(Tetromino* t) {
    t->type = TETROMINO_NONE;
}

bool is_tetromino_falling(Tetromino* t) {
    return t->type != TETROMINO_NONE;
}

