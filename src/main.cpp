#include <Arduino.h>
#include "settings_manager.h"
#include "wifi_manager.h"
#include "web_server.h"
#include "mesh_manager.h"

SettingsManager settings_mgr;
WiFiManager wifi_mgr;
WebServer web_server;
MeshManager mesh_mgr;
ControllerSettings settings;

void setup() {
    Serial.begin(115200);
    settings_mgr.begin();
    settings_mgr.load(settings);
    if (!wifi_mgr.connect(settings)) {
        wifi_mgr.start_ap();
    }
    mesh_mgr.begin(settings.is_root);
    web_server.begin(settings_mgr, settings);
}

void loop() {
    mesh_mgr.update();
    delay(10);
}
