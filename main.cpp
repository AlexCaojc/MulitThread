#include <iostream>
#include <thread>

void function_1()
{
    std::cout << "www.oxox.work" << std::endl;
}

int main()
{
    std::thread t1(function_1);

//    t1.join();///主线程会等待这里的t1线程结束后再运行，t1和主线程是两个完全互不影响的线程

//    t1.detach();///一个线程一旦detach，就不能join了
    if (t1.joinable())
    {
        t1.join();
    }
    return 0;
}
