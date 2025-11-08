#include "thread.h"

Thread::Thread(int& tickets, QMutex& mutex)
    : _tickets(tickets), _mutex(mutex) {}

void Thread::run() {
    while (true) {
        // RAII 管理释放时机
        QMutexLocker lock(&_mutex);
        if (_tickets > 0) {
            // 进行一些"耗时操作", 制造窗口期, 让错误更加明显
            char buffer[64] = {0};
            snprintf(buffer, sizeof(buffer), "[%llu]通知: %s, %s:%d",
                     reinterpret_cast<quintptr>(QThread::currentThreadId()), "购得一张票",
                     "剩余票数", _tickets);
            qDebug() << buffer;

            --_tickets;
        } else {
            return;
        }
    }
}
