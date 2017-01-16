#ifndef GAMOFLIFE_H
#define GAMEOFLIFE_H

#include "constants.h"
#include "led.h"

/*
 * The index of the outermost cell in the grid.
 */
const uint8_t OUTERMOST_CELL = 13;

void gameoflife_setup(LED leds[][Ze::NUM_COLS], uint16_t cells[Ze::NUM_ROWS]);

void gameoflife_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, uint16_t cells[Ze::NUM_ROWS]);

#endif
