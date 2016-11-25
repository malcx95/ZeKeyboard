#ifndef STANDARD_H
#define STANDARD_H 

#include "../constants.h"
#include "../led.h"

void standard_setup(LED leds[Ze::NUM_ROWS][Ze::NUM_COLS]);

void standard_update(LED leds[Ze::NUM_ROWS][Ze::NUM_COLS], Tlc5940* tlc, Ze::Board* board);

#endif /* ifndef STANDARD_H */
