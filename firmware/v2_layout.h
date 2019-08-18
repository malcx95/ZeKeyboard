#ifndef V2_LAYOUT_H
#define V2_LAYOUT_H

#include "keyboard.h"

namespace Ze {

    const Key KEYS[NUM_ROWS][NUM_COLS] = {

        //******************************************
        // ROW 0
        //******************************************
        
        {
            Key(KEY_ESC, KEY_TILDE, 0, 0), 
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
            Key(KEY_BACKSPACE, 0, 13),
            Key(KEY_BACKLIGHT_STYLE, 0, 14),
            Key(KEYPAD_SLASH, 0, 15),
            Key(KEYPAD_ASTERIX, 0, 16),
            Key(KEYPAD_MINUS, 0, 17)
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
            Key(KEY_BACKSLASH, 1, 13),
            Key(KEY_7, 1, 14),
            Key(KEY_8, 1, 15),
            Key(KEY_9, 1, 16),
            Key(KEYPAD_PLUS, 1, 17)
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
            Key(KEY_ENTER, 2, 13),
            Key(KEY_4, 2, 14),
            Key(KEY_5, 2, 15),
            Key(KEY_6, 2, 16),
            Key() // dummy
        },

        //******************************************
        // ROW 3
        //******************************************
        
        {
            Key(KEY_LSHIFT, 3, 0),
            Key(), // dummy
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
            Key(KEY_RSHIFT, 3, 13),
            Key(KEY_1, 3, 14),
            Key(KEY_2, 3, 15),
            Key(KEY_3, 3, 16),
            Key(KEYPAD_ENTER, 3, 17)
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
            Key(KEY_MEDIA_VOLUME_INC, KEY_MEDIA_NEXT_TRACK, 4, 13),
            Key(), // dummy
            Key(KEYPAD_0, 4, 15),
            Key(KEYPAD_PERIOD, 4, 16),
            Key() // dummy
        }
    };
};

#endif /* ifndef V2_LAYOUT_H */
