#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton(this);
    button->setText("button");
    button->move(200, 200);
    connect(button, &QPushButton::clicked, this, &Widget::onClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onClicked()
{
    // 按下按钮, 变化窗口标题

    this->setWindowTitle("The window title was changed.");
}
