#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    auto layout = new QFormLayout();

    QVector<QString> v = {"姓名", "年龄", "电话"};    
    for(int i = 0; i < 3; ++i)
    {
        auto label = new QLabel(v[i]);
        auto edit = new QLineEdit();
        layout->addRow(label, edit);
    }

    auto button = new QPushButton("提交");
    layout->addRow(nullptr, button);

    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
