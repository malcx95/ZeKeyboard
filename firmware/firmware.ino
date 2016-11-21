#include "keyboard.h"
#include "Tlc5940.h"

Ze::Board keyboard;
Tlc5940 tlc;

void setup() {

    keyboard.init();

    tlc.init();
    delay(300);
    tlc.setAll(4095);
    delay(300);
    tlc.update();
    delay(300);

    Serial.begin(9600);

    delay(16);

}

void loop() {

    keyboard.update();

    delay(16);

}
