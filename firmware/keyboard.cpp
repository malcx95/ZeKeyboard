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

int Ze::Board::translate_modifier(const int modifier) const {
    if (modifier >= 0) return -1;
    return MODIFIER_MAP[-1 * modifier - 1];
}

void Ze::Board::init() {

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

    fn_pressed = false;
    num_keys_pressed = 0;

    // Initialize the key buffers to nullptrs
    for (uint8_t i = 0; i < MAX_NUM_KEYS; ++i) {
        curr_pressed_keys[i] = nullptr;
        keys_to_send[i] = nullptr;
        codes_to_send[i] = 0;
    }

    test_counter = 0;
}

void Ze::Board::reset_pressed_keys() {
    for (uint8_t i = 0; i < MAX_NUM_KEYS; ++i) {
        curr_pressed_keys[i] = nullptr;
    }
}

void Ze::Board::update() {
    reset_pressed_keys();
    current_modifier = 0;
}

void Ze::Board::send_keys() {

    // TODO update codes to send
    // We need some way of making sure that
    // when a 2:nd function is used, that 
    // it doesn't send the main code
    // after the FN-key is released if
    // that key is still held down. Or
    // we ignore this problem and see if
    // it causes annoyance.

    Keyboard.set_key1(codes_to_send[0]);
    Keyboard.set_key2(codes_to_send[1]);
    Keyboard.set_key3(codes_to_send[2]);
    Keyboard.set_key4(codes_to_send[3]);
    Keyboard.set_key5(codes_to_send[4]);
    Keyboard.set_key6(codes_to_send[5]);
    
    Keyboard.set_modifier(current_modifier);

    Keyboard.send_now();
}

