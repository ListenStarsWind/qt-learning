#include "mainwindow.h"
#include "dialog.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
        auto dialog = new Dialog();
        dialog->resize(400, 300);
        dialog->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
        dialog->show();
    });
}

MainWindow::~MainWindow() {
    delete ui;
}