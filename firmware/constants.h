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
#elif defined V2
    const uint8_t NUM_ROWS = 5;
    const uint8_t NUM_COLS = 18; 
#endif
    const uint8_t MAX_NUM_KEYS = 6;

};

#ifdef SIXTY_PERCENT
const uint8_t NUM_LEDS = 64;
#elif defined FULLSIZE
const uint8_t NUM_LEDS = 109;
#elif defined V2
const uint8_t NUM_LEDS = 81;
#endif

#ifdef SIXTY_PERCENT
const uint8_t NUM_STYLES = 5;
enum BacklightStyle {STANDARD, WATER, GAMEOFLIFE, TETRIS, CHRISTMAS, RAVE};
#elif defined FULLSIZE
const uint8_t NUM_STYLES = 4;
enum BacklightStyle {STANDARD, GAMEOFLIFE, TETRIS, WATER, CHRISTMAS, RAVE};
#elif defined V2
const uint8_t NUM_STYLES = 7;
enum BacklightStyle {STANDARD, ATT, WATER, GAMEOFLIFE, TETRIS, CHRISTMAS, HEATMAP, RAVE};
#endif

#endif /* ifndef CONSTANTS_H */

