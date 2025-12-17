#include <QPushButton>
#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    auto button = new QPushButton(this);
    button->setGeometry(0, 0, 100, 100);
    button->setStyleSheet("QPushButton { border: 5px solid red; margin: 20px; }");
    button->setText("按钮");
}

Widget::~Widget() {
    delete ui;
}
