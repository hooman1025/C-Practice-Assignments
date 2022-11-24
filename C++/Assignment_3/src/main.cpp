#include "Function.hpp"
#include <iostream>

int main(void) {
    std::cout << "Input string : ";
    std::string input_data = Function::input_string();
    
    std::cout << "number of words : " << Function::count_string(input_data) << std::endl;
}
