#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>
#include <Arduino.h>
#include "constants.h"

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

    // Keycodes for changing the backlight brightness
    const int KEY_INC_BRIGHTNESS = KEY_LSHIFT;

    const uint8_t NUM_MODIFIERS = 6;

    const uint8_t READ_DELAY = 5;

    struct Key {
        
        /*
         * Initializes dummy key.
         */
        Key();

        /*
         * Initializes key without second function.
         */
        Key(int code, uint8_t row, uint8_t col);

        /*
         * Initializes key with main and second function.
         */
        Key(int main, int second, uint8_t row, uint8_t col);

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

        uint8_t row;

        uint8_t col;
    
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

            Key* get_curr_pressed_keys();

            uint8_t get_num_keys_pressed();

            bool brightness_inc_pressed();

        private:

            const int MODIFIER_MAP[NUM_MODIFIERS] = {

                MODIFIERKEY_LEFT_SHIFT,
                MODIFIERKEY_CTRL,
                MODIFIERKEY_LEFT_ALT,
                MODIFIERKEY_RIGHT_ALT,
                MODIFIERKEY_GUI,
                MODIFIERKEY_RIGHT_SHIFT

            };

            const uint8_t ROW_PINS[NUM_ROWS] = {0, 4, 5, 6, 7};
            const uint8_t COL_PINS[NUM_COLS] = 
            {
                8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22
            };

            bool fn_pressed;

            bool b_inc_pressed;

            uint8_t num_keys_pressed;

            uint8_t tot_num_keys_pressed;

            /*
             * The keys that are being pressed in the
             * current iteration, which can be sent.
             * The keys always occupy the lowes possible index.
             */
            Key curr_pressed_keys[MAX_NUM_KEYS];

            /*
             * Array of all currently pressed keys, even
             * those that won't be sent.
             */
            Key all_pressed_keys[NUM_ROWS * NUM_COLS];

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
            Key(KEY_ESC, 0, 0), 
            Key(KEY_1, KEY_F1, 0, 1),
            Key(KEY_2, KEY_F2, 0, 2),
            Key(KEY_3, KEY_F3, 0, 3),
            Key(KEY_4, KEY_F4, 0, 4), 
            Key(KEY_5, KEY_F5, 0, 5),
            Key(KEY_6, KEY_F6, 0, 6), 
            Key(KEY_7, KEY_F7, 0, 7),
            Key(KEY_8, KEY_F8, 0, 8),
            Key(KEY_9, KEY_F9, 0, 9),
            Key(KEY_0, KEY_F10, 0, 10), 
            Key(KEY_MINUS, 0, 11), 
            Key(KEY_EQUAL, 0, 12),
            Key(KEY_BACKSPACE, 0, 13)
        },

        //******************************************
        // ROW 1
        //******************************************

        {
            Key(KEY_TAB, 1, 0),
            Key(KEY_Q, 1, 1), 
            Key(KEY_W, 1, 2),
            Key(KEY_E, 1, 3), 
            Key(KEY_R, 1, 4),
            Key(KEY_T, 1, 5), 
            Key(KEY_Y, 1, 6),
            Key(KEY_U, 1, 7), 
            Key(KEY_I, 1, 8),
            Key(KEY_O, 1, 9), 
            Key(KEY_P, 1, 10),
            Key(KEY_LEFT_BRACE, 1, 11),
            Key(KEY_RIGHT_BRACE, 1, 12),
            Key(KEY_BACKSLASH, 1, 13)
        },

        //******************************************
        // ROW 2
        //******************************************
        
        {
            Key(KEY_FN, 2, 0),
            Key(KEY_A, 2, 1),
            Key(KEY_S, 2, 2),
            Key(KEY_D, 2, 3), 
            Key(KEY_F, 2, 4), 
            Key(KEY_G, 2, 5), 
            Key(KEY_H, KEY_LEFT, 2, 6),
            Key(KEY_J, KEY_DOWN, 2, 7),
            Key(KEY_K, KEY_UP, 2, 8),
            Key(KEY_L, KEY_RIGHT, 2, 9),
            Key(KEY_SEMICOLON, 2, 10),
            Key(KEY_QUOTE, 2, 11),
            Key(), // dummy
            Key(KEY_ENTER, 2, 13)
        },

        //******************************************
        // ROW 3
        //******************************************
        
        {
            Key(KEY_LSHIFT, 3, 0),
            Key(KEY_NON_US_BS, 3, 1),
            Key(KEY_Z, 3, 2),
            Key(KEY_X, 3, 3),
            Key(KEY_C, 3, 4),
            Key(KEY_V, 3, 5),
            Key(KEY_B, 3, 6),
            Key(KEY_N, 3, 7),
            Key(KEY_M, 3, 8),
            Key(KEY_COMMA, 3, 9),
            Key(KEY_PERIOD, 3, 10),
            Key(KEY_SLASH, 3, 11),
            Key(), // dummy
            Key(KEY_RSHIFT, 3, 13)
        },

        //******************************************
        // ROW 4
        //******************************************
        
        {
            Key(KEY_CTRL, 4, 0),
            Key(KEY_SUPER, 4, 1),
            Key(KEY_ALT, 4, 2),
            Key(), // dummy
            Key(), // dummy
            Key(), // dummy
            Key(KEY_SPACE, 4, 6),
            Key(), // dummy
            Key(), // dummy
            Key(), // dummy
            Key(KEY_ALTGR, 4, 10),
            Key(KEY_MEDIA_PLAY_PAUSE, 4, 11),
            Key(KEY_MEDIA_VOLUME_DEC, KEY_MEDIA_PREV_TRACK, 4, 12),
            Key(KEY_MEDIA_VOLUME_INC, KEY_MEDIA_NEXT_TRACK, 4, 13)
        }
    };

};

#endif
