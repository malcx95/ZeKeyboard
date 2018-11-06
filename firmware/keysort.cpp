#include "keysort.h"
#include "config.h"
#include <Arduino.h>
#include "util.h"


void swap(uint8_t intensities[NUM_KEYS], Swap swaps[NUM_KEYS*NUM_KEYS],
        int* swap_ptr, uint8_t from, uint8_t to) {
    uint8_t temp = intensities[from];
    intensities[from] = intensities[to];
    intensities[to] = temp;
    // swaps[*swap_ptr] = Swap { from, to };
    // (*swap_ptr)++;
}

uint8_t partition(uint8_t intensities[NUM_KEYS], Swap swaps[NUM_KEYS*NUM_KEYS],
        int* swap_ptr, uint8_t start, uint8_t end) {
    Serial.print("END IS ");
    Serial.println(end);
    uint8_t pivot = intensities[end];
    uint8_t i = start - 1;
    Serial.println("Here");
    Serial.print("i=");
    Serial.println(i);
    for (uint8_t j = start; j < end; ++j) {
        Serial.print("accessing: ");
        Serial.println(j);
        if (intensities[j] < pivot && i != j) {
            i++;
            swap(intensities, swaps, swap_ptr, i, j);
        }
        Serial.println("done");
    }
    i++;
    
    Serial.print("Final swap -> ");
    swap(intensities, swaps, swap_ptr, i, end);
    Serial.println("Final swap done");
    return i;
}

void quicksort(uint8_t intensities[NUM_KEYS], Swap swaps[NUM_KEYS*NUM_KEYS],
        int* swap_ptr, uint8_t start, uint8_t end) {
    if (start < end) {
        uint8_t p = partition(intensities, swaps, swap_ptr, start, end);
        quicksort(intensities, swaps, swap_ptr, start, p-1);
        quicksort(intensities, swaps, swap_ptr, p+1, end);
    }
}


Color intensity_to_color(uint8_t intensity, uint8_t max_intensity) {
    float i = ((float)intensity)/((float)max_intensity);
    return Color {i, 0, 1.0-i};
}


void keysort_setup(LED leds[][Ze::NUM_COLS], uint8_t intensities[NUM_KEYS]) {
    for (uint8_t i = 0; i < NUM_KEYS; ++i) {
        intensities[i] = i;
    }
}


void keysort_update(LED leds[][Ze::NUM_COLS], Ze::Board* board,
        uint64_t it, uint8_t intensities[NUM_KEYS], uint8_t intensities_temp[NUM_KEYS],
        Swap swaps[NUM_KEYS*NUM_KEYS], int* swap_ptr) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            Color c = intensity_to_color(intensities[row*Ze::NUM_COLS + col], NUM_KEYS-1);
            leds[row][col].r = c.r;
            leds[row][col].g = c.g;
            leds[row][col].b = c.b;
        }
    }

    Ze::Key* keys = board->get_just_released_keys();

    bool scroll_lock_pressed = false;

    // swap keys
    for (uint8_t i = 0; i < board->get_num_released_keys(); ++i) {
        uint8_t rand_key = it % NUM_KEYS;
        uint8_t pos = keys[i].row * Ze::NUM_COLS + keys[i].col;
        uint8_t temp = intensities[rand_key];
        intensities[rand_key] = intensities[pos];
        intensities[pos] = temp;

        scroll_lock_pressed = scroll_lock_pressed || keys[i].code == KEY_SCROLL_LOCK;
    }

    if (scroll_lock_pressed) {
        (*swap_ptr) = 0;
        quicksort(intensities, swaps, swap_ptr, 0, NUM_KEYS - 1);
    }
}

