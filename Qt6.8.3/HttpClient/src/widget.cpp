#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setWindowTitle("客户端");
    manger = new QNetworkAccessManager(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::onPushButtonClicked);
}

Widget::~Widget() {
    delete ui;
}

void Widget::onPushButtonClicked() {
    // 构造一个请求头
    QUrl url(ui->lineEdit->text());
    ui->lineEdit->clear();
    QNetworkRequest request(url);

    // 发起 get 请求
    auto reply = manger->get(request);

    // 将接收完成的信号与对应的槽函数进行链接
    connect(reply, &QNetworkReply::finished, this, [reply, this]() {
        auto status = reply->error();
        if (status == QNetworkReply::NoError) {
            QString html = reply->readAll();
            ui->plainTextEdit->setPlainText(html);
        } else {
            ui->plainTextEdit->setPlainText(reply->errorString());
        }

        reply->deleteLater();
    });
}
