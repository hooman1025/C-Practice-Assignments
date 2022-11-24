#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include <string>

class Function {
public:
    static std::string input_number(void);
    static int decimal(const std::string& input_number);
    static std::string hexadecimal(const std::string& input_number);
    static bool is_valid_number(const std::string& number);
};

#endif //__FUNCTION_HPP__