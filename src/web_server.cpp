#include "web_server.h"
#include <ArduinoJson.h>
#include "default_index.h"
#include <Arduino.h>

void WebServer::begin(SettingsManager &settings_mgr, ControllerSettings &settings,
                      SceneManager &scene_mgr, FXEngine &fx, MeshManager &mesh) {
    scenes = &scene_mgr;
    fx_engine = &fx;
    mesh_mgr = &mesh;

    bool spiffs_ok = SPIFFS.begin(true);
    if (!spiffs_ok) {
        Serial.println("[WebServer] SPIFFS mount failed, using fallback page");
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

    server.on("/scenes", HTTP_GET, [this](AsyncWebServerRequest *req) {
        DynamicJsonDocument doc(512);
        JsonArray arr = doc.to<JsonArray>();
        for (auto &s : scenes->get_scenes()) {
            JsonObject obj = arr.createNestedObject();
            obj["id"] = s.id;
            obj["name"] = s.name;
            obj["effect"] = s.effect;
        }
        String out;
        serializeJson(doc, out);
        req->send(200, "application/json", out);
    });

    server.on("/scenes", HTTP_POST, [this](AsyncWebServerRequest *req) {}, NULL,
        [this](AsyncWebServerRequest *req, uint8_t *data, size_t len, size_t, size_t) {
            DynamicJsonDocument doc(512);
            if (deserializeJson(doc, data, len)) {
                req->send(400, "application/json", "{}");
                return;
            }
            scenes->get_scenes().clear();
            for (JsonObject obj : doc.as<JsonArray>()) {
                Scene s;
                s.id = obj["id"].as<uint32_t>();
                s.name = obj["name"].as<String>();
                s.effect = obj["effect"].as<String>();
                scenes->get_scenes().push_back(s);
            }
            scenes->save();
            req->send(200, "application/json", "{}");
        });

    server.on("/nodes", HTTP_GET, [this](AsyncWebServerRequest *req) {
        if (!mesh_mgr) { req->send(200, "application/json", "[]"); return; }
        DynamicJsonDocument doc(256);
        JsonArray arr = doc.to<JsonArray>();
        for (auto &n : mesh_mgr->get_nodes()) {
            arr.add(n);
        }
        String out;
        serializeJson(doc, out);
        req->send(200, "application/json", out);
    });

    server.on("/play", HTTP_POST, [this](AsyncWebServerRequest *req) {}, NULL,
        [this](AsyncWebServerRequest *req, uint8_t *data, size_t len, size_t, size_t) {
            DynamicJsonDocument doc(64);
            if (deserializeJson(doc, data, len)) {
                req->send(400, "application/json", "{}");
                return;
            }
            uint32_t id = doc["id"].as<uint32_t>();
            Scene *sc = scenes->find_scene(id);
            if (!sc) {
                req->send(404, "application/json", "{}");
                return;
            }
            if (fx_engine) {
                if (sc->effect == "CHASE") fx_engine->set_effect(EffectType::CHASE);
                else if (sc->effect == "PULSE") fx_engine->set_effect(EffectType::PULSE);
                else fx_engine->set_effect(EffectType::NONE);
            }
            req->send(200, "application/json", "{}");
        });

    if (spiffs_ok && SPIFFS.exists("/index.html")) {
        server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");
    } else {
        server.on("/", HTTP_GET, [](AsyncWebServerRequest *req) {
            req->send_P(200, "text/html", DEFAULT_INDEX);
        });
    }
    server.begin();
}
