#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include <Arduino.h>
#include "config.h"
#ifdef SIXTY_PERCENT
    #include "ledssixty.h"
#elif defined FULLSIZE
    #include "ledsfull.h"
#endif
#include "led.h"
#include "keyboard.h"
#include "constants.h"
#include "standard.h"
#include "water.h"
#include "christmas.h"
#include "rave.h"
#include "tetris.h"
#include "gameoflife.h"
#include <FastLED.h>

const uint8_t NUM_BRIGHTNESS_VALUES = 4;
const float BRIGHTNESS_VALUES[NUM_BRIGHTNESS_VALUES] = {0.0, 0.25, 0.5, 1.0};

class Backlight {

    public:

        Backlight();

        void init(Ze::Board* keyboard, CRGB* ledstrip);

        /*
         * Prints the grid for debugging.
         */
        void print_grid();

        /*
         * Sets up a background style
         */
        void setup(BacklightStyle style);

        /*
         * Runs an iteration of the backlight effect.
         */
        void update();

    private:

        BacklightStyle style;

        Ze::Board* keyboard;

        uint8_t curr_brightness;

        float brightness;

        /*
         * The actual LED-strip, an array of 64 brightness values.
         */
        CRGB* ledstrip;

        /*
         * Grid containing all the LEDs to be manipulated
         * by the effects.
         */
        LED leds[Ze::NUM_ROWS][Ze::NUM_COLS];

        /*
         * Counter for iterating through, for example,
         * the STANDARD effect.
         */
        uint64_t it;

        bool already_changed_bright;

        bool already_changed_style;

        /*
         * The sea of water particles the WATER effect uses.
         */
        WaterParticle particles[WATER_HEIGHT][WATER_WIDTH];

        /*
         * The grid of ceĺls in the game of life effect.
         * Each bit corresponds to a cell.
         */
        uint32_t cells[Ze::NUM_ROWS];

        uint8_t translate_grid_to_strip(uint8_t row, uint8_t col);

        uint8_t christmas_scroll;

        /*
         * Counter which counts down to control
         * the effect when the game is over.
         */
        uint8_t tetris_game_over_counter;

        tetris::SquareType tetris_board[tetris::NUM_ROWS][tetris::NUM_COLS];

        tetris::Tetromino falling_tetromino;

        void increase_brightness();

        void change_style();

        void change_backlight_style();

        void handle_brightness_change();
        
        void handle_backlight_change();

};

#ifdef SIXTY_PERCENT

const led_t LED_GRID[Ze::NUM_ROWS][Ze::NUM_COLS] =
{

    //******************************************
    // ROW 0
    //******************************************

    {
        LED_ESC, 
        LED_1,
        LED_2,
        LED_3,
        LED_4,
        LED_5,
        LED_6,
        LED_7,
        LED_8,
        LED_9,
        LED_0,
        LED_MINUS, 
        LED_EQUAL,
        LED_BACKSPACE
    },

    //******************************************
    // ROW 1
    //******************************************

    {
        LED_TAB,
        LED_Q, 
        LED_W,
        LED_E, 
        LED_R,
        LED_T, 
        LED_Y,
        LED_U, 
        LED_I,
        LED_O, 
        LED_P,
        LED_LEFT_BRACE,
        LED_RIGHT_BRACE,
        LED_BACKSLASH
    },

    //******************************************
    // ROW 2
    //******************************************
    
    {
        LED_FN,
        LED_A, 
        LED_S,
        LED_D, 
        LED_F, 
        LED_G, 
        LED_H,
        LED_J,
        LED_K,
        LED_L, 
        LED_SEMICOLON, 
        LED_QUOTE,
        LED_DUMMY,
        LED_ENTER
    },

    //******************************************
    // ROW 3
    //******************************************
    
    {
        LED_LSHIFT,
        LED_NON_US_BS,
        LED_Z,
        LED_X,
        LED_C,
        LED_V,
        LED_B,
        LED_N,
        LED_M,
        LED_COMMA,
        LED_PERIOD,
        LED_SLASH,
        LED_DUMMY,
        LED_RSHIFT
    },

    //******************************************
    // ROW 4
    //******************************************
    
    {
        LED_CTRL,
        LED_SUPER,
        LED_ALT,
        LED_DUMMY,
        LED_DUMMY,
        LED_SPACE_LEFT,
        LED_SPACE_MAIN,
        LED_SPACE_RIGHT,
        LED_DUMMY,
        LED_DUMMY,
        LED_ALTGR,
        LED_PLAY_PAUSE,
        LED_VOL_DOWN,
        LED_VOL_UP
    }
};
#elif defined FULLSIZE

const led_t LED_GRID[Ze::NUM_ROWS][Ze::NUM_COLS] =
{

    //******************************************
    // ROW 0
    //******************************************

    {
        LED_ESC, 
        LED_DUMMY,
        LED_F1,
        LED_F2,
        LED_F3,
        LED_F4,
        LED_DUMMY,
        LED_F5,
        LED_F6,
        LED_F7,
        LED_F8,
        LED_F9,
        LED_F10,
        LED_F11,
        LED_F12,
        LED_PRINTSCREEN,
        LED_SCROLL_LOCK, 
        LED_PAUSE,
        LED_EXTRA1,
        LED_EXTRA2,
        LED_EXTRA3,
        LED_EXTRA4
    },

    //******************************************
    // ROW 1
    //******************************************

    {
        LED_TILDE, 
        LED_1,
        LED_2,
        LED_3,
        LED_4,
        LED_5,
        LED_6,
        LED_7,
        LED_8,
        LED_9,
        LED_0,
        LED_MINUS, 
        LED_EQUAL,
        LED_DUMMY,
        LED_BACKSPACE,
        LED_INSERT,
        LED_HOME,
        LED_PGUP,
        LED_NUMLOCK,
        LED_NUMPAD_SLASH,
        LED_NUMPAD_ASTERISK,
        LED_NUMPAD_MINUS
    },

    //******************************************
    // ROW 2
    //******************************************

    {
        LED_TAB,
        LED_DUMMY,
        LED_Q, 
        LED_W,
        LED_E, 
        LED_R,
        LED_T, 
        LED_Y,
        LED_U, 
        LED_I,
        LED_O, 
        LED_P,
        LED_LEFT_BRACE,
        LED_RIGHT_BRACE,
        LED_ENTER,
        LED_DEL,
        LED_END,
        LED_PGDOWN,
        LED_NUMPAD_7,
        LED_NUMPAD_8,
        LED_NUMPAD_9,
        LED_NUMPAD_PLUS
    },

    //******************************************
    // ROW 3
    //******************************************
    
    {
        LED_FN,
        LED_DUMMY,
        LED_A, 
        LED_S,
        LED_D, 
        LED_F, 
        LED_G, 
        LED_H,
        LED_J,
        LED_K,
        LED_L, 
        LED_SEMICOLON, 
        LED_QUOTE,
        LED_BACKSLASH,
        LED_DUMMY,
        LED_DUMMY,
        LED_DUMMY,
        LED_DUMMY,
        LED_NUMPAD_4,
        LED_NUMPAD_5,
        LED_NUMPAD_6,
        LED_DUMMY
    },

    //******************************************
    // ROW 4
    //******************************************
    
    {
        LED_LSHIFT,
        LED_DUMMY,
        LED_NON_US_BS,
        LED_Z,
        LED_X,
        LED_C,
        LED_V,
        LED_B,
        LED_N,
        LED_M,
        LED_COMMA,
        LED_PERIOD,
        LED_SLASH,
        LED_DUMMY,
        LED_RSHIFT,
        LED_DUMMY,
        LED_UP,
        LED_DUMMY,
        LED_NUMPAD_1,
        LED_NUMPAD_2,
        LED_NUMPAD_3,
        LED_NUMPAD_ENTER
    },

    //******************************************
    // ROW 5
    //******************************************
    
    {
        LED_LEFT_CTRL,
        LED_DUMMY,
        LED_LEFT_SUPER,
        LED_ALT,
        LED_DUMMY,
        LED_DUMMY,
        LED_DUMMY,
        LED_SPACE,
        LED_DUMMY,
        LED_DUMMY,
        LED_DUMMY,
        LED_ALTGR,
        LED_RIGHT_SUPER,
        LED_RIGHT_FN,
        LED_RIGHT_CTRL,
        LED_LEFT,
        LED_DOWN,
        LED_RIGHT,
        LED_DUMMY,
        LED_NUMPAD_0,
        LED_NUMPAD_PERIOD,
        LED_DUMMY
    }
};

#elif defined V2 

const led_t LED_GRID[Ze::NUM_ROWS][Ze::NUM_COLS] =
{


    //******************************************
    // ROW 0
    //******************************************

    {
        LED_ESC, 
        LED_1,
        LED_2,
        LED_3,
        LED_4,
        LED_5,
        LED_6,
        LED_7,
        LED_8,
        LED_9,
        LED_0,
        LED_MINUS, 
        LED_EQUAL,
        LED_BACKSPACE,
        LED_NUMLOCK,
        LED_NUMPAD_SLASH,
        LED_NUMPAD_ASTERISK,
        LED_NUMPAD_MINUS
    },

    //******************************************
    // ROW 1
    //******************************************

    {
        LED_TAB,
        LED_Q, 
        LED_W,
        LED_E, 
        LED_R,
        LED_T, 
        LED_Y,
        LED_U, 
        LED_I,
        LED_O, 
        LED_P,
        LED_LEFT_BRACE,
        LED_RIGHT_BRACE,
        LED_BACKSLASH,
        LED_NUMPAD_7,
        LED_NUMPAD_8,
        LED_NUMPAD_9,
        LED_NUMPAD_PLUS
    },

    //******************************************
    // ROW 2
    //******************************************
    
    {
        LED_FN,
        LED_A, 
        LED_S,
        LED_D, 
        LED_F, 
        LED_G, 
        LED_H,
        LED_J,
        LED_K,
        LED_L, 
        LED_SEMICOLON, 
        LED_QUOTE,
        LED_DUMMY,
        LED_ENTER,
        LED_NUMPAD_4,
        LED_NUMPAD_5,
        LED_NUMPAD_6,
        LED_DUMMY
    },

    //******************************************
    // ROW 3
    //******************************************
    
    {
        LED_LSHIFT,
        LED_DUMMY,
        LED_Z,
        LED_X,
        LED_C,
        LED_V,
        LED_B,
        LED_N,
        LED_M,
        LED_COMMA,
        LED_PERIOD,
        LED_SLASH,
        LED_DUMMY,
        LED_RSHIFT,
        LED_NUMPAD_1,
        LED_NUMPAD_2,
        LED_NUMPAD_3,
        LED_NUMPAD_ENTER
    },

    //******************************************
    // ROW 4
    //******************************************
    
    {
        LED_CTRL,
        LED_SUPER,
        LED_ALT,
        LED_DUMMY,
        LED_DUMMY,
        LED_SPACE_LEFT,
        LED_SPACE_MAIN,
        LED_SPACE_RIGHT,
        LED_DUMMY,
        LED_DUMMY,
        LED_ALTGR,
        LED_PLAY_PAUSE,
        LED_VOL_DOWN,
        LED_VOL_UP,
        LED_DUMMY,
        LED_NUMPAD_0,
        LED_NUMPAD_PERIOD,
        LED_DUMMY
    }
};

#endif

#endif
