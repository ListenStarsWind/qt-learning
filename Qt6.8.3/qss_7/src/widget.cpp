#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    QString style = "QLabel { border: 5px dashed red; padding-left: 5px; }";
    this->setStyleSheet(style);
}

Widget::~Widget() {
    delete ui;
}
