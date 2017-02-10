#include "Conversions.hpp"
#include "misc.hpp"

namespace Utils
{

int ToInt(char letter, unsigned int basis)
{
    if (basis < 2 || basis > 36)
        return -1;
    if ('0' <= letter && letter <= '9')
        letter -= '0';
    else if ('a' <= letter && letter <= 'z')
        letter = letter - 'a' + 10;
    else if ('A' <= letter && letter <= 'Z')
        letter = letter - 'A' + 10;
    else
        return -1;
    if (letter >= (char)basis)
        return -1;
    return letter;
}

int ToInt(const char * str, unsigned int basis)
{
    int res;
    ToInt(res, str, basis);
    return res;
}

bool ToInt(int & result, const char * str, unsigned int basis)
{
    if (basis < 2 || basis > 36 || str == nullptr)
        return false;
    result = 0;
    const char * ptr = str;
    if (str[0] == '-')
        ptr = &str[1];
    int i = 0;
    while (true)
    {
        char letter = ToInt(ptr[i], basis);
        if (letter == -1)
            break;
        result = result*basis + letter;
        i++;
    }
    if (ptr != str)
        result = -result;
    return i > 0;
}

char _ToChar(int value, bool isLower);

char _ToChar(int value, bool isLower)
{
    if (value < 10)
        return '0'+value;
    else
        return (isLower ? 'a' : 'A')+value-10;
}

char ToChar(int value, unsigned int basis, bool isLower)
{
    if (value < 0 || basis < 2 || basis > 36 || value >= (int)basis)
        return 0;
    return _ToChar(value, isLower);
}

int ToString_RequiredSize(int value, unsigned int basis)
{
    if (basis < 2 || basis > 36)
        return -1;
    int count = 0;
    if (value < 0)
    {
        count++;
        value = -value;
    }
    do
    {
        value /= basis;
        count++;
    } while (value != 0);
    return count;
}

bool ToString(char * str, int value, unsigned int basis, bool isLower, bool reverse)
{
    if (str == nullptr || basis < 2 || basis > 36)
        return false;
    char * ptr = str;
    if (value < 0)
    {
        value = -value;
        *str = '-';
        str++;
        ptr++;
    }
    do
    {
        *ptr = _ToChar(value%basis, isLower);
        ptr++;
        value /= basis;
    } while (value != 0);
    *ptr = '\0';
    if (reverse)
        ReverseContent(str, ptr-str);
    return true;
}

const char * ToString(bool b)
{
    return (b ? "true" : "false");
}

}

