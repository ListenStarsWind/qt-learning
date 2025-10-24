#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
}

Widget::~Widget() {
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent* event) {
    if (event->modifiers() == Qt::Modifier::CTRL && event->key() == Qt::Key::Key_A) {
        qDebug() << "按下了组合键 ctrl + a";
    }
}
