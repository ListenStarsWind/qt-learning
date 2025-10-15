#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 为现在的两个标签页增加label子控件
    // 注意这两个label的父对象是自己的标签页
    auto label1 = new QLabel(ui->tab);
    label1->setText("第一个标签页");
    label1->resize(100, 50);

    auto label2 = new QLabel(ui->tab_2);
    label2->setText("第二个标签页");
    label2->resize(200, 50);

    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::onPushButtonClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Widget::onPushButton_2Clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onPushButtonClicked()
{
    // 创建新的标签页(尾插)
    // 首先我们先new QWidget, 然后再加进去
    auto widget = new QWidget(); // 添加进去时会自动加入对象树, 此处不必添加
    int count = ui->tabWidget->count();     // 获取当前标签页的个数, 作为新标签页文本内容的依据
    ui->tabWidget->addTab(widget, QString("Tab ") + QString::number(count + 1));

    // 再加一个label添点文本
    auto label = new QLabel(widget);
    label->setText(QString("标签页 ") + QString::number(count + 1));
    label->resize(100, 50);

    // 跳转到新创建的标签页
    ui->tabWidget->setCurrentWidget(widget);
}

void Widget::onPushButton_2Clicked()
{
    auto index = ui->tabWidget->currentIndex();
    if(index >= 0)
    {
        ui->tabWidget->removeTab(index);
    }
}
