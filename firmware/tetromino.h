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
        TETROMINO_I = 0, TETROMINO_L = 1, TETROMINO_J = 2, TETROMINO_O = 3,
        TETROMINO_S = 4, TETROMINO_T = 5, TETROMINO_Z = 6, TETROMINO_NONE = 7
    };

    struct Tetromino {
        int8_t x;
        int8_t y;
        TetrominoType type;
        uint8_t body[TETROMINO_SIZE][TETROMINO_SIZE];
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

    // for testing
    char tetrominotype_to_char(TetrominoType type);

    void tetromino_init(Tetromino* t, 
            TetrominoType type);

    void tetromino_deinit(Tetromino* t);

    bool is_tetromino_falling(Tetromino* t);

    TetrominoType generate_random_tetromino_type(uint64_t it);

    SquareType tetromino_type_to_square_type(TetrominoType type);

    Color square_type_to_color(SquareType type);

    void tetromino_rotate_left(Tetromino* t);

    void tetromino_rotate_right(Tetromino* t);

    void tetromino_copy(Tetromino* src, Tetromino* copy);

    char squaretype_to_char(SquareType type);

};

#endif /* ifndef TETROMINO_H */
