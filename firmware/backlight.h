#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include "Tlc5940.h"

typedef uint8_t led_t;

//*********************************
// ROW 1
//*********************************

const led_t LED_ESC =         1;
const led_t LED_1 =           2;
const led_t LED_2 =           3;
const led_t LED_3 =           4;
const led_t LED_4 =           5;
const led_t LED_5 =           6;
const led_t LED_6 =           7;
const led_t LED_7 =           8;
const led_t LED_8 =           9;
const led_t LED_9 =           10;
const led_t LED_0 =           11;
const led_t LED_MINUS =       12;
const led_t LED_EQUALS =      13;
const led_t LED_BACKSPACE =   14;

//*****************************
// ROW 2
//*****************************

const led_t LED_TAB =         17;
const led_t LED_Q =           18;
const led_t LED_W =           19;
const led_t LED_E =           20;
const led_t LED_R =           21;
const led_t LED_T =           22;
const led_t LED_Y =           23;
const led_t LED_U =           24;
const led_t LED_I =           25;
const led_t LED_O =           26;
const led_t LED_P =           27;
const led_t LED_LEFT_BRACE =  28;
const led_t LED_RIGHT_BRACE = 29;
const led_t LED_BACKSLASH =   30;

//*****************************
// ROW 3
//*****************************

const led_t LED_FN =          33;
const led_t LED_A =           34;
const led_t LED_S =           35;
const led_t LED_D =           36;
const led_t LED_F =           37;
const led_t LED_G =           38;
const led_t LED_H =           39;
const led_t LED_J =           40;
const led_t LED_K =           41;
const led_t LED_L =           42;
const led_t LED_SEMICOLON =   43;
const led_t LED_QUOTE =       44;
const led_t LED_ENTER =       45;

//*****************************
// ROW 4
//*****************************

const led_t LED_LEFT_SHIFT =  49;
const led_t LED_ASTERISK =    50;
const led_t LED_Z =           51;
const led_t LED_X =           52;
const led_t LED_C =           53;
const led_t LED_V =           54;
const led_t LED_B =           55;
const led_t LED_N =           56;
const led_t LED_M =           57;
const led_t LED_COMMA =       58;
const led_t LED_PERIOD =      59;
const led_t LED_SLASH =       60;
const led_t LED_RIGHT_SHIFT = 61;

//*****************************
// ROW 5
//*****************************

const led_t LED_CTRL =        64;
const led_t LED_GUI =         65;
const led_t LED_LEFT_ALT =    66;
const led_t LED_SPACE_LEFT =  67;
const led_t LED_SPACE_MAIN =  68;
const led_t LED_SPACE_RIGHT = 69;
const led_t LED_RIGHT_ALT =   70;
const led_t LED_EXTRA1 =      71;
const led_t LED_EXTRA2 =      72;
const led_t LED_EXTRA3 =      73;

#endif
