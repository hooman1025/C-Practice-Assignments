#include "function.hpp"
#include <iostream>
#include <sstream>

std::string Function::input_string(void) {
    std::string input_s;

    getline(std::cin, input_s);

    return input_s;
}

int Function::count_string(const std::string& user_input) {
    std::stringstream ss;
    std::string tmp_s;
    int space = 0;

    ss.str(user_input);

    while (ss >> tmp_s) {
        ++space;;
    }

    return space;
}
