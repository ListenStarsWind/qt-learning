#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    auto button1 = new QPushButton("按钮1");
    auto button2 = new QPushButton("按钮2");
    auto button3 = new QPushButton("按钮3");
    auto button4 = new QPushButton("按钮4");

    auto layout = new QGridLayout();
    
    // 以 2 行 2 列 的形式排列按钮
    // layout->addWidget(button1, 0, 0);
    // layout->addWidget(button2, 0, 1);
    // layout->addWidget(button3, 1, 0);
    // layout->addWidget(button4, 1, 1);

    // 以单行方式排列
    // layout->addWidget(button1, 0, 1);
    // layout->addWidget(button2, 0, 2);
    // layout->addWidget(button3, 0, 3);
    // layout->addWidget(button4, 0, 4);
    
    // 以单列方式排列
    // layout->addWidget(button1, 0, 0);
    // layout->addWidget(button2, 1, 0);
    // layout->addWidget(button3, 2, 0);
    // layout->addWidget(button4, 3, 0);
    
    // 每个按钮单独一列一行
    layout->addWidget(button1, 0, 0);
    layout->addWidget(button2, 1, 1);
    layout->addWidget(button3, 2, 2);
    layout->addWidget(button4, 100, 100);

    // 将layout 挂载到 widget上
    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
