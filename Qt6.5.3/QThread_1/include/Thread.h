#pragma once

#include <QThread>

class Thread : public QThread{
    Q_OBJECT
    public:
    void run() override;

    signals:
    void notify();
};