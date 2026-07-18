#pragma once

#include "scene.hpp"

#include <QLabel>
#include <atomic>
#include <protocol/protocol.hpp>

class LoadingScene : public Scene {
    Q_OBJECT;

    constexpr static int LABEL_WIDTH_ = 200;
    constexpr static int LABEL_HEIGHT_ = 50;

    QLabel* label_ = nullptr;
    std::atomic_bool is_loaded_ = false;

    void updateScreen();
    void loadData();

signals:
    void loaded(std::uint64_t user_id,
                const protocol::serialization::utils::serialize_data_t& data);

private slots:
    void on_loaded(std::uint64_t user_id,
                   const protocol::serialization::utils::serialize_data_t& data);

public:
    LoadingScene(QWidget* parent = nullptr);

    void start() override;
};
