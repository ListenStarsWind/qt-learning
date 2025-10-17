#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    auto button1 = new QPushButton("按钮1");
    auto button2 = new QPushButton("按钮2");
    auto layout = new QHBoxLayout();
    auto spacer = new QSpacerItem(200, 20);

    layout->addWidget(button1);
    layout->addSpacerItem(spacer);
    layout->addWidget(button2);

    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
