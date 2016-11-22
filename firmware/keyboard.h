#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "backlight/leds.h"
#include <stdint.h>
#include <Arduino.h>

namespace Ze {

    const int KEY_DUMMY = 0;

    // Codes for modifiers, but aren't actual
    // keycodes for the modifiers, but exist to
    // make things more efficient. Do not change
    // these.
    const int KEY_LSHIFT = -1;
    const int KEY_CTRL = -2;
    const int KEY_ALT = -3;
    const int KEY_ALTGR = -4;
    const int KEY_SUPER = -5;
    const int KEY_RSHIFT = -6;

    // Again, this keycode is not sent, but used
    // to control behavior of other keys
    const int KEY_FN = -7;

    const uint8_t NUM_ROWS = 5;
    const uint8_t NUM_COLS = 14; 
    const uint8_t NUM_MODIFIERS = 6;
    const uint8_t MAX_NUM_KEYS = 6;

    const uint8_t READ_DELAY = 5;

    struct Key {
        
        /*
         * Initializes dummy key.
         */
        Key();

        /*
         * Initializes key without second function.
         */
        Key(int code, led_t led);

        /*
         * Initializes key with main and second function.
         */
        Key(int main, int second, led_t led);

        /*
         * Checks whether this key is a modifier key.
         */
        bool is_modifier() const;

        /*
         * Checks whether this key is a media key.
         */
        bool is_media() const;

        /*
         * Checks whether this key is a dummy key.
         */
        bool is_dummy() const;

        /*
         * Checks whether this key is the FN key.
         */
        bool is_fn() const;

        /*
         * Checks whether this key has a second function.
         */
        bool has_second() const;

        bool operator==(const Key& other) const;

        bool operator!=(const Key& other) const;

        /*
         * The associated LED with this key.
         */
        led_t led;

        /* 
         * The keycode for the main function of this key.
         */
        int code;

        /*
         * The keycode for the second function of this key,
         * that is, the function this key will have when 
         * the FN-key is pressed. If this key has no second
         * function, this is set as KEY_DUMMY.
         */
        int second;
    
    };

    class Board {

        public:
            
            /*
             * Initializes the keyboard, by initializing
             * the ports to the switches. Does not initialize
             * the backlighting.
             */
            void init();

            void update();

        private:

            const int MODIFIER_MAP[NUM_MODIFIERS] = {

                MODIFIERKEY_LEFT_SHIFT,
                MODIFIERKEY_CTRL,
                MODIFIERKEY_LEFT_ALT,
                MODIFIERKEY_RIGHT_ALT,
                MODIFIERKEY_GUI,
                MODIFIERKEY_RIGHT_SHIFT

            };

            const uint8_t ROW_PINS[NUM_ROWS] = {8, 9, 10, 11, 12};
            const uint8_t COL_PINS[NUM_COLS] = 
            {
                0,  1,  2,
                29, 14, 15, 
                16, 17, 18,
                19, 20, 21,
                22, 23
            };

            bool fn_pressed;

            uint8_t num_keys_pressed;

            /*
             * The keys that are being pressed in the
             * current iteration. The keys always
             * occupy the lowes possible index.
             */
            Key curr_pressed_keys[MAX_NUM_KEYS];

            /*
             * The keys to be sent. We need this
             * to make sure that the same key is
             * not in one instance sent as for instance
             * key 1, and then key 2. 
             */
            Key keys_to_send[MAX_NUM_KEYS];

            /*
             * The actual keycodes to be sent;
             */
            int codes_to_send[MAX_NUM_KEYS];

            int current_modifier;

            Key pressed_media;

            int current_media;

            int test_counter;
            
            void print_key_arrays();

            /*
             * Gets the real modifier code for a modifier key.
             * Does not translate the FN-key, and the modifier
             * must be negative.
             */
            int translate_modifier(const int modifier) const;

            /*
             * Removes the keys from the keys_to_send
             * and codes_to_send arrays that are no
             * longer being pressed.
             */
            void remove_released_keys();

            /*
             * Clears curr_pressed_keys.
             */
            void reset_pressed_keys();

            /*
             * Places a key into a free spot in the
             * keys_to_send and codes_to_send arrays.
             * Returns true if the key was placed,
             * false if the array was full
             * or the key had already been placed.
             */
            bool try_place_key(Key& k);

            /*
             * Updates the keys_to_send
             * and codes_to_send arrays, 
             * based on an up to date
             * curr_pressed_keys array.
             */
            void update_keys_to_send();

            void scan_keys();

            void send_keys();
    
    };

    const Key KEYS[NUM_ROWS][NUM_COLS] = {

        //******************************************
        // ROW 0
        //******************************************
        
        {
            Key(KEY_ESC, LED_ESC), 
            Key(KEY_1, KEY_F1, LED_1),
            Key(KEY_2, KEY_F2, LED_2),
            Key(KEY_3, KEY_F3, LED_3),
            Key(KEY_4, KEY_F4, LED_4), 
            Key(KEY_5, KEY_F5, LED_5),
            Key(KEY_6, KEY_F6, LED_6), 
            Key(KEY_7, KEY_F7, LED_7),
            Key(KEY_8, KEY_F8, LED_8),
            Key(KEY_9, KEY_F9, LED_9),
            Key(KEY_0, KEY_F10, LED_0), 
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
            Key(KEY_H, KEY_LEFT, LED_H), 
            Key(KEY_J, KEY_DOWN, LED_J), 
            Key(KEY_K, KEY_UP, LED_K), 
            Key(KEY_L, KEY_RIGHT, LED_L), 
            Key(KEY_SEMICOLON, LED_SEMICOLON), 
            Key(KEY_QUOTE, LED_QUOTE),
            Key(), // dummy
            Key(KEY_ENTER, LED_ENTER)
        },

        //******************************************
        // ROW 3
        //******************************************
        
        {
            Key(KEY_LSHIFT, LED_LEFT_SHIFT),
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
            Key(KEY_RSHIFT, LED_RIGHT_SHIFT),
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
            Key(KEY_MEDIA_VOLUME_DEC, KEY_MEDIA_PREV_TRACK, LED_VOL_DOWN),
            Key(KEY_MEDIA_VOLUME_INC, KEY_MEDIA_NEXT_TRACK, LED_VOL_UP)
        }
    };

};

#endif
