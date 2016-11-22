#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include "Tlc5940.h"
#include "leds.h"
#include "../keyboard.h"

class Backlight {

    public:
        
        virtual void update() = 0;
        
    private:

        Ze::Board* keyboard;
        
};

#endif
