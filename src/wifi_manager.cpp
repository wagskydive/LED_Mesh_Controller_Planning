#include "wifi_manager.h"

bool WiFiManager::connect(ControllerSettings &settings) {
    if (settings.ssid.isEmpty()) {
        return false;
    }
    WiFi.mode(WIFI_STA);
    WiFi.begin(settings.ssid.c_str(), settings.password.c_str());
    unsigned long start = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
        delay(500);
    }
    return WiFi.status() == WL_CONNECTED;
}

void WiFiManager::start_ap() {
    WiFi.mode(WIFI_AP);
    WiFi.softAP("LEDMesh", "meshpass");
}
