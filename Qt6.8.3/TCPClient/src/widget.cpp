#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    this->setWindowTitle("客户端");
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::readyRead, this, [this]() {
        QString response = socket->readAll();
        ui->listWidget->addItem("服务端: " + response);
    });

    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::button_clicked);

    // 需要注意的是, 和原生的connect相比, 这个接口是异步连接的
    // 对于linux 的 connect 来说, 它是阻塞的, 如果返回, 可以确定连接有没有成功
    // 但这个 connectToHost, 它是非阻塞的, 返回我也不知道有没有三次握手成功
    socket->connectToHost("127.0.0.1", 8080);
    // 因此, 我们需要显式等待, 确认连接是否成功, 再往下走
    if (!socket->waitForConnected()) {
        QMessageBox::critical(this, "无法连接到服务端: ", socket->errorString());
    }
}

Widget::~Widget() {
    delete ui;
}

void Widget::button_clicked() {
    const auto& text = ui->lineEdit->text();
    socket->write(text.toUtf8());
    ui->listWidget->addItem("客户端: " + text);
    ui->lineEdit->clear();
}
