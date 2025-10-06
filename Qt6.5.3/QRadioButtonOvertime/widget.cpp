#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->radioButtonYes->setChecked(true);
    ui->radioButtonYes->click();

    ui->radioButtonNo->setEnabled(false);
    // ui->radioButtonNo->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_radioButtonYes_clicked()
{
    ui->label->setText("感谢您的理解与支持");
}


void Widget::on_radioButtonNo_clicked()
{
    ui->label->setText("您的意见已记录");
}

