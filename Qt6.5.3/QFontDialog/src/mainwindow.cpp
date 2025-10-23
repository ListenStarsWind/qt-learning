#include "mainwindow.h"

#include <cstdio>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto layout = new QGridLayout();
    this->centralWidget()->setLayout(layout);

    auto button = new QPushButton("点击以选择字体");
    button->setMinimumSize(100, 30);  // 最小尺寸
    button->setMaximumSize(200, 50);  // 最大尺寸
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, [this]() {
        bool ok = false;
        auto font = QFontDialog::getFont(&ok, this);
        if (ok == true) {
            qDebug() << font;
            this->setFont(font);

            char buffer[256] = {0};
            snprintf(buffer, sizeof(buffer),
                     "font-family: \"%s\"; font-size: %dpx; font-style: %s; font-weight: %s;",
                     font.family().toUtf8().constData(), font.pointSize(),
                     font.italic() ? "italic" : "normal", font.bold() ? "bold" : "normal");

            qDebug() << buffer;
        }
    });
}

MainWindow::~MainWindow() {
    delete ui;
}