#ifndef WATER_H
#define WATER_H

/*
 * A backlight effect that simulates a pool
 * of liquid. Press a key do disrupt the surface.
 */

#include "constants.h"
#include "keyboard.h"
#include "led.h"
#include "util.h"
#include <math.h>

const uint8_t WATER_HEIGHT = 30;
const uint8_t WATER_WIDTH = 90;
const float WIDTH_UNIT = WATER_WIDTH / Ze::NUM_COLS;
const float HEIGHT_UNIT = WATER_HEIGHT / Ze::NUM_ROWS;

const float PHI_SPEED = 2.0;
const float THETA_SPEED = 3.0;
const float GLOBAL_SPEED_DIVISOR_W = 500.0;

const float CORNER_DIST = 1.0 / sqrt(2);

const float DAMPENING = 0.98;

const uint8_t KEY_PRESS_RADIUS = 4;

struct WaterParticle {
    int16_t speed;
    int16_t pos;
    int16_t prev_speed;
    int16_t prev_pos;
    int8_t row;
    int8_t col;
};

void water_setup(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_WIDTH]);

void water_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, WaterParticle particles[][WATER_WIDTH], uint64_t it);

void water_destroy(WaterParticle particles[][WATER_WIDTH]);

// The widths of the keys, zeros are dummies
const float KEY_WIDTHS[Ze::NUM_ROWS][Ze::NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {1.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.5},
    {1.7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2.3},
    {1.25, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2.75},
    {1.25, 1.25, 1.25, 0, 0, 2, 2.25, 2, 0, 0, 1.25, 1.25, 1.25, 1.25}
};

#endif /* ifndef WATER_H */

