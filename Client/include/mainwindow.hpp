#pragma once

#include "scene-context.hpp"

#include <QMainWindow>

class MainWindow final : public QMainWindow {
    Q_OBJECT;

    constexpr static std::size_t WINDOW_WIDTH_ = 800;
    constexpr static std::size_t WINDOW_HEIGHT_ = 600;

    SceneContext scene_context_;

    void initScene();

public slots:
    void on_next_scene();

public:
    MainWindow();
};
