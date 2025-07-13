#include "scene_manager.h"
#include <SPIFFS.h>
#include <ArduinoJson.h>

bool SceneManager::begin() {
    return SPIFFS.begin(true);
}

bool SceneManager::load() {
    scenes.clear();
    if (!SPIFFS.exists("/scenes.json")) return true;
    File f = SPIFFS.open("/scenes.json", FILE_READ);
    if (!f) return false;
    DynamicJsonDocument doc(512);
    DeserializationError err = deserializeJson(doc, f);
    f.close();
    if (err) return false;
    for (JsonObject obj : doc.as<JsonArray>()) {
        Scene s;
        s.id = obj["id"].as<uint32_t>();
        s.name = obj["name"].as<String>();
        s.effect = obj["effect"].as<String>();
        scenes.push_back(s);
    }
    return true;
}

bool SceneManager::save() {
    DynamicJsonDocument doc(512);
    JsonArray arr = doc.to<JsonArray>();
    for (auto &s : scenes) {
        JsonObject obj = arr.createNestedObject();
        obj["id"] = s.id;
        obj["name"] = s.name;
        obj["effect"] = s.effect;
    }
    File f = SPIFFS.open("/scenes.json", FILE_WRITE);
    if (!f) return false;
    serializeJson(doc, f);
    f.close();
    return true;
}

std::vector<Scene>& SceneManager::get_scenes() {
    return scenes;
}

Scene* SceneManager::find_scene(uint32_t id) {
    for (auto &s : scenes) {
        if (s.id == id) return &s;
    }
    return nullptr;
}
