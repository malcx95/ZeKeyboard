#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "backlight.h"
#include <stdint.h>

namespace Ze {

    const int KEY_DUMMY = 0;

    // Codes for modifiers, but aren't actual
    // keycodes for the modifiers, but exist to
    // make things more efficient. Do not change
    // these.
    const int KEY_SHIFT = -1;
    const int KEY_CTRL = -2;
    const int KEY_ALT = -3;
    const int KEY_ALTGR = -4;
    const int KEY_SUPER = -5;

    // Again, this keycode is not sent, but used
    // to control behavior of other keys
    const int KEY_FN = -6;

    const uint8_t ROWS = 5;
    const uint8_t COLS = 14; 
    const uint8_t NUM_MODIFIERS = 5;

    struct Key {
        
        /*
         * Initializes dummy key
         */
        Key();

        /*
         * Initializes key
         */
        Key(int code, led_t led);

        /*
         * Checks whether this key is a modifier key.
         */
        bool is_modifier() const;

        /*
         * Checks whether this key is a dummy key.
         */
        bool is_dummy() const;

        /*
         * Checks whether this key is the FN key.
         */
        bool is_fn() const;

        led_t led;
        int code;
    
    };

    class Keyboard {

        public:

            Keyboard();
            ~Keyboard();

            void update();

        private:

            const int MODIFIER_MAP[NUM_MODIFIERS] = {

                MODIFIERKEY_SHIFT,
                MODIFIERKEY_CTRL,
                MODIFIERKEY_LEFT_ALT,
                MODIFIERKEY_RIGHT_ALT,
                MODIFIERKEY_GUI

            };

            /*
             * Gets the real modifier code for a modifier key.
             * Does not translate the FN-key, and the modifier
             * must be negative.
             */
            int translate_modifier(const int modifier) const;
    
    };

    const Key KEYS[ROWS][COLS] = {

        //******************************************
        // ROW 0
        //******************************************
        
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

        //******************************************
        // ROW 1
        //******************************************

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

        //******************************************
        // ROW 2
        //******************************************
        
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
            Key(), // dummy
            Key(KEY_QUOTE, LED_QUOTE),
            Key(KEY_ENTER, LED_ENTER)
        },

        //******************************************
        // ROW 3
        //******************************************
        
        {
            Key(KEY_SHIFT, LED_LEFT_SHIFT),
            Key(KEY_NON_US_BS, LED_LESS_MORE),
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
            Key(KEY_SHIFT, LED_RIGHT_SHIFT),
            Key() // dummy
        },

        //******************************************
        // ROW 4
        //******************************************
        
        {
            Key(KEY_CTRL, LED_CTRL),
            Key(KEY_SUPER, LED_SUPER),
            Key(KEY_ALT, LED_ALT),
            Key(), // dummy
            Key(), // dummy
            Key(), // dummy
            Key(KEY_SPACE, LED_SPACE_MAIN),
            Key(), // dummy
            Key(), // dummy
            Key(), // dummy
            Key(KEY_ALTGR, LED_ALTGR),
            Key(KEY_MEDIA_PLAY_PAUSE, LED_PLAY_PAUSE),
            Key(KEY_MEDIA_VOLUME_INC, LED_VOL_UP),
            Key(KEY_MEDIA_VOLUME_DEC, LED_VOL_DOWN)
        }
    };

};

#endif
