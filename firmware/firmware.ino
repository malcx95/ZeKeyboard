#include "backlight.h"
#include "keyboard.h"
#include "constants.h"

Ze::Board keyboard;
Tlc5940 tlc;
Backlight backlight;

void setup() {

    delay(50);
    
    tlc.init();

    delay(200);
    
    tlc.setAll(1000);
    
    delay(200);

    tlc.update();

    keyboard.init();

    backlight.init(&tlc, &keyboard);

    backlight.setup(BacklightStyle::STANDARD);

    Serial.begin(9600);

    delay(16);
    //backlight.print_grid();

}

void loop() {

    keyboard.update();

    delay(16);

}
