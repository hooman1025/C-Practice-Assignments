#include "PrimeNumbers.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <memory>
#include <regex>

void PrimeNumbers::primeNumber(const char* inputNumber, int* presult) {
    int result = 0;
    int64_t number = atol(inputNumber);

    //std::unique_ptr<bool[]> prime(new bool[number + 1]());
    bool* prime = new bool[number + 1]();
    prime[0] = prime[1] = true;

    for (int64_t i = 2; i * i <= number; ++i) {
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
    delete[] prime;
}

void PrimeNumbers::primeThread(const int argc, char* argv[]) {
    std::vector<std::thread> workers;
    std::ofstream log1("log1.txt");
    std::ofstream log2("log2.txt");
    int result[argc] = {0};
    
    for (int index = 1; index < argc; ++index) {
        workers.push_back(std::thread(PrimeNumbers::primeNumber, argv[index], &result[THREADNUMBER]));
    }

    for (int index = 1; index < argc; ++index) {
        workers[THREADNUMBER].join();
    }

    for (int index = 1; index < argc; ++index) {
        if (1 == LOGNUMBER) {
            if (true == log1.is_open()) {
                log1 << "thread[" << index << "] finished. prime numbers between 0 and " << argv[index] << ": " << result[THREADNUMBER] << '\n';
            }
        } else {
            if (true == log2.is_open()) {
                log2 << "thread[" << index << "] finished. prime numbers between 0 and " << argv[index] << ": " << result[THREADNUMBER] << '\n';
            }
        }
    }
}

bool PrimeNumbers::isValidNumber(const int argc, char* argv[]) {
    int str_size;
    bool result = true;

    if ((int)Arguement::NOARGUEMENT != argc) {
        for (int i = 1; i < argc; ++i) {
            std::string str(argv[i]);
            str_size = str.size();

            if (false == std::regex_match(str, std::regex("[0-9]+"))) {
                result = false;
                break;
            }

            if (MAXNUMBER == stol(str) && ((int)Arguement::MINIMUNARGUEMENT == argc)) {
                continue;
            } else if (MAXNUMBER / 10 < stol(str) || ((int)Arguement::MAXARGUEMENT < argc)) {
                result = false;
                break;
            } 
        }
    } else {
        result = false;
    }

    return result;
}