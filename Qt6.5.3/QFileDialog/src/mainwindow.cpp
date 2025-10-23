#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto layout = new QGridLayout();
    this->centralWidget()->setLayout(layout);

    auto openFileButton = new QPushButton("点击以打开文件");
    openFileButton->setMinimumSize(100, 30);  // 最小尺寸
    openFileButton->setMaximumSize(200, 50);  // 最大尺寸
    layout->addWidget(openFileButton, 0, 0);

    auto saveFileButton = new QPushButton("点击以保存文件");
    saveFileButton->setMinimumSize(100, 30);  // 最小尺寸
    saveFileButton->setMaximumSize(200, 50);  // 最大尺寸
    layout->addWidget(saveFileButton, 0, 1);

    connect(openFileButton, &QPushButton::clicked, this, [this](){
        auto path = QFileDialog::getOpenFileName(this);
        qDebug() << path;
    }); 

    connect(saveFileButton, &QPushButton::clicked, this, [this](){
        auto path = QFileDialog::getSaveFileName(this);
        qDebug() << path;
    });    
}

MainWindow::~MainWindow() {
    delete ui;
}