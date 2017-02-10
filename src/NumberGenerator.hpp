#ifndef UTILS_NUMBERGENERATOR_HPP
#define UTILS_NUMBERGENERATOR_HPP

#include <cstdint>

namespace Utils
{

/**
 * @brief Number generator.
 *
 * Class used for numbers generating. Numbers can be random the same way they can be predictable.
 */
class NumberGenerator
{
    public:
        NumberGenerator();
        virtual ~NumberGenerator();

        /**
         * @brief Get a positive integer.
         * @return Positive integer.
         */
        virtual uint32_t operator()() throw() = 0;
};

}

#endif
