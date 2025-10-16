#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 按钮添加到布局管理器会自动挂载到对象树上
    auto pushButton1 = new QPushButton("按钮1");
    auto pushButton2 = new QPushButton("按钮2");
    auto pushButton3 = new QPushButton("按钮3");

    auto layout = new QVBoxLayout();
    layout->addWidget(pushButton1);
    layout->addWidget(pushButton2);
    layout->addWidget(pushButton3);

    // 最后把布局管理器挂载到this上
    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
