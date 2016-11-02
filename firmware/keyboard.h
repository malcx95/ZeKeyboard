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
    //     {Key(KEY_ESC, LED_ESC), Key(KEY_1, LED_1), Key(KEY_2, LED_2), Key(KEY_3, LED_3), 
    //         Key(KEY_4, LED_4), Key(KEY_5, LED_5), Key(KEY_6, LED_6), Key(KEY_7, LED_7),
    //         Key(KEY_8, LED_8), Key(KEY_9, LED_9), Key(KEY_0, LED_0), Key(KEY_MINUS, LED_MINUS), 
    //         Key(KEY_EQUAL, LED_EQUAL), Key(KEY_BACKSPACE, LED_BACKSPACE)},
    // TODO finish
    //     {},
    //     {},
    //     {},
    //     {}
    // };

};

#endif
