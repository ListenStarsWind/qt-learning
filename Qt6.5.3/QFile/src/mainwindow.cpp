#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // 设置全局默认字体
    auto font = QFont("Microsoft YaHei", 10);
    qApp->setFont(font);

    auto menuBar = this->menuBar();
    this->setMenuBar(menuBar);

    auto statusBar = this->statusBar();
    this->setStatusBar(statusBar);

    this->setWindowTitle("编辑器");

    textEdit = new QTextEdit();
    this->setCentralWidget(textEdit);  // 将 center widget 替换成 textEdit

    auto menu = new QMenu("文件");
    this->menuBar()->addMenu(menu);

    auto openAction = new QAction("打开");
    auto saveAction = new QAction("保存");
    menu->addAction(openAction);
    menu->addAction(saveAction);

    connect(openAction, &QAction::triggered, this, &MainWindow::onOpenActionTriggered);
    connect(saveAction, &QAction::triggered, this, &MainWindow::onSaveActionTriggered);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onOpenActionTriggered() {
    auto path = QFileDialog::getOpenFileName();
    auto file = QScopedPointer<QFile>(new QFile(path, this));  // unique_ptr 托管生命周期

    // 只读方式打开, 并以文本而非二进制方式解析
    if (!file->open(QIODeviceBase::ReadOnly | QIODeviceBase::Text)) {
        // 以对话框形式反馈失败原因
        switch (file->error()) {
            case QFileDevice::PermissionsError:
                QMessageBox::critical(
                    this, "权限不足",
                    tr("无法打开文件:\n%1\n\n请检查权限或以管理员身份运行。").arg(path));
                break;
            default:
                QMessageBox::critical(this, "打开失败", file->errorString());
                break;
        }
        return;
    }

    QString text = file->readAll();  // QString 含有对 QByteArray operator= 重载
    textEdit->setText(text);
    textEdit->moveCursor(QTextCursor::MoveOperation::End);  // 光标移到末尾
    file->close();

    return;
}

void MainWindow::onSaveActionTriggered() {
    auto path = QFileDialog::getSaveFileName();
    auto file = QScopedPointer<QSaveFile>(new QSaveFile(path, this));  // unique_ptr 托管生命周期

    // 只写方式打开, 并以文本而非二进制方式保存
    if (!file->open(QIODeviceBase::WriteOnly | QIODeviceBase::Text)) {
        switch (file->error()) {
            case QFileDevice::PermissionsError:
                QMessageBox::critical(
                    this, "权限不足",
                    tr("无法保存文件到:\n%1\n\n请检查权限或以管理员身份运行。").arg(path));
                break;
            case QFileDevice::OpenError:
                QMessageBox::critical(this, "无法打开文件", file->errorString());
                break;
            default:
                QMessageBox::critical(this, "保存失败", file->errorString());
                break;
        }
        return;
    }

    auto byteArray = textEdit->toPlainText().toUtf8();
    file->write(byteArray);

    // QSaveFile 没有 close 成员, close 在语义上存在歧义: 分不清是替换并关闭还是直接关闭
    // 尝试原子性替换, 旧文件不存在, 直接保存
    if (!file->commit()) {
        QMessageBox::critical(this, "保存失败", file->errorString());
    } else {
        QString message("成功保存到" + path);
        this->statusBar()->showMessage(message, 3000);
    }

    return;
}