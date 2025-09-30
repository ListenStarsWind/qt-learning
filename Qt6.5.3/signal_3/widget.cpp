#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(this, &Widget::Submitted, this, &Widget::onWidgetSubmitted);
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::onPushButtonClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Widget::onPushButton_2Clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onWidgetSubmitted(const QString & text)
{
    this->setWindowTitle(text);
}

void Widget::onPushButtonClicked()
{
    emit Submitted("one", "");
}

void Widget::onPushButton_2Clicked()
{
    emit Submitted("two", "");
}
