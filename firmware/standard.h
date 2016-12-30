#ifndef STANDARD_H
#define STANDARD_H 

/*
 * The standard backlighting is a composition of sine waves
 * varying the color among other things. This creates waves of 
 * different colors propagating from varying directions with
 * varying phase difference. When a key is pressed, the key lights
 * up with the complementary color.
 */

#include "constants.h"
#include "led.h"
#include "keyboard.h"
#include <math.h>

const float DEFAULT_BRIGHTNESS = 0.5;

const float RED_SPEED = 2.1;
const float GREEN_SPEED = 5.0;
const float BLUE_SPEED = M_PI * M_PI;
const float ROW_DIR_CHANGE_SPEED = M_PI / 3.0;
const float COL_DIR_CHANGE_SPEED = 0.51;

const float GLOBAL_SPEED_DIVISOR = 500.0;
const float PHASE_DIFFERENCE = 0.2;

void standard_setup(LED leds[][Ze::NUM_COLS]);

void standard_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it);

#endif /* ifndef STANDARD_H */
