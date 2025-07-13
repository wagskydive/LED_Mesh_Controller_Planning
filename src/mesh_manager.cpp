#include "mesh_manager.h"
#include <esp_wifi.h>
#include <esp_mesh.h>

bool MeshManager::begin(bool is_root) {
    root = is_root;
    pinMode(LED_BUILTIN, OUTPUT);
    // TODO: Initialize ESP-Mesh here
    return true;
}

void MeshManager::update() {
    // TODO: Handle mesh events
    unsigned long interval = root ? 1000 : 300;
    if (millis() - last_led_toggle > interval) {
        last_led_toggle = millis();
        led_state = !led_state;
        digitalWrite(LED_BUILTIN, led_state);
    }
}

bool MeshManager::is_root_node() const {
    return root;
}

void MeshManager::send_message(const String &msg) {
    // TODO: Broadcast message via mesh
    if (message_cb) {
        message_cb(msg); // loopback for now
    }
}

void MeshManager::on_message(std::function<void(const String&)> cb) {
    message_cb = cb;
}
