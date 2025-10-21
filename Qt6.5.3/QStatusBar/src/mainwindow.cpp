#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto statusBar = this->statusBar();
    this->setStatusBar(statusBar);

    auto label = new QLabel("标签");
    statusBar->addWidget(label);

    auto progressBar = new QProgressBar();
    progressBar->setValue(42);
    statusBar->addWidget(progressBar);
}

MainWindow::~MainWindow() {
    delete ui;
}