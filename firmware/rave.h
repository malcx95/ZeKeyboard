#ifndef RAVE_H
#define RAVE_H

/*
 * A backlight profile that just rapidly flashes.
 */

#include "constants.h"
#include "led.h"
#include "keyboard.h"
#include <math.h>

void rave_setup(LED leds[][Ze::NUM_COLS]);
void rave_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it);
void rave_destroy();

#endif
