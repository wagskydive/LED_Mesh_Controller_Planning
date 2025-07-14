#include <Arduino.h>

#include "artnet_receiver.h"
#include "dmx_output.h"
#include "fx_engine.h"
#include "led_manager.h"
#include "mesh_manager.h"
#include "mic_input.h"
#include "scene_manager.h"
#include "settings_manager.h"
#include "web_server.h"
#include "wifi_manager.h"

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
    bool connected = false;
    if (settings.extend_network) {
        connected = wifi_mgr.connect(settings, 5);
    }
    if (!connected) {
        wifi_mgr.start_ap();
    }
    scene_mgr.begin();
    scene_mgr.load();
    mesh_mgr.begin(settings.is_root);
    led_mgr.begin(settings.led_count, 5);
    fx_engine.begin(led_mgr);
    mic_input.begin(34);
    fx_engine.attach_mic(mic_input);
    fx_engine.enable_auto_fx(false);
    fx_engine.set_effect(EffectType::AUDIO_REACTIVE);
    dmx_out.begin(Serial1, 17);
    artnet.begin();
    artnet.set_universe(settings.dmx_universe);
    artnet.on_dmx_frame([](const uint8_t *data, uint16_t len) {
        if (settings.enable_dmx) {
            dmx_out.send_frame(data, len);
        }
        uint16_t start = settings.start_channel - 1;
        for (uint16_t i = 0; i < led_mgr.count(); ++i) {
            uint16_t idx = start + i * 3;
            if (idx + 2 < len) {
                led_mgr.set_pixel(i, data[idx], data[idx + 1], data[idx + 2]);
            }
        }
        led_mgr.show();
        last_dmx_time = millis();
        if (!fx_overridden) {
            fx_engine.set_effect(EffectType::NONE);
            fx_overridden = true;
        }
    });
    web_server.begin(settings_mgr, settings, scene_mgr, fx_engine, mesh_mgr, wifi_mgr);
}

void loop() {
    mesh_mgr.update();
    artnet.update();
    if (fx_overridden) {
        if (millis() - last_dmx_time > DMX_TIMEOUT) {
            fx_overridden = false;
            fx_engine.set_effect(EffectType::AUDIO_REACTIVE);
        }
    }
    static unsigned long last_pulse = 0;
    if (!fx_overridden) {
        if (mic_input.detect_beat()) {
            fx_engine.set_effect(EffectType::PULSE);
            last_pulse = millis();
        } else if (fx_engine.get_effect() == EffectType::PULSE && millis() - last_pulse > 500) {
            fx_engine.set_effect(EffectType::AUDIO_REACTIVE);
        }
        fx_engine.update();
    }
    web_server.update();
    delay(10);
}
