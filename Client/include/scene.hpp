#pragma once

#include "scene-type.hpp"

#include <QWidget>

class Scene : public QWidget {
    Q_OBJECT;

    constexpr static std::string_view CLIENT_CONFIG_PATH_ = "config.json";

    SceneType type_;

protected:
    Scene(SceneType type, QWidget* parent = nullptr);

    std::string_view getClientConfigPath() const;

public:
    virtual ~Scene() {}

    SceneType getSceneType() const;

    virtual void start();

signals:
    void nextScene();
};
