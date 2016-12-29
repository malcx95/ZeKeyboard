#include "led.h"

void LED::init() {
    this->port = LED_DUMMY;
    this->r = 0.0;
    this->g = 0.0;
    this->b = 0.0;
}

bool LED::is_dummy() const {
    return this->port == LED_DUMMY;
}

uint32_t LED::get_hex_code(float brightness) const {
    uint32_t red = (((uint32_t)(r * MAX_BYTE * brightness)) << 16);
    uint32_t green = (((uint32_t)(g * MAX_BYTE * brightness)) << 8);
    uint32_t blue = (uint32_t)(b * MAX_BYTE * brightness);
    return red | green | blue;
}

