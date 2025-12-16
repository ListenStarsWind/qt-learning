#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    QString style = "#pushButton_2, QLineEdit, QLabel { color: red; }";
    this->setStyleSheet(style);
}

Widget::~Widget() {
    delete ui;
}
