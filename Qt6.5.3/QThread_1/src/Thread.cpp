#include "Thread.h"

void Thread::run()
{
    // 十次循环, 每轮循环休眠一秒, 以达到计时的效果
    for(int i = 10; i > 0; --i)
    {
        this->sleep(1);
        // 发送信号, 让主线程修改控件状态
        emit notify();
    }    
}
