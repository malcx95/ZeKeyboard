#include <Tlc5940.h>
#include <tlc_shifts.h>
#include <tlc_animations.h>
#include <tlc_config.h>
#include <tlc_fades.h>
#include <tlc_servos.h>
#include <tlc_progmem_utils.h>

#include "keyboard.h"
#include "backlight/backlight.h"

Ze::Board keyboard;
Tlc5940 tlc;

void setup() {

    delay(50);
    
    tlc.init();

    delay(200);
    
    tlc.setAll(1000);
    
    delay(200);

    tlc.update();

    keyboard.init();

    Serial.begin(9600);

    delay(16);

}

void loop() {

    keyboard.update();

    delay(16);

}
