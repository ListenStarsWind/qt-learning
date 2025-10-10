#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("麦辣鸡腿堡");
    ui->comboBox->addItem("巨无霸");
    ui->comboBox->addItem("培根蔬萃双层牛堡");

    ui->comboBox_2->addItem("中薯条");
    ui->comboBox_2->addItem("麦乐鸡块");
    ui->comboBox_2->addItem("麦辣鸡翅");

    ui->comboBox_3->addItem("雪碧");
    ui->comboBox_3->addItem("可乐");

    ui->spinBox->setMinimum(1);
    ui->spinBox_2->setMinimum(1);
    ui->spinBox_3->setMinimum(1);

    ui->spinBox->setSuffix("份");
    ui->spinBox_2->setSuffix("份");
    ui->spinBox_3->setSuffix("杯");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    qDebug() << ui->comboBox->currentText() << ui->spinBox->text() << " "
             << ui->comboBox_2->currentText() << ui->spinBox_2->text() << " "
             << ui->comboBox_3->currentText() << ui->spinBox_3->text() << " ";
}

