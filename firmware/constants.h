#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <stdint.h>
#include "config.h"

namespace Ze {

#ifdef SIXTY_PERCENT
    const uint8_t NUM_ROWS = 5;
    const uint8_t NUM_COLS = 14; 
#elif defined FULLSIZE
    const uint8_t NUM_ROWS = 6;
    const uint8_t NUM_COLS = 22; 
#endif
    const uint8_t MAX_NUM_KEYS = 6;

};

#ifdef SIXTY_PERCENT
const uint8_t NUM_LEDS = 64;
#elif defined FULLSIZE
const uint8_t NUM_LEDS = 109;
#endif

#ifdef SIXTY_PERCENT
// 4, since we don't want to use the last one
const uint8_t NUM_STYLES = 4;
enum BacklightStyle {STANDARD, WATER, GAMEOFLIFE, TETRIS, CHRISTMAS, RAVE};
#elif defined FULLSIZE
const uint8_t NUM_STYLES = 3;
enum BacklightStyle {STANDARD, GAMEOFLIFE, TETRIS, WATER, CHRISTMAS, RAVE};
#endif

#endif /* ifndef CONSTANTS_H */

