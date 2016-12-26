#include "backlight.h"
#include "keyboard.h"
#include "constants.h"
#include <stdint.h>
#include <FastLED.h>


Ze::Board keyboard;
Backlight backlight;

//CRGB row0[NUM_ROW0_LEDS];
//CRGB row1[NUM_ROW1_LEDS];
//CRGB row2[NUM_ROW2_LEDS];
//CRGB row3[NUM_ROW3_LEDS];
//CRGB row4[NUM_ROW4_LEDS];
//
//CRGB* rows[Ze::NUM_ROWS] = {
//    row0,
//    row1,
//    row2,
//    row3,
//    row4
//};

CRGB leds[NUM_LEDS];

uint8_t count;

void setup() {

    // FastLED.addLeds<WS2812B, ROW0_PIN>(row0, NUM_ROW0_LEDS);
    // FastLED.addLeds<WS2812B, ROW1_PIN>(row1, NUM_ROW1_LEDS);
    // FastLED.addLeds<WS2812B, ROW2_PIN>(row2, NUM_ROW2_LEDS);
    // FastLED.addLeds<WS2812B, ROW3_PIN>(row3, NUM_ROW3_LEDS);
    // FastLED.addLeds<WS2812B, ROW4_PIN>(row4, NUM_ROW4_LEDS);

    FastLED.addLeds<NEOPIXEL, 2>(leds, 64);

    FastLED.clear();

    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);

    delay(50);


    // for (uint8_t i = 0; i < 64; ++i) {
    //     leds[i].r = 1;
    //     leds[i].g = 6;
    //     leds[i].b = 3;
    // }

    FastLED.show();
    
    keyboard.init();

    backlight.init(&keyboard, leds);

    backlight.setup(BacklightStyle::STANDARD);

    Serial.begin(9600);

    delay(16);
    
    //backlight.print_grid();

}

void loop() {

    // for (uint8_t i = 0; i < 64; ++i) {
    //     leds[i] = CRGB::Purple;
    //     delay(100);
    //     FastLED.show();
    // }


    // for (uint8_t i = 0; i < 64; ++i) {
    //     leds[i] = CRGB::Green;
    //     delay(100);
    //     FastLED.show();
    // }


    // for (uint8_t i = 0; i < 64; ++i) {
    //     leds[i] = CRGB::Red;
    //     delay(100);
    //     FastLED.show();
    // }


    // for (uint8_t i = 0; i < 64; ++i) {
    //     leds[i] = CRGB::Blue;
    //     delay(100);
    //     FastLED.show();
    // }


    // for (uint8_t i = 0; i < 64; ++i) {
    //     leds[i] = CRGB::Yellow;
    //     delay(100);
    //     FastLED.show();
    // }


    // for (uint8_t i = 0; i < 64; ++i) {
    //     leds[i] = CRGB::White;
    //     delay(100);
    //     FastLED.show();
    // }

    keyboard.update();
    
    backlight.update();

    delay(16);

}
