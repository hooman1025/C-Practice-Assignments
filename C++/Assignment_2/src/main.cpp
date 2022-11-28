#include "Function.hpp"
#include <iostream>

int main(void) {
    std::cout << "input number : ";
    std::string number = Function::input_number();

    if (false == Function::is_valid_number(number)) {
        std::cout << "not valid number. valid number is binary value and no more than 20 digits." << std::endl;
        exit(1);
    }

    std::cout << "Decimal : " << Function::decimal(number) << std::endl;
    std::cout << "Hexadecimal : " << Function::hexadecimal(number) << std::endl;

    return 0;
}