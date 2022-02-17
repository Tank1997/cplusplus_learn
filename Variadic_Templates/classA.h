//
// Created by 17783 on 2022/2/16.
//

#ifndef VARIADIC_TEMPLATES_CLASSA_H
#define VARIADIC_TEMPLATES_CLASSA_H


#include <string>

class classA {
public:
    classA(std::string& data);
    ~classA();
    static void printData(std::string& prExpression);

    std::string m_strData;
    static int m_intData;
};


#endif //VARIADIC_TEMPLATES_CLASSA_H
