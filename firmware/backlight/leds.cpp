#include "leds.h"

LED::LED(led_t port) {
    this->port = port;
    this->brightness = 0;
}

bool LED::is_dummy() {
    return this->port = LED_DUMMY;
}

