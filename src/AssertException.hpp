#ifdef DEBUG

#ifndef UTILS_ASSERTEXCEPTION_HPP
#define UTILS_ASSERTEXCEPTION_HPP

#include <stdexcept>

namespace Utils
{

class AssertException: public std::exception
{
    public:
        AssertException(const char * msg) throw();
        AssertException(const AssertException & e) throw() = default;
        AssertException & operator=(const AssertException & e) throw() = default;
        virtual ~AssertException() throw();
        virtual const char * what() const throw();
    private:
        const char * _msg;
};

}

#endif // UTILS_ASSERTEXCEPTION_HPP

    #define Assert(condition, message) if (!(condition)) throw(Utils::AssertException(message))
#else
    #define Assert(condition, message) ;
#endif
