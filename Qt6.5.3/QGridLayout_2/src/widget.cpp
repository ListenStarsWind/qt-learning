#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    auto layout = new QGridLayout();

    // 创建按钮并交给layout
    for(int col = 0; col < 2; col++)
    {
        for(int row = 0; row < 3; row++)
        {
            auto pushButton = new QPushButton(QString("按钮") + QString::number(col * 3 + row + 1));
            pushButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            layout->addWidget(pushButton, row, col);
        }
    }

    // 行尺寸比例为  1 : 1 : 2
    layout->setRowStretch(0, 1);
    layout->setRowStretch(1, 1);
    layout->setRowStretch(2, 2);

    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
