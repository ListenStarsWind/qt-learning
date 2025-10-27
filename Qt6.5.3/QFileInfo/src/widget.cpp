#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    // 对象树 RAII-LINK, QPointer处理悬空(自动置空)
    auto layout = QPointer<QGridLayout>(new QGridLayout());
    this->setLayout(layout);

    auto button = QPointer<QPushButton>(new QPushButton("点击选择文件"));
    button->setMinimumSize(100, 30);  // 最小大小
    button->setMaximumSize(300, 60);  // 最大大小
    button->resize(150, 40);          // 默认初始大小

    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, []() {
        auto path = QFileDialog::getOpenFileName();
        auto fileInfo = QFileInfo(path);
        qDebug() << "文件名:" << fileInfo.fileName();
        qDebug() << "后缀名:" << fileInfo.suffix();
        qDebug() << "所在路径:" << fileInfo.path();
        qDebug() << "文件大小:" << fileInfo.size() / 1024.0 << "KB";
        qDebug() << "是否为文件:" << fileInfo.isFile();
        qDebug() << "是否为目录:" << fileInfo.isDir();
    });
}

Widget::~Widget() {
    delete ui;
}
