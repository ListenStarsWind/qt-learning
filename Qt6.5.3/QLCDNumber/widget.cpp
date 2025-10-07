#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lcdNumber->display(10);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::onTimerTimeout);

    timer->start(1000);         //  启动定时器, 每1000毫秒触发信号
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onTimerTimeout()
{
    int val = ui->lcdNumber->value();
    if(val <= 0)
    {
        timer->stop();          // 停止定时
        disconnect(timer, &QTimer::timeout, this, &Widget::onTimerTimeout);
        return ;
    }

    val -= 1;
    ui->lcdNumber->display(val);
}
