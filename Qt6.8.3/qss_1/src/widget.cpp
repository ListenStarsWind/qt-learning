#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setStyleSheet("* { color: #00E5EE; }");
}

Widget::~Widget() {
    delete ui;
}
