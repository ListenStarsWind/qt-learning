#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->myButton, &QPushButton::clicked, this, &Widget::onClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onClicked()
{
    if(ui->myButton->text() == QString("hello world"))
        ui->myButton->setText("hello qt");
    else
        ui->myButton->setText("hello world");
}
