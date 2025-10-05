#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QIcon icon(":/image/doge.jpg");
    QIcon icon_up(":/image/up.png");
    QIcon icon_down(":/image/down.png");
    QIcon icon_left(":/image/left.png");
    QIcon icon_right(":/image/right.png");

    ui->pushButton->setIcon(icon);
    ui->pushButton->setIconSize(QSize(201, 121));

    ui->pushButtonUp->setIcon(icon_up);
    ui->pushButtonUp->setIconSize(QSize(30, 30));

    ui->pushButtonDown->setIcon(icon_down);
    ui->pushButtonDown->setIconSize(QSize(30, 30));

    ui->pushButtonLeft->setIcon(icon_left);
    ui->pushButtonLeft->setIconSize(QSize(30, 30));

    ui->pushButtonRight->setIcon(icon_right);
    ui->pushButtonRight->setIconSize(QSize(30, 30));

    ui->pushButtonUp->setShortcut(Qt::Key_K);
    ui->pushButtonDown->setShortcut(Qt::Key_J);
    ui->pushButtonLeft->setShortcut(Qt::Key_H);
    ui->pushButtonRight->setShortcut(Qt::Key_L);

    auto shortcutW = new QShortcut(Qt::Key_W, this);
    auto shortcutS = new QShortcut(Qt::Key_S, this);
    auto shortcutA = new QShortcut(Qt::Key_A, this);
    auto shortcutD = new QShortcut(Qt::Key_D, this);

    connect(shortcutW, &QShortcut::activated, ui->pushButtonUp, &QPushButton::click);
    connect(shortcutS, &QShortcut::activated, ui->pushButtonDown, &QPushButton::click);
    connect(shortcutA, &QShortcut::activated, ui->pushButtonLeft, &QPushButton::click);
    connect(shortcutD, &QShortcut::activated, ui->pushButtonRight, &QPushButton::click);

    ui->pushButtonUp->setAutoRepeat(true);
    ui->pushButtonDown->setAutoRepeat(true);
    ui->pushButtonLeft->setAutoRepeat(true);
    ui->pushButtonRight->setAutoRepeat(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonUp_clicked()
{
    QRect rect = ui->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x(), rect.y()-5, rect.width(), rect.height());
}

void Widget::on_pushButtonDown_clicked()
{
    QRect rect = ui->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x(), rect.y()+5, rect.width(), rect.height());
}

void Widget::on_pushButtonLeft_clicked()
{
    QRect rect = ui->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x()-5, rect.y(), rect.width(), rect.height());
}

void Widget::on_pushButtonRight_clicked()
{
    QRect rect = ui->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x()+5, rect.y(), rect.width(), rect.height());
}

