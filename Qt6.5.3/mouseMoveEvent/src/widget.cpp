#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setMouseTracking(true);
}

Widget::~Widget() {
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent* event) {
    qDebug() << event->position().x() << "," << event->position().y();
}
