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

void setup() {

    FastLED.addLeds<NEOPIXEL, 2>(leds, 64);

    FastLED.clear();

    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);

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
    } else {
        Serial.println(elapsed);
    }
    delayMicroseconds(DELAY_MICROS - elapsed);
}
