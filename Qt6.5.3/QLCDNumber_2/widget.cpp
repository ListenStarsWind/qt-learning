#include "widget.h"
#include "./ui_widget.h"
#include <thread>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // int val = ui->lcdNumber->intValue();
    // while(val--)
    // {
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    //     ui->lcdNumber->display(val);
    // }

    std::thread t([this](){
        int val = ui->lcdNumber->intValue();
        while(val--)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            ui->lcdNumber->display(val);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
