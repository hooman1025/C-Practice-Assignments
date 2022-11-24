#include "PrimeNumbers.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <memory>
#include <cmath>
#include <cstring>
#include <cstdint>

void PrimeNumbers::primeNumber(const char* inputNumber, int* presult) {
    int64_t result = 0;
    int64_t number = atol(inputNumber);

    std::unique_ptr<bool[]> prime(new bool[number + 1]());
    prime[0] = prime[1] = true;
    
    for (int64_t i = 2; i <= sqrt(number); ++i) {
        if (false == prime[i]) {
            for(int64_t j = i * i; j <= number; j += i) {
                prime[j] = true;
            }
        }
    }

    for (int64_t i = 2; i <= number; ++i) {
        if (false == prime[i]) {
            ++result;
        }
    }

    *presult = result;
}

void PrimeNumbers::primeThread(const int argc, char* argv[]) {
    std::vector<std::thread> workers;
    std::ofstream log1("log1.txt");
    std::ofstream log2("log2.txt");
    int result[argc] = {0};
    
    for (int i = 0; i < argc; ++i) {
        workers.push_back(std::thread(PrimeNumbers::primeNumber, argv[i], &result[i]));
    }

    for (int i = 0; i < argc; ++i) {
        workers[i].join();
    }

    for (int i = 1; i < argc; ++i) {
        if (1 == LOGNUMBER) {
            if (true == log1.is_open()) {
                log1 << "thread[" << i << "] finished. prime numbers between 0 and " << argv[i] << ": " << result[i] << '\n';
            }
        } else {
            if (true == log2.is_open()) {
                log2 << "thread[" << i << "] finished. prime numbers between 0 and " << argv[i] << ": " << result[i] << '\n';
            }
        }
    }
}

bool PrimeNumbers::isValidNumber(const int argc, char* argv[]) {
    size_t str_size;
    bool result = true;

    if (1 != argc) {
        for (int i = 1; i < argc; ++i) {
            str_size = strlen(argv[i]);
            if (10 < str_size) {
                result = false;
                break;
            }

            for (int j = 0; j < str_size; ++j) {
                if ((' ' == argv[i][j]) || (('0' > argv[i][j]) || ('9' < argv[i][j]))) {
                    result = false;
                    break;
                }
            }

            if (false == result) {
                break;
            }
        }
    } else {
        result = false;
    }

    return result;
}