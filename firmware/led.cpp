#include "led.h"
#include <math.h>

float get_brightness(float r, float g, float b) {
    return sqrt(pow(r, 2) + pow(g, 2) + pow(b, 2));
}

uint32_t to_hex(float r, float g, float b) {
    uint32_t red = (((uint32_t)(r * MAX_BYTE)) << 16);
    uint32_t green = (((uint32_t)(g * MAX_BYTE)) << 8);
    uint32_t blue = (uint32_t)(b * MAX_BYTE);
    return red | green | blue;
}

void LED::init() {
    this->port = LED_DUMMY;
    this->r = 0.0;
    this->g = 0.0;
    this->b = 0.0;
}

bool LED::is_dummy() const {
    return this->port == LED_DUMMY;
}

uint32_t LED::get_hex_code() const {
    float brightness = get_brightness(r, g, b);
    if (brightness <= 1.0) {
        return to_hex(r, g, b);
    }
    return to_hex((1 / brightness) * r, (1 / brightness) * g, (1 / brightness) * b);
}

