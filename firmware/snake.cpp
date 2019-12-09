#include "snake.h"
#include "config.h"
#ifdef SIXTY_PERCENT
    #include "sixty_layout.h"
#elif defined FULLSIZE
    #include "fullsize_layout.h"
#elif defined V2
    #include "v2_layout.h"
#endif
#include "util.h"
#include <Arduino.h>


void update_snake(SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS],
        SnakeSegment* food, uint64_t it) {
    SnakeSegment* first = snake;
    for (uint8_t i = 0; snake[i+1].active; ++i) {
        snake_segment_copy(&snake[i], &snake[i+1]);
    }
    int8_t dx = 0;
    int8_t dy = 0;
    switch (first->dir) {
        case UP:
            dy = -1;
            break;
        case DOWN:
            dy = 1;
            break;
        case LEFT:
            dx = -1;
            break;
        case RIGHT:
            dx = 1;
            break;
    }
    first->row = wrap_around(first->row + dy, Ze::NUM_ROWS - 1);
    first->col = wrap_around(first->col + dx, Ze::NUM_COLS - 1);
    if (first->row == food->row && first->col == food->col) {
        uint8_t new_row = it % (Ze::NUM_ROWS - 1);
        uint8_t new_col = it % (Ze::NUM_COLS - 1);

        food->row = new_row;
        food->col = new_col;

        Serial.println("=======================================");
        uint8_t last_index = 0;
        while (snake[last_index].active) {
            last_index++;
        }
        Serial.println("=======================================");
        last_index -= 1;
        uint8_t new_index = last_index + 1;
        Direction old_dir = snake[last_index].dir;
        int8_t new_dx = 0;
        int8_t new_dy = 0;
        switch (old_dir) {
            case UP:
                new_dy = 1;
                break;
            case DOWN:
                new_dy = -1;
                break;
            case LEFT:
                new_dx = 1;
                break;
            case RIGHT:
                new_dx = -1;
                break;
            default:
                new_dx = 5;
                new_dy = 5;
        }
        Serial.print("dx: ");
        Serial.print(new_dx);
        Serial.print(", dy: ");
        Serial.println(new_dy);
        snake[new_index].row = wrap_around(snake[last_index].row + new_dy, Ze::NUM_ROWS - 1);
        snake[new_index].col = wrap_around(snake[last_index].col + new_dx, Ze::NUM_COLS - 1);
        snake[new_index].active = true;
        snake[new_index].dir = old_dir;
        Serial.println(last_index);
        Serial.println(new_index);
        Serial.print("r: ");
        Serial.print(snake[last_index].row);
        Serial.print(", c: ");
        Serial.print(snake[last_index].col);
        Serial.print(" r2: ");
        Serial.print(snake[new_index].row);
        Serial.print(", c2: ");
        Serial.println(snake[new_index].col);
    }
}


void snake_segment_copy(SnakeSegment* from, SnakeSegment* to) {
    to->color_index = from->color_index;
    to->row = from->row;
    to->col = from->col;
    to->active = from->active;
    to->dir = from->dir;
}


void draw_snake(SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS],
        LED leds[][Ze::NUM_COLS], SnakeSegment* food) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
        }
    }
    for (uint8_t i = 0; snake[i].active; ++i) {
        Color c = COLORS[snake[i].color_index];
        uint8_t row = snake[i].row;
        uint8_t col = snake[i].col;
        leds[row][col].r = c.r;
        leds[row][col].g = c.g;
        leds[row][col].b = c.b;
    }

    Color c = COLORS[1];
    leds[food->row][food->col].r = c.r;
    leds[food->row][food->col].g = c.g;
    leds[food->row][food->col].b = c.b;

}


void update_snake_direction(Ze::Board* board,
    SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS]) {

    Ze::Key* released = board->get_just_released_keys();
    for (uint8_t i = 0; i < board->get_num_released_keys(); ++i) {
        if (released[i].code == KEY_H) {
            snake[0].dir = Direction::LEFT;
        } else if (released[i].code == KEY_L) {
            snake[0].dir = Direction::RIGHT;
        } else if (released[i].code == KEY_J) {
            snake[0].dir = Direction::DOWN;
        } else if (released[i].code == KEY_K) {
            snake[0].dir = Direction::UP;
        }
    }
}


void snake_setup(LED leds[][Ze::NUM_COLS],
        SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS], SnakeSegment* food) {
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            leds[row][col].r = 0;
            leds[row][col].g = 0;
            leds[row][col].b = 0;
        }
    }
    for (uint8_t i = 0; i < Ze::NUM_ROWS*Ze::NUM_COLS; ++i) {
        snake[i].active = false;
    }
    SnakeSegment start{ 0, 3, 10, true, Direction::UP };
    snake[0] = start;
    food->row = 2;
    food->col = 14;
}


void snake_update(LED leds[][Ze::NUM_COLS], SnakeSegment snake[Ze::NUM_COLS*Ze::NUM_ROWS],
        Ze::Board* board, uint64_t it, SnakeSegment* food) {
    if (it % 16 == 0) {
        update_snake(snake, food, it);
    }
    update_snake_direction(board, snake);
    draw_snake(snake, leds, food);

    // Serial.print("r: ");
    // Serial.print(snake[0].row);
    // Serial.print(", c: ");
    // Serial.println(snake[0].col);
}

