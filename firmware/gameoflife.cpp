#include "gameoflife.h"
#include <Arduino.h>

bool is_cell_alive(uint16_t cells[Ze::NUM_ROWS], uint8_t row, uint8_t col) {
    uint16_t r = cells[row];
    uint16_t mask = (1 << col);
    return (mask & r) != 0;
}

void set_cell(uint16_t cells[Ze::NUM_ROWS], uint8_t row, uint8_t col, bool alive) {
    if (alive) {
        cells[row] |= (1 << col);
    } else {
        cells[row] &= ~(1 << col);
    }
}

uint8_t count_alive_neighbors(uint16_t cells[Ze::NUM_ROWS], int8_t row, int8_t col) {
    uint8_t res = 0;
    for (int8_t i = -1; i < 2; ++i) {
        for (int8_t j = -1; j < 2; ++j) {
            if (is_cell_alive(cells, wrap_around(row + i, Ze::NUM_ROWS - 1),
                        wrap_around(col + j, Ze::NUM_COLS - 1))) {
                if (!(i == 0 && j == 0)) {
                    res++;
                }
            }
        }
    }
    return res;
}

void update_cells(uint16_t cells[Ze::NUM_ROWS]) {
    uint16_t copy[Ze::NUM_ROWS];
    for (uint8_t i = 0; i < Ze::NUM_ROWS; ++i) {
        copy[i] = cells[i];
    }

    for (int8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (int8_t col = 0; col < Ze::NUM_COLS; ++col) {
            uint8_t num_neighbors = count_alive_neighbors(copy, row, col);
            if (is_cell_alive(copy, row, col)) {
                if (num_neighbors > 3 || num_neighbors < 2) {
                    set_cell(cells, row, col, false);
                }
            } else {
                if (num_neighbors == 3) {
                    set_cell(cells, row, col, true);
                }
            }
        }
    }
}

void print_cells(uint16_t cells[Ze::NUM_ROWS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            if (is_cell_alive(cells, row, col)) {
                Serial.print(1);
            }
            else {
                Serial.print(0);
            }
            Serial.print(" ");
        }
        Serial.println("");
    }
    Serial.println("");
}

void gameoflife_setup(LED leds[][Ze::NUM_COLS], uint16_t cells[Ze::NUM_ROWS]) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            LED* l = &leds[row][col];
            l->r = 0;
            l->g = 0;
            l->b = 0;
        }
    }

    for (uint8_t i = 0; i < Ze::NUM_ROWS; ++i) {
        cells[i] = 0;
    }

    // Start with glider
    set_cell(cells, 3, 5, true);
    set_cell(cells, 3, 6, true);
    set_cell(cells, 3, 7, true);
    set_cell(cells, 2, 7, true);
    set_cell(cells, 1, 6, true);
}

void gameoflife_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, uint16_t cells[Ze::NUM_ROWS], uint64_t it) {

    if (it % DELAY == 0) {
        update_cells(cells);
    }

    // set the cells that correspond to keys to alive if they are pressed
    Ze::Key* pressed = board->get_curr_pressed_keys();
    for (uint8_t i = 0; i < board->get_num_keys_pressed(); ++i) {
        set_cell(cells, pressed[i].row, pressed[i].col, true);

        if (pressed[i].code == KEY_SPACE) {

            // Set the secondary cells of the spacebar as alive
            
            set_cell(cells, pressed[i].row, pressed[i].col - 1, true);
            set_cell(cells, pressed[i].row, pressed[i].col + 1, true);

        }

    }

    // update the leds
    for (int8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (int8_t col = 0; col < Ze::NUM_COLS; ++col) {
            if (is_cell_alive(cells, row, col)) {
                Color c = CELL_COLORS[count_alive_neighbors(cells, row, col)];
                leds[row][col].r = c.r;
                leds[row][col].g = c.g;
                leds[row][col].b = c.b;

            } else {
                leds[row][col].r = 0;
                leds[row][col].g = 0;
                leds[row][col].b = 0;
            }
        }
    }
}

