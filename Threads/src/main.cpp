#include "PrimeNumbers.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    clock_t start, end;
    ExitStatus status = ExitStatus::SUCCESS;

    if (false == PrimeNumbers::isValidNumber(argc, argv)) {
        std::cout << "Usage : " << argv[0] << " <number1> <number2> <num...> ..." << std::endl; 
        status = ExitStatus::FAILURE;
    }

    if (ExitStatus::SUCCESS == status) {
        start = clock();
        PrimeNumbers::primeThread(argc, argv);
        end = clock();
    }
    double time = (double)(end - start) / CLOCKS_PER_SEC; 
    std::cout << "수행시간 : " << time << std::endl;
    return static_cast<int>(status);
}