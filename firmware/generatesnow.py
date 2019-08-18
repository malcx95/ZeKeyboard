import numpy as np
import random

skeleton = """
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

const uint8_t NUM_FRAMES = {count};

const uint8_t TREE_GRID[NUM_FRAMES][Ze::NUM_ROWS][Ze::NUM_COLS] = {{
{{
    {{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}
}},
{{
    {{0, 1, 1, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0}},
    {{1, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0}},
    {{1, 0, 1, 1, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0}},
    {{1, 0, 0, 1, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0}},
    {{0, 1, 1, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0}}
}},
{{
    {{0, 1, 1, 1, 0, 0, 2, 2, 0, 0, 3, 3, 3, 0}},
    {{1, 0, 0, 0, 0, 2, 0, 0, 2, 0, 3, 0, 0, 3}},
    {{1, 0, 1, 1, 0, 2, 0, 0, 2, 0, 3, 0, 0, 3}},
    {{1, 0, 0, 1, 0, 2, 0, 0, 2, 0, 3, 0, 0, 3}},
    {{0, 1, 1, 1, 0, 0, 2, 2, 0, 0, 3, 3, 3, 0}}
}},
{{
    {{0, 1, 1, 1, 0, 0, 2, 2, 0, 0, 3, 3, 3, 0}},
    {{1, 0, 0, 0, 0, 2, 0, 0, 2, 0, 3, 0, 0, 3}},
    {{1, 0, 1, 1, 0, 2, 0, 0, 2, 0, 3, 0, 0, 3}},
    {{1, 0, 0, 1, 0, 2, 0, 0, 2, 0, 3, 0, 0, 3}},
    {{0, 1, 1, 1, 0, 0, 2, 2, 0, 0, 3, 3, 3, 0}}
}},
{{
    {{0, 1, 1, 1, 0, 0, 2, 2, 0, 0, 3, 3, 3, 0}},
    {{1, 0, 0, 0, 0, 2, 0, 0, 2, 0, 3, 0, 0, 3}},
    {{1, 0, 1, 1, 0, 2, 0, 0, 2, 0, 3, 0, 0, 3}},
    {{1, 0, 0, 1, 0, 2, 0, 0, 2, 0, 3, 0, 0, 3}},
    {{0, 1, 1, 1, 0, 0, 2, 2, 0, 0, 3, 3, 3, 0}}
}},
{{
    {{0, 0, 0, 2, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0}},
    {{0, 0, 0, 2, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0}},
    {{0, 0, 0, 2, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0}},
    {{0, 2, 0, 2, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0}},
    {{0, 0, 2, 0, 0, 0, 3, 3, 0, 0, 1, 1, 1, 1}}
}},
{{
    {{0, 0, 0, 2, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0}},
    {{0, 0, 0, 2, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0}},
    {{0, 0, 0, 2, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0}},
    {{0, 2, 0, 2, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0}},
    {{0, 0, 2, 0, 0, 0, 3, 3, 0, 0, 1, 1, 1, 1}}
}},
{{
    {{0, 0, 0, 2, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0}},
    {{0, 0, 0, 2, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0}},
    {{0, 0, 0, 2, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0}},
    {{0, 2, 0, 2, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0}},
    {{0, 0, 2, 0, 0, 0, 3, 3, 0, 0, 1, 1, 1, 1}}
}},
{christmas}
}};

void christmas_setup(LED leds[][Ze::NUM_COLS], uint8_t* scroll);

void christmas_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, uint64_t it, uint8_t* scroll);

#endif
"""

NUM_ROWS = 5
NUM_COLS = 14

NUM_FRAMES = 70

frames = []
frame = np.zeros((NUM_ROWS, NUM_COLS))

snow_flakes = []

for i in range(NUM_FRAMES):
    # top_row = np.zeros((NUM_COLS,), dtype='uint8')
    for i in range(NUM_COLS):
        if random.randint(0, 20) == 0 and frame[0, i] == 0:
            snow_flakes.append((-1, i))
    for i in range(len(snow_flakes)):
        y, x = snow_flakes[i]
        if y != NUM_ROWS-1 and frame[y+1, x] == 0:
            snow_flakes[i] = (y+1, x)

    new_frame = np.zeros((NUM_ROWS, NUM_COLS), dtype='uint8')
    for y, x in snow_flakes:
        new_frame[y, x] = 4
    
    frames.append(new_frame)
    frame = new_frame

final_frames = []
for frame in frames:
    rows = []
    for i in range(NUM_ROWS):
        row = "{" + ", ".join(str(int(x)) for x in list(frame[i, :])) + "}"
        rows.append(row)
    final_frames.append("{\n" + ",\n".join(rows) + "\n}")

code = ",\n".join(final_frames)
all_code = skeleton.format(christmas=code, count=NUM_FRAMES+8)

with open("christmas.h", "w") as f:
    f.write(all_code)

