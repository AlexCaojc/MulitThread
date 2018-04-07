
#include <iostream>
#include <thread>
#include <string>

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
    std::string msg = "i love www.oxox.work";
    std::thread t1((Factor()), std::ref(msg));///传递引用，但是会导致线程间分享内存，引起数据竞争
//    std::thread t1((Factor()), std::move(msg));///将msg从主线程移动到子线程,但是编译不过，暂时没有找到原因
//    std::thread t1((Factor()), msg);///将msg从主线程移动到子线程，但是编译不过，暂时没有找到原因

    t1.join();
    std::cout << "from main:" << msg << std::endl;
    return 0;
}
