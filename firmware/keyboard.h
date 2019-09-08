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

    // Again, these keycodes are not sent, but used
    // to control behavior of other keys
    const int KEY_FN = -7;
    const int KEY_LOCK = -8;

#ifdef SIXTY_PERCENT 
    // Keycode for changing the backlight brightness
    const int KEY_INC_BRIGHTNESS = KEY_RSHIFT;

    // Keycode for changing the backlight style
    const int KEY_BACKLIGHT_STYLE = KEY_LSHIFT;
#else
    // Keycode for changing the backlight brightness
    const int KEY_INC_BRIGHTNESS = -100;

    // Keycode for changing the backlight style
    const int KEY_BACKLIGHT_STYLE = -101;
#endif

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

            Key* get_just_released_keys();

            uint8_t get_num_keys_pressed();

            uint8_t get_num_released_keys();

            bool brightness_inc_pressed();

            bool backlight_style_changed();

            bool is_just_pressed[NUM_ROWS][NUM_COLS];

        private:

            bool been_pressed[NUM_ROWS][NUM_COLS];

            const int MODIFIER_MAP[NUM_MODIFIERS] = {

                MODIFIERKEY_LEFT_SHIFT,
                MODIFIERKEY_CTRL,
                MODIFIERKEY_LEFT_ALT,
                MODIFIERKEY_RIGHT_ALT,
                MODIFIERKEY_GUI,
                MODIFIERKEY_RIGHT_SHIFT

            };

#ifdef SIXTY_PERCENT
            const uint8_t ROW_PINS[NUM_ROWS] = {0, 4, 5, 6, 7};
            const uint8_t COL_PINS[NUM_COLS] = 
            {
                8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22
            };
#elif defined FULLSIZE
            const uint8_t ROW_PINS[NUM_ROWS] = {26, 27, 28, 29, 30, 31};
            const uint8_t COL_PINS[NUM_COLS] = 
            {
                4, 5, 6, 7, 8, 9, 10, 11, 12, 1,
                14, 15, 16, 17, 18, 19, 20, 21, 22, 33, 34, 37 };
#elif defined V2
            const uint8_t ROW_PINS[NUM_ROWS] = {32, 31, 30, 29, 28};
            const uint8_t COL_PINS[NUM_COLS] = 
            { 22, 23, 21, 20, 2, 0, 1, 25, 24, 12, 11, 10, 9, 8, 7, 5, 6, 4 };
#endif
            bool fn_pressed;

            bool b_inc_pressed;

            bool b_style_pressed;

            uint8_t num_keys_pressed;

            uint8_t num_keys_released;

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
             * Array of the keys that were just released
             * in this iteration.
             */
            Key just_released_keys[MAX_NUM_KEYS];

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

};

#endif
