#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::onPushButtonClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Widget::onPushButton_2Clicked1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onPushButtonClicked()
{
    this->setWindowTitle("window");
}

void Widget::onPushButton_2Clicked1()
{
    disconnect(ui->pushButton, &QPushButton::clicked, this, &Widget::onPushButtonClicked);
    disconnect(ui->pushButton_2, &QPushButton::clicked, this, &Widget::onPushButton_2Clicked1);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Widget::onPushButton_2Clicked2);
}

void Widget::onPushButton_2Clicked2()
{
    this->setWindowTitle("title");
}
