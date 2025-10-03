#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("这是窗口标题");

    auto button = new QPushButton("按钮", this);
    button->setWindowTitle("这是按钮");
}

Widget::~Widget()
{
    delete ui;
}
