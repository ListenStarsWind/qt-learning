#include "widget.h"

#include "ui_widget.h"


Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget), tickets(1000) {
    ui->setupUi(this);

    // 配置线程基本属性
    thread1 = std::make_unique<Thread>(tickets, mutex);
    thread2 = std::make_unique<Thread>(tickets, mutex);

    // 启动线程
    thread1->start();
    thread2->start();

    // 等待线程运行结束
    thread1->wait();
    thread2->wait();

    char buffer[64] = {0};
    snprintf(buffer, sizeof(buffer), "[主线程]通知: 最终剩余票数: %d", tickets);
    qDebug() << buffer;
}

Widget::~Widget() {
    delete ui;
}
