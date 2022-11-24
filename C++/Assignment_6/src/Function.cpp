#include "Function.hpp"
#include <iostream>
#include <cmath>

std::string Function::inputString(void) {
    std::string inputString;

    std::getline(std::cin, inputString);

    return inputString;
}

void Function::drawRadius(const std::string& inputRadius, const std::string& inputCharacter, const std::string& inputFill) {
    float radius = stof(inputRadius);
    int row;
    int column;

    if (("y" == inputFill) || ("Y" == inputFill)) {
        for (row = -radius; row <= radius; ++row) {
            for (column = -radius; column <= radius; ++column) {
                if (std::pow(row, 2) + std::pow(column, 2) < std::pow(radius, 2)) {
                    std::cout << inputCharacter << inputCharacter << inputCharacter;
                } else {
                    std::cout << EMPTY_PART;
                }
            }
            std::cout << std::endl;
        }
    } else if (("n" == inputFill) || ("N" == inputFill)) {
        for (row = -radius; row <= radius; ++row) {
            for (column = -radius; column <= radius; ++column) {
                if (std::pow(row, 2) + std::pow(column, 2) < std::pow(radius, 2) &&
                    std::pow(row, 2) + std::pow(column, 2) > std::pow(radius - 2.5, 2)) {
                    std::cout << inputCharacter << inputCharacter << inputCharacter;
                } else {
                    std::cout << EMPTY_PART;
                }
            }
            std::cout << std::endl;
        }
    }
}

bool Function::isValidRadius(const std::string& inputRadius) {
    int length = inputRadius.size();
    int radius;
    bool result = true;

    if ((0 != length)) {
        for (int i = 0; i < length; ++i) {
            if ((' ' == inputRadius[i]) || ('0' > inputRadius[i]) || ('9' < inputRadius[i])) {
                result = false;
                break;
            }
        }

        if (true == result) {
            radius = stoi(inputRadius);

            if (20 < radius || 5 > radius) {
                result = false;
            }
        }
    } else {
        result = false;
    }

    return result;
}

bool Function::isValidCharacters(const std::string& inputCharacters) {
    int length = inputCharacters.size();
    bool result = true;

    if (1 == length) {
        if (' ' == inputCharacters[0]) {
            result = false;
        }
    } else {
        result = false;
    }
    
    return result;
}

bool Function::isValidFill(const std::string& inputFill) {
    int length = inputFill.size();
    char fill;
    bool result = true;

    if (1 == length) {
        if (' ' == inputFill[0]) {
            result = false;
        }

        if (true == result) {
            fill = tolower(inputFill[0]);

            if (('y' != fill) && ('n' != fill)) {
                result = false;
            }
        }
    } else {
        result = false;
    }

    return result;
}
