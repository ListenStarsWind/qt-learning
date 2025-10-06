#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::onPushButtonClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onPushButtonClicked()
{
    QString result = "你的假期安排是: ";

    if(ui->checkBoxStay->isChecked())
        result += ui->checkBoxStay->text();
    if(ui->checkBoxHome->isChecked())
        result += ui->checkBoxHome->text();
    if(ui->checkBoxDebug->isChecked())
        result += ui->checkBoxDebug->text();

    qDebug() << result;

    ui->label->setText(result);
}
