#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>
#include "settings_manager.h"

class WiFiManager {
public:
    bool connect(ControllerSettings &settings, uint8_t attempts = 3);
    void start_ap();
};

#endif // WIFI_MANAGER_H
