#pragma once

#include "scene.hpp"

#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>

class DesktopScene final : public Scene {
    Q_OBJECT;

    constexpr static int WIDGET_WIDTH_ = 700;
    constexpr static int WIDGET_HEIGHT_ = 50;
    constexpr static int WIDGET_STEP_ = 20;

    constexpr static int PUSH_BUTTON_WIDTH_ = 100;

    QListWidget* data_list_ = nullptr;
    QPushButton* leave_button_ = nullptr;
    QLineEdit* line_edit_ = nullptr;
    QPushButton* push_button_ = nullptr;

    std::uint64_t user_id_ = 0;

    void addData(std::uint64_t id, const std::string_view& data);

private slots:
    void on_send();
    void on_leave();

public:
    DesktopScene(QWidget* parent = nullptr);

    void start() override;
};
