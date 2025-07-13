#include <Arduino.h>
#include "settings_manager.h"
#include "wifi_manager.h"
#include "web_server.h"
#include "mesh_manager.h"
#include "led_manager.h"
#include "fx_engine.h"

SettingsManager settings_mgr;
WiFiManager wifi_mgr;
WebServer web_server;
MeshManager mesh_mgr;
LEDManager led_mgr;
FXEngine fx_engine;
ControllerSettings settings;

void setup() {
    Serial.begin(115200);
    settings_mgr.begin();
    settings_mgr.load(settings);
    if (!wifi_mgr.connect(settings)) {
        wifi_mgr.start_ap();
    }
    mesh_mgr.begin(settings.is_root);
    led_mgr.begin(settings.led_count, 5);
    fx_engine.begin(led_mgr);
    fx_engine.enable_auto_fx(true);
    fx_engine.set_effect(EffectType::CHASE);
    web_server.begin(settings_mgr, settings);
}

void loop() {
    mesh_mgr.update();
    fx_engine.update();
    delay(10);
}
