#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <Arduino.h>
#include "backlight.h"
#include <stdint.h>

namespace Ze {

    const int LESS_THAN_MORE_THAN = -1;
    const int MODIFIER_SHIFT = -2;
    const int MODIFIER_CTRL = -3;
    const int MODIFIER_ALT = -4;
    const int MODIFIER_SUPER = -5;
    const int MODIFIER_FN = -6;

    const uint8_t ROWS = 5;
    const uint8_t COLS = 14; 

    struct Key {

        Key(int code, led_t led);
        led_t led;
        int code;
        bool is_modifier() const;
    
    };

    class Keyboard {

        public:

            Keyboard();
            ~Keyboard();

            void update();

        private:
    
    };

    // const Key KEYS[ROWS][COLS] = {
    //     {},
    //     {},
    //     {},
    //     {},
    //     {},
    //     {}
    // };

};

#endif
