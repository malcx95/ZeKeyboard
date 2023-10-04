#include "layout.hpp"


using namespace keyboard;


const Action* Layout::get(unsigned row, unsigned col) const
{
    return &actions[row][col];
}


void Layout::set_default_layout()
{
    for (int row = 0; row < common::NUM_ROWS; ++row) {
        for (int col = 0; col < common::NUM_COLS; ++col) {
            actions[row][col] = Action(1);
        }
    }
}

