#include "widget.h"
#include "./ui_widget.h"

#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton(this);
    button->move(200, 200);

    connect(button, &QPushButton::clicked, this, [button](){
        qDebug() << "lambda";
        button->move(300, 300);
    });
}

Widget::~Widget()
{
    delete ui;
}
