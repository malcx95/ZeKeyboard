#ifndef UTIL_H
#define UTIL_H 

#include <math.h>
#include <stdint.h>

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

/*
 * Converts spherical coordinates to color, where red is x, green is y,
 * and blue is z.
 */
void spherical_color(double r, double phi, double theta, Color& res);

uint8_t clamp(int index, uint8_t max);

uint8_t wrap_around(int index, uint8_t max);


#endif /* ifndef UTIL_H */
