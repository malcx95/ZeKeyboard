#ifndef STANDARD_H
#define STANDARD_H 

#include "constants.h"
#include "led.h"
#include "keyboard.h"
#include <math.h>

const float DEFAULT_BRIGHTNESS = 0.1;

const float RED_SPEED = 2 * M_PI;
const float GREEN_SPEED = 7;
const float BLUE_SPEED = M_PI * M_PI;

const float GLOBAL_SPEED_DIVISOR = 1000;

void standard_setup(LED leds[][Ze::NUM_COLS]);

void standard_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it);

#endif /* ifndef STANDARD_H */
