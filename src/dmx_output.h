#ifndef DMX_OUTPUT_H
#define DMX_OUTPUT_H

#include <HardwareSerial.h>

class DMXOutput {
public:
    bool begin(HardwareSerial &serial, int tx_pin);
    void send_frame(const uint8_t *data, uint16_t length);
private:
    HardwareSerial *dmx_serial = nullptr;
};

#endif // DMX_OUTPUT_H
