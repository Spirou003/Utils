#ifndef UTILS_MATRIX_HPP
#define UTILS_MATRIX_HPP

#include <stdexcept>
#include <cstdlib>
#include <cstdio>

namespace Utils
{

template <typename T>
class Matrix
{
    public:
        Matrix(unsigned int l = 1, unsigned int c = 1);
        Matrix(Matrix<T> const & M);
        Matrix(Matrix<T> const * m);
        ~Matrix() throw();

        Matrix<T> & operator=(const Matrix<T> & M) = delete;

        T & operator()(unsigned int l, unsigned int c);
        T const & operator()(unsigned int l, unsigned int c) const;
        T & At(unsigned int l, unsigned int c) throw();
        T const & At(unsigned int l, unsigned int c) const throw();

        const unsigned int Lines, Columns;

    private:
        T * _tab;
};

}

#include "Matrix.cpp"

#endif
