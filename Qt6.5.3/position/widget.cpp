#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton(this);
    button->setText("hello world");
    button->move(200, 300);

    this->move(100, 0);
}

Widget::~Widget()
{
    delete ui;
}
