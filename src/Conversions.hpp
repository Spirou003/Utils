#ifndef UTILS_CONVERSIONS_HPP
#define UTILS_CONVERSIONS_HPP

namespace Utils
{

/**
 * @brief Convert a one-digit number of specified basis to int.
 * @param letter Digit to convert.
 * @param basis The basis used to convert \a letter.
 * @return The corresponding number on success, -1 otherwise.
 * @note Success happen when 2 <= basis <= 36 and ('0' <= \a letter <= '9' or 'a' <= \a letter <= 'z' or 'A' <= \a letter <= 'Z') and \a letter < \a basis.
 */
int ToInt(char letter, unsigned int basis = 10);
/**
 * @brief Convert a C-style string of specified basis to int.
 * @param str String to convert.
 * @param basis The basis used to convert \a letter.
 * @return The corresponding number on success, 0 otherwise.
 * @note Success happen when all characters are convertibles but even first may be '-' for negative numbers. This function don't care of integer overflow.
 */
int ToInt(const char * str, unsigned int basis = 10);
/**
 * @brief Convert a C-style string of specified basis to int.
 * @param str String to convert.
 * @param basis The basis used to convert \a letter.
 * @return The corresponding number on success, 0 otherwise.
 * @note Success happen when all characters are convertibles but even first may be '-' for negative numbers. This function don't care of integer overflow.
 */
int ToInt(const char * str, unsigned int basis, unsigned int size);
/**
 * @brief Convert a C-style string of specified basis to int.
 * @param result The corresponding number on success, undefined otherwise.
 * @param str String to convert.
 * @param basis The basis used to convert \a letter.
 * @return On success \a true, otherwise \a false.
 * @note Success happen when all characters are convertibles but even first may be '-' for negative numbers, and str is not null. This function don't care of integer overflow.
 */
bool ToInt(int & result, const char * str, unsigned int basis = 10);
/**
 * @brief Convert an integer to single character.
 * @param value Number to convert.
 * @param basis The basis used to encode a letter.
 * @param isLower Tell if the generated letter is lowercase.
 * @return Corresponding letter of specified basis if possible, otherwise -1.
 * @note Conversion is possible iff 2 <= \a basis <= 36 and 0 <= \a value < \a basis.
 */
char ToChar(int value, unsigned int basis = 10, bool isLower = false);
/**
 * @brief Compute required size to store the converted integer to a string of specified basis.
 * @param value Number to convert.
 * @param basis The basis used to encode a letter.
 * @return Size of the representing string for \a value if possible, otherwise -1.
 * @note Calcul is possible iff 2 <= \a basis <= 36.
 */
int ToString_RequiredSize(int value, unsigned int basis = 10);
/**
 * @brief Convert integer to a string of specified basis.
 * @param str Destination string. Content is altered.
 * @param value Number to convert.
 * @param basis The basis used to encode a letter.
 * @param isLower Tell if the generated string is lowercase.
 * @param reverse Tell if the generated string is reverted before return.
 * @return Conversion status: \a true on success, \a false on failure.
 * @note Conversion is possible iff 2 <= \a basis <= 36. If \a reverse is \a false, generated string for -100 with basis 10 is -001, otherwise -100.
 * @bug Smallest integer will produce undefined string.
 */
bool ToString(char * str, int value, unsigned int basis = 10, bool isLower = false, bool reverse = true);
/**
 * @brief Convert a boolean to a string.
 * @param b Boolean to convert.
 * @return If \a b is \a true returns "true", otherwise "false".
 */
const char * ToString(bool b);

}

#endif
