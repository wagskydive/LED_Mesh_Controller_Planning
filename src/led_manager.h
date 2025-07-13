#ifndef LED_MANAGER_H
#define LED_MANAGER_H

#include <Adafruit_NeoPixel.h>

class LEDManager {
public:
    bool begin(uint16_t count, uint8_t pin);
    void set_pixel(uint16_t idx, uint8_t r, uint8_t g, uint8_t b);
    void show();
    void clear();
    uint16_t count() const;
private:
    Adafruit_NeoPixel strip{0, 0, NEO_GRB + NEO_KHZ800};
    uint16_t led_count = 0;
};

#endif // LED_MANAGER_H
