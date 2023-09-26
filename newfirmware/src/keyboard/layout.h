#pragma once
#include "action.h"

namespace keyboard
{

class Layout
{
public:
    Action* get(unsigned row, unsigned col);
private:
    Action** codes;
};

}
