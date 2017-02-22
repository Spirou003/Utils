#ifndef UTILS_MATRIX_HPP
#define UTILS_MATRIX_HPP

#include <stdexcept>
#include <assert.h>
#include <cstdlib>
#include <cstdio>

namespace Utils
{

template <typename T>
class Matrix
{
    public:
        Matrix(size_t l = 1, size_t c = 1);
        Matrix(Matrix<T> const & M);
        ~Matrix() throw();

        Matrix<T> & operator=(const Matrix<T> & M) = delete;

        T & operator()(size_t l, size_t c);
        T const & operator()(size_t l, size_t c) const;
        T & At(size_t l, size_t c) throw();
        T const & At(size_t l, size_t c) const throw();

        const size_t Lines, Columns;

    private:
        T * _tab;
};

}

#include "Matrix.cpp"

#endif
