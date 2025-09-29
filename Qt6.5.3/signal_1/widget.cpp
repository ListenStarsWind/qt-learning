#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton(this);
    button->setText("close");
    button->move(200, 200);

    connect(button, &QPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{
    delete ui;
}
