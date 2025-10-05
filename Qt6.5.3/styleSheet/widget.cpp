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

void Widget::on_pushButtonLight_clicked()
{
    this->setStyleSheet("background-color: #F0F0F0;");                                // 窗口背景 #F0F0F0 == rgb(240, 240, 240)[十进制表示]
    ui->plainTextEdit->setStyleSheet("background-color: #F0F0F0; color: black;");     // 输入框背景和字体
    ui->pushButtonLight->setStyleSheet("color: black;");                            // 按钮字体
    ui->pushButtonDark->setStyleSheet("color: black;");
}


void Widget::on_pushButtonDark_clicked()
{
    this->setStyleSheet("background-color: black;");
    ui->plainTextEdit->setStyleSheet("background-color: black; color: white;");
    ui->pushButtonLight->setStyleSheet("color: white;");
    ui->pushButtonDark->setStyleSheet("color: white;");
}

