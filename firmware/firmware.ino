#include "keyboard.h"
#include "constants.h"
#include <stdint.h>

const int DELAY_MICROS = 16000;

Ze::Board keyboard;

void smart_delay(unsigned long start_time);

void setup() {
    
    keyboard.init();

    Serial.begin(9600);

    delay(16);

}

void loop() {

    unsigned long start_time = micros();

    keyboard.update();

    smart_delay(start_time);

}

void smart_delay(unsigned long start_time) {
    unsigned long time = micros();

    // overflow has occurred
    if (time < start_time) return;

    unsigned long elapsed = time - start_time;
    if (elapsed > DELAY_MICROS) {
        return;
    }
    delayMicroseconds(DELAY_MICROS - elapsed);
}
