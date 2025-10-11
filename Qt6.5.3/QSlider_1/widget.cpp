#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QRect rect = this->geometry();
    qDebug() << rect;

    ui->horizontalSlider->setMinimum(rect.width()/2);
    ui->horizontalSlider->setMaximum(1920);
    ui->horizontalSlider->setValue(rect.width());

    ui->verticalSlider->setMinimum(rect.height()/2);
    ui->verticalSlider->setMaximum(1080);
    ui->verticalSlider->setValue(rect.height());

    ui->horizontalSlider->setSingleStep(50);
    ui->verticalSlider->setSingleStep(50);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_verticalSlider_valueChanged(int value)
{
    QRect rect = this->geometry();
    this->setGeometry(rect.x(), rect.y(), rect.width(), value);
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    QRect rect = this->geometry();
    this->setGeometry(rect.x(), rect.y(), value, rect.height());
}

