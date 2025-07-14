#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H

#include <Preferences.h>
#include <ArduinoJson.h>

struct ControllerSettings {
    uint16_t universe = 1;
    uint16_t start_channel = 1;
    uint16_t led_count = 30;
    uint16_t dmx_universe = 1;
    uint8_t mode = 0;
    bool is_root = false;
    bool extend_network = false;
    String ssid = "";
    String password = "";
};

class SettingsManager {
public:
    bool begin();
    void load(ControllerSettings &settings);
    void save(const ControllerSettings &settings);
    String to_json(const ControllerSettings &settings);
    void from_json(const String &json, ControllerSettings &settings);
private:
    Preferences prefs;
};

#endif // SETTINGS_MANAGER_H
