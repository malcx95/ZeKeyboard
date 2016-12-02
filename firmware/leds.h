#ifndef LEDS_H 
#define LEDS_H 

#include <stdint.h>

typedef uint8_t led_t;

//*********************************
// ROW 0
//*********************************

const led_t LED_ESC =         13;
const led_t LED_1 =           12;
const led_t LED_2 =           11;
const led_t LED_3 =           10;
const led_t LED_4 =           9;
const led_t LED_5 =           8;
const led_t LED_6 =           7;
const led_t LED_7 =           6;
const led_t LED_8 =           5;
const led_t LED_9 =           4;
const led_t LED_0 =           3;
const led_t LED_MINUS =       2;
const led_t LED_EQUAL =       1;
const led_t LED_BACKSPACE =   0;

//*****************************
// ROW 1
//*****************************

const led_t LED_TAB =         13;
const led_t LED_Q =           12;
const led_t LED_W =           11;
const led_t LED_E =           10;
const led_t LED_R =           9;
const led_t LED_T =           8;
const led_t LED_Y =           7;
const led_t LED_U =           6;
const led_t LED_I =           5;
const led_t LED_O =           4;
const led_t LED_P =           3;
const led_t LED_LEFT_BRACE =  2;
const led_t LED_RIGHT_BRACE = 1;
const led_t LED_BACKSLASH =   0;

//*****************************
// ROW 2
//*****************************

const led_t LED_FN =          12;
const led_t LED_A =           11;
const led_t LED_S =           10;
const led_t LED_D =           9;
const led_t LED_F =           8;
const led_t LED_G =           7;
const led_t LED_H =           6;
const led_t LED_J =           5;
const led_t LED_K =           4;
const led_t LED_L =           3;
const led_t LED_SEMICOLON =   2;
const led_t LED_QUOTE =       1;
const led_t LED_ENTER =       0;

//*****************************
// ROW 3
//*****************************

const led_t LED_LSHIFT =      12;
const led_t LED_NON_US_BS =   11;
const led_t LED_Z =           10;
const led_t LED_X =           9;
const led_t LED_C =           8;
const led_t LED_V =           7;
const led_t LED_B =           6;
const led_t LED_N =           5;
const led_t LED_M =           4;
const led_t LED_COMMA =       3;
const led_t LED_PERIOD =      2;
const led_t LED_SLASH =       1;
const led_t LED_RSHIFT =      0;

//*****************************
// ROW 4
//*****************************

const led_t LED_CTRL =        9;
const led_t LED_SUPER =       8;
const led_t LED_ALT =         7;
const led_t LED_SPACE_LEFT =  6;
const led_t LED_SPACE_MAIN =  5;
const led_t LED_SPACE_RIGHT = 4;
const led_t LED_ALTGR =       3;
const led_t LED_PLAY_PAUSE =  2;
const led_t LED_VOL_UP =      1;
const led_t LED_VOL_DOWN =    0;


#endif
