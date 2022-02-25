#include <iostream>
#include <string>

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
int main(int argc, char *argv[])
{
    last_word_length();
    return 0;
}