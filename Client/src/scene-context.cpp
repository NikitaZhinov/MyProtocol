#include "scene-context.hpp"

#include "login-scene.hpp"
#include "loading-scene.hpp"
#include "desktop-scene.hpp"

void SceneContext::addScene(std::shared_ptr<Scene> new_scene) {
    scenes_.emplace_back(new_scene);
}

void SceneContext::init(QWidget* parent) {
    addScene(std::make_shared<LoginScene>(parent));
    addScene(std::make_shared<LoadingScene>(parent));
    addScene(std::make_shared<DesktopScene>(parent));

    cur_scene_ = scenes_.begin();
}

void SceneContext::nextScene() {
    cur_scene_->get()->hide();
    ++cur_scene_;

    if (cur_scene_ == scenes_.end()) {
        cur_scene_ = scenes_.begin();
    }
}

const Scene* SceneContext::getCurrentScene() const {
    return cur_scene_->get();
}

void SceneContext::start() {
    cur_scene_->get()->show();
    cur_scene_->get()->start();
}
