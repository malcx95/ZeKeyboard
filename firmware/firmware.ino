#include "keyboard.h"

Ze::Board keyboard;

void setup() {

    keyboard.init();

    Serial.begin(9600);

    delay(16);

}

void loop() {

    keyboard.update();

    delay(16);

}
