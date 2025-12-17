#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    QString style = "QPushButton { color: red; }";
    style += "QPushButton:hover { color: green; }";
    style += "QPushButton:pressed { color: blue; }";
    this->setStyleSheet(style);
}

Widget::~Widget() {
    delete ui;
}
