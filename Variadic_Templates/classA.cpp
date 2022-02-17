//
// Created by 17783 on 2022/2/16.
//

#include <iostream>
#include "classA.h"

int classA::m_intData = 0;

classA::classA(std::string &data)
    :m_strData(data)
{
}

void classA::printData(std::string &prExpression)
{
    std::cout << prExpression <<  std::endl;
}

classA::~classA()
{}