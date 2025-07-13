#include "fx_engine.h"

void FXEngine::begin(LEDManager &manager) {
    leds = &manager;
}

void FXEngine::set_effect(EffectType type) {
    current_effect = type;
    last_change = millis();
    if (type == EffectType::NONE) {
        leds->clear();
    }
}

void FXEngine::enable_auto_fx(bool enable) {
    auto_fx = enable;
    last_change = millis();
}

void FXEngine::update() {
    if (!leds) return;

    if (auto_fx && millis() - last_change > 5000) {
        if (current_effect == EffectType::CHASE) {
            set_effect(EffectType::PULSE);
        } else if (current_effect == EffectType::PULSE) {
            set_effect(EffectType::COMPLEMENTARY);
        } else {
            set_effect(EffectType::CHASE);
        }
    }

    switch (current_effect) {
        case EffectType::CHASE:
            run_chase();
            break;
        case EffectType::PULSE:
            run_pulse();
            break;
        case EffectType::COMPLEMENTARY:
            run_complementary();
            break;
        default:
            break;
    }
}

void FXEngine::run_chase() {
    if (millis() - last_update < 100) return;
    last_update = millis();
    leds->clear();
    leds->set_pixel(chase_pos % leds->count(), 255, 0, 0);
    leds->show();
    chase_pos = (chase_pos + 1) % leds->count();
}

void FXEngine::run_pulse() {
    if (millis() - last_update < 30) return;
    last_update = millis();
    uint8_t val = pulse_val;
    for (uint16_t i = 0; i < leds->count(); ++i) {
        leds->set_pixel(i, val, 0, val);
    }
    leds->show();
    if (pulse_up) {
        pulse_val += 5;
        if (pulse_val >= 250) {
            pulse_val = 250;
            pulse_up = false;
        }
    } else {
        if (pulse_val > 5) pulse_val -= 5; else pulse_val = 0;
        if (pulse_val == 0) pulse_up = true;
    }
}

void FXEngine::run_complementary() {
    if (millis() - last_update < 50) return;
    last_update = millis();
    for (uint16_t i = 0; i < leds->count(); ++i) {
        uint8_t hue = (i < leds->count() / 2) ? comp_hue : (uint8_t)(comp_hue + 128);
        uint8_t r, g, b;
        // simple HSV to RGB conversion
        uint8_t region = hue / 43;
        uint8_t remainder = (hue - (region * 43)) * 6;
        uint8_t p = 0;
        uint8_t q = (255 * (255 - remainder)) / 255;
        uint8_t t = (255 * remainder) / 255;
        switch(region) {
            case 0:
                r = 255; g = t; b = p; break;
            case 1:
                r = q; g = 255; b = p; break;
            case 2:
                r = p; g = 255; b = t; break;
            case 3:
                r = p; g = q; b = 255; break;
            case 4:
                r = t; g = p; b = 255; break;
            default:
                r = 255; g = p; b = q; break;
        }
        leds->set_pixel(i, r, g, b);
    }
    leds->show();
    comp_hue++;
}
