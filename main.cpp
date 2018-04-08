#include <iostream>
#include <thread>
#include <string>
#include <mutex>


std::mutex mu;

void shared_print(std::string msg, int id)
{
    ///类 lock_guard 是互斥封装器，为在作用域块期间占有互斥提供便利 RAII 风格机制。
    ///创建 lock_guard 对象时，它试图接收给定互斥的所有权。控制离开创建 lock_guard 对象的作用域时，销毁 lock_guard 并释放互斥。
    ///lock_guard 类不可复制。
    ///当guard对象析构时，不管程序有没有异常，mu都会被解锁
    /// Resource Acquisition Is Initialization
    /// 在资源获取的时候将其封装在某类的object中，
    /// 利用"栈资源会在相应object的生命周期结束时自动销毁"来自动释放资源，
    /// 即将资源释放写在析构函数中。所以这个RAII其实就是和智能指针的实现是类似的
    std::lock_guard<std::mutex> guard(mu);
    std::cout << msg << id << std::endl;
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
