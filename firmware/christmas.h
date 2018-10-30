#ifndef CHRISTMAS_H
#define CHRISTMAS_H

#include "constants.h"
#include "keyboard.h"
#include "led.h"
#include "util.h"

const uint8_t TREE_HEIGHT = 20;
const uint8_t CHRISMAS_DELAY = 10;

const uint8_t EMPTY = 0;
const uint8_t GREEN = 1;
const uint8_t RED = 2;
const uint8_t GOLD = 3;
const uint8_t WHITE = 4;

const uint8_t TREE_GRID[TREE_HEIGHT][Ze::NUM_COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 2, 1, 1, 1, 2, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 2, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 3, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 2, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 3, 1, 0, 0, 0},
    {0, 0, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void christmas_setup(LED leds[][Ze::NUM_COLS], uint8_t* scroll);

void christmas_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, uint64_t it, uint8_t* scroll);

#endif
