#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    this->setWindowTitle("客户端");

    socket = new QUdpSocket(this);

    connect(socket, &QUdpSocket::readyRead, this, &Widget::Response);
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::on_button_clicked);
}

Widget::~Widget() {
    delete ui;
}

void Widget::on_button_clicked() {
    // 获取输入框中的内容
    const auto& text = ui->lineEdit->text();
    // 拼出一份请求数据包
    QNetworkDatagram request_message(text.toUtf8(), QHostAddress(server_ip), server_port);
    // 发出去
    socket->writeDatagram(request_message);
    // 清理输入框
    ui->lineEdit->clear();
    // 把发送请求添加到列表框中
    ui->listWidget->addItem("客户端说: " + text);
}

void Widget::Response() {
    const auto& response_message = socket->receiveDatagram();
    QString response = response_message.data();
    ui->listWidget->addItem("服务端说: " + response);
}
