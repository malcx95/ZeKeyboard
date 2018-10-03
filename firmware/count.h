#ifndef COUNT_H
#define COUNT_H 

/*
 * The standard backlighting is a composition of sine waves
 * varying the color among other things. This creates waves of 
 * different colors propagating from varying directions with
 * varying phase difference. When a key is pressed, the key lights
 * up with the complementary color.
 */

#include "constants.h"
#include "led.h"
#include "water.h"
#include "keyboard.h"
#include <math.h>

const int16_t COUNT_AMOUNT = 2;
const int16_t FADE_FREQ = 15;
const float MAX_VAL = 100.0;

void count_setup(LED leds[][Ze::NUM_COLS], uint16_t keyboard_freq[][Ze::NUM_COLS]);

void count_update(LED leds[][Ze::NUM_COLS], uint16_t keyboard_freq[][Ze::NUM_COLS], Ze::Board* board, uint64_t it);

void count_destroy();

#endif /* ifndef STANDARD_H */
