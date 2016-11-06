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

bool Ze::Key::operator==(const Key& other) const {
    return code == other.code && second == other.second;
}

bool Ze::Key::operator!=(const Key& other) const {
    return !(*this == other);
}

bool Ze::Key::is_fn() const {
    return code == KEY_FN;
}

bool Ze::Key::has_second() const {
    return second != KEY_DUMMY;
}

int Ze::Board::translate_modifier(const int modifier) const {
    if (modifier >= 0) return -1;
    return MODIFIER_MAP[-1 * modifier - 1];
}

// for debugging
void Ze::Board::print_key_arrays() {
    
    Serial.println("-------------------------");

    for (uint8_t i = 0; i < MAX_NUM_KEYS; ++i) {
        Serial.print(curr_pressed_keys[i].code);
        Serial.print(" ");
    }
    Serial.println("");

    for (uint8_t i = 0; i < MAX_NUM_KEYS; ++i) {
        Serial.print(keys_to_send[i].code);
        Serial.print(" ");
    }
    Serial.println("");

    for (uint8_t i = 0; i < MAX_NUM_KEYS; ++i) {
        Serial.print(codes_to_send[i]);
        Serial.print(" ");
    }
    Serial.println("");
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
        curr_pressed_keys[i] = Key();
        keys_to_send[i] = Key();
        codes_to_send[i] = 0;
    }

    test_counter = 0;
}

void Ze::Board::reset_pressed_keys() {
    for (uint8_t i = 0; i < MAX_NUM_KEYS; ++i) {
        curr_pressed_keys[i] = Key();
    }
}

void Ze::Board::update() {
    reset_pressed_keys();
    current_modifier = 0;

    // TODO scan the keys

    //*******************
    // TEST
    //*******************

    test_counter++;

    curr_pressed_keys[0] = KEYS[1][3];

    //*******************
    
    
    update_keys_to_send();
    send_keys();
    
}

void Ze::Board::remove_released_keys() {
    for (uint8_t i = 0; i < MAX_NUM_KEYS; ++i) {
        Key k = keys_to_send[i];

        if (!k.is_dummy()) {

            bool found = false;
            for (uint8_t j = 0; j < MAX_NUM_KEYS; ++j) {
                if (k == curr_pressed_keys[j]) {
                    found = true;
                    break;
                }
            }

            // if the key was not found in the 
            // curr_pressed_keys array, it has
            // been released. Remove it from keys 
            // to send.
            if (!found) {
                keys_to_send[i] = Key();
                codes_to_send[i] = KEY_DUMMY;
            }
        }
    }
}

void Ze::Board::update_keys_to_send() {
    remove_released_keys();
    for (uint8_t i = 0; i < MAX_NUM_KEYS; ++i) {
        Key k = curr_pressed_keys[i];
        if (!k.is_dummy()) {
            try_place_key(k);
        }
    }
}

bool Ze::Board::try_place_key(Key& k) {
    uint8_t lowest_free_index = 0;
    bool found_lowest_index = false;
    for (uint8_t i = 0; i < MAX_NUM_KEYS; ++i) {

        // if this slot is empty and we haven't already found
        // a free slot
        if (keys_to_send[i].is_dummy() && !found_lowest_index) {
            // save the slot
            lowest_free_index = i;
            found_lowest_index = true;
        } else if (keys_to_send[i] == k) {
            // key is already sent, don't do anything
            return false;
        }
    }

    // the array was full
    if (!found_lowest_index) return false;
    
    uint8_t code;

    if (k.has_second() && fn_pressed) {
        code = k.second;
    } else {
        code = k.code;
    }

    keys_to_send[lowest_free_index] = k;

    codes_to_send[lowest_free_index] = code;

    return true;

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
    //
    print_key_arrays();

    Keyboard.set_key1(codes_to_send[0]);
    Keyboard.set_key2(codes_to_send[1]);
    Keyboard.set_key3(codes_to_send[2]);
    Keyboard.set_key4(codes_to_send[3]);
    Keyboard.set_key5(codes_to_send[4]);
    Keyboard.set_key6(codes_to_send[5]);
    
    Keyboard.set_modifier(current_modifier);

    Keyboard.send_now();
}

