#ifndef FX_ENGINE_H
#define FX_ENGINE_H

#include <Arduino.h>
#include "led_manager.h"

enum class EffectType {
    NONE,
    CHASE,
    PULSE,
    COMPLEMENTARY
};

class FXEngine {
public:
    void begin(LEDManager &manager);
    void set_effect(EffectType type);
    void enable_auto_fx(bool enable);
    void update();
private:
    LEDManager *leds = nullptr;
    EffectType current_effect = EffectType::NONE;
    bool auto_fx = false;
    unsigned long last_update = 0;
    unsigned long last_change = 0;
    uint16_t chase_pos = 0;
    uint8_t pulse_val = 0;
    bool pulse_up = true;
    uint8_t comp_hue = 0;
    void run_chase();
    void run_pulse();
    void run_complementary();
};

#endif // FX_ENGINE_H
