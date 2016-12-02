#include "backlight.h"
#include "keyboard.h"
#include "constants.h"
#include "FastLED.h"

#define NUM_ROWS    5

#define NUM_ROW0_LEDS   14
#define NUM_ROW1_LEDS   14
#define NUM_ROW2_LEDS   13
#define NUM_ROW3_LEDS   13
#define NUM_ROW4_LEDS   10

#define ROW0_PIN    3
#define ROW1_PIN    4
#define ROW2_PIN    5
#define ROW3_PIN    6
#define ROW4_PIN    7

Ze::Board keyboard;
Backlight backlight;

CRGB row0[NUM_ROW0_LEDS];
CRGB row1[NUM_ROW1_LEDS];
CRGB row2[NUM_ROW2_LEDS];
CRGB row3[NUM_ROW3_LEDS];
CRGB row4[NUM_ROW4_LEDS];

CRGB* rows[NUM_ROWS] = {
    row0,
    row1,
    row2,
    row3,
    row4
};

void setup() {

    FastLED.addLeds<WS2812B, ROW0_PIN>(row0, NUM_ROW0_LEDS);
    FastLED.addLeds<WS2812B, ROW1_PIN>(row1, NUM_ROW1_LEDS);
    FastLED.addLeds<WS2812B, ROW2_PIN>(row2, NUM_ROW2_LEDS);
    FastLED.addLeds<WS2812B, ROW3_PIN>(row3, NUM_ROW3_LEDS);
    FastLED.addLeds<WS2812B, ROW4_PIN>(row4, NUM_ROW4_LEDS);

    delay(50);
    
    keyboard.init();

    backlight.init(&keyboard);

    backlight.setup(BacklightStyle::STANDARD);

    Serial.begin(9600);

    delay(16);
    //backlight.print_grid();

}

void loop() {

    keyboard.update();

    delay(16);

}
