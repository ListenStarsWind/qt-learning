#pragma once

#include <QDebug>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>

class Thread : public QThread {
    Q_OBJECT
   public:
    Thread(int& tickets, QMutex& mutex);

    void run();

   private:
    int& _tickets;
    QMutex& _mutex;
};
