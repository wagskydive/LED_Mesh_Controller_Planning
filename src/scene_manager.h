#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <Arduino.h>
#include <vector>

struct Scene {
    uint32_t id;
    String name;
    String effect;
};

class SceneManager {
public:
    bool begin();
    bool load();
    bool save();
    std::vector<Scene>& get_scenes();
    Scene* find_scene(uint32_t id);
private:
    std::vector<Scene> scenes;
};

#endif // SCENE_MANAGER_H
