#ifndef UTILS_DEFINES_HPP
#define UTILS_DEFINES_HPP

#if defined _WIN32 || defined _WIN64
    #define OS_WINDOWS
    #define MakeDirectory(x) mkdir(x)
    #define MakePause() system("pause")
#else
    #define OS_LINUX
    #define MakeDirectory(x) mkdir(x, 0777)
    #define MakePause() {printf("Appuyez sur entrée pour continuer... ");getchar();}
#endif

#ifndef PI
#define PI 3.141592653589793238463
#endif

#define DeleteIfNotNull(ptr) if (ptr == nullptr) { delete(ptr); }

#include "AssertException.hpp"

#endif


