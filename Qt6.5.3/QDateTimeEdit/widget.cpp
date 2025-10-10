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

void Widget::on_pushButton_clicked()
{
    QDateTime initDateTime = ui->dateTimeEdit->dateTime();
    QDateTime termDateTime = ui->dateTimeEdit_2->dateTime();

    qDebug() << "开始时间: "<<initDateTime
             << "终止时间: "<<termDateTime;

    int seconds = initDateTime.secsTo(termDateTime);
    int days = seconds / 3600 / 24;
    int hours = (seconds / 3600) % 24;


    ui->label->setText(QString("已经过去了") + QString::number(days) + QString("天零") + QString::number(hours) + QString("小时"));
}

