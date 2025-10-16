#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建两个按钮, 将其交给vLayout
    auto button1 = new QPushButton("按钮1");
    auto button2 = new QPushButton("按钮2");
    auto vLayout = new QVBoxLayout();
    vLayout->addWidget(button1);
    vLayout->addWidget(button2);

    // 创建一个水平布局

    // 创建两个按钮, 将其交给hLayout
    auto button3 = new QPushButton("按钮3");
    auto button4 = new QPushButton("按钮4");
    auto hLayout = new QHBoxLayout();
    hLayout->addWidget(button3);
    hLayout->addWidget(button4);

    // 将hLayout挂载到父对象
    vLayout->addLayout(hLayout);

    // 将垂直布局挂载带父对象
    this->setLayout(vLayout);
}

Widget::~Widget()
{
    delete ui;
}
