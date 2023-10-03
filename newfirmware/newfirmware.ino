#include "src/firmware.hpp"

Firmware firmware;

void setup() {
    firmware.setup();
}

void loop() {
    firmware.update();
}
