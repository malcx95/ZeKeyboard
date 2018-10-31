#include "water.h"
#include <Arduino.h>

const int NUM_NEIGHBORS = 8;

void get_neighbors(WaterParticle particles[][WATER_WIDTH],
        WaterParticle neighbors[NUM_NEIGHBORS / 2], int row, int col) {
    neighbors[0] = particles[clamp(row + 1, WATER_HEIGHT - 1)][clamp(col, WATER_WIDTH - 1)];
    neighbors[1] = particles[clamp(row - 1, WATER_HEIGHT - 1)][clamp(col, WATER_WIDTH - 1)];
    neighbors[2] = particles[clamp(row, WATER_HEIGHT - 1)][clamp(col + 1, WATER_WIDTH - 1)];
    neighbors[3] = particles[clamp(row, WATER_HEIGHT - 1)][clamp(col - 1, WATER_WIDTH - 1)];
}

void get_corner_neighbors(WaterParticle particles[][WATER_WIDTH],
        WaterParticle neighbors[NUM_NEIGHBORS / 2], int row, int col) {
    neighbors[0] = particles[clamp(row + 1, WATER_HEIGHT - 1)]
        [clamp(col + 1, WATER_WIDTH - 1)];
    neighbors[1] = particles[clamp(row - 1, WATER_HEIGHT - 1)]
        [clamp(col + 1, WATER_WIDTH - 1)];
    neighbors[2] = particles[clamp(row + 1, WATER_HEIGHT - 1)]
        [clamp(col - 1, WATER_WIDTH - 1)];
    neighbors[3] = particles[clamp(row - 1, WATER_HEIGHT - 1)]
        [clamp(col - 1, WATER_WIDTH - 1)];
}

void do_water_physics(WaterParticle particles[][WATER_WIDTH]) {
    for (int row = 0; row < WATER_HEIGHT; ++row) {
        for (int col = 0; col < WATER_WIDTH; ++col) {
            WaterParticle* p = &particles[row][col];

            // make sure we still have the previous speed and position
            p->prev_speed = p->speed;
            p->prev_pos = p->pos;

            WaterParticle neighbors[NUM_NEIGHBORS / 2];
            WaterParticle corners[NUM_NEIGHBORS / 2];

            get_neighbors(particles, neighbors, row, col);
            get_corner_neighbors(particles, corners, row, col);
            int speed = 0;
            for (uint8_t i = 0; i < NUM_NEIGHBORS / 2; ++i) {
                speed += (int)neighbors[i].prev_pos;
                speed += (int)(corners[i].prev_pos * CORNER_DIST);
            }
            speed = (speed / NUM_NEIGHBORS) - p->prev_pos;
            p->speed = (int16_t)(((float)(p->prev_speed + speed)) *
                    DAMPENING);
            p->pos += p->speed;
        }
    }
}

void convert_colors(LED leds[][Ze::NUM_COLS],
        WaterParticle particles[][WATER_WIDTH], uint64_t it) {
    Color res;
    spherical_color(
            1.0, 
            it * PHI_SPEED / GLOBAL_SPEED_DIVISOR_W,
            it * THETA_SPEED / GLOBAL_SPEED_DIVISOR_W, 
            res);
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            if (!leds[row][col].is_dummy()) {
                LED* led = &leds[row][col];
                WaterParticle* p = (WaterParticle*)led->aux;
                float amount = ((((float)p->pos) / 32767.0) + 1.0) / 2.0;
                amount *= amount * amount;
                led->r = fabs(res.r) * amount;
                led->g = fabs(res.g) * amount;
                led->b = fabs(res.b) * amount;
            }
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
            particles[row][col] = {0, 0, 0, 0, row, col};
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
                    [clamp(col, WATER_WIDTH - 1)].pos = PRESS_FORCE;
            }
        }

    }
}

void update_previous_fields(WaterParticle particles[][WATER_WIDTH]) {
    for (uint8_t row = 0; row < WATER_HEIGHT; ++row) {
        for (uint8_t col = 0; col < WATER_WIDTH; ++col) {
            WaterParticle* p = &particles[row][col];
            p->prev_pos = p->pos;
            p->prev_speed = p->speed;
        }
    }
}

void water_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, WaterParticle particles[][WATER_WIDTH], uint64_t it) {
    react_to_keypress(board, particles, leds);

    do_water_physics(particles);
    
    convert_colors(leds, particles, it);

    update_previous_fields(particles);
}

void water_destroy(WaterParticle particles[][WATER_WIDTH]) {
    // TODO implement and change from array to **
}

