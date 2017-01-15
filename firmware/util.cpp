#include "util.h"

void morph(Color from, Color to, float amount, Color& res) {
    if (amount < 0.0) amount = 0.0;
    else if (amount > 1.0) amount = 1.0;

    float rdiff = from.r - to.r;
    float gdiff = from.g - to.g;
    float bdiff = from.b - to.b;

    res.r = from.r - rdiff * amount;
    res.g = from.g - gdiff * amount;
    res.b = from.b - bdiff * amount;
}

uint8_t clamp(int index, uint8_t max) {
    if (index < 0) return 0;
    else if (index > max) return max;
    else return index;
}

