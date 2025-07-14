#include <Arduino.h>
#ifndef ARDUINO_ARCH_ESP32
#error "This firmware requires an ESP32 board. Select 'ESP32 Dev Module' in the Arduino IDE."
#endif
#include "src/settings_manager.h"
#include "src/wifi_manager.h"
#include "src/web_server.h"
#include "src/mesh_manager.h"
#include "src/led_manager.h"
#include "src/fx_engine.h"
#include "src/artnet_receiver.h"
#include "src/dmx_output.h"
#include "src/scene_manager.h"
#include "src/mic_input.h"

SettingsManager settings_mgr;
WiFiManager wifi_mgr;
WebServer web_server;
MeshManager mesh_mgr;
LEDManager led_mgr;
FXEngine fx_engine;
ArtNetReceiver artnet;
DMXOutput dmx_out;
SceneManager scene_mgr;
MicInput mic_input;
ControllerSettings settings;
static unsigned long last_dmx_time = 0;
static const unsigned long DMX_TIMEOUT = 2000;
static bool fx_overridden = false;

void setup() {
    Serial.begin(115200);
    settings_mgr.begin();
    settings_mgr.load(settings);
    if (!wifi_mgr.connect(settings)) {
        wifi_mgr.start_ap();
    }
    scene_mgr.begin();
    scene_mgr.load();
    mesh_mgr.begin(settings.is_root);
    led_mgr.begin(settings.led_count, 5);
    fx_engine.begin(led_mgr);
    mic_input.begin(34);
    fx_engine.enable_auto_fx(true);
    fx_engine.set_effect(EffectType::CHASE);
    dmx_out.begin(Serial1, 17);
    artnet.begin();
    artnet.set_universe(settings.dmx_universe);
    artnet.on_dmx_frame([](const uint8_t *data, uint16_t len) {
        dmx_out.send_frame(data, len);
        last_dmx_time = millis();
        if (!fx_overridden) {
            fx_engine.set_effect(EffectType::NONE);
            fx_overridden = true;
        }
    });
    web_server.begin(settings_mgr, settings, scene_mgr, fx_engine, mesh_mgr);
}

void loop() {
    mesh_mgr.update();
    artnet.update();
    if (fx_overridden) {
        if (millis() - last_dmx_time > DMX_TIMEOUT) {
            fx_overridden = false;
            fx_engine.set_effect(EffectType::CHASE);
        }
    }
    if (!fx_overridden) {
        if (mic_input.detect_beat()) {
            fx_engine.set_effect(EffectType::PULSE);
        }
        fx_engine.update();
    }
    delay(10);
}

