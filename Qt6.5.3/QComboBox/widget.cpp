#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << QCoreApplication::applicationDirPath();

    std::ifstream file("config.txt");
    if(!file.is_open())
    {
        qDebug() << "文件打开失败";
        return ;
    }
    std::string line;
    while(std::getline(file, line))
    {
        // Qt接口用QString, 所以要转换
        ui->comboBox->addItem(QString::fromStdString(line));
        // QString -> std::string 使用成员函数toStdString();
    }
    file.close();
}

Widget::~Widget()
{
    delete ui;
}
