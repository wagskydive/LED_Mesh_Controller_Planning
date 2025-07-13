#ifndef MIC_INPUT_H
#define MIC_INPUT_H

#include <Arduino.h>

class MicInput {
public:
    bool begin(uint8_t pin);
    bool detect_beat();
private:
    uint8_t mic_pin = 34;
    uint16_t threshold = 800;
    unsigned long last_trigger = 0;
};

#endif // MIC_INPUT_H
