#include "christmas.h"
#include <Arduino.h>


void christmas_setup(LED leds[][Ze::NUM_COLS], uint8_t* scroll) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            LED* l = &leds[row][col];
            l->r = 0;
            l->g = 0;
            l->b = 0;
        }
    }
    *scroll = TREE_HEIGHT - 1;
}

void christmas_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, uint64_t it, uint8_t* scroll) {

    if (it % CHRISMAS_DELAY == 0) {
        for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
            for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
                LED* l = &leds[row][col];
                uint8_t val = TREE_GRID[(Ze::NUM_ROWS - row - 1) + *scroll - Ze::NUM_ROWS][col];

                if (val == GREEN) {
                    l->r = 0;
                    l->g = 1;
                    l->b = 0;
                } else if (val == RED) {
                    l->r = 1;
                    l->g = 0;
                    l->b = 0;
                } else if (val == EMPTY) {
                    l->r = 0;
                    l->g = 0;
                    l->b = 0;
                } else if (val == GOLD) {
                    l->r = 1;
                    l->g = 0.84;
                    l->b = 0;
                } else if (val == WHITE) {
                    l->r = 1;
                    l->g = 1;
                    l->b = 1;
                }

            }
        }
        if (*scroll == 0) {
            *scroll = TREE_HEIGHT - 1;
        } else {
            *scroll -= 1;
        }
    
    }
}

