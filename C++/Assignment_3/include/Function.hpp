#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include <string>

class Function {
public:
    static std::string input_string(void);
    static int count_string(const std::string& user_input);
};

#endif //__FUNCTION_HPP__