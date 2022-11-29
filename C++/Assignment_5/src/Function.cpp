#include "Function.hpp"
#include <iostream>

std::string Function::inputString(void) {
    std::string inputNumString;

    std::cout << "Input number of row : ";
    getline(std::cin, inputNumString);

    std::cout << std::endl;

    return inputNumString;
}

void Function::triPattern(const std::string& inputNumString) {
    int inputNum = stoi(inputNumString);
    int row = 0;
    int column = 0;
    int space = 0;
    int minor = 0;

    for (row; row < inputNum; ++row) {
        for (space = inputNum - row; space > 0; --space) {
            std::cout << " ";
        }

        for (column = 1; column <= row; ++column) {
            std::cout << column;
        }

        for (minor = 0; minor <= row; ++minor) {
            std::cout << column - minor;
        }

        std::cout << std::endl;
    }
}

bool Function::isValidNumber(const std::string& number) {
    int length = number.size();
    int inputNum;
    bool result = true;

    if ((0 == length)) {
        result = false;
    } else {
        for (int i = 0; i < length; ++i) {
            if ((' ' == number[i]) || ('0' > number[i]) || ('9' < number[i])) {
                result = false;
                break;
            }
        }

        if (true == result) {
            inputNum = stoi(number);

            if (9 < inputNum || 1 > inputNum) {
                result = false;
            }
        }
    }

    return result;
}
