#include "Function.hpp"
#include <iostream>

int main(void) {
    Status status = Status::SUCCESS;
    std::string radius;
    std::string characters;
    std::string fill;

    std::cout << "input radius : ";
    radius = Function::inputString();

    if (false == Function::isValidRadius(radius)) {
        std::cout << "not valid radius. valid radius is 5 to 20" << std::endl;
        status = Status::FAILURE;
    }

    if (Status::SUCCESS == status) {
        std::cout << "input characters : ";
        characters = Function::inputString();

        if (false == Function::isValidCharacters(characters)) {
            std::cout << "not valid value. valid value is only one character." << std::endl;
            status = Status::FAILURE;
        }
    }

    if (Status::SUCCESS == status) {
        std::cout << "input fill(y/n) : ";
        fill = Function::inputString();

        if (false == Function::isValidFill(fill)) {
            std::cout << "not valid value. valid value is only y and n." << std::endl;
            status = Status::FAILURE;
        }
    }

    if (Status::SUCCESS == status) {
        Function::drawRadius(radius, characters, fill);
    }

    return static_cast<int>(status);
}
