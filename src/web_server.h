#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "settings_manager.h"

class WebServer {
public:
    void begin(SettingsManager &settings_mgr, ControllerSettings &settings);
private:
    AsyncWebServer server{80};
};

#endif // WEB_SERVER_H
