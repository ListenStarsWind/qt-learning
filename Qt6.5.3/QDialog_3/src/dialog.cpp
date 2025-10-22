#include "dialog.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

Dialog::Dialog() {
    auto layout = new QVBoxLayout();
    this->setLayout(layout);
    
    auto label = new QLabel("φ(>ω<*) ");
    auto button = new QPushButton("关闭");
    
    layout->addWidget(label);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, [this](){
        this->close();
    });
}
