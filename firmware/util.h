#ifndef UTIL_H
#define UTIL_H 

#include <FastLED.h>

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

/*
 * Returns a color that is between the color from and to.
 * Amount specifies how much to be morphed: 0.0 is fully original
 * and 1.0 is fully new.
 */
Color morph(Color from, Color to, float amount);

#endif /* ifndef UTIL_H */
