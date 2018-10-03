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

Color Color::operator+(Color other) {
    return Color{this->r + other.r, this->g + other.g, this->b + other.b};
}

Color Color::operator*(float scale) {
    return Color{this->r*scale, this->g*scale, this->b*scale};
}

Color get_random_color(uint64_t seed) {
    return Color {(seed % 256)/255, ((seed*seed) % 256)/255, ((seed*seed*seed) % 256)/255};
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
