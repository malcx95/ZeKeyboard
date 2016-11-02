#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <Arduino.h>
#include "backlight.h"
#include <stdint.h>

namespace Ze {

    const int LESS_THAN_MORE_THAN = -1;
    const int KEY_SHIFT = -2;
    const int KEY_CTRL = -3;
    const int KEY_ALT = -4;
    const int KEY_SUPER = -5;
    const int KEY_FN = -6;

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

    const Key KEYS[ROWS][COLS] = {

        //*****************************************************************************
        // ROW 0
        //*****************************************************************************
        
        {
            Key(KEY_ESC, LED_ESC), 
            Key(KEY_1, LED_1),
            Key(KEY_2, LED_2),
            Key(KEY_3, LED_3),
            Key(KEY_4, LED_4), 
            Key(KEY_5, LED_5),
            Key(KEY_6, LED_6), 
            Key(KEY_7, LED_7),
            Key(KEY_8, LED_8),
            Key(KEY_9, LED_9),
            Key(KEY_0, LED_0), 
            Key(KEY_MINUS, LED_MINUS), 
            Key(KEY_EQUAL, LED_EQUAL),
            Key(KEY_BACKSPACE, LED_BACKSPACE)
        },

        //*****************************************************************************
        // ROW 1
        //*****************************************************************************

        {
            Key(KEY_TAB, LED_TAB),
            Key(KEY_Q, LED_Q), 
            Key(KEY_W, LED_W),
            Key(KEY_E, LED_E), 
            Key(KEY_R, LED_R),
            Key(KEY_T, LED_T), 
            Key(KEY_Y, LED_Y),
            Key(KEY_U, LED_U), 
            Key(KEY_I, LED_I),
            Key(KEY_O, LED_O), 
            Key(KEY_P, LED_P),
            Key(KEY_LEFT_BRACE, LED_LEFT_BRACE),
            Key(KEY_RIGHT_BRACE, LED_RIGHT_BRACE),
            Key(KEY_BACKSLASH, LED_BACKSLASH)
        },

        //*****************************************************************************
        // ROW 2
        //*****************************************************************************
        
        {
            Key(KEY_FN, LED_FN),
            Key(KEY_A, LED_A), 
            Key(KEY_S, LED_S),
            Key(KEY_D, LED_D), 
            Key(KEY_F, LED_F), 
            Key(KEY_G, LED_G), 
            Key(KEY_H, LED_H), 
            Key(KEY_J, LED_J), 
            Key(KEY_K, LED_K), 
            Key(KEY_L, LED_L), 
            Key(KEY_SEMICOLON, LED_SEMICOLON), 
            Key(KEY_QUOTE, LED_QUOTE),
            Key(KEY_ENTER, LED_ENTER)
        },

        //*****************************************************************************
        // ROW 3
        //*****************************************************************************
        
        {
            Key(KEY_SHIFT, LED_LEFT_SHIFT),
            Key(KEYPAD_ASTERISK, LED_ASTERISK),
            Key(KEY_Z, LED_Z),
            Key(KEY_X, LED_X),
            Key(KEY_C, LED_C),
            Key(KEY_V, LED_V),
            Key(KEY_B, LED_B),
            Key(KEY_N, LED_N),
            Key(KEY_M, LED_M),
            Key(KEY_COMMA, LED_COMMA),
            Key(KEY_PERIOD, LED_PERIOD),
            Key(KEY_SLASH, LED_SLASH),
            Key(KEY_SHIFT, LED_RIGHT_SHIFT)
        },

        //*****************************************************************************
        // ROW 4
        //*****************************************************************************
        
        {
            Key(KEY_CTRL, LED_CTRL),
            Key(KEY_SUPER, LED_SUPER),
            Key(KEY_ALT, LED_LEFT_ALT),
            Key(KEY_SPACE, LED_SPACE_MAIN),
            Key(KEY_ALT, LED_),
            Key(KEY_, LED_),
            Key(KEY_, LED_),
            Key(KEY_, LED_),
            Key(KEY_, LED_),
            Key(KEY_, LED_),
            Key(KEY_, LED_),
            Key(KEY_, LED_),
            Key(KEY_, LED_),
        }
    };

};

#endif
