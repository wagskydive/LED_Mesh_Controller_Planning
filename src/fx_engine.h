#ifndef FX_ENGINE_H
#define FX_ENGINE_H

#include <Arduino.h>

#include "led_manager.h"
#include "mic_input.h"

enum class EffectType {
    NONE,
    CHASE,
    PULSE,
    STATIC,
    WIPE,
    BOUNCE,
    COLOR_CYCLE,
    COMPLEMENTARY,
    AUDIO_REACTIVE
};

class FXEngine {
   public:
    void begin(LEDManager &manager);
    void set_effect(EffectType type);
    EffectType get_effect() const;
    void enable_auto_fx(bool enable, unsigned long interval_ms = 5000);
    void attach_mic(MicInput &mic);
    void update();

   private:
    LEDManager *leds = nullptr;
    EffectType current_effect = EffectType::NONE;
    bool auto_fx = false;
    unsigned long auto_interval = 5000;
    unsigned long last_update = 0;
    unsigned long last_change = 0;
    uint16_t chase_pos = 0;
    uint8_t pulse_val = 0;
    bool pulse_up = true;
    uint16_t wipe_pos = 0;
    int16_t bounce_pos = 0;
    bool bounce_forward = true;
    uint8_t cycle_hue = 0;
    uint8_t comp_hue = 0;
    MicInput *mic_in = nullptr;
    void run_chase();
    void run_pulse();
    void run_static();
    void run_wipe();
    void run_bounce();
    void run_color_cycle();
    void run_complementary();
    void run_audio_reactive();
};

#endif  // FX_ENGINE_H
