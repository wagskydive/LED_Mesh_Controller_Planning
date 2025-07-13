#include "dmx_output.h"

bool DMXOutput::begin(HardwareSerial &serial, int tx_pin) {
    dmx_serial = &serial;
    dmx_serial->begin(250000, SERIAL_8N2, -1, tx_pin); // DMX standard
    return true;
}

void DMXOutput::send_frame(const uint8_t *data, uint16_t length) {
    if (!dmx_serial) return;
    dmx_serial->write(0); // start code
    dmx_serial->write(data, length);
    dmx_serial->flush();
}
