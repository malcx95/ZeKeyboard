#include "util.h"

void morph(Color& from, Color& to, float amount, Color& res) {
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

uint8_t wrap_around(int index, uint8_t max) {
    if (index < 0) return max;
    else if (index > max) return 0;
    else return index;
}

void spherical_color(double r, double phi, double theta, Color& res) {
    double sinphi = sin(phi);
    double sintheta = sin(theta);
    double cosphi = cos(phi);
    double costheta = cos(theta);

    res.r = r * sintheta * cosphi;
    res.g = r * sintheta * sinphi;
    res.b = r * costheta;
}

double interpolate(double val, double y0, double x0, double y1, double x1) {
    return (val-x0)*(y1-y0)/(x1-x0) + y0;
}

double base(double val) {
    if (val <= -0.75) return 0;
    else if (val <= -0.25) return interpolate( val, 0.0, -0.75, 1.0, -0.25 );
    else if (val <= 0.25) return 1.0;
    else if (val <= 0.75) return interpolate( val, 1.0, 0.25, 0.0, 0.75 );
    else return 0.0;
}

double red(double gray) {
    return base(gray - 0.5);
}

double green(double gray) {
    return base(gray);
}

double blue(double gray) {
    return base(gray + 0.5);
}

void jet_color_map(uint8_t val, Color& to) {
    float f_val = (((float)val)/255.0 - 0.5)*2.0;
    to.r = red(f_val);
    to.g = green(f_val);
    to.b = blue(f_val);
}
