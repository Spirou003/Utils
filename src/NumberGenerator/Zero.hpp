#ifndef UTILS_NUMBERGENERATORRANDOM_HPP
#define UTILS_NUMBERGENERATORRANDOM_HPP

#include "../NumberGenerator.hpp"

namespace Utils
{

/**
 * @brief Generator of zeros.
 *
 * Simple class that only generates nul numbers.
 */
class Zero: public NumberGenerator
{
    public:
        /**
         * @brief Get a positive integer.
         * @return Zéro.
         */
        uint32_t operator()() throw();

        /**
         * @brief Get the instance of the class.
         * @return The unique instance of a zero-generator.
         */
        static NumberGenerator * GetInstance();

    private:
        Zero();
        ~Zero();

        static Zero * instance;
};

}

#endif
