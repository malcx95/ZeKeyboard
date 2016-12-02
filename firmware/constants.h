#ifndef CONSTANTS_H
#define CONSTANTS_H value
#include <stdint.h>

namespace Ze {

    const uint8_t NUM_ROWS = 5;
    const uint8_t NUM_COLS = 14; 
    const uint8_t MAX_NUM_KEYS = 6;

};

const uint8_t ROW0_PIN = 3;
const uint8_t ROW1_PIN = 4;
const uint8_t ROW2_PIN = 5;
const uint8_t ROW3_PIN = 6;
const uint8_t ROW4_PIN = 7;

const uint8_t NUM_ROW0_LEDS = 14;
const uint8_t NUM_ROW1_LEDS = 14;
const uint8_t NUM_ROW2_LEDS = 13;
const uint8_t NUM_ROW3_LEDS = 13;
const uint8_t NUM_ROW4_LEDS = 10;

const uint8_t LED_ROW_LENGTHS[Ze::NUM_ROWS] = {
    NUM_ROW0_LEDS,
    NUM_ROW1_LEDS,
    NUM_ROW2_LEDS,
    NUM_ROW3_LEDS,
    NUM_ROW4_LEDS
};

enum BacklightStyle {STANDARD};

#endif /* ifndef CONSTANTS_H */

