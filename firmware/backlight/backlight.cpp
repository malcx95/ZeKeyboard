#include "backlight.h"

Backlight::Backlight(Tlc5940* tlc, Ze::Keyboard* keyboard) {
    this->tlc = tlc;
    this->keyboard = keyboard;
}


