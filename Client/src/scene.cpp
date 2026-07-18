#include "scene.hpp"

Scene::Scene(SceneType type, QWidget* parent) : type_(type), QWidget(parent) {
    hide();
}

SceneType Scene::getSceneType() const {
    return type_;
}

void Scene::start() {}

std::string_view Scene::getClientConfigPath() const {
    return CLIENT_CONFIG_PATH_;
}
