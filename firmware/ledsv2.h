#ifndef LEDSV2_H 
#define LEDSV2_H 

#include <stdint.h>

typedef uint8_t led_t;

//*********************************
// ROW 0
//*********************************

const led_t LED_ESC =           0;
const led_t LED_1 =             1;
const led_t LED_2 =             2;
const led_t LED_3 =             3;
const led_t LED_4 =             4;
const led_t LED_5 =             5;
const led_t LED_6 =             6;
const led_t LED_7 =             7;
const led_t LED_8 =             8;
const led_t LED_9 =             9;
const led_t LED_0 =             10;
const led_t LED_MINUS =         11;
const led_t LED_EQUAL =         12;
const led_t LED_BACKSPACE =     13;
const led_t LED_NUMLOCK =       14;
const led_t LED_NUMPAD_SLASH =  15;
const led_t LED_NUMPAD_ASTERISK = 16;
const led_t LED_NUMPAD_MINUS =  17;

//*****************************
// ROW 1
//*****************************

const led_t LED_TAB =           35;
const led_t LED_Q =             34;
const led_t LED_W =             33;
const led_t LED_E =             32;
const led_t LED_R =             31;
const led_t LED_T =             30;
const led_t LED_Y =             29;
const led_t LED_U =             28;
const led_t LED_I =             27;
const led_t LED_O =             26;
const led_t LED_P =             25;
const led_t LED_LEFT_BRACE =    24;
const led_t LED_RIGHT_BRACE =   23;
const led_t LED_BACKSLASH =     22;
const led_t LED_NUMPAD_7 =      21;
const led_t LED_NUMPAD_8 =      20;
const led_t LED_NUMPAD_9 =      19;
const led_t LED_NUMPAD_PLUS =   18;

//*****************************
// ROW 2
//*****************************

const led_t LED_FN =            36;
const led_t LED_A =             37;
const led_t LED_S =             38;
const led_t LED_D =             39;
const led_t LED_F =             40;
const led_t LED_G =             41;
const led_t LED_H =             42;
const led_t LED_J =             43;
const led_t LED_K =             44;
const led_t LED_L =             45;
const led_t LED_SEMICOLON =     46;
const led_t LED_QUOTE =         47;
const led_t LED_ENTER =         48;
const led_t LED_NUMPAD_4 =      49;
const led_t LED_NUMPAD_5 =      50;
const led_t LED_NUMPAD_6 =      51;

//*****************************
// ROW 3
//*****************************

const led_t LED_LSHIFT =        66;
const led_t LED_Z =             65;
const led_t LED_X =             64;
const led_t LED_C =             63;
const led_t LED_V =             62;
const led_t LED_B =             61;
const led_t LED_N =             60;
const led_t LED_M =             59;
const led_t LED_COMMA =         58;
const led_t LED_PERIOD =        57;
const led_t LED_SLASH =         56;
const led_t LED_RSHIFT =        55;
const led_t LED_NUMPAD_1 =      54;
const led_t LED_NUMPAD_2 =      53;
const led_t LED_NUMPAD_3 =      52;

//*****************************
// ROW 4
//*****************************

const led_t LED_CTRL =        67;
const led_t LED_SUPER =       68;
const led_t LED_ALT =         69;
const led_t LED_SPACE_LEFT =  70;
const led_t LED_SPACE_MAIN =  71;
const led_t LED_SPACE_RIGHT = 72;
const led_t LED_ALTGR =       73;
const led_t LED_PLAY_PAUSE =  74;
const led_t LED_VOL_DOWN =    75;
const led_t LED_VOL_UP =      76;
const led_t LED_NUMPAD_0 = 77;
const led_t LED_NUMPAD_PERIOD = 78;
const led_t LED_NUMPAD_ENTER = 79;
const led_t LED_LOGO = 80;

#endif
