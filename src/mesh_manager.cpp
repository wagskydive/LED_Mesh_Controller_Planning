#include "mesh_manager.h"
#include <Arduino.h>
#include <esp_wifi.h>
#include <esp_mesh.h>

bool MeshManager::begin(bool is_root) {
    pinMode(LED_BUILTIN, OUTPUT);
    state = MeshState::SEARCHING;
    root = is_root;

    // Basic ESP-Mesh initialization
    mesh_cfg_t cfg = MESH_INIT_CONFIG_DEFAULT();
    esp_mesh_init();
    esp_mesh_set_config(&cfg);
    esp_mesh_start();

    // Check if this node became the root
    if (!root && esp_mesh_is_root()) {
        root = true;
    }

    state = root ? MeshState::ROOT : MeshState::NODE;
    return true;
}

void MeshManager::update() {
    if (message_cb) {
        mesh_addr_t from;
        mesh_data_t data;
        int flag = 0;
        uint8_t buf[150];
        data.data = buf;
        data.size = sizeof(buf);
        if (esp_mesh_recv(&from, &data, 0, &flag, NULL, 0) == ESP_OK) {
            String msg = String((char *)data.data);
            message_cb(msg);
        }
    }

    if (state == MeshState::ROOT) {
        digitalWrite(LED_BUILTIN, HIGH);
        return;
    }

    unsigned long interval = (state == MeshState::NODE) ? 1000 : 100;
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
    mesh_addr_t broadcast_addr{};
    memset(&broadcast_addr, 0, sizeof(broadcast_addr));
    mesh_data_t data;
    data.data = (uint8_t *)msg.c_str();
    data.size = msg.length() + 1;
    data.proto = MESH_PROTO_JSON;
    data.tos = MESH_TOS_P2P;
    esp_mesh_send(&broadcast_addr, &data, MESH_DATA_P2P, NULL, 0);
    if (message_cb) {
        message_cb(msg);
    }
}

void MeshManager::on_message(std::function<void(const String&)> cb) {
    message_cb = cb;
}
