#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::onPushButton);
    connect(this, &Widget::confirmedSubmit, this, &Widget::onSubmitted);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onPushButton()
{
    if(ui->checkBox->isChecked())
        emit confirmedSubmit();
    else
        this->setWindowTitle("nothing");
}

void Widget::onSubmitted()
{
    this->setWindowTitle("title");
}
