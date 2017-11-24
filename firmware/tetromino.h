#ifndef TETROMINO_H
#define TETROMINO_H 

#include "util.h"

namespace tetris {

    const uint8_t NUM_TETROMINOS = 7;
    const uint8_t TETROMINO_SIZE = 4;

    enum SquareType {
        SQUARE_EMPTY, SQUARE_I, SQUARE_L, SQUARE_J,
        SQUARE_O, SQUARE_S, SQUARE_T, SQUARE_Z
    };
    
    enum TetrominoType {
        TETROMINO_I, TETROMINO_L, TETROMINO_J, TETROMINO_O,
        TETROMINO_S, TETROMINO_T, TETROMINO_Z, TETROMINO_NONE
    };

    struct Tetromino {
        uint8_t x;
        uint8_t y;
        TetrominoType type;
    };

    const uint8_t I_BODY[TETROMINO_SIZE][TETROMINO_SIZE] {
        {0,0,0,0},
        {1,1,1,1},
        {0,0,0,0},
        {0,0,0,0}
    };

    const uint8_t L_BODY[TETROMINO_SIZE][TETROMINO_SIZE] {
        {0,0,0,0},
        {1,1,1,0},
        {1,0,0,0},
        {0,0,0,0}
    };

    const uint8_t J_BODY[TETROMINO_SIZE][TETROMINO_SIZE] {
        {0,0,0,0},
        {0,1,1,1},
        {0,0,0,1},
        {0,0,0,0}
    };

    const uint8_t O_BODY[TETROMINO_SIZE][TETROMINO_SIZE] {
        {0,0,0,0},
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    const uint8_t S_BODY[TETROMINO_SIZE][TETROMINO_SIZE] {
        {0,0,0,0},
        {0,0,1,1},
        {0,1,1,0},
        {0,0,0,0}
    };

    const uint8_t T_BODY[TETROMINO_SIZE][TETROMINO_SIZE] {
        {0,0,0,0},
        {0,1,1,1},
        {0,0,1,0},
        {0,0,0,0}
    };

    const uint8_t Z_BODY[TETROMINO_SIZE][TETROMINO_SIZE] {
        {0,0,0,0},
        {1,1,0,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    
    const Color I_COLOR = {0, 1, 1};
    const Color L_COLOR = {1, 0.5, 0};
    const Color J_COLOR = {0, 0, 1};
    const Color O_COLOR = {1, 1, 0};
    const Color S_COLOR = {0, 1, 0};
    const Color T_COLOR = {0.8, 0, 1};
    const Color Z_COLOR = {1, 0, 0};
    const Color EMPTY_COLOR = {0, 0, 0};

    void tetromino_init(Tetromino* t, 
            TetrominoType type);

    void tetromino_deinit(Tetromino* t);

    bool is_tetromino_falling(Tetromino* t);

};

#endif /* ifndef TETROMINO_H */
