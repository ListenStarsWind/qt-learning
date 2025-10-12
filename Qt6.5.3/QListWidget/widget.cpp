#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // ui->listWidget->addItem("C++");
    // ui->listWidget->addItem("Java");
    // ui->listWidget->addItem("Python");

    ui->listWidget->addItem(new QListWidgetItem("C++"));
    ui->listWidget->addItem(new QListWidgetItem("Java"));
    ui->listWidget->addItem(new QListWidgetItem("Python"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    const QString text = ui->lineEdit->text();
    if(!text.isEmpty())
    {
        ui->listWidget->addItem(text);
        ui->lineEdit->clear();
    }
}


void Widget::on_pushButton_2_clicked()
{
    int row = ui->listWidget->currentRow();
    if(row >= 0)
    {
        ui->listWidget->takeItem(row);
    }
}


void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(current != nullptr)
    {
        qDebug() <<"当前选中的是: "<<current->text();
    }
    if(previous != nullptr)
    {
        qDebug() <<"上一个选中的是: "<<previous->text();
    }
}

