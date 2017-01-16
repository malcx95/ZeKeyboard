#include "backlight.h"

Backlight::Backlight() {
    this->keyboard = nullptr;
    this->ledstrip = nullptr;
    this->style = BacklightStyle::STANDARD;
}

void Backlight::init(Ze::Board* keyboard, CRGB* ledstrip) {
    this->keyboard = keyboard;
    this->ledstrip = ledstrip;
    this->curr_brightness = 2;
    this->brightness = BRIGHTNESS_VALUES[this->curr_brightness];
    this->it = 0;
    this->already_changed_bright = false;

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            LED l;
            l.init();
            l.port = LED_GRID[row][col];
            leds[row][col] = l;
        }
    }
}

void Backlight::print_grid() {
    Serial.println("-------------------------");

    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            uint16_t b = leds[row][col].r;
            Serial.print(b);
            if (b < 10) {
                Serial.print(" ");
            }
        }
        Serial.println("");
    }
    Serial.println("");
}

void Backlight::setup(BacklightStyle style) {
    this->style = style;
    switch (style) {
        case STANDARD:
            standard_setup(this->leds);
            break;
        case WATER:
            water_setup(this->leds, this->particles);
            break;
        case RAVE:
            rave_setup(this->leds);
            break;
        case GAMEOFLIFE:
            gameoflife_setup(this->leds, this->cells);
            break;
    }
}

void Backlight::handle_brightness_change() {
    if (this->keyboard->brightness_inc_pressed()) {
        if (!this->already_changed_bright) {
            increase_brightness();
        }
        this->already_changed_bright = true;
    } else {
        this->already_changed_bright = false;
    }
}

void Backlight::change_style() {
    switch (this->style) {
        case STANDARD:
            standard_destroy();
            break;
        case WATER:
            water_destroy(this->particles);
            break;
        case RAVE:
            rave_destroy();
            break;
    }
    BacklightStyle s = static_cast<BacklightStyle>((((int)this->style) + 1) % NUM_STYLES);
    this->setup(s);
}

void Backlight::handle_backlight_change() {
    if (this->keyboard->backlight_style_changed()) {
        if (!this->already_changed_style) {
            change_style();
        }
        this->already_changed_style = true;
    } else {
        this->already_changed_style = false;
    }
}

void Backlight::update() {

    handle_backlight_change();
    
    handle_brightness_change();

    this->it++;
    switch (style) {
        case STANDARD:
            standard_update(this->leds, this->keyboard, this->it);
            break;
        case WATER:
            water_update(this->leds, this->keyboard, this->particles, this->it);
            break;
        case RAVE:
            rave_update(this->leds, this->keyboard, this->it);
            break;
        case GAMEOFLIFE:
            gameoflife_update(this->leds, this->keyboard, this->cells, this->it);
            break;
    }

    // update the leds
    for (uint8_t row = 0; row < Ze::NUM_ROWS; ++row) {
        for (uint8_t col = 0; col < Ze::NUM_COLS; ++col) {
            LED curr = leds[row][col];
            if (!curr.is_dummy()) {
                // set the color
                ledstrip[translate_grid_to_strip(row, col)] = 
                    curr.get_hex_code(this->brightness);
            }
        }
    }
    FastLED.show();
}

void Backlight::increase_brightness() {
    this->curr_brightness = (curr_brightness + 1) % NUM_BRIGHTNESS_VALUES;
    this->brightness = BRIGHTNESS_VALUES[curr_brightness];
}

uint8_t Backlight::translate_grid_to_strip(uint8_t row, uint8_t col) {
    return LED_GRID[row][col];
}
