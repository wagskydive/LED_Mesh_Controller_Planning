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
