#include "artnet_receiver.h"

bool ArtNetReceiver::begin(uint16_t port) {
    listen_port = port;
    return udp.begin(listen_port);
}

void ArtNetReceiver::set_universe(uint16_t universe) {
    universe_filter = universe;
}

void ArtNetReceiver::on_dmx_frame(std::function<void(const uint8_t*, uint16_t)> cb) {
    frame_cb = cb;
}

void ArtNetReceiver::update() {
    if (!udp.parsePacket()) return;
    uint8_t header[18];
    if (udp.read(header, sizeof(header)) != sizeof(header)) return;
    if (memcmp(header, "Art-Net\0", 8) != 0) return;
    uint16_t opcode = header[8] | (header[9] << 8);
    if (opcode != 0x5000) return; // ArtDMX
    uint16_t prot_ver = header[10] << 8 | header[11];
    (void)prot_ver;
    uint16_t sequence = header[12];
    (void)sequence;
    uint16_t physical = header[13];
    (void)physical;
    uint16_t universe = header[14] | (header[15] << 8);
    uint16_t length = header[16] << 8 | header[17];
    static uint8_t data[512];
    if (length > sizeof(data)) length = sizeof(data);
    udp.read(data, length);
    if (universe_filter != 0 && universe_filter != universe) return;
    if (frame_cb) {
        frame_cb(data, length);
    }
}
