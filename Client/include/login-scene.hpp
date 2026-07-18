#pragma once

#include "scene.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFont>

class LoginScene final : public Scene {
    Q_OBJECT;

    constexpr static int WIDGETS_WIDTH_ = 200;
    constexpr static int WIDGETS_HEIGHT_ = 50;
    constexpr static int WIDGETS_HEIGHT_STEP_ = 20;

    QLabel* label_ = nullptr;
    QLineEdit* line_edit_ = nullptr;
    QPushButton* push_button_ = nullptr;

    void initLabel();
    void initLineEdit();
    void initPushButton();
    void initView();
    void initConnect();

    void checkLogin();

private slots:
    void on_login();

public:
    LoginScene(QWidget* parent = nullptr);

    void start() override;
};
