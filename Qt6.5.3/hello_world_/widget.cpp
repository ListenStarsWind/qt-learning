#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    button = new QPushButton(this);
    button->setText("hello world");

    connect(button, &QPushButton::clicked, this, &Widget::onClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onClicked()
{
    if(button->text() == QString("hello world"))
        button->setText("hello qt");
    else
        button->setText("hello world");
}
