#include "water.h"

void map_leds(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_HEIGHT]) {

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            float width = KEY_WIDTHS[row][col];
            // TODO finish this
        }
    }

}

void water_setup(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_HEIGHT]) {
    // TODO implement
}

void water_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, WaterParticle particles[][WATER_HEIGHT]) {
    // TODO implement
}

