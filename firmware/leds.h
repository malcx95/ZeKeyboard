#ifndef LEDS_H 
#define LEDS_H 

#include <stdint.h>

typedef uint8_t led_t;

//*********************************
// ROW 0
//*********************************

const led_t LED_ESC =         0;
const led_t LED_1 =           1;
const led_t LED_2 =           2;
const led_t LED_3 =           3;
const led_t LED_4 =           4;
const led_t LED_5 =           5;
const led_t LED_6 =           6;
const led_t LED_7 =           7;
const led_t LED_8 =           8;
const led_t LED_9 =           9;
const led_t LED_0 =           10;
const led_t LED_MINUS =       11;
const led_t LED_EQUAL =       12;
const led_t LED_BACKSPACE =   13;

//*****************************
// ROW 1
//*****************************

const led_t LED_TAB =         27;
const led_t LED_Q =           26;
const led_t LED_W =           25;
const led_t LED_E =           24;
const led_t LED_R =           23;
const led_t LED_T =           22;
const led_t LED_Y =           21;
const led_t LED_U =           20;
const led_t LED_I =           19;
const led_t LED_O =           18;
const led_t LED_P =           17;
const led_t LED_LEFT_BRACE =  16;
const led_t LED_RIGHT_BRACE = 15;
const led_t LED_BACKSLASH =   14;

//*****************************
// ROW 2
//*****************************

const led_t LED_FN =          28;
const led_t LED_A =           29;
const led_t LED_S =           30;
const led_t LED_D =           31;
const led_t LED_F =           32;
const led_t LED_G =           33;
const led_t LED_H =           34;
const led_t LED_J =           35;
const led_t LED_K =           36;
const led_t LED_L =           37;
const led_t LED_SEMICOLON =   38;
const led_t LED_QUOTE =       39;
const led_t LED_ENTER =       40;

//*****************************
// ROW 3
//*****************************

const led_t LED_LSHIFT =      53;
const led_t LED_NON_US_BS =   52;
const led_t LED_Z =           51;
const led_t LED_X =           50;
const led_t LED_C =           49;
const led_t LED_V =           48;
const led_t LED_B =           47;
const led_t LED_N =           46;
const led_t LED_M =           45;
const led_t LED_COMMA =       44;
const led_t LED_PERIOD =      43;
const led_t LED_SLASH =       42;
const led_t LED_RSHIFT =      41;

//*****************************
// ROW 4
//*****************************

const led_t LED_CTRL =        54;
const led_t LED_SUPER =       55;
const led_t LED_ALT =         56;
const led_t LED_SPACE_LEFT =  57;
const led_t LED_SPACE_MAIN =  58;
const led_t LED_SPACE_RIGHT = 59;
const led_t LED_ALTGR =       60;
const led_t LED_PLAY_PAUSE =  61;
const led_t LED_VOL_UP =      63;
const led_t LED_VOL_DOWN =    62;


#endif
