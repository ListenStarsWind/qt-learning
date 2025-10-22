#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->button, &QPushButton::clicked, this, [this](){
        auto dialog = new QDialog(this);
        dialog->setWindowTitle("对话框");                                // QDailog 也继承自 QWidget 
        dialog->resize(400, 300);               
        dialog->show();                                                 // 通过 show 方法显示对话框
        dialog->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
    });
}

MainWindow::~MainWindow() {
    delete ui;
}