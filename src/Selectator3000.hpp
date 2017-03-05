#ifndef UTILS_SELECTATOR3000_HPP
#define UTILS_SELECTATOR3000_HPP

#include <iterator>
#include <algorithm>

namespace Utils
{

template <typename T>
class Selectator3000
{
    public:
        Selectator3000(int min = 0, int max = 0);
        Selectator3000(int min, int max, const T & value);
        Selectator3000(const Selectator3000 & other);
        ~Selectator3000();

        Selectator3000<T> & operator=(const Selectator3000 & other);

        bool Contains(int n) const;
        T & Get();
        const T & Get() const;
        void SetRange(int min, int max);
        int GetMin() const;
        int GetMax() const;

        template <typename Iterator3000>
        static Iterator3000 Find(Iterator3000 first, Iterator3000 last, int contained, size_t n = 0);
        template <typename Iterator3000>
        static size_t ContainingCount(Iterator3000 first, Iterator3000 last, int contained);

    private:
        int _min, _max;
        T _value;
};

}

#include "Utils/Selectator3000.cpp"

#endif
