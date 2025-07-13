#ifndef ARTNET_RECEIVER_H
#define ARTNET_RECEIVER_H

#include <WiFiUdp.h>
#include <functional>

class ArtNetReceiver {
public:
    bool begin(uint16_t port = 6454);
    void set_universe(uint16_t universe);
    void on_dmx_frame(std::function<void(const uint8_t*, uint16_t)> cb);
    void update();
private:
    WiFiUDP udp;
    uint16_t listen_port = 6454;
    uint16_t universe_filter = 0;
    std::function<void(const uint8_t*, uint16_t)> frame_cb = nullptr;
};

#endif // ARTNET_RECEIVER_H
