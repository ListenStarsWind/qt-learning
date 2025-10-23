#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto layout = new QGridLayout();
    this->centralWidget()->setLayout(layout);

    auto button = new QPushButton("点击以打开对话框");
    button->setMinimumSize(100, 30);  // 最小尺寸
    button->setMaximumSize(200, 50);  // 最大尺寸
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, [this]() {
        int result = QMessageBox::warning(
            this, "对话框", "是否保存修改",
            QMessageBox::Button::Save | QMessageBox::Button::Discard | QMessageBox::Button::Cancel);

        if (result == QMessageBox::Button::Save) {
            qDebug() << "save";
        } else if (result == QMessageBox::Button::Discard) {
            qDebug() << "discard";
        } else if (result == QMessageBox::Button::Cancel) {
            qDebug() << "cancel";
        }
    });
}

MainWindow::~MainWindow() {
    delete ui;
}