#ifndef STANDARD_H
#define STANDARD_H 

#include "../constants.h"
#include "../led.h"
#include "../keyboard.h"

const float DEFAULT_BRIGHTNESS = 0.1;

void standard_setup(LED leds[][Ze::NUM_COLS]);

void standard_update(LED leds[][Ze::NUM_COLS], Ze::Board* board);

#endif /* ifndef STANDARD_H */
