#ifndef RAVE_H
#define RAVE_H

#include "constants.h"
#include "led.h"
#include "keyboard.h"
#include <math.h>

void rave_setup(LED leds[][Ze::NUM_COLS]);
void rave_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it);

#endif
