#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::onPushButtonClicked);
    connect(ui->pushButtonEnable, &QPushButton::clicked, this, &Widget::onPushButtonEnableClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onPushButtonClicked()
{
    qDebug() << "(*^▽^*)";
}

void Widget::onPushButtonEnableClicked()
{
    bool loop = ui->pushButton->isEnabled();
    ui->pushButton->setEnabled(!loop);
}
