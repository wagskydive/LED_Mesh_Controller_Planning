#include <Arduino.h>
#include "settings_manager.h"
#include "wifi_manager.h"
#include "web_server.h"

SettingsManager settings_mgr;
WiFiManager wifi_mgr;
WebServer web_server;
ControllerSettings settings;

void setup() {
    Serial.begin(115200);
    settings_mgr.begin();
    settings_mgr.load(settings);
    if (!wifi_mgr.connect(settings)) {
        wifi_mgr.start_ap();
    }
    web_server.begin(settings_mgr, settings);
}

void loop() {
    delay(1000);
}
