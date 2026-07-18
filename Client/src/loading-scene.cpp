#include "loading-scene.hpp"

#include "network.hpp"

#include <boost/asio.hpp>
#include <thread>
#include <chrono>
#include <fstream>
#include <boost/json.hpp>

namespace json = boost::json;

void LoadingScene::updateScreen() {
    int counter = 1;

    auto start_text = label_->text();

    while (!is_loaded_) {
        auto text = label_->text();

        if (counter == 4) {
            text = start_text;
            counter = 0;
        } else {
            text.push_back('.');
        }

        label_->setText(text);
        ++counter;

        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void LoadingScene::loadData() {
    std::ifstream ifs(getClientConfigPath().data());

    if (!ifs.is_open()) {
        throw std::runtime_error("can not open config");
    }

    auto value = boost::json::parse(ifs);

    ifs.close();

    std::uint64_t user_id = value.as_object()["userId"].as_int64();

    protocol::request::GetDataRequestFactory factory;
    auto request = factory.create(user_id);

    protocol::serialization::GetDataRequestSerialization serializer;
    auto serializer_request = serializer.serialize(request);

    protocol::serialization::utils::serialize_data_t data;

    while (true) {
        try {
            auto& network = Network::getInstance();
            network.send(serializer_request);
            data = network.wait();
            break;
        } catch (...) {}
    }

    emit loaded(user_id, data);
}

void LoadingScene::on_loaded(
    std::uint64_t user_id, const protocol::serialization::utils::serialize_data_t& data) {
    protocol::deserialization::GetDataResponseDeserialization deserializer;
    auto response = deserializer.deserialize(data);
    auto get_data_response =
        std::static_pointer_cast<protocol::response::GetDataResponse>(response);
    auto user_data_ids = get_data_response->getDataIds();
    auto user_data = get_data_response->getData();

    json::object obj {
        {  "userId",       user_id },
        { "dataIds", user_data_ids },
        {    "data",     user_data }
    };

    std::ofstream ofs(getClientConfigPath().data());

    ofs << json::serialize(obj);

    ofs.close();

    is_loaded_ = true;

    emit nextScene();
}

LoadingScene::LoadingScene(QWidget* parent) : Scene(SceneType::Loading, parent) {
    setFixedSize(parent->width(), parent->height());

    label_ = new QLabel(this);

    label_->setText("Please wait");
    label_->setGeometry(width() / 2 - LABEL_WIDTH_ / 2, height() / 2 - LABEL_HEIGHT_ / 2,
                        LABEL_WIDTH_, LABEL_HEIGHT_);

    QFont font;
    font.setWeight(QFont::Weight::Black);
    font.setPointSize(20);
    label_->setFont(font);

    connect(this, &LoadingScene::loaded, &LoadingScene::on_loaded);
}

void LoadingScene::start() {
    std::thread update_screen(&LoadingScene::updateScreen, this);
    update_screen.detach();

    std::thread load_data(&LoadingScene::loadData, this);
    load_data.detach();
}
