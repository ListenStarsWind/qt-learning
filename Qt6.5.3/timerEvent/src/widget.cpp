#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    // 开启定时器事件, 间隔1000毫秒
    timerID = this->startTimer(1000);
}

Widget::~Widget() {
    delete ui;
}

void Widget::timerEvent(QTimerEvent* event) {
    // 防御性编程: 不同的timer做不同的事, 便于之后扩展
    if (event->timerId() == this->timerID) {
        int val = ui->lcdNumber->intValue();
        if (val <= 0) {
            this->killTimer(timerID);
        } else {
            ui->lcdNumber->display(val - 1);
        }
    }
}
