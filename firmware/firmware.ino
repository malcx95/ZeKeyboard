#include <Tlc5940.h>
#include <tlc_shifts.h>
#include <tlc_animations.h>
#include <tlc_config.h>
#include <tlc_fades.h>
#include <tlc_servos.h>
#include <tlc_progmem_utils.h>


#include "keyboard.h"

Ze::Board keyboard;
Tlc5940 tlc;

void setup() {

    tlc.init();
    delay(200);
    tlc.setAll(3000);
    delay(200);
    tlc.update();
    delay(200);
    keyboard.init();

    Serial.begin(9600);

    delay(16);

}

void loop() {

    keyboard.update();

    delay(16);

}
