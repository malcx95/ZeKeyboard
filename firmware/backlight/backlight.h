#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include "Tlc5940.h"
#include "leds.h"

class Backlight {

    public:

        Backlight(Tlc5940* tlc);

        virtual void setup() = 0;

        virtual void update() = 0;

    protected:

        Tlc5940 tlc;

};

#endif
