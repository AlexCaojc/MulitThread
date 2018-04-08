#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

class LogFile
{
public:
    LogFile() {
        f.open("log.txt");
    }

    void share_print(std::string id, int value)
    {
        ///在一个类的函数内使用互斥构造lock_guard，同时维护资源，这样就不可能在类外对资源进行单独操作
        /// 保证资源不会造成竞争
        std::lock_guard<std::mutex> locker(m_mutex);
        f << "from" << id << ":" <<value << std::endl;
    }

    ///但你必须维护这个保护等级，不能返回资源的引用到类外，同时不能将资源作为函数的参数传递出去
#if 0
    std::ofstream &getOfstreanm() { return f; }
    void processf(void fun(ofstream&))
    {
        fun(f);
    }

#endif

private:
    std::mutex m_mutex;
    std::ofstream f;

};
void function_1(LogFile &log)
{
    for (int i = 0; i < 100; i++)
    {
        log.share_print("from function_1: i = ", i);
    }
}

int main()
{
    LogFile log;
    std::thread t1((function_1), std::ref(log));
    for (int i = 0; i < 100; i++)
    {
        log.share_print("from main: i = ", i);
    }

    t1.join();
    return 0;
}
