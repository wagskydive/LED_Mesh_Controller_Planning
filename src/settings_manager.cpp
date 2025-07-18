#include "settings_manager.h"

bool SettingsManager::begin() { return prefs.begin("controller", false); }

void SettingsManager::load(ControllerSettings &settings) {
    settings.universe = prefs.getUShort("universe", settings.universe);
    settings.start_channel = prefs.getUShort("start_channel", settings.start_channel);
    settings.led_count = prefs.getUShort("led_count", settings.led_count);
    settings.dmx_universe = prefs.getUShort("dmx_universe", settings.dmx_universe);
    settings.mode = prefs.getUChar("mode", settings.mode);
    settings.is_root = prefs.getBool("is_root", settings.is_root);
    settings.extend_network = prefs.getBool("extend_network", settings.extend_network);
    settings.enable_dmx = prefs.getBool("enable_dmx", settings.enable_dmx);
    settings.ssid = prefs.getString("ssid", settings.ssid);
    settings.password = prefs.getString("password", settings.password);
}

void SettingsManager::save(const ControllerSettings &settings) {
    prefs.putUShort("universe", settings.universe);
    prefs.putUShort("start_channel", settings.start_channel);
    prefs.putUShort("led_count", settings.led_count);
    prefs.putUShort("dmx_universe", settings.dmx_universe);
    prefs.putUChar("mode", settings.mode);
    prefs.putBool("is_root", settings.is_root);
    prefs.putBool("extend_network", settings.extend_network);
    prefs.putBool("enable_dmx", settings.enable_dmx);
    prefs.putString("ssid", settings.ssid);
    prefs.putString("password", settings.password);
}

String SettingsManager::to_json(const ControllerSettings &settings) {
    StaticJsonDocument<256> doc;
    doc["universe"] = settings.universe;
    doc["start_channel"] = settings.start_channel;
    doc["led_count"] = settings.led_count;
    doc["dmx_universe"] = settings.dmx_universe;
    doc["mode"] = settings.mode;
    doc["is_root"] = settings.is_root;
    doc["extend_network"] = settings.extend_network;
    doc["enable_dmx"] = settings.enable_dmx;
    doc["ssid"] = settings.ssid;
    doc["password"] = settings.password;
    String output;
    serializeJson(doc, output);
    return output;
}

void SettingsManager::from_json(const String &json, ControllerSettings &settings) {
    StaticJsonDocument<256> doc;
    DeserializationError err = deserializeJson(doc, json);
    if (err) {
        return;
    }
    if (doc.containsKey("universe")) settings.universe = doc["universe"].as<uint16_t>();
    if (doc.containsKey("start_channel"))
        settings.start_channel = doc["start_channel"].as<uint16_t>();
    if (doc.containsKey("led_count")) settings.led_count = doc["led_count"].as<uint16_t>();
    if (doc.containsKey("dmx_universe")) settings.dmx_universe = doc["dmx_universe"].as<uint16_t>();
    if (doc.containsKey("mode")) settings.mode = doc["mode"].as<uint8_t>();
    if (doc.containsKey("is_root")) settings.is_root = doc["is_root"].as<bool>();
    if (doc.containsKey("extend_network"))
        settings.extend_network = doc["extend_network"].as<bool>();
    if (doc.containsKey("enable_dmx")) settings.enable_dmx = doc["enable_dmx"].as<bool>();
    if (doc.containsKey("ssid")) settings.ssid = doc["ssid"].as<String>();
    if (doc.containsKey("password")) settings.password = doc["password"].as<String>();
}
