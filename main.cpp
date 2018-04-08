#include <iostream>
#include <thread>
#include <string>
#include <mutex>


std::mutex mu;

void shared_print(std::string msg, int id)
{
    ///使用互斥对象进行同步资源的访问解决资源竞争问题,一个线程占用资源是其他线程需要等待，
    /// 当前线程调用结束之后其他线程才可以调用
    /// 但是当程序抛出异常时可能会导致程序死锁
    mu.lock();
    std::cout << msg << id << std::endl;
    mu.unlock();
}

void function_1()
{
    for (int i = 0; i < 100; i++)
    {
        shared_print("from function_1: i = ", i);
    }
}

int main()
{
    std::thread t1(function_1);

    for (int i = 0; i < 100; i++)
    {
        shared_print("from main: i = ", i);
    }

    t1.join();
    return 0;
}
