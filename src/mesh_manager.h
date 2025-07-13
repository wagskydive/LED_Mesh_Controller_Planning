#ifndef MESH_MANAGER_H
#define MESH_MANAGER_H

#include <Arduino.h>
#include <functional>

enum class MeshState {
    SEARCHING,
    ROOT,
    NODE
};

class MeshManager {
public:
    bool begin(bool is_root);
    void update();
    bool is_root_node() const;
    void send_message(const String &msg);
    void on_message(std::function<void(const String&)> cb);

private:
    bool root = false;
    MeshState state = MeshState::SEARCHING;
    std::function<void(const String&)> message_cb = nullptr;
    unsigned long last_led_toggle = 0;
    bool led_state = false;
};

#endif // MESH_MANAGER_H
