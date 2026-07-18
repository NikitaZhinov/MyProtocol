#pragma once

#include "scene.hpp"

#include <vector>

class SceneContext final {
    std::vector<std::shared_ptr<Scene>> scenes_;
    decltype(scenes_)::iterator cur_scene_;

    void addScene(std::shared_ptr<Scene> new_scene);

public:
    void init(QWidget* parent);

    void nextScene();

    const Scene* getCurrentScene() const;

    void start();
};
