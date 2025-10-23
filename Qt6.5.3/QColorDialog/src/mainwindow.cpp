#include "mainwindow.h"

#include "./ui_mainwindow.h"

#include <cstdio>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto layout = new QGridLayout();
    this->centralWidget()->setLayout(layout);

    auto button = new QPushButton("点击以打开对话框");
    button->setMinimumSize(100, 30);  // 最小尺寸
    button->setMaximumSize(200, 50);  // 最大尺寸
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, [this](){
        auto color = QColorDialog::getColor(QColor(22, 63, 107), this, "调色盘");
        
        // 拼接为 QSS 格式备用
        char style[1024] = {0};
        snprintf(style, sizeof(style), "background-color: rgb(%d, %d, %d)", color.red(), color.green(), color.blue());

        qDebug() << style;
        qDebug() << color;

        this->setStyleSheet(style);
    });
}

MainWindow::~MainWindow() {
    delete ui;
}