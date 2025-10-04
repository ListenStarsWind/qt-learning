#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButtonYes->setToolTip("这是yes");
    ui->pushButtonYes->setToolTipDuration(3000);

    ui->pushButtonNo->setToolTip("那是no");
    ui->pushButtonNo->setToolTipDuration(4000);
}

Widget::~Widget()
{
    delete ui;
}
