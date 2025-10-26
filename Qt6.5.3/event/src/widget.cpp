#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
}

Widget::~Widget() {
    delete ui;
}

bool Widget::event(QEvent* event) {
    if (event->type() == QEvent::Type::MouseButtonPress) {
        qDebug() << "我们在event这里将事件进行了处理";
        // return true;  // 返回true 表示处理完毕
    }

    // 其它情况, 使用 基类原有的分支
    return QWidget::event(event);
}

void Widget::mousePressEvent(QMouseEvent* event) {
    qDebug() << "我们在mousePressEvent这里对事件进行了处理";
}
