#include "keyboard.h"

Ze::Key::Key() {
    this->code = KEY_DUMMY;
    this->led = LED_DUMMY;
}

Ze::Key::Key(int code, led_t led) {
    this->code = code;
    this->led = led;
    this->second = KEY_DUMMY;
}

Ze::Key::Key(int code, int second, led_t led) {
    this->code = code;
    this->led = led;
    this->second = second;
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

void Ze::Keyboard::init() {

    // Set the rows as outputs
    for (uint8_t r = 0; r < NUM_ROWS; ++r) {
        pinMode(ROW_PINS[r], OUTPUT);
        digitalWrite(ROW_PINS[r], HIGH);
    }

    // Set the columns as inputs with pull up resistors
    for (uint8_t c = 0; c < NUM_COLS; ++c) {
        pinMode(COL_PINS[c], INPUT_PULLUP);
        digitalWrite(COL_PINS[c], INPUT_PULLUP);
    }

}

