#ifndef UTILS_POINT2D_HPP
#define UTILS_POINT2D_HPP

namespace Utils
{

template <typename T>
class Point2D
{
    public:
        Point2D();
        Point2D(T x, T y);
        Point2D(const Point2D<T> & p);
        ~Point2D();

        Point2D<T> & operator+= (const Point2D<T> & p);
        Point2D<T> & operator-= (const Point2D<T> & p);
        Point2D<T> & operator*= (const T & r);
        Point2D<T> & operator= (const Point2D<T> & p);

        T x, y;
};

template <typename T>
Point2D<T> operator+ (const Point2D<T> & p);
template <typename T>
Point2D<T> operator- (const Point2D<T> & p);

template <typename T>
Point2D<T> operator+ (const Point2D<T> & p, const Point2D<T> & q);
template <typename T>
Point2D<T> operator- (const Point2D<T> & p, const Point2D<T> & q);
template <typename T>
Point2D<T> operator* (const Point2D<T> & p, const T & r);
template <typename T>
Point2D<T> operator* (const T & r, const Point2D<T> & p);
template <typename T>
T operator| (const Point2D<T> & p, const Point2D<T> & q);

template <typename T>
bool operator== (const Point2D<T> & p, const Point2D<T> & q);
template <typename T>
bool operator!= (const Point2D<T> & p, const Point2D<T> & q);

#include "Point2D.cpp"

}

#endif
