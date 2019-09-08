#ifndef HEATMAP_H
#define HEATMAP_H 

#include "constants.h"
#include "led.h"
#include "keyboard.h"
#include <math.h>


void heatmap_setup(LED leds[][Ze::NUM_COLS], uint8_t count_map[][Ze::NUM_COLS],
        bool previously_pressed[][Ze::NUM_COLS]);

void heatmap_update(LED leds[][Ze::NUM_COLS], uint8_t count_map[][Ze::NUM_COLS],
        bool previously_pressed[][Ze::NUM_COLS], Ze::Board* board, uint64_t it);

#endif /* ifndef HEATMAP_H */
