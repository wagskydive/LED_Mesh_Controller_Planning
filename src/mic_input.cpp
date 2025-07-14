#include "mic_input.h"

bool MicInput::begin(uint8_t pin) {
    mic_pin = pin;
    pinMode(mic_pin, INPUT);
    return true;
}

bool MicInput::detect_beat() {
    int val = analogRead(mic_pin);
    if (val > threshold && millis() - last_trigger > 150) {
        last_trigger = millis();
        return true;
    }
    return false;
}

uint16_t MicInput::read_level() { return analogRead(mic_pin); }
