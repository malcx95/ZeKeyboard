#pragma once
#include "action.hpp"
#include "../common/constants.hpp"

namespace keyboard
{

class Layout
{
public:
    Action* get(unsigned row, unsigned col);
private:
    Action actions[common::NUM_ROWS][common::NUM_COLS];
};

}
