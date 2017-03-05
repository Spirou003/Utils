azertyu#ifdef UTILS_SELECTATOR3000_HPP

#include "Utils/Selectator3000.hpp"

template <typename T>
Utils::Selectator3000<T>::Selectator3000(int min, int max):
_min(min), _max(max), _value()
{
    SetRange(min, max);
}

template <typename T>
Utils::Selectator3000<T>::Selectator3000(int min, int max, const T & value):
_min(min), _max(max), _value(value)
{
    SetRange(min, max);
}

template <typename T>
Utils::Selectator3000<T>::Selectator3000(const Selectator3000 & other):
_min(other._min), _max(other._max), _value(other._value)
{}

template <typename T>
Utils::Selectator3000<T>::~Selectator3000(){}

template <typename T>
Utils::Selectator3000<T> & Utils::Selectator3000<T>::operator=(const Selectator3000 & other)
{
    _min = other._min;
    _max = other._max;
    _value = other._value;
    return *this;
}

template <typename T>
bool Utils::Selectator3000<T>::Contains(int n) const
{
    return (_min <= n && n <= _max);
}

template <typename T>
T & Utils::Selectator3000<T>::Get()
{
    return _value;
}

template <typename T>
const T & Utils::Selectator3000<T>::Get() const
{
    return _value;
}

template <typename T>
void Utils::Selectator3000<T>::SetRange(int min, int max)
{
    if (min < max)
    {
        _min = min;
        _max = max;
    }
    else
    {
        _min = max;
        _max = min;
    }
}

template <typename T>
int Utils::Selectator3000<T>::GetMin() const
{
    return _min;
}

template <typename T>
int Utils::Selectator3000<T>::GetMax() const
{
    return _max;
}

template <typename T>
template <typename Iterator3000>
Iterator3000 Utils::Selectator3000<T>::Find(Iterator3000 first, Iterator3000 last, int contained, size_t n)
{
    size_t count = 0;
    while (first != last)
    {
        if (first->Contains(contained))
        {
            if (count == n)
                return first;
            count++;
        }
        first++;
    }
    return last;
}

template <typename T>
template <typename Iterator3000>
size_t Utils::Selectator3000<T>::ContainingCount(Iterator3000 first, Iterator3000 last, int contained)
{
    size_t count = 0;
    while (first != last)
    {
        if (first->Contains(contained))
            count++;
        first++;
    }
    return count;
}

#endif
