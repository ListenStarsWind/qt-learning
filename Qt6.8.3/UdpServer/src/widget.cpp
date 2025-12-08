#include "widget.h"

#include <QMessageBox>
#include <format>

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    // 设置窗口标题便于与客户端分辨
    this->setWindowTitle("服务端");

    // 创建出 UDP 套接字对象, 并挂载到对象树上
    socket = new QUdpSocket(this);

    // 连接信号槽
    connect(socket, &QUdpSocket::readyRead, this, &Widget::Request);

    // 绑定端口号, 做好提供服务的准备
    bool r = socket->bind(QHostAddress::AnyIPv4, 8080);
    if (r == false) {
        // 若是绑定失败, 那就弹对话框吧, errorString 就相当于读取错误码, 并转成对应字符串
        QMessageBox::critical(this, "服务器启动失败!", socket->errorString());
        return;
    }
}

Widget::~Widget() {
    delete ui;
}

void Widget::Request() {
    // 读取数据报
    const auto& datagram = socket->receiveDatagram();
    // 回调上层的报文处理函数
    QString request = datagram.data();
    const auto& response = on_message_call_bacl(request);
    // 再发回去
    QNetworkDatagram response_message(response.toUtf8(), datagram.senderAddress(),
                                      datagram.senderPort());
    socket->writeDatagram(response_message);
    // 回显一下请求
    QString log = QString::fromUtf8(std::format(
        "[{}:{}] req: {}, resp: {}", response_message.senderAddress().toString().toStdString(),
        response_message.senderPort(), request.toStdString(), response.toStdString()));
    ui->listWidget->addItem(log);
}

QString Widget::on_message_call_bacl(const QString& request) {
    // 如果要写应用层, 那工作量就有点大了, 而且这个应用层和 Qt 实际上没太大关系,
    // 所以我们这里就直接返回原文
    return request;
}
