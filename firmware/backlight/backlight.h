#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include "Tlc5940.h"
#include "leds.h"
#include "../keyboard.h"
#include <stdint.h>


typedef uint8_t led_t;


struct LED {

    LED(led_t port);

    bool is_dummy();

    led_t port;

    uint16_t brightness;

};

class Backlight {

    public:

        Backlight(Tlc5940* tlc, Ze::Board* keyboard);

        virtual void setup() = 0;

        virtual void update() = 0;

    protected:

        Tlc5940* tlc;

        Ze::Board* keyboard;

        LED leds[Ze::NUM_ROWS][Ze::NUM_COLS];

};

const led_t LED_DUMMY = 0;

const led_t LED_GRID[NUM_ROWS][NUM_COLS] =
{
    {
        LED_ESC,
        LED_1,
        LED_2,
        LED_3,
        LED_4,
        LED_5,
        LED_6,
        LED_7,
        LED_8,
        LED_9,
        LED_0,
        LED_MINUS,
        LED_EQUAL,
        LED_BACKSPACE
    },
}

#endif
