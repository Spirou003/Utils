#include "Zero.hpp"

namespace Utils
{

Zero * Zero::instance = nullptr;

Zero::Zero(){}
Zero::~Zero(){}

uint32_t Zero::operator()() throw()
{
    return 0;
}

NumberGenerator * Zero::GetInstance()
{
    if (instance == nullptr)
        instance = new Zero();
    return instance;
}

}

