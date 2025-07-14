#include "fx_engine.h"
#include "color_utils.h"

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

void FXEngine::enable_auto_fx(bool enable, unsigned long interval_ms) {
    auto_fx = enable;
    auto_interval = interval_ms;
    last_change = millis();
}

void FXEngine::update() {
    if (!leds) return;

    if (auto_fx && millis() - last_change > auto_interval) {
        switch (current_effect) {
            case EffectType::CHASE:
                set_effect(EffectType::PULSE);
                break;
            case EffectType::PULSE:
                set_effect(EffectType::STATIC);
                break;
            case EffectType::STATIC:
                set_effect(EffectType::WIPE);
                break;
            case EffectType::WIPE:
                set_effect(EffectType::BOUNCE);
                break;
            case EffectType::BOUNCE:
                set_effect(EffectType::COLOR_CYCLE);
                break;
            case EffectType::COLOR_CYCLE:
                set_effect(EffectType::COMPLEMENTARY);
                break;
            default:
                set_effect(EffectType::CHASE);
                break;
        }
    }

    switch (current_effect) {
        case EffectType::CHASE:
            run_chase();
            break;
        case EffectType::PULSE:
            run_pulse();
            break;
        case EffectType::STATIC:
            run_static();
            break;
        case EffectType::WIPE:
            run_wipe();
            break;
        case EffectType::BOUNCE:
            run_bounce();
            break;
        case EffectType::COLOR_CYCLE:
            run_color_cycle();
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

void FXEngine::run_static() {
    if (millis() - last_update < 500) return;
    last_update = millis();
    for (uint16_t i = 0; i < leds->count(); ++i) {
        leds->set_pixel(i, 0, 0, 255);
    }
    leds->show();
}

void FXEngine::run_wipe() {
    if (millis() - last_update < 50) return;
    last_update = millis();
    leds->set_pixel(wipe_pos, 0, 255, 0);
    leds->show();
    wipe_pos++;
    if (wipe_pos >= leds->count()) {
        wipe_pos = 0;
        leds->clear();
    }
}

void FXEngine::run_bounce() {
    if (millis() - last_update < 80) return;
    last_update = millis();
    leds->clear();
    leds->set_pixel(bounce_pos, 255, 255, 0);
    leds->show();
    if (bounce_forward) {
        bounce_pos++;
        if (bounce_pos >= (int16_t)leds->count() - 1) bounce_forward = false;
    } else {
        bounce_pos--;
        if (bounce_pos <= 0) bounce_forward = true;
    }
}

void FXEngine::run_color_cycle() {
    if (millis() - last_update < 60) return;
    last_update = millis();
    for (uint16_t i = 0; i < leds->count(); ++i) {
        uint8_t hue = cycle_hue + i * 5;
        uint8_t region = hue / 43;
        uint8_t remainder = (hue - (region * 43)) * 6;
        uint8_t p = 0;
        uint8_t q = (255 * (255 - remainder)) / 255;
        uint8_t t = (255 * remainder) / 255;
        uint8_t r, g, b;
        switch(region) {
            case 0: r = 255; g = t; b = p; break;
            case 1: r = q; g = 255; b = p; break;
            case 2: r = p; g = 255; b = t; break;
            case 3: r = p; g = q; b = 255; break;
            case 4: r = t; g = p; b = 255; break;
            default: r = 255; g = p; b = q; break;
        }
        leds->set_pixel(i, r, g, b);
    }
    leds->show();
    cycle_hue++;
}

void FXEngine::run_complementary() {
    if (millis() - last_update < 50) return;
    last_update = millis();
    for (uint16_t i = 0; i < leds->count(); ++i) {
        uint8_t hue = (i < leds->count() / 2) ? comp_hue : comp_hue + 128;
        RGB c = hsl_to_rgb(hue, 255, 127);
        leds->set_pixel(i, c.r, c.g, c.b);
    }
    leds->show();
    comp_hue++;
}
