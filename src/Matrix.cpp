#ifdef UTILS_MATRIX_HPP

#include "AssertException.hpp"

template <typename T>
Utils::Matrix<T>::Matrix(size_t l, size_t c):
Lines(_lines), Columns(_columns), _tab(nullptr), _lines(l), _columns(c)
{
    if (l == 0 || c == 0)
    {
        _lines = (_columns = 0);
        return;
    }
    else if ((l*c)/c != l)
        throw std::overflow_error("Too big dimensions.");
    _tab = new T[l*c];
}

template <typename T>
Utils::Matrix<T>::Matrix(Matrix<T> const & M):
Matrix(M, &Assign)
{}

template <typename T>
Utils::Matrix<T>::Matrix(Matrix<T> const & M, Constructor ctor):
Lines(_lines), Columns(_columns), _tab(nullptr), _lines(0), _columns(0)
{
    resize(M.Lines, M.Columns, ctor);
    size_t i = 0, s = Lines*Columns;
    while (i < s)
    {
        ctor(_tab[i], M._tab[i]);
        i++;
    }
}

template <typename T>
Utils::Matrix<T>::~Matrix() throw()
{
    if (_tab != nullptr)
        delete[](_tab);
}

template <typename T>
void Utils::Matrix<T>::resize(size_t l, size_t c)
{
    resize(l, c, &Assign);
}

template <typename T>
void Utils::Matrix<T>::resize(size_t l, size_t c, Constructor ctor)
{
    if (ctor == nullptr)
        throw std::invalid_argument("ctor = null");
    if (l == 0 || c == 0)
        clear();
    else if ((l*c)/c != l)
        throw std::overflow_error("Too big dimensions.");
    else if (l == Lines && c == Columns)
        return;
    T * tab = new T[l*c];
    const size_t L = (l > Lines ? Lines : l);
    const size_t C = (c > Columns ? Columns : c);
    size_t i = 0, j = 0;
    try
    {
        while (i < L)
        {
            j = 0;
            while (j < C)
            {
                ctor(tab[i*C+j], (*this)(i, j));
                j++;
            }
            i++;
        }
    }
    catch(...)
    {
        delete[](tab);
        throw;
    }
    if (_tab != nullptr)
        delete[](_tab);
    _tab = tab;
    _lines = l;
    _columns = c;
}

template <typename T>
bool Utils::Matrix<T>::empty() const
{
    return Lines == 0;
}

template <typename T>
void Utils::Matrix<T>::clear()
{
    if (Lines == 0)
        return;
    delete[](_tab);
    _lines = 0;
    _columns = 0;
}

template <typename T>
T & Utils::Matrix<T>::operator()(size_t l, size_t c)
{
    Assert(l < Lines, "Invalid line number on access.");
    Assert(c < Columns, "Invalid column number on access.");
    return _tab[l*Columns+c];
}

template <typename T>
T const & Utils::Matrix<T>::operator()(size_t l, size_t c) const
{
    Assert(l < Lines, "Invalid line number on access.");
    Assert(c < Columns, "Invalid column number on access.");
    return _tab[l*Columns+c];
}

template <typename T>
T & Utils::Matrix<T>::at(size_t l, size_t c)
{
    if (l >= Lines)
        throw std::out_of_range("Invalid line number on access.");
    else if (c >= Columns)
        throw std::out_of_range("Invalid column number on access.");
    return _tab[l*Columns+c];
}

template <typename T>
T const & Utils::Matrix<T>::at(size_t l, size_t c) const
{
    if (l >= Lines)
        throw std::out_of_range("Invalid line number on read access.");
    else if (c >= Columns)
        throw std::out_of_range("Invalid column number on read access.");
    return _tab[l*Columns+c];
}

template <typename T>
void Utils::Matrix<T>::Assign(T & toConstruct, T & constructFrom)
{
    toConstruct = constructFrom;
}

#endif

