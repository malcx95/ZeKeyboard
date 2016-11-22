#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include "Tlc5940.h"
#include "leds.h"
#include "../keyboard.h"
#include <stdint>


typedef uint8_t led_t;


struct LED {

    LED(led_t port);

    bool is_dummy();

    led_t port;

    uint16_t brightness;

};

class Backlight {

    public:

        Backlight(Tlc5940* tlc, Ze::Board* keyboard, );

        virtual void setup() = 0;

        virtual void update() = 0;

    protected:

        Tlc5940* tlc;

        Ze::Board* keyboard;

        LED leds[Ze::NUM_ROWS][Ze::NUM_COLS];

};

#endif
