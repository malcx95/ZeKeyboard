#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <stdint.h>

namespace Ze {

    const uint8_t NUM_ROWS = 5;
    const uint8_t NUM_COLS = 14; 
    const uint8_t MAX_NUM_KEYS = 6;

};

const uint8_t NUM_LEDS = 64;

// 4, since we don't want to use the last one
const uint8_t NUM_STYLES = 4;
enum BacklightStyle {STANDARD, WATER, GAMEOFLIFE, TETRIS, RAVE};

#endif /* ifndef CONSTANTS_H */

