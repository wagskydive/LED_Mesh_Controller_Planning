#ifndef COLOR_UTILS_H
#define COLOR_UTILS_H
#include <Arduino.h>
struct RGB { uint8_t r; uint8_t g; uint8_t b; };
RGB hsl_to_rgb(uint8_t h, uint8_t s, uint8_t l);
RGB complementary_color(uint8_t h, uint8_t s, uint8_t l);
#endif
