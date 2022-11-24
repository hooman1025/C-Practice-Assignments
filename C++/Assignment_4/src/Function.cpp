#include "Function.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

std::string Function::inputString(void) {
    std::string inputString;

    getline(std::cin, inputString);

    return inputString;
}

std::string Function::binaryCalculator(const std::string& inputFirstBinary, const std::string& inputSecondBinary, const OperatorsNumber inputOperatorFlag) {
    std::vector<char> firstBinary;
    std::vector<char> secondBinary;

    int pushSize = abs(inputFirstBinary.size() - inputSecondBinary.size());

    int sizeFlag = (inputFirstBinary.size() > inputSecondBinary.size()) ? inputFirstBinary.size() : inputSecondBinary.size();

    std::string result;


    if (inputFirstBinary.size() > inputSecondBinary.size()) {
        pushBackBinary(inputFirstBinary, firstBinary, inputSecondBinary, secondBinary, pushSize);
    } else {
        pushBackBinary(inputSecondBinary, secondBinary, inputFirstBinary, firstBinary, pushSize);
    }

    switch (inputOperatorFlag) {
    case OperatorsNumber::AND:
        for (int i = 0; i < sizeFlag; ++i) {
            (firstBinary.at(i) & secondBinary.at(i)) == 1 ? result.push_back('1') : result.push_back('0');
        }
        break;
    case OperatorsNumber::OR:
        for (int i = 0; i < sizeFlag; ++i) {
            (firstBinary.at(i) | secondBinary.at(i)) == 1 ? result.push_back('1') : result.push_back('0');
        }
        break;
    case OperatorsNumber::XOR:

        for (int i = 0; i < sizeFlag; ++i) {
            (firstBinary.at(i) ^ secondBinary.at(i)) == 1 ? result.push_back('1') : result.push_back('0');
        }
        break;
    case OperatorsNumber::NOR:
        for (int i = 0; i < sizeFlag; ++i) {
            !((firstBinary.at(i) | secondBinary.at(i))) == 1 ? result.push_back('1') : result.push_back('0');
        }
        break;
    }

    return result;
}

bool Function::isValidBinary(const std::string& inputString) {
    int length = inputString.size();
    bool result = true;

    if (0 >= length) {
        result = false;
    } else {
        for (int index = 0; index < length; ++index) {
            if ((false == inputString.find(' ')) || (('1' != inputString[index]) && ('0' != inputString[index]))) {
                result = false;
                break;
            }
        }
    }

    return result;
}

OperatorsNumber Function::convertOperator(std::string& inputOperator) {
    OperatorsNumber result = OperatorsNumber::ERROR;
    const std::map<std::string, OperatorsNumber> availableOperators = 
    {
        { "and", OperatorsNumber::AND },
        { "or", OperatorsNumber::OR },
        { "xor", OperatorsNumber::XOR },
        { "nor", OperatorsNumber::NOR }
    };

    std::transform(inputOperator.begin(), inputOperator.end(), inputOperator.begin(), [](unsigned char c) {
        return tolower(c);
    });

    auto iter = availableOperators.find(inputOperator);

    if (availableOperators.end() != iter) {
        result = iter->second;
    }

    return result;
}

void Function::pushBackBinary(const std::string& inputFirstBinary, std::vector<char>& firstBinary, const std::string& inputSecondBinary, std::vector<char>& secondBinary, size_t pushSize) {
    firstBinary.reserve(20);
    secondBinary.reserve(20);

    for (int i = 0; i < inputFirstBinary.size(); ++i) {
        firstBinary.push_back(inputFirstBinary.at(i) - '0');
    }

    for (int i = 0; i < pushSize; ++i) {
        secondBinary.push_back(0);
    }

    for (int i = 0; i < inputSecondBinary.size(); ++i) {
        secondBinary.push_back(inputSecondBinary.at(i) - '0');
    }
}
