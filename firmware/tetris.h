#ifndef TETRIS_H
#define TETRIS_H

#include "led.h"
#include "keyboard.h"

void tetris_setup(LED leds[][Ze::NUM_COLS]);

void tetris_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it);

#endif /* ifndef TETRIS_H */
