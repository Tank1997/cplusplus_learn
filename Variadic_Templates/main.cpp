#include <iostream>
#include <thread>
#include "classA.h"

void print()
{
    static std::string  st1 {"hello"};
    std::cout << st1 << std::endl;
}

template <typename T,typename... Types>
void print(const T& firstArg,const Types&... args)
{
    std::cout<< firstArg << std::endl;
    print(args...);
}


void run()
{
    std::cout << "world" << std::endl;
}

void foo()
{
    std::cout << "hello" << std::endl;
}

int main() {
    std::thread thread1(run);
    std::thread thread2(foo);
    thread1.join();
    thread2.join();

    std::cout << "finished" << std::endl;
    return 0;
}
