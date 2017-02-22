#ifdef DEBUG

#include "AssertException.hpp"

namespace Utils
{
AssertException::AssertException(const char * msg) throw():_msg(msg){}
AssertException::~AssertException() throw(){}
const char * AssertException::what() const throw(){return _msg;}
}

#endif
