#include "Function.hpp"
#include <iostream>

int main(void) {
    std::string inputNumber = Function::inputString();
    int status = 0;

    if (false == Function::isValidNumber(inputNumber)) {
        std::cout << "not valid number. valid number is 1 to 9." << std::endl;
        status = 1;
    }

    if (0 == status) {
        Function::triPattern(inputNumber);
    }

    return status;
}
