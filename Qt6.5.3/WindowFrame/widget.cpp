#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton("button", this);

    connect(button, &QPushButton::clicked, this, [this](){
        QRect rect1 = this->geometry();
        QRect rect2 = this->frameGeometry();
        qDebug() << rect1;
        qDebug() << rect2;
    });

    // QRect rect1 = this->geometry();
    // QRect rect2 = this->frameGeometry();

    // qDebug() << rect1;
    // qDebug() << rect2;
}

Widget::~Widget()
{
    delete ui;
}
