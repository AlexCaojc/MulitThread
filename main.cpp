#include <iostream>
#include <thread>
#include <string>

void function_1()
{
    for (int i = 0; i < 100; i++)
    {
        std::cout << "from function_1: i = " << i << std::endl;
    }
}

int main()
{
    std::thread t1(function_1);

    for (int i = 0; i < 100; i++)
    {
        std::cout << "from main: i = " << i << std::endl;
    }

    ///此时t1和主线程同时竞争std::cout资源，导致数据输出时乱的

    t1.join();
    return 0;
}
