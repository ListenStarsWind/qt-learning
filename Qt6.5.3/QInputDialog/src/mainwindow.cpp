#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto layout = new QGridLayout();
    this->centralWidget()->setLayout(layout);

    auto inputIntButton = new QPushButton("选择一个整数");
    inputIntButton->setMinimumSize(100, 30);  // 最小尺寸
    inputIntButton->setMaximumSize(200, 50);  // 最大尺寸
    layout->addWidget(inputIntButton, 0, 0);

    auto inputDoubleButton = new QPushButton("选择一个小数");
    inputDoubleButton->setMinimumSize(100, 30);  // 最小尺寸
    inputDoubleButton->setMaximumSize(200, 50);  // 最大尺寸
    layout->addWidget(inputDoubleButton, 0, 1);

    auto inputStringButton = new QPushButton("选择一个项");
    inputStringButton->setMinimumSize(100, 30);  // 最小尺寸
    inputStringButton->setMaximumSize(200, 50);  // 最大尺寸
    layout->addWidget(inputStringButton, 0, 2);

    connect(inputIntButton, &QPushButton::clicked, this, [this]() {
        auto result = QInputDialog::getInt(this, "标题", "正文");
        qDebug() << result;
    });

    connect(inputDoubleButton, &QPushButton::clicked, this, [this]() {
        auto result = QInputDialog::getDouble(this, "标题", "正文");
        qDebug() << result;
    });

    connect(inputStringButton, &QPushButton::clicked, this, [this]() {
        QStringList items = {"0001", "0002", "0003", "0004"};
        auto result = QInputDialog::getItem(this, "标题", "正文", items);
        qDebug() << result;
    });
}

MainWindow::~MainWindow() {
    delete ui;
}