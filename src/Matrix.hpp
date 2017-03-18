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
        typedef void (Constructor (T & toConstruct, T & constructFrom));

        Matrix(size_t l = 0, size_t c = 0);
        Matrix(Matrix<T> const & M);
        Matrix(Matrix<T> const & M, Constructor ctor);
        ~Matrix() throw();

        Matrix<T> & operator=(const Matrix<T> & M) = delete;

        void resize(size_t l, size_t c);
        void resize(size_t l, size_t c, Constructor ctor);
        bool empty() const;
        void clear();

        T & operator()(size_t l, size_t c);
        T const & operator()(size_t l, size_t c) const;
        T & at(size_t l, size_t c);
        T const & at(size_t l, size_t c) const;

        const size_t & Lines;
        const size_t & Columns;

    private:
        T * _tab;
        size_t _lines, _columns;

        static void Assign(T & toConstruct, T & constructFrom);
};

}

#include "Utils/Matrix.cpp"

#endif
