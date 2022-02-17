#include <iostream>
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

static std::string st2{"world"};
int main() {

    std::cout << classA::m_intData << std::endl;
    return 0;
}
