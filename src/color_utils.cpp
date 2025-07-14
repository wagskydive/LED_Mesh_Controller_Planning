#include "color_utils.h"
#include <cmath>

RGB hsl_to_rgb(uint8_t h, uint8_t s, uint8_t l) {
    float hf = (h / 255.0f) * 360.0f;
    float sf = s / 255.0f;
    float lf = l / 255.0f;
    float c = (1.0f - fabsf(2 * lf - 1)) * sf;
    float x = c * (1 - fabsf(fmodf(hf / 60.0f, 2) - 1));
    float m = lf - c / 2;
    float rf = 0, gf = 0, bf = 0;
    int region = (int)(hf / 60.0f) % 6;
    switch (region) {
        case 0: rf = c; gf = x; break;
        case 1: rf = x; gf = c; break;
        case 2: gf = c; bf = x; break;
        case 3: gf = x; bf = c; break;
        case 4: rf = x; bf = c; break;
        default: rf = c; bf = x; break;
    }
    uint8_t r = (uint8_t)((rf + m) * 255);
    uint8_t g = (uint8_t)((gf + m) * 255);
    uint8_t b = (uint8_t)((bf + m) * 255);
    return {r, g, b};
}

RGB complementary_color(uint8_t h, uint8_t s, uint8_t l) {
    return hsl_to_rgb(h + 128, s, l);
}
