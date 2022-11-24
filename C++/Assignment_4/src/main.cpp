#include "Function.hpp"
#include <iostream>

int main(void) {
    int status = 0;
    std::string firstBinary;
    std::string secondBinary;
    std::string operatorValue;
    OperatorsNumber operatorFlag;

    std::cout << "A : ";
    firstBinary = Function::inputString();
    if (false == Function::isValidBinary(firstBinary)) {
        std::cout << "not valid value. valid value is binary number." << std::endl;
        status = 1;
    }

    if (0 == status) {
        std::cout << "B : ";
        secondBinary = Function::inputString();
        if (false == Function::isValidBinary(secondBinary)) {
            std::cout << "not valid value. valid value is binary number." << std::endl;
            status = 2;
        }
    }

    if (0 == status) {
        std::cout << "OP : ";
        operatorValue = Function::inputString();
        operatorFlag = Function::convertOperator(operatorValue);
        if (OperatorsNumber::ERROR == operatorFlag) {
            std::cout << "supported operators : and, or, xor, nor" << std::endl;
            status = 3;
        }
    }

    if (0 == status) {
        std::cout << "Result : " << Function::binaryCalculator(firstBinary, secondBinary, operatorFlag) << std::endl;
    }

    return status;
}
