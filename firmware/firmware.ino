#include "backlight.h"
#include "keyboard.h"
#include "constants.h"
#include "FastLED.h"

#define ROW1_LEDS   14
#define ROW2_LEDS   14
#define ROW3_LEDS   13
#define ROW4_LEDS   13
#define ROW5_LEDS   10

Ze::Board keyboard;
Backlight backlight;

CRGB row1[ROW1_LEDS];
CRGB row2[ROW2_LEDS];
CRGB row3[ROW3_LEDS];
CRGB row4[ROW4_LEDS];
CRGB row5[ROW5_LEDS];

void setup() {

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
