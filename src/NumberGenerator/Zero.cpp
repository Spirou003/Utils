#include "Zero.hpp"

namespace Utils
{

Zero * Zero::instance = 00;

Zero::Zero(){}
Zero::~Zero(){}

uint32_t Zero::operator()() throw()
{
    return 0;
}

NumberGenerator * Zero::GetInstance()
{
    if (instance == 00)
        instance = new Zero();
    return instance;
}

}

