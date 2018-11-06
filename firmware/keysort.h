#ifndef KEYSORT_H
#define KEYSORT_H 

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

struct Swap {
    uint8_t src;
    uint8_t dest;
};

const uint8_t NUM_KEYS = Ze::NUM_COLS*Ze::NUM_ROWS;

void keysort_setup(LED leds[][Ze::NUM_COLS], uint8_t intensities[NUM_KEYS]);

void keysort_update(LED leds[][Ze::NUM_COLS], Ze::Board* board,
        uint64_t it, uint8_t intensities[NUM_KEYS], uint8_t intensities_temp[NUM_KEYS],
        Swap swaps[NUM_KEYS*NUM_KEYS], int* swap_ptr);

#endif
