#include "PrimeNumbers.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    clock_t start, end;
    ExitStatus status = ExitStatus::SUCCESS;

    if (false == PrimeNumbers::isValidNumber(argc, argv)) {
        std::cout << "Usage : " << argv[0] << " <number1> <number2> <num...> ..." << std::endl;
        std::cout << "max number : '10,000,000,000' one set or '1,000,000,000' ten set" << std::endl;
        status = ExitStatus::FAILURE;
    }
    start = clock();
    if (ExitStatus::SUCCESS == status) {
        PrimeNumbers::primeThread(argc, argv);
    }
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC; 
    std::cout << "running time : " << time << " sec" << std::endl;
    return static_cast<int>(status);
}