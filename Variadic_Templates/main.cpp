#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
//字符串最后一个单词的长度
void last_word_length()
{
    std::string str_input;
    std::getline(std::cin,str_input);

    int index = str_input.rfind(" ");
    if( index != std::string::npos)
    {
        str_input = str_input.substr(index + 1);
    }
    std::cout << str_input.length() << std::endl;
    return;
}

//计算某字符出现的次数
void solution_HJ2()
{

    std::map<char,int> cache;
    char char_input;
    while(std::cin.get(char_input))
    {
        if(char_input == '\n')
        {
            break;
        }
        char_input = toupper(char_input);
        if(cache.find(char_input) != cache.end())
        {
            cache[char_input]++;
        }
        else
        {
            cache[char_input] = 1;
        }
    }
    char_input = toupper(std::cin.get());
    std::cout << cache[char_input] << std::endl;
    return;
}

//
void solution_HJ3(int inputCount)
{
    std::set<int> cache;
    cache.clear();

    int intInput = 0;
    for(int i = 0; i < inputCount; ++i)
    {
        std::cin >> intInput;
        cache.insert(intInput);
    }

    for(auto iter: cache)
    {
        std::cout << iter << std::endl;
    }
    return;
}

// 进制转换
void solution_HJ5(const std::string& str)
{
        int sum = 0;
        int index = str.length() - 1;
        int e = 0;
        while(index > 1)
        {
            if(str[index] >= '0' && str[index] <= '9')
            {
                sum+= (str[index] - '0')* pow(16,e);
            }
            else if(str[index] >= 'A' && str[index] <= 'Z')
            {
                sum+= (str[index] - 'A' + 10)* pow(16,e);
            }
            --index;
            ++e;
        }
        std::cout << sum << std::endl;
        return;
}

// 字符个数统计
void solution_HJ10(const std::string& str)
{
    std::set<char> cache;
    for(char iter:str)
    {
        cache.insert(iter);
    }
    std::cout << cache.size() << std::endl;
}

// 跳台阶 NC68
void solution_NC68(int count)
{
    std::vector<int> res(count + 1,0);
    res[1] = 1;
    res[2] = 2;
    for(int i = 3; i < count; ++i)
    {
        res[i] = res[i-1] + res[i-2];
    }
}

// 坐标移动 HJ17
void changeCoordinate(std::vector<int>& coordinate,char dir, int value)
{
    int index = -1;
    switch (dir)
    {
        case 'A':{
            index = 0;
            value = (-value);
            break;
        }
        case 'D': {
            index = 0;
            break;
        }
        case 'W':{
            index = 1;
            break;
        }
        case 'S':{
            index = 1;
            value = (-value);
            break;
        }
    }
    if(index > -1)
    {
        coordinate[index] += value;
    }
    return;
}

void getDistance(const std::string& strInput)
{
    // AD->cache[0],WS->cache[1]
    std::vector<int> cache(2,0);
    int startIndex = 0;
    for(int endIndex = 0; endIndex < strInput.length(); ++endIndex)
    {
        if(startIndex > endIndex)
        {
            break;
        }

        if(strInput[endIndex] == ';')
        {
            std::string subStr = strInput.substr(startIndex,endIndex-startIndex);
            if(subStr.length() == 2 && subStr[1] >= '0' && subStr[1] <= '9')
            {
                char dir = subStr[0];
                int  value = subStr[1] - '0';
                changeCoordinate(cache,dir,value);

            }
            else if(subStr.length() == 3 &&subStr[1] >= '0' &&subStr[2] >='0' &&subStr[1] <='9' &&subStr[2] <='9')
            {
                char dir = subStr[0];
                int value = (subStr[1] - '0')*10 + (subStr[2] - '0');
                changeCoordinate(cache,dir,value);
            }
            startIndex = endIndex + 1;
        }
    }
    std::cout << cache[0] << ',' << cache[1] << std::endl;
}

// 密码验证合格程序
void solution_HJ20(const std::string& strInput)
{
    //condition 1
    if(strInput.length() <= 8)
    {
        std::cout << "NG" << std::endl;
        return;
    }
    //condition 2
    bool bCondition2[4]{false};
    int sum = 0;
    for(char iter : strInput)
    {
        if(sum >= 3)
        {
            break;
        }
        if('a' <= iter && iter <= 'z') {
            if(!bCondition2[0]){
                bCondition2[0] = true;
                ++sum;
            }
        }
        else if('A' <= iter && iter <= 'Z')
        {
            if(!bCondition2[1]) {
                bCondition2[1] = true;
                ++sum;
            }
        }
        else if('0' <= iter && iter <= '9')
        {
            if(!bCondition2[2]) {
                bCondition2[2] = true;
                ++sum;
            }
        }
        else if(iter != ' ' && iter != '\n')
        {
            if(!bCondition2[3]) {
                bCondition2[3] = true;
                ++sum;
            }
        }
    }

    if(sum < 3)
    {
        std::cout << "NG" << std::endl;
        return;
    }

    //condition 3
    for(int index = 0; index + 3 < strInput.length(); ++index)
    {
        std::string subStr = strInput.substr(index,3);
        if(strInput.find(subStr,index + 3) != std::string::npos)
        {
            std::cout << "NG" << std::endl;
            return;
        }
    }

    std::cout << "OK" << std::endl;
    return;
}

// 删除字符串中出现次数最少的字符
void solution_HJ23(const std::string& str_input)
{
    std::map<char,int> cache;
    for(auto iter: str_input)
    {
        if(cache.find(iter) != cache.end())
        {
            ++cache[iter];
        }
        else
        {
            cache[iter] = 1;
        }
    }

    int counter = 20;
    for(auto iter: cache)
    {
        if(iter.second < counter)
        {
            counter = iter.second;
        }
    }

    std::string str_result = "";
    for(auto iter:str_input)
    {
        if(cache[iter] != counter)
        {
            str_result += iter;
        }
    }
    std::cout << str_result << std::endl;
    return;
}

void solution_HJ101(std::vector<int>& dataSet,int com)
{
    auto fun = com? [](int a,int b){return a > b;} : [](int a,int b){return a < b;};
    std::sort(dataSet.begin(),dataSet.end(),fun);
    for(auto iter : dataSet)
    {
        std::cout << iter << " ";
    }
    return;
}

void solution_HJ106(std::string& strInput)
{
    std::string result;
    for(auto iter : strInput)
    {
        result = iter + result;
    }
    std::cout << result << std::endl;
}

void solution_HJ46(std::string& strInput,unsigned int len)
{
    std::cout << strInput.substr(0,len) << std::endl;
    return;
}

void solution_HJ8(std::map<int,int>& data,int key,int value)
{
    if(data.find(key) != data.end())
    {
        data[key] += value;
    }
    else
    {
        data[key] = value;
    }
}

void solution_HJ14(std::vector<std::string>& str)
{
    std::sort(str.begin(),str.end());
    for(auto iter: str)
    {
        std::cout << iter << std::endl;
    }
    return;
}
int main()
{
    int count;
    std::vector<int> dataSet;
    int compKey;

    std::cin >> count;
    for(int i = 0; i < count; ++i)
    {
        std::cin >> compKey;
        dataSet.push_back(compKey);
    }
    std::cin >> compKey;
    solution_HJ101(dataSet,compKey);
}