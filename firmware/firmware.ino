#include "config.h"
#include "backlight.h"
#include "keyboard.h"
#include "constants.h"
#include <stdint.h>
#include <FastLED.h>


const int DELAY_MICROS = 16000;

Ze::Board keyboard;
Backlight backlight;

CRGB leds[NUM_LEDS];

uint8_t count;

void smart_delay(unsigned long start_time);

void check_serial();

void setup() {

    FastLED.addLeds<NEOPIXEL, 2>(leds, NUM_LEDS);

    FastLED.clear();

#ifdef FULLSIZE
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 800);
#else
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
#endif


    delay(50);

    FastLED.show();
    keyboard.init();

    backlight.init(&keyboard, leds);

    backlight.setup(BacklightStyle::STANDARD);
    Serial.begin(9600);

    delay(500);

}


void loop() {

    unsigned long start_time = micros();

    keyboard.update();
     
    backlight.update();

    smart_delay(start_time);

}

void smart_delay(unsigned long start_time) {
    unsigned long time = micros();

    // overflow has occurred
    if (time < start_time) return;

    unsigned long elapsed = time - start_time;
    if (elapsed > DELAY_MICROS) {
        Serial.print("Computing took more than 16 ms: ");
        Serial.println(elapsed);
        return;
    }
    delayMicroseconds(DELAY_MICROS - elapsed);
}

