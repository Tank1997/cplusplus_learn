#include <iostream>
#include <boost/thread.hpp>

void th1()
{
    std::cout << "I'm thread one" << std::endl;
}

void th2()
{
    std::cout << "I'm thread two" << std::endl;
}

int main(int argc, char *argv[])
{
    boost::thread t1(th1);
    boost::thread t2(th2);
    t1.join();
    t2.join();
    return 0;
}