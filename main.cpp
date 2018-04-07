
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

    std::thread t2 = std::move(t1);///线程对象只能被移动而不能被复制

    std::cout << "the main id = "<<std::this_thread::get_id() <<std::endl;
    std::cout << "the t2 id = " << t2.get_id() << std::endl;

    t2.join();
    std::cout << "the most cpu core num = " << std::thread::hardware_concurrency() << std::endl;
    return 0;
}
