#ifndef HEATMAP_H
#define HEATMAP_H 

#include "constants.h"
#include "led.h"
#include "keyboard.h"
#include <math.h>


struct Position {
    uint8_t row;
    uint8_t col;
};

void heatmap_setup(LED leds[][Ze::NUM_COLS],
        Position* previously_pressed,
        uint32_t count_map[][Ze::NUM_COLS][Ze::NUM_ROWS][Ze::NUM_COLS]);

void heatmap_update(LED leds[][Ze::NUM_COLS],
        uint32_t count_map[][Ze::NUM_COLS][Ze::NUM_ROWS][Ze::NUM_COLS],
        Position* previously_pressed,
        Ze::Board* board, uint64_t it);

#endif /* ifndef HEATMAP_H */
