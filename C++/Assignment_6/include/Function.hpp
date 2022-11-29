#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include <string>

#define EMPTY_PART "   "

enum class Status {
    SUCCESS,
    FAILURE
};

class Function {
public:
    static std::string inputString(void);
    static void drawRadius(const std::string& inputRadius, const std::string& inputCharacter, const std::string& inputFill);
    static bool isValidRadius(const std::string& inputRadius);
    static bool isValidCharacters(const std::string& inputCharacters);
    static bool isValidFill(const std::string& inputFill);
};

#endif  // __FUNCTION_HPP__
