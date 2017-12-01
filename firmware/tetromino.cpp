#include "tetromino.h"

using namespace tetris;

void tetris::tetromino_init(Tetromino* t, 
        TetrominoType type) {
    t->type = type;
    t->x = 0;
    t->y = 0;
}

void tetris::tetromino_deinit(Tetromino* t) {
    t->type = TETROMINO_NONE;
}

bool tetris::is_tetromino_falling(Tetromino* t) {
    return t->type != TETROMINO_NONE;
}

TetrominoType tetris::generate_random_tetromino_type(uint64_t it) {
    return (TetrominoType)(it % (NUM_TETROMINOS - 1));
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

uint8_t** tetris::get_body(TetrominoType type) {
    switch (type) {
        case TETROMINO_I:
            return (uint8_t**)I_BODY;
        case TETROMINO_L:
            return (uint8_t**)L_BODY;
        case TETROMINO_J:
            return (uint8_t**)J_BODY;
        case TETROMINO_O:
            return (uint8_t**)O_BODY;
        case TETROMINO_S:
            return (uint8_t**)S_BODY;
        case TETROMINO_T:
            return (uint8_t**)T_BODY;
        case TETROMINO_Z:
            return (uint8_t**)Z_BODY;
        default:
            return nullptr;
    }
}

// char tetris::tetrominotype_to_char(TetrominoType type) {
//     switch (type) {
//         case SQUARE_EMPTY:
//             return ' ';
//         case SQUARE_I:
//             return 'I';
//         case SQUARE_L:
//             return 'L';
//         case SQUARE_J:
//             return 'J';
//         case SQUARE_O:
//             return 'O';
//         case SQUARE_S:
//             return 'S';
//         case SQUARE_T:
//             return 'T';
//         case SQUARE_Z:
//             return 'Z';
//         default:
//             return ' ';
//     }
// }

