#include <iostream>
#include <thread>

void function_1()
{
    std::cout << "www.oxox.work" << std::endl;
}

int main()
{
    std::thread t1(function_1);

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
