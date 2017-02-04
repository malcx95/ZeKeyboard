#ifndef VIM_H
#define VIM_H

#include "led.h"
#include "keyboard.h"

void vim_setup(LED leds[][Ze::NUM_COLS]);

void vim_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it);

#endif /* ifndef VIM_H */
