#include "login-scene.hpp"

#include <boost/json.hpp>
#include <fstream>
#include <filesystem>
#include <QMessageBox>

namespace json = boost::json;

void LoginScene::initLabel() {
    label_ = new QLabel(this);
    label_->setText("Enter your ID");
    label_->setGeometry(width() / 2 - WIDGETS_WIDTH_ / 2,
                        height() / 2 - WIDGETS_HEIGHT_ * 2 - WIDGETS_HEIGHT_STEP_,
                        WIDGETS_WIDTH_, WIDGETS_HEIGHT_);
    label_->setAlignment(Qt::AlignCenter);

    QFont font;
    font.setWeight(QFont::Weight::Black);
    font.setPointSize(20);
    label_->setFont(font);
}

void LoginScene::initLineEdit() {
    line_edit_ = new QLineEdit(this);
    line_edit_->setGeometry(width() / 2 - WIDGETS_WIDTH_ / 2,
                            height() / 2 - WIDGETS_HEIGHT_, WIDGETS_WIDTH_,
                            WIDGETS_HEIGHT_);

    QFont font;
    font.setWeight(QFont::Weight::Black);
    font.setPointSize(20);
    line_edit_->setFont(font);
}

void LoginScene::initPushButton() {
    push_button_ = new QPushButton(this);
    push_button_->setText("Login");
    push_button_->setGeometry(width() / 2 - WIDGETS_WIDTH_ / 2,
                              height() / 2 + WIDGETS_HEIGHT_STEP_, WIDGETS_WIDTH_,
                              WIDGETS_HEIGHT_);

    QFont font;
    font.setWeight(QFont::Weight::Black);
    font.setPointSize(20);
    push_button_->setFont(font);
}

void LoginScene::initView() {
    initLabel();
    initLineEdit();
    initPushButton();
}

void LoginScene::initConnect() {
    connect(push_button_, &QPushButton::clicked, this, &LoginScene::on_login);
}

void LoginScene::checkLogin() {
    if (!std::filesystem::exists(getClientConfigPath())) {
        return;
    }

    emit nextScene();
}

void LoginScene::on_login() {
    if (line_edit_->text().isEmpty()) {
        QMessageBox::warning(this, "Empty edit line!", "Enter your ID, please!");
        return;
    }

    std::ofstream ofs(getClientConfigPath().data());

    ofs << json::serialize(json::object {
        { "userId", line_edit_->text().toULongLong() }
    });

    ofs.close();

    emit nextScene();
}

LoginScene::LoginScene(QWidget* parent) : Scene(SceneType::Login, parent) {
    setFixedSize(parent->width(), parent->height());

    initView();
    initConnect();
}

void LoginScene::start() {
    checkLogin();
}
