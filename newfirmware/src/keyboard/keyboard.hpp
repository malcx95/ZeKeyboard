#pragma once

#include "layout.hpp"

namespace keyboard
{

class KeyboardState
{

public:
    KeyboardState(unsigned rows, unsigned cols);
private:
    Layout layout;
};

}

