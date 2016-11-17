#include "keyboard.h"

Ze::Board keyboard;
Tlc5940 tlc;

void setup() {

    keyboard.init();

    tlc.init();
    delay(100);
    tlc.setAll(4095);
    delay(100);
    tlc.update();
    delay(100);

    Serial.begin(9600);

    delay(16);

}

void loop() {

    keyboard.update();

    delay(16);

}
