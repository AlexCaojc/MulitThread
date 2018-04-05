#include <iostream>
#include <thread>
#include <string>

void function_1()
{
    std::cout << "www.oxox.work" << std::endl;
}

class Factor
{
public:
    void operator() (std::string &msg)
    {
        std::cout << "from t1: " << msg << std::endl;
        msg = "i love XuHuanDaXue";
    }
};

int main()
{
    ///在不同线程中传递数据采用的是值传递，即使函数参数为引用形式
    std::string s = "i love www.oxox.work";
    std::thread t1((Factor()), s);

    t1.join();
    std::cout << "from main:" << s << std::endl;
    return 0;
}
