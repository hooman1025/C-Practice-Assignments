#include "function.hpp"
#include <iostream>

int main(void) {
    std::cout << "input number : ";
    uint64_t number = Function::input_number();

    if (false == Function::is_valid_number(number)) {
        std::cout << "not valid number. valid number is on 0 to 20" << std::endl;
        exit(1);
    }

    std::cout << "\n with recursion" << std::endl;
    std::cout << "Factorial of " << number << " is " << Function::factorial_rec(number) << std::endl;

    std::cout << "\n without recursion" << std::endl;
    std::cout << "Factorial of " << number << " is " << Function::factorial_wo(number) << std::endl;

    return 0;
}
