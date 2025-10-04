#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonAdd_clicked()
{
    float opacity = this->windowOpacity();
    qDebug() << opacity;
    opacity += 0.1;
    if(opacity > 1.0)
        return;


    this->setWindowOpacity(opacity);
}


void Widget::on_pushButtonSub_clicked()
{
    float opacity = this->windowOpacity();
    qDebug() << opacity;
    opacity -= 0.1;
    if(opacity < 0.0)
        return;

    this->setWindowOpacity(opacity);
}

