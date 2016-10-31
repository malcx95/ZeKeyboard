#include "keyboard.h"
// TODO not yet implemented

bool Ze::Key::is_modifier() {
    return this->code < 0;
}
