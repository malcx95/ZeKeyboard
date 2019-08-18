#include "standard.h"
#include "config.h"
#include <Arduino.h>

void standard_setup(LED leds[][Ze::NUM_COLS], WaterParticle particles[][WATER_WIDTH]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
            // map each LED to a particle for fade out effect. Yes, this is pretty hacky.
            leds[row][col].aux = &particles[row][col];
            particles[row][col].pos = 0;
        }
    }
}

void standard_update(LED leds[][Ze::NUM_COLS], Ze::Board* board, uint64_t it) {
    float fade_dir_row = sin(ROW_DIR_CHANGE_SPEED * it / GLOBAL_SPEED_DIVISOR);
    float fade_dir_col = sin(COL_DIR_CHANGE_SPEED * it / GLOBAL_SPEED_DIVISOR);
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            float r = DEFAULT_BRIGHTNESS * 
                (cos(RED_SPEED * it / GLOBAL_SPEED_DIVISOR +
                        (row * fade_dir_row - col * fade_dir_col) *
                        PHASE_DIFFERENCE) + 1) / 2;
            float g = DEFAULT_BRIGHTNESS * 
                (sin(GREEN_SPEED * it / GLOBAL_SPEED_DIVISOR +
                        (row * fade_dir_row - col * fade_dir_col) *
                        PHASE_DIFFERENCE) + 1) / 2;
            float b = DEFAULT_BRIGHTNESS * 
                (sin(BLUE_SPEED * it / GLOBAL_SPEED_DIVISOR +
                        (row * fade_dir_row - col * fade_dir_col) *
                        PHASE_DIFFERENCE) + 1) / 2;
            LED* l = &leds[row][col];
            int16_t pos = ((WaterParticle*)l->aux)->pos;
            if (pos > 0) {
                float amount = (float)((float)pos) / ((float)INITIAL_VALUE);
                Color res = {r - (r - 1) * amount, g * (1 - amount), b * (1 - amount)};
                l->r = res.r;
                l->g = res.g;
                l->b = res.b;
                ((WaterParticle*)l->aux)->pos -= FADE_OUT_SPEED;
            } else {
                l->r = r;
                l->g = g;
                l->b = b;
            }
        }
    }

    Ze::Key* pressed = board->get_curr_pressed_keys();

    for (uint8_t i = 0; i < board->get_num_keys_pressed(); ++i) {

        Ze::Key* k = &pressed[i];
        
        ((WaterParticle*)leds[k->row][k->col].aux)->pos = INITIAL_VALUE;

#ifndef FULLSIZE 
        if (pressed[i].code == KEY_SPACE) {
            // Light up the left and right leds of the space bar
            
            ((WaterParticle*)leds[k->row][k->col - 1].aux)->pos = INITIAL_VALUE;
            ((WaterParticle*)leds[k->row][k->col + 1].aux)->pos = INITIAL_VALUE;

        }
#endif
    }
}

void standard_destroy() {}

