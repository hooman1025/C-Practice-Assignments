#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include <string>

class Function {
public:
    static std::string inputString(void);
    static void triPattern(const std::string& inputNumString);
    static bool isValidNumber(const std::string& number);
};

#endif //__FUNCTION_HPP__