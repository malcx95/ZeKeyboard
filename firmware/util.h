#ifndef UTIL_H
#define UTIL_H 

#include <FastLED.h>

struct Color {
    float r;
    float g;
    float b;
};

/*
 * Returns a color that is between the color from and to.
 * Amount specifies how much to be morphed: 0.0 is fully original
 * and 1.0 is fully new.
 */
void morph(Color from, Color to, float amount, Color& res);

#endif /* ifndef UTIL_H */
