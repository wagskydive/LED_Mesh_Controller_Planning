#include "web_server.h"

void WebServer::begin(SettingsManager &settings_mgr, ControllerSettings &settings) {
    if (!SPIFFS.begin(true)) {
        return;
    }

    server.on("/settings", HTTP_GET, [&settings_mgr, &settings](AsyncWebServerRequest *req) {
        String json = settings_mgr.to_json(settings);
        req->send(200, "application/json", json);
    });

    server.on("/settings", HTTP_POST, [&settings_mgr, &settings](AsyncWebServerRequest *req) {}, NULL,
        [&settings_mgr, &settings](AsyncWebServerRequest *req, uint8_t *data, size_t len, size_t, size_t) {
            String body = String((const char*)data, len);
            settings_mgr.from_json(body, settings);
            settings_mgr.save(settings);
            req->send(200, "application/json", settings_mgr.to_json(settings));
        });

    server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");
    server.begin();
}
