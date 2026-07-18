#include "mainwindow.hpp"

#include "login-scene.hpp"

void MainWindow::initScene() {
    connect(scene_context_.getCurrentScene(), &Scene::nextScene, this,
            &MainWindow::on_next_scene);
    scene_context_.start();
}

void MainWindow::on_next_scene() {
    disconnect(scene_context_.getCurrentScene(), &Scene::nextScene, this,
               &MainWindow::on_next_scene);
    scene_context_.nextScene();
    initScene();
}

MainWindow::MainWindow() {
    setFixedSize(WINDOW_WIDTH_, WINDOW_HEIGHT_);
    scene_context_.init(this);
    initScene();
}
