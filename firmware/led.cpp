#include "led.h"

void LED::init() {
    this->port = LED_DUMMY;
    this->brightness = 0.0;
    this->r = 0.0;
    this->g = 0.0;
    this->b = 0.0;
}

bool LED::is_dummy() const {
    return this->port == LED_DUMMY;
}

uint32_t LED::get_hex_code() const {
    // TODO implement
    return 0;
}

