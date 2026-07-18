#include "desktop-scene.hpp"

#include "network.hpp"

#include <QMessageBox>
#include <boost/json.hpp>
#include <fstream>
#include <filesystem>

namespace json = boost::json;

void DesktopScene::addData(std::uint64_t id, const std::string_view& data) {
    auto new_data_line =
        new QListWidgetItem(std::format("{:5} | {}", id, data).c_str(), data_list_);

    data_list_->addItem(new_data_line);
}

void DesktopScene::on_send() {
    if (line_edit_->text().isEmpty()) {
        QMessageBox::warning(this, "Empty line edit!", "A enter field can't be empty!");
        return;
    }

    protocol::request::NewDataRequestFactory factory;
    auto request = factory.create(user_id_, line_edit_->text().toStdString());

    protocol::serialization::NewDataRequestSerialization serializer;
    auto serialized_request = serializer.serialize(request);

    auto& network = Network::getInstance();
    network.send(serialized_request);

    auto serialized_response = network.wait();

    protocol::deserialization::NewDataResponseDeserialization deserializer;
    auto response = std::static_pointer_cast<protocol::response::NewDataResponse>(
        deserializer.deserialize(serialized_response));

    addData(response->getDataId(), line_edit_->text().toStdString());
}

void DesktopScene::on_leave() {
    std::filesystem::remove(getClientConfigPath());
    data_list_->clear();
    emit nextScene();
}

DesktopScene::DesktopScene(QWidget* parent) : Scene(SceneType::Desktop, parent) {
    setFixedSize(parent->width(), parent->height());

    data_list_ = new QListWidget(this);
    data_list_->setGeometry(width() / 2 - WIDGET_WIDTH_ / 2, WIDGET_STEP_, WIDGET_WIDTH_,
                            height() - WIDGET_STEP_ * 3 - WIDGET_HEIGHT_);
    QFont font_data_list;
    font_data_list.setWeight(QFont::Weight::Black);
    font_data_list.setPointSize(20);
    data_list_->setFont(font_data_list);

    leave_button_ = new QPushButton(this);
    leave_button_->setGeometry(width() / 2 - WIDGET_WIDTH_ / 2,
                               height() - WIDGET_STEP_ - WIDGET_HEIGHT_,
                               PUSH_BUTTON_WIDTH_, WIDGET_HEIGHT_);
    leave_button_->setText("LEAVE");
    QFont font_leave_button;
    font_leave_button.setWeight(QFont::Weight::Black);
    font_leave_button.setPointSize(20);
    leave_button_->setFont(font_leave_button);

    line_edit_ = new QLineEdit(this);
    line_edit_->setGeometry(leave_button_->x() + leave_button_->width() + WIDGET_STEP_,
                            height() - WIDGET_STEP_ - WIDGET_HEIGHT_,
                            WIDGET_WIDTH_ - PUSH_BUTTON_WIDTH_ * 2 - WIDGET_STEP_,
                            WIDGET_HEIGHT_);
    QFont font_line_edit;
    font_line_edit.setWeight(QFont::Weight::Black);
    font_line_edit.setPointSize(20);
    line_edit_->setFont(font_line_edit);

    push_button_ = new QPushButton(this);
    push_button_->setGeometry(line_edit_->x() + line_edit_->width() + WIDGET_STEP_,
                              height() - WIDGET_STEP_ - WIDGET_HEIGHT_,
                              PUSH_BUTTON_WIDTH_, WIDGET_HEIGHT_);
    push_button_->setText("SEND");
    QFont font_push_button;
    font_push_button.setWeight(QFont::Weight::Black);
    font_push_button.setPointSize(20);
    push_button_->setFont(font_push_button);

    connect(push_button_, &QPushButton::clicked, this, &DesktopScene::on_send);
    connect(leave_button_, &QPushButton::clicked, this, &DesktopScene::on_leave);
}

void DesktopScene::start() {
    std::ifstream ifs(getClientConfigPath().data());

    if (!ifs.is_open()) {
        throw std::runtime_error("can not open config");
    }

    auto value = json::parse(ifs);

    ifs.close();

    auto& obj = value.as_object();

    user_id_ = obj["userId"].as_int64();

    auto& data_ids = obj["dataIds"].as_array();
    auto& data = obj["data"].as_array();

    for (std::size_t i = 0, max_i = data_ids.size(); i < max_i; ++i) {
        addData(data_ids[i].as_int64(), data[i].as_string());
    }
}
