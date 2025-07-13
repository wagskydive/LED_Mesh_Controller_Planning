#include "led_manager.h"

bool LEDManager::begin(uint16_t count, uint8_t pin) {
    led_count = count;
    strip.updateLength(count);
    strip.setPin(pin);
    strip.begin();
    strip.show();
    return true;
}

void LEDManager::set_pixel(uint16_t idx, uint8_t r, uint8_t g, uint8_t b) {
    if (idx >= led_count) return;
    strip.setPixelColor(idx, r, g, b);
}

void LEDManager::show() {
    strip.show();
}

void LEDManager::clear() {
    strip.clear();
    strip.show();
}

uint16_t LEDManager::count() const {
    return led_count;
}
