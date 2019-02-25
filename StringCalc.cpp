#include <iostream>
#include <string>
using std::string;

int Add(const std::string &num)
{
    if (num == "")
    {
        return 0;
    }
    else
        {
        return std::stoi(num);
    }


}