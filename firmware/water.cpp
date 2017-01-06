#include "water.h"
#include <math.h>
#include <Arduino.h>

void do_water_physics(WaterParticle particles[][WATER_WIDTH]) {
    for (uint8_t row = 0; row < WATER_HEIGHT; ++row) {
        for (uint8_t col = 0; col < WATER_WIDTH; ++col) {
            // TODO do physix
        }
    }
}

void convert_colors(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_WIDTH], uint64_t it) {
    Color base_color = {
        (sin(it * RED_SPEED_W / GLOBAL_SPEED_DIVISOR_W) + 1) / 2,
        (sin(it * GREEN_SPEED_W / GLOBAL_SPEED_DIVISOR_W) + 1) / 2,
        (sin(it * BLUE_SPEED_W / GLOBAL_SPEED_DIVISOR_W) + 1) / 2,
    };
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            Color res;
            LED* led = &leds[row][col];
            WaterParticle* p = (WaterParticle*)led->aux;
            float amount = p->pos / 128.0;
            morph(base_color, WAVE_COLOR, amount, res);
            led->r = res.r;
            led->g = res.g;
            led->b = res.b;
        }
    }
}

void copy_particles(WaterParticle main[][WATER_WIDTH],
        WaterParticle copy[][WATER_WIDTH] ) {
    for (uint8_t row = 0; row < WATER_HEIGHT; ++row) {
        for (uint8_t col = 0; col < WATER_WIDTH; ++col) {
            copy[row][col] = main[row][col];
        }
    }
}

void map_leds(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_WIDTH]) {

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        int curr_width = 0;
        int row_index = (int)(row * HEIGHT_UNIT) + HEIGHT_UNIT / 2;
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            if (!leds[row][col].is_dummy()) {
                float width = KEY_WIDTHS[row][col];
                float offset = width * WIDTH_UNIT / 2;
                int index = (int)curr_width + offset;
                leds[row][col].aux = (void*)&particles[row_index][index];
                curr_width += (int)2 * offset;
            }
        }
    }
}

void water_setup(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_WIDTH]) {
    for (uint8_t row = 0; row < WATER_HEIGHT; ++row) {
        for (uint8_t col = 0; col < WATER_WIDTH; ++col) {
            particles[row][col] = {0, 0};
        }
    }
    map_leds(leds, particles);
}

void water_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, WaterParticle particles[][WATER_WIDTH], uint64_t it) {
    WaterParticle copy[WATER_HEIGHT][WATER_WIDTH];
    copy_particles(particles, copy);

    do_water_physics(particles);
    
    convert_colors(leds, particles, it);
}

