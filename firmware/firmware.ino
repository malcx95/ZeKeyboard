#include "config.h"
#include "backlight.h"
#include "keyboard.h"
#include "constants.h"
#include <stdint.h>
#include <FastLED.h>

#include "teensy4ledcontroller.h"

const int DELAY_MICROS = 16000;

Ze::Board keyboard;
Backlight backlight;

CRGB leds[NUM_LEDS];

#ifdef V3
byte pinList[1] = { 38 };
DMAMEM int displayMemory[NUM_LEDS * 3 / 4];
int drawingMemory[NUM_LEDS * 3 / 4];
OctoWS2811 octo(NUM_LEDS, displayMemory, drawingMemory, WS2811_RGB | WS2811_800kHz, 1, pinList);
CTeensy4Controller<GRB, WS2811_800kHz>* pcontroller;
#endif

uint8_t count;

void smart_delay(unsigned long start_time);

void check_serial();

void setup() {

#ifdef V2
    FastLED.addLeds<NEOPIXEL, 3>(leds, NUM_LEDS);
#elif defined V3
    octo.begin();
    pcontroller = new CTeensy4Controller<GRB, WS2811_800kHz>(&octo);
    FastLED.setBrightness(255);
    FastLED.addLeds(pcontroller, leds, NUM_LEDS);
#else
    FastLED.addLeds<NEOPIXEL, 2>(leds, NUM_LEDS);
#endif

    FastLED.clear();

#ifdef FULLSIZE
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 800);
#elif defined V2 
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 900);
#elif defined V3 
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 900);
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
        // Serial.print("Computing took more than 16 ms: ");
        // Serial.println(elapsed);
        return;
    }
    delayMicroseconds(DELAY_MICROS - elapsed);
}

