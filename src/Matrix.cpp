#ifdef UTILS_MATRIX_HPP

#include "AssertException.hpp"

template <typename T>
Utils::Matrix<T>::Matrix(size_t l, size_t c):
Lines(l), Columns(c), _tab(nullptr)
{
    if (l == 0)
        throw std::length_error("Can't create matrix with no line.");
    else if (c == 0)
        throw std::length_error("Can't create matrix with no column.");
    else if ((long long int)(l) * (long long int)(l) > (long long int)(l*c))
        throw std::overflow_error("Too big dimensions.");
    _tab = new T[l*c];
}

template <typename T>
Utils::Matrix<T>::Matrix(Matrix<T> const & M):
Lines(M.Lines), Columns(M.Columns), _tab(new T[M.Lines*M.Columns])
{
    int i = 0, s = Lines*Columns;
    while (i < s)
    {
        _tab[i] = M._tab[i];
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
T & Utils::Matrix<T>::operator()(size_t l, size_t c)
{
    Assert(l >= Lines || c >= Columns, "");
    return _tab[l*Columns+c];
}

template <typename T>
T const & Utils::Matrix<T>::operator()(size_t l, size_t c) const
{
    Assert(l >= Lines || c >= Columns, "");
    return _tab[l*Columns+c];
}

template <typename T>
T & Utils::Matrix<T>::At(size_t l, size_t c) throw()
{
    if (l >= Lines)
        throw std::out_of_range("Invalid line number on access.");
    else if (c >= Columns)
        throw std::out_of_range("Invalid column number on access.");
    return _tab[l*Columns+c];
}

template <typename T>
T const & Utils::Matrix<T>::At(size_t l, size_t c) const throw()
{
    if (l >= Lines)
        throw std::out_of_range("Invalid line number on read access.");
    else if (c >= Columns)
        throw std::out_of_range("Invalid column number on read access.");
    return _tab[l*Columns+c];
}

#endif

