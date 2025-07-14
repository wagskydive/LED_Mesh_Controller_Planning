#include "wifi_manager.h"

bool WiFiManager::connect(ControllerSettings &settings, uint8_t attempts) {
    if (!settings.extend_network || settings.ssid.isEmpty()) {
        return false;
    }
    WiFi.mode(WIFI_STA);
    for (uint8_t i = 0; i < attempts; ++i) {
        WiFi.begin(settings.ssid.c_str(), settings.password.c_str());
        unsigned long start = millis();
        while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
            delay(500);
        }
        if (WiFi.status() == WL_CONNECTED) {
            return true;
        }
        WiFi.disconnect(true);
        delay(1000);
    }
    return false;
}

void WiFiManager::start_ap() {
    WiFi.mode(WIFI_AP);
    WiFi.softAP("LEDMesh", "meshpass");
}

std::vector<String> WiFiManager::scan_networks() {
    WiFi.mode(WIFI_STA);
    int n = WiFi.scanNetworks();
    std::vector<String> ssids;
    for (int i = 0; i < n; ++i) {
        ssids.push_back(WiFi.SSID(i));
    }
    WiFi.scanDelete();
    return ssids;
}
