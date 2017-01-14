#include "water.h"
#include <math.h>
#include <Arduino.h>

const int NUM_NEIGHBORS = 4;

void get_neighbors(WaterParticle particles[][WATER_WIDTH],
        WaterParticle neighbors[NUM_NEIGHBORS], int row, int col) {
    neighbors[0] = particles[clamp(row + 1, WATER_HEIGHT - 1)][clamp(col, WATER_WIDTH - 1)];
    neighbors[1] = particles[clamp(row - 1, WATER_HEIGHT - 1)][clamp(col, WATER_WIDTH - 1)];
    neighbors[2] = particles[clamp(row, WATER_HEIGHT - 1)][clamp(col + 1, WATER_WIDTH - 1)];
    neighbors[3] = particles[clamp(row, WATER_HEIGHT - 1)][clamp(col - 1, WATER_WIDTH - 1)];
}

void do_water_physics(WaterParticle particles[][WATER_WIDTH],
        WaterParticle copy[][WATER_WIDTH]) {
    for (int row = 0; row < WATER_HEIGHT; ++row) {
        for (int col = 0; col < WATER_WIDTH; ++col) {
            WaterParticle neighbors[NUM_NEIGHBORS];
            get_neighbors(copy, neighbors, row, col);
            int speed = 0;
            for (uint8_t i = 0; i < NUM_NEIGHBORS; ++i) {
                speed += (int)neighbors[i].pos;
            }
            speed = (speed / NUM_NEIGHBORS) - copy[row][col].pos;
            particles[row][col].speed = (int16_t)(((float)(copy[row][col].speed + speed))
                    * DAMPENING);
            particles[row][col].pos += particles[row][col].speed;
            //Serial.print(particles[row][col].pos);
            //Serial.print(" ");
        }
        //Serial.println("");
    }
}

void convert_colors(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_WIDTH], uint64_t it) {
    //Color base_color = {
    //    (sin(it * RED_SPEED_W / GLOBAL_SPEED_DIVISOR_W) + 1) / 2,
    //    (cos(it * GREEN_SPEED_W / GLOBAL_SPEED_DIVISOR_W) + 1) / 2,
    //    (sin(it * BLUE_SPEED_W / GLOBAL_SPEED_DIVISOR_W) + 1) / 2,
    //};
    Color base_color = {0.0, 0.0, 1.0};
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            if (!leds[row][col].is_dummy()) {
                Color res;
                LED* led = &leds[row][col];
                WaterParticle* p = (WaterParticle*)led->aux;
                float amount = ((((float)p->pos) / 32767.0) + 1.0) / 2.0;
                amount *= amount * amount;
                //Serial.print(amount);
                //Serial.print(" ");
                //morph(base_color, WAVE_COLOR, amount, res);
                //led->r = res.r;
                //led->g = res.g;
                //led->b = res.b;
                led->r = 0;
                led->g = 0;
                led->b = amount;
            }
        }
        //Serial.println("");
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
            particles[row][col] = {0, 0, row, col};
        }
    }
    map_leds(leds, particles);
}

void react_to_keypress(Ze::Board* board,
        WaterParticle particles[][WATER_WIDTH], LED leds[][Ze::NUM_COLS]) {
    Ze::Key* keys = board->get_just_released_keys();
    
    for (uint8_t i = 0; i < board->get_num_released_keys(); ++i) {
        LED* led = &leds[keys[i].row][keys[i].col];
        WaterParticle* p = (WaterParticle*)led->aux;
        
        for (int row = p->row - KEY_PRESS_RADIUS; row < p->row + KEY_PRESS_RADIUS; ++row) {
            for (int col = p->col - KEY_PRESS_RADIUS; col < p->col + KEY_PRESS_RADIUS; ++col) {
                particles[clamp(row, WATER_HEIGHT - 1)]
                    [clamp(col, WATER_WIDTH - 1)].pos = 32767;
            }
        }

    }
}

void water_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, WaterParticle particles[][WATER_WIDTH], uint64_t it) {
    react_to_keypress(board, particles, leds);
    WaterParticle copy[WATER_HEIGHT][WATER_WIDTH];
    copy_particles(particles, copy);

    do_water_physics(particles, copy);
    
    convert_colors(leds, particles, it);
}

