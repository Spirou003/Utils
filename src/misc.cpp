#include "misc.hpp"

#include <cstring>

namespace Utils
{

void ReverseString(char * str, char eos)
{
    char * ptr = (str ? strchr(str, eos) : nullptr);
    ReverseContent(str, (ptr ? ptr - str : 0));
}

void ReverseContent(char * str, unsigned int size)
{
    if (str == nullptr || size < 2)
        return;
    unsigned int i = 0;
    char temp;
    while (i < size)
    {
        size--;
        temp = str[i];
        str[i] = str[size];
        str[size] = temp;
        i++;
    }
}

}
