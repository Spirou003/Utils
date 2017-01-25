#ifndef UTILS_MISC_HPP
#define UTILS_MISC_HPP

namespace Utils
{

/**
 * @brief Reverse a C-style string.
 * @param str String to reverse. Content is altered.
 * @param eos End of string character.
 * @note Parameter \a str may be null.
 */
void ReverseString(char * str, char eos = '\0');
/**
 * @brief Reverse a part of a C-style string.
 * @param str String to reverse. Content is altered.
 * @param size Size of the string to be reversed.
 * @note Parameter \a str may be null. Produce buffer-overflow if Length(str) < size.
 */
void ReverseContent(char * str, unsigned int size);

}
#endif
