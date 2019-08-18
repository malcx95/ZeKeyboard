#ifndef FULLSIZE_LAYOUT_H
#define FULLSIZE_LAYOUT_H

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
            Key(), // dummy
            Key(KEY_F5, 0, 7),
            Key(KEY_F6, 0, 8), 
            Key(KEY_F7, 0, 9),
            Key(KEY_F8, 0, 10),
            Key(KEY_F9, 0, 11),
            Key(KEY_F10, 0, 12), 
            Key(KEY_F11, 0, 13), 
            Key(KEY_F12, 0, 14), 
            Key(KEY_PRINTSCREEN, 0, 15), 
            Key(KEY_SCROLL_LOCK, 0, 16),
            Key(KEY_PAUSE, 0, 17),
            Key(KEY_MEDIA_VOLUME_DEC, KEY_MEDIA_MUTE, 0, 18),
            Key(KEY_MEDIA_VOLUME_INC, KEY_MEDIA_MUTE, 0, 19),
            Key(KEY_INC_BRIGHTNESS, 0, 20),
            Key(KEY_BACKLIGHT_STYLE, 0, 21)
        },

        //******************************************
        // ROW 1
        //******************************************
        
        {
            Key(KEY_TILDE, 1, 0), 
            Key(KEY_1, 1, 1),
            Key(KEY_2, 1, 2),
            Key(KEY_3, 1, 3),
            Key(KEY_4, 1, 4), 
            Key(KEY_5, 1, 5),
            Key(KEY_6, 1, 6), 
            Key(KEY_7, 1, 7),
            Key(KEY_8, 1, 8),
            Key(KEY_9, 1, 9),
            Key(KEY_0, 1, 10), 
            Key(KEY_MINUS, 1, 11), 
            Key(KEY_EQUAL, 1, 12),
            Key(), // dummy
            Key(KEY_BACKSPACE, 1, 14),
            Key(KEY_INSERT, 1, 15),
            Key(KEY_HOME, 1, 16),
            Key(KEY_PAGE_UP, 1, 17),
            Key(KEY_NUM_LOCK, 1, 18),
            Key(KEYPAD_SLASH, 1, 19),
            Key(KEYPAD_ASTERIX, 1, 20),
            Key(KEYPAD_MINUS, 1, 21)
        },

        //******************************************
        // ROW 2
        //******************************************

        {
            Key(KEY_TAB, 2, 0),
            Key(), // dummy
            Key(KEY_Q, 2, 2), 
            Key(KEY_W, 2, 3),
            Key(KEY_E, 2, 4), 
            Key(KEY_R, 2, 5),
            Key(KEY_T, 2, 6), 
            Key(KEY_Y, 2, 7),
            Key(KEY_U, 2, 8), 
            Key(KEY_I, 2, 9),
            Key(KEY_O, 2, 10), 
            Key(KEY_P, 2, 11),
            Key(KEY_LEFT_BRACE, 2, 12),
            Key(KEY_RIGHT_BRACE, 2, 13),
            Key(KEY_ENTER, 2, 14),
            Key(KEY_DELETE, 2, 15),
            Key(KEY_END, 2, 16),
            Key(KEY_PAGE_DOWN, 2, 17),
            Key(KEYPAD_7, 2, 18),
            Key(KEYPAD_8, 2, 19),
            Key(KEYPAD_9, 2, 20),
            Key(KEYPAD_PLUS, 2, 21),
        },

        //******************************************
        // ROW 3
        //******************************************
        
        {
            Key(KEY_FN, 3, 0),
            Key(), // dummy
            Key(KEY_A, 3, 2),
            Key(KEY_S, 3, 3),
            Key(KEY_D, 3, 4), 
            Key(KEY_F, 3, 5), 
            Key(KEY_G, 3, 6), 
            Key(KEY_H, KEY_LEFT, 3, 7),
            Key(KEY_J, KEY_DOWN, 3, 8),
            Key(KEY_K, KEY_UP, 3, 9),
            Key(KEY_L, KEY_RIGHT, 3, 10),
            Key(KEY_SEMICOLON, 3, 11),
            Key(KEY_QUOTE, 3, 12),
            Key(KEY_BACKSLASH, 3, 13),
            Key(), // dummy
            Key(), // dummy
            Key(), // dummy
            Key(), // dummy
            Key(KEYPAD_4, 3, 18),
            Key(KEYPAD_5, 3, 19),
            Key(KEYPAD_6, 3, 20),
            Key() // dummy
        },

        //******************************************
        // ROW 4
        //******************************************
        
        {
            Key(KEY_LSHIFT, 4, 0),
            Key(), // dummy
            Key(KEY_NON_US_BS, 4, 2),
            Key(KEY_Z, 4, 3),
            Key(KEY_X, 4, 4),
            Key(KEY_C, 4, 5),
            Key(KEY_V, 4, 6),
            Key(KEY_B, 4, 7),
            Key(KEY_N, 4, 8),
            Key(KEY_M, 4, 9),
            Key(KEY_COMMA, 4, 10),
            Key(KEY_PERIOD, 4, 11),
            Key(KEY_SLASH, 4, 12),
            Key(), // dummy
            Key(KEY_RSHIFT, 4, 14),
            Key(), // dummy
            Key(KEY_UP, 4, 16),
            Key(), // dummy
            Key(KEYPAD_1, 4, 18),
            Key(KEYPAD_2, 4, 19),
            Key(KEYPAD_3, 4, 20),
            Key(KEYPAD_ENTER, 4, 21)
        },

        //******************************************
        // ROW 5
        //******************************************
        
        {
            Key(KEY_CTRL, 5, 0),
            Key(), // dummy
            Key(KEY_SUPER, 5, 2),
            Key(KEY_ALT, 5, 3),
            Key(), // dummy
            Key(), // dummy
            Key(), // dummy
            Key(KEY_SPACE, 5, 7),
            Key(), // dummy
            Key(), // dummy
            Key(), // dummy
            Key(KEY_ALTGR, 5, 11),
            Key(KEY_SUPER, 5, 12),
            Key(KEY_FN, 5, 13),
            Key(KEY_CTRL, 5, 14),
            Key(KEY_LEFT, 5, 15),
            Key(KEY_DOWN, 5, 16),
            Key(KEY_RIGHT, 5, 17),
            Key(), // dummy
            Key(KEYPAD_0, 5, 19),
            Key(KEYPAD_PERIOD, 5, 20),
            Key() // dummy
        }
    };
};

#endif /* ifndef FULLSIZE_LAYOUT_H */
