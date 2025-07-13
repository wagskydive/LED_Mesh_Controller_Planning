#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "settings_manager.h"
#include "scene_manager.h"
#include "fx_engine.h"
#include "mesh_manager.h"

class WebServer {
public:
    void begin(SettingsManager &settings_mgr, ControllerSettings &settings,
               SceneManager &scene_mgr, FXEngine &fx, MeshManager &mesh);
private:
    AsyncWebServer server{80};
    SceneManager *scenes = nullptr;
    FXEngine *fx_engine = nullptr;
    MeshManager *mesh_mgr = nullptr;
};

#endif // WEB_SERVER_H
