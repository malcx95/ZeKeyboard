#ifndef WATER_H
#define WATER_H

/*
 * A backlight effect that simulates a pool
 * of liquid. Press a key to disrupt the surface.
 */

#include "constants.h"
#include "keyboard.h"
#include "led.h"
#include "util.h"
#include <math.h>

#ifdef SIXTY_PERCENT
const uint8_t WATER_HEIGHT = 30;
const uint8_t WATER_WIDTH = 90;
#elif defined FULLSIZE
const uint8_t WATER_HEIGHT = 40;
const uint8_t WATER_WIDTH = 160;
#elif defined V2 //  TODO UPDATE
const uint8_t WATER_HEIGHT = 40;
const uint8_t WATER_WIDTH = 160;
#endif
const float WIDTH_UNIT = WATER_WIDTH / Ze::NUM_COLS;
const float HEIGHT_UNIT = WATER_HEIGHT / Ze::NUM_ROWS;

const float PHI_SPEED = 2.0;
const float THETA_SPEED = 3.0;
const float GLOBAL_SPEED_DIVISOR_W = 500.0;

const float CORNER_DIST = 1.0 / sqrt(2);

const float DAMPENING = 0.98;

const uint8_t KEY_PRESS_RADIUS = 4;

const int16_t PRESS_FORCE = 12000;

struct WaterParticle {
    int16_t speed;
    int16_t pos;
    int16_t prev_speed;
    int16_t prev_pos;
#ifdef SIXTY_PERCENT
    int8_t row;
    int8_t col;
#else
    int16_t row;
    int16_t col;
#endif

};

void water_setup(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_WIDTH]);

void water_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, WaterParticle particles[][WATER_WIDTH], uint64_t it);

void water_destroy(WaterParticle particles[][WATER_WIDTH]);

// The widths of the keys, zeros are dummies

#ifdef SIXTY_PERCENT
const float KEY_WIDTHS[Ze::NUM_ROWS][Ze::NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {1.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.5},
    {1.7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2.3},
    {1.25, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2.75},
    {1.25, 1.25, 1.25, 0, 0, 2, 2.25, 2, 0, 0, 1.25, 1.25, 1.25, 1.25}
};

#elif defined FULLSIZE
const float KEY_WIDTHS[Ze::NUM_ROWS][Ze::NUM_COLS] = {
    {2, 0, 1, 1, 1, 1.5, 0, 1, 1, 1, 1.5, 1, 1, 1, 1.5, 1, 1, 1.5, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2.5, 1, 1, 1.5, 1, 1, 1, 1},
    {1.5, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1.5, 1, 1, 1, 1},
    {1.7, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7.3, 0, 0, 0, 0, 1, 1, 2, 0},
    {1.25, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 4.25, 0, 2.5, 0, 1, 1, 1, 1},
    {1.25, 0, 1.25, 1.25, 0, 0, 0, 6.25, 0, 0, 0, 1.25, 1.25, 1.25, 1.75, 1, 1, 1.5, 0, 2, 1, 0}
};
#elif defined V2 
const float KEY_WIDTHS[Ze::NUM_ROWS][Ze::NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1},
    {1.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.5, 1, 1, 1, 1},
    {1.7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2.3, 1, 1, 2, 0},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2.75, 1, 1, 1, 1},
    {1.25, 1.25, 1.25, 0, 0, 2, 2.25, 2, 0, 0, 1.25, 1.25, 1.25, 1.25, 0, 2, 1, 0}
};
#endif

#endif /* ifndef WATER_H */

