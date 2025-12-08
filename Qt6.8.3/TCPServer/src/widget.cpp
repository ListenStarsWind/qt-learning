#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    // 修改标题
    this->setWindowTitle("服务端");

    // 实例化监听套接字
    server = new QTcpServer(this);

    // 用 epoll 的话来说, 是注册监听套接字的读回调方法, Qt 的说法是, 让新连接信号有对应的槽函数
    connect(server, &QTcpServer::newConnection, this, &Widget::accept_connection);

    // 绑定并设置监听状态
    if (!server->listen(QHostAddress::AnyIPv4, 8080)) {
        QMessageBox::critical(this, "服务端初始化存在致命性问题", server->errorString());
        return;
    }
}

Widget::~Widget() {
    delete ui;
}

void Widget::accept_connection() {
    auto socket = server->nextPendingConnection();
    const auto& client_address = socket->peerAddress().toString();
    const auto& client_port = QString::number(socket->peerPort());
    QString src = "[" + client_address + ":" + client_port + "]";
    ui->listWidget->addItem("新增连接: " + src);
    connect(socket, &QTcpSocket::readyRead, this, [socket, this, src]() {
        QString request = socket->readAll();
        const auto& response = on_message_call_back(request);
        socket->write(response.toUtf8());
        auto log = QString("%1 requ: %2, resp: %3").arg(src).arg(request).arg(response);
        ui->listWidget->addItem(log);
    });
    connect(socket, &QTcpSocket::disconnected, this, [socket, this, src](){
        ui->listWidget->addItem("连接断开: " + src);
        socket->deleteLater();
    });
}

QString Widget::on_message_call_back(QString& request) {
    return request;
}
