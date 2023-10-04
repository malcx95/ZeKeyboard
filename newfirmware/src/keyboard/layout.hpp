#pragma once
#include "action.hpp"
#include "../common/constants.hpp"

namespace keyboard
{

class Layout
{
public:
    const Action* get(unsigned row, unsigned col) const;

    void set_default_layout();

private:
    Action actions[common::NUM_ROWS][common::NUM_COLS];
};

}
