#ifndef ATT_H
#define ATT_H 

#include "constants.h"
#include "led.h"
#include "water.h"
#include "keyboard.h"
#include <math.h>

void att_setup(LED leds[][Ze::NUM_COLS], uint8_t data[][Ze::NUM_COLS]);

void att_update(LED leds[][Ze::NUM_COLS], uint8_t data[][Ze::NUM_COLS], Ze::Board* board, uint64_t it);

#endif /* ifndef ATT_H */
