#include <iostream>
#include <thread>

void function_1()
{
    std::cout << "www.oxox.work" << std::endl;
}

class Factor
{
public:
    void operator() ()
    {
        for (int i = 0; i > -100; i--)
            std::cout << "from t1: " << i << std::endl;
    }
};

int main()
{
//    Factor fct;
//    std::thread t1(fct);///使用对象创建线程,t1和主线程交互运行
    std::thread t1((Factor()));
    try
    {
        for (int i = 0; i <100; i++)
        {
            std::cout << "from main:" << i << std::endl;
        }
    }
    catch (...)
    {
        t1.join();
        throw;
    }
    t1.join();
    return 0;
}
