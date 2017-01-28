#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "Matrix.hpp"

namespace
{
    char CHAR_ARRAY_ERR[255];
}

template <typename T>
Utils::Matrix<T>::Matrix(unsigned int l, unsigned int c):
Lines(l), Columns(c), _tab(nullptr)
{
    if (l == 0 || c == 0)
    {
        sprintf(CHAR_ARRAY_ERR, "Matrix must have at least one dimension (L = %d , C = %d)", l, c);
        throw std::length_error(CHAR_ARRAY_ERR);
    }
    else if ((long long int)(l) * (long long int)(l) > (long long int)(l*c))
    {
        sprintf(CHAR_ARRAY_ERR, "Size of matrix is too big");
        throw std::overflow_error(CHAR_ARRAY_ERR);
    }
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
Utils::Matrix<T>::Matrix(Matrix<T> const * M):
Lines(0), Columns(0), _tab(nullptr)
{
    if (M == nullptr)
    {
        sprintf(CHAR_ARRAY_ERR, "Can't create a matrix from a null pointer");
    }
    Lines = M->Lines;
    Columns = M->Columns;
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
    delete[](_tab);
}

template <typename T>
T & Utils::Matrix<T>::operator()(unsigned int l, unsigned int c)
{
    if (l >= Lines || c >= Columns)
    {
        sprintf(CHAR_ARRAY_ERR, "(L , C) = (%d , %d), dimensions are %d x %d", l, c, Lines, Columns);
        throw std::out_of_range(CHAR_ARRAY_ERR);
    }
    return _tab[l*Columns+c];
}

template <typename T>
T const & Utils::Matrix<T>::operator()(unsigned int l, unsigned int c) const
{
    if (l >= Lines || c >= Columns)
    {
        sprintf(CHAR_ARRAY_ERR, "(L , C) = (%d , %d), dimensions are %d x %d", l, c, Lines, Columns);
        throw std::out_of_range(CHAR_ARRAY_ERR);
    }
    return _tab[l*Columns+c];
}

template <typename T>
T & Utils::Matrix<T>::At(unsigned int l, unsigned int c) throw()
{
    return _tab[l*Columns+c];
}

template <typename T>
T const & Utils::Matrix<T>::At(unsigned int l, unsigned int c) const throw()
{
    return _tab[l*Columns+c];
}

#endif

