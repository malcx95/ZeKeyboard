#include "keyboard.h"

Ze::Key::Key(int code, LED* led) {
    this->code = code;
    this->led = led;
}

bool Ze::Key::is_modifier() const {
    return this->code < 0;
}
