#ifndef UTILS_NONCOPYABLE_HPP
#define UTILS_NONCOPYABLE_HPP

namespace Utils
{

/**
 * @brief Class that can't be copied.
 *
 * If a class is derived from \a NonCopyable, this class won't allow to make any copy using both operator=(...) or copy constructor.
 */
class NonCopyable
{
    public:
        /**
         * @brief Constructor.
         */
        NonCopyable();

        NonCopyable(const NonCopyable &) = delete;
        NonCopyable & operator=(const NonCopyable &) = delete;
};

}

#endif
