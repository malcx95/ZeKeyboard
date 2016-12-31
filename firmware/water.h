#ifndef WATER_H
#define WATER_H

#include "constants.h"
#include "keyboard.h"
#include "led.h"

const uint8_t WATER_HEIGHT = 60;
const uint8_t WATER_WIDTH = 20;

struct WaterParticle {

    int8_t speed;

    int8_t pos;

};

void water_setup(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_HEIGHT]);

void water_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, WaterParticle particles[][WATER_HEIGHT]);

// The widths of the keys, zeros are dummies
const float KEY_WIDTHS[Ze::NUM_ROWS][Ze::NUM_COLS] {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {1.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.5},
    {1.7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2.3},
    {1.25, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2.75},
    {1.25, 1.25, 1.25, 0, 0, 2, 2.25, 2, 0, 0, 1.25, 1.25, 1.25, 1.25}
};

#endif /* ifndef WATER_H */
