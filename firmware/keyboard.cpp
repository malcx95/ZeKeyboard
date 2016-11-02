#include "keyboard.h"

Ze::Key::Key() {
    this->code = KEY_DUMMY;
    this->led = LED_DUMMY;
}

Ze::Key::Key(int code, led_t led) {
    this->code = code;
    this->led = led;
}

bool Ze::Key::is_modifier() const {
    return this->code < -1;
}

bool Ze::Key::is_dummy() const {
    return code == KEY_DUMMY || led == LED_DUMMY;
}

bool Ze::Key::is_fn() const {
    return code == KEY_FN;
}

int Ze::Keyboard::translate_modifier(const int modifier) const {
    if (modifier >= 0) return -1;
    return MODIFIER_MAP[-1 * modifier - 1];
}

