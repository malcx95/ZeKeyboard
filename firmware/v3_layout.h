#ifndef V3_LAYOUT_H
#define V3_LAYOUT_H

#include "keyboard.h"

namespace Ze {

    const Key KEYS[NUM_ROWS][NUM_COLS] = {

        //******************************************
        // ROW 0
        //******************************************
        
        {
            Key(KEY_ESC, 0, 0), 
            Key(), // dummy
            Key(KEY_F1, 0, 2),
            Key(KEY_F2, 0, 3),
            Key(KEY_F3, 0, 4),
            Key(KEY_F4, 0, 5), 
            Key(KEY_F5, 0, 6),
            Key(KEY_F6, 0, 7), 
            Key(KEY_F7, 0, 8),
            Key(KEY_F8, 0, 9),
            Key(KEY_F9, 0, 10),
            Key(KEY_F10, 0, 11), 
            Key(KEY_F12, 0, 12), 
            Key(KEY_F12, 0, 13), 
            Key(), // dummy
            Key(), // dummy
            Key(), // dummy
            Key(), // dummy
            Key() // dummy
        },

        //******************************************
        // ROW 1
        //******************************************
        
        {
            Key(KEY_TILDE, 1, 0), 
            Key(KEY_1, KEY_F1, 1, 1),
            Key(KEY_2, KEY_F2, 1, 2),
            Key(KEY_3, KEY_F3, 1, 3),
            Key(KEY_4, KEY_F4, 1, 4), 
            Key(KEY_5, KEY_F5, 1, 5),
            Key(KEY_6, KEY_F6, 1, 6), 
            Key(KEY_7, KEY_F7, 1, 7),
            Key(KEY_8, KEY_F8, 1, 8),
            Key(KEY_9, KEY_F9, 1, 9),
            Key(KEY_0, KEY_F10, 1, 10), 
            Key(KEY_MINUS, 1, 11), 
            Key(KEY_EQUAL, 1, 12),
            Key(KEY_BACKSPACE, 1, 13),
            Key(KEY_MACRO1, 1, 14),
            Key(KEY_BACKLIGHT_STYLE, 1, 15),
            Key(KEYPAD_SLASH, 1, 16),
            Key(KEYPAD_ASTERIX, 1, 17),
            Key(KEYPAD_MINUS, 1, 18)
        },

        //******************************************
        // ROW 2
        //******************************************

        {
            Key(KEY_TAB, 2, 0),
            Key(KEY_Q, 2, 1), 
            Key(KEY_W, 2, 2),
            Key(KEY_E, 2, 3), 
            Key(KEY_R, 2, 4),
            Key(KEY_T, 2, 5), 
            Key(KEY_Y, 2, 6),
            Key(KEY_U, 2, 7), 
            Key(KEY_I, 2, 8),
            Key(KEY_O, 2, 9), 
            Key(KEY_P, 2, 20),
            Key(KEY_LEFT_BRACE, 2, 12),
            Key(KEY_RIGHT_BRACE, 2, 12),
            Key(KEY_BACKSLASH, 2, 13),
            Key(KEY_MACRO2, 2, 14),
            Key(KEY_7, 2, 15),
            Key(KEY_8, 2, 16),
            Key(KEY_9, 2, 17),
            Key(KEYPAD_PLUS, 2, 18)
        },

        //******************************************
        // ROW 3
        //******************************************
        
        {
            Key(KEY_FN, 3, 0),
            Key(KEY_A, 3, 1),
            Key(KEY_S, 3, 2),
            Key(KEY_D, 3, 3), 
            Key(KEY_F, 3, 4), 
            Key(KEY_G, 3, 5), 
            Key(KEY_H, KEY_LEFT, 3, 6),
            Key(KEY_J, KEY_DOWN, 3, 7),
            Key(KEY_K, KEY_UP, 3, 8),
            Key(KEY_L, KEY_RIGHT, 3, 9),
            Key(KEY_SEMICOLON, 3, 10),
            Key(KEY_QUOTE, 3, 11),
            Key(), // dummy
            Key(KEY_ENTER, 3, 13),
            Key(KEY_MACRO3, 3, 14),
            Key(KEY_4, 3, 15),
            Key(KEY_5, 3, 16),
            Key(KEY_6, 3, 17),
            Key() // dummy
        },

        //******************************************
        // ROW 4
        //******************************************
        
        {
            Key(KEY_LSHIFT, 4, 0),
            Key(KEY_NON_US_BS, 4, 1),
            Key(KEY_Z, 4, 2),
            Key(KEY_X, 4, 3),
            Key(KEY_C, 4, 4),
            Key(KEY_V, 4, 5),
            Key(KEY_B, 4, 6),
            Key(KEY_N, 4, 7),
            Key(KEY_M, 4, 8),
            Key(KEY_COMMA, 4, 9),
            Key(KEY_PERIOD, 4, 10),
            Key(KEY_SLASH, 4, 11),
            Key(KEY_UP, 4, 12),
            Key(KEY_EXTRA, 4, 13),
            Key(KEY_MACRO4, 4, 14),
            Key(KEY_1, 4, 15),
            Key(KEY_2, 4, 16),
            Key(KEY_3, 4, 17),
            Key(KEYPAD_ENTER, 4, 18)
        },

        //******************************************
        // ROW 5
        //******************************************
        
        {
            Key(KEY_CTRL, 5, 0),
            Key(KEY_SUPER, 5, 1),
            Key(KEY_ALT, 5, 2),
            Key(), // dummy
            Key(KEY_SPACE, 5, 4),
            Key(), // dummy
            Key(KEY_FN, 5, 6),
            Key(), // dummy
            Key(KEY_SPACE, 5, 8),
            Key(), // dummy
            Key(KEY_ALTGR, 5, 10),
            Key(KEY_MEDIA_PLAY_PAUSE, 5, 11),
            Key(KEY_MEDIA_VOLUME_DEC, KEY_MEDIA_PREV_TRACK, 5, 12),
            Key(KEY_MEDIA_VOLUME_INC, KEY_MEDIA_NEXT_TRACK, 5, 13),
            Key(KEY_MACRO5, 5, 14),
            Key(KEY_0, 5, 15),
            Key(), // dummy
            Key(KEY_PERIOD, 5, 17),
            Key() // dummy
        }
    };
};

#endif /* ifndef V3_LAYOUT_H */
