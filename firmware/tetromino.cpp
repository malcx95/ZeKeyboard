#include "tetromino.h"

using namespace tetris;

void body_copy(Tetromino* t, 
        const uint8_t body[TETROMINO_SIZE][TETROMINO_SIZE]) {
    for (uint8_t row = 0; row < tetris::TETROMINO_SIZE; ++row) {
        for (uint8_t col = 0; col < tetris::TETROMINO_SIZE; ++col) {
            t->body[row][col] = body[row][col];
        }
    }
}

void tetris::tetromino_rotate_right(Tetromino* t) {
    // Deal with it
    tetromino_rotate_left(t);
    tetromino_rotate_left(t);
    tetromino_rotate_left(t);
}

void tetris::tetromino_rotate_left(Tetromino* t) {
    Tetromino old;
    tetromino_copy(t, &old);
    for (uint8_t row = 0; row < tetris::TETROMINO_SIZE; ++row) {
        for (uint8_t col = 0; col < tetris::TETROMINO_SIZE; ++col) {
            t->body[row][col] = old.body[TETROMINO_SIZE - col - 1][row];
        }
    }
}

void tetris::tetromino_copy(Tetromino* src, Tetromino* copy) {
    copy->type = src->type;
    copy->x = src->x;
    copy->y = src->y;
    copy->rushing_down = src->rushing_down;
    body_copy(copy, src->body);
}


void tetris::tetromino_init(Tetromino* t, 
        TetrominoType type) {
    t->type = type;
    t->x = TETROMINO_START_X;
    t->y = TETROMINO_START_Y;
    t->rushing_down = false;
    switch (type) {
        case TETROMINO_I:
            body_copy(t, I_BODY);
            break;
        case TETROMINO_L:
            body_copy(t, L_BODY);
            break;
        case TETROMINO_J:
            body_copy(t, J_BODY);
            break;
        case TETROMINO_O:
            body_copy(t, O_BODY);
            break;
        case TETROMINO_S:
            body_copy(t, S_BODY);
            break;
        case TETROMINO_T:
            body_copy(t, T_BODY);
            break;
        case TETROMINO_Z:
            body_copy(t, Z_BODY);
            break;
    }
}


void tetris::tetromino_deinit(Tetromino* t) {
    t->type = TETROMINO_NONE;
}

bool tetris::is_tetromino_falling(Tetromino* t) {
    return t->type != TETROMINO_NONE;
}

TetrominoType tetris::generate_random_tetromino_type(uint64_t it) {
    return (TetrominoType)((it >> 1) % NUM_TETROMINOS);
}

Color tetris::square_type_to_color(SquareType type) {
    switch (type) {
        case SQUARE_I:
            return I_COLOR;
        case SQUARE_L:
            return L_COLOR;
        case SQUARE_J:
            return J_COLOR;
        case SQUARE_O:
            return O_COLOR;
        case SQUARE_S:
            return S_COLOR;
        case SQUARE_T:
            return T_COLOR;
        case SQUARE_Z:
            return Z_COLOR;
        default:
            return EMPTY_COLOR;
    }
}

SquareType tetris::tetromino_type_to_square_type(TetrominoType type) {
    switch (type) {
        case TETROMINO_I:
            return SQUARE_I;
        case TETROMINO_L:
            return SQUARE_L;
        case TETROMINO_J:
            return SQUARE_J;
        case TETROMINO_O:
            return SQUARE_O;
        case TETROMINO_S:
            return SQUARE_S;
        case TETROMINO_T:
            return SQUARE_T;
        case TETROMINO_Z:
            return SQUARE_Z;
        default:
            return SQUARE_EMPTY;
    }
}

char tetris::squaretype_to_char(SquareType type) {
    switch (type) {
        case SQUARE_EMPTY:
            return ' ';
        case SQUARE_I:
            return 'I';
        case SQUARE_L:
            return 'L';
        case SQUARE_J:
            return 'J';
        case SQUARE_O:
            return 'O';
        case SQUARE_S:
            return 'S';
        case SQUARE_T:
            return 'T';
        case SQUARE_Z:
            return 'Z';
        default:
            return ' ';
    }
}

