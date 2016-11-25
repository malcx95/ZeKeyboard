#include "led.h"

bool LED::is_dummy() const {
    return this->port == LED_DUMMY;
}
