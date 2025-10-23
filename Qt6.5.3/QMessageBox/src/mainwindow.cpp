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
        auto messageBox = new QMessageBox(this);

        messageBox->setWindowTitle("对话框");             // 标题
        messageBox->setText("是否保存更改");              // 文本
        messageBox->setIcon(QMessageBox::Icon::Warning);  // 图标

        messageBox->setStandardButtons(
            QMessageBox::Button::Save | QMessageBox::Button::Discard |
            QMessageBox::Button::Cancel);  // 添加 保存 丢弃(更改) 取消 三个按钮

        // auto button = new QPushButton("保存");
        // messageBox->addButton(button, QMessageBox::ButtonRole::AcceptRole);

        // 以阻塞的非模态运行
        int result = messageBox->exec();

        if (result == QMessageBox::Button::Save) {
            qDebug() << "save";
        } else if (result == QMessageBox::Button::Discard) {
            qDebug() << "discard";
        } else if (result == QMessageBox::Button::Cancel) {
            qDebug() << "cancel";
        }

        delete messageBox;
    });
}

MainWindow::~MainWindow() {
    delete ui;
}