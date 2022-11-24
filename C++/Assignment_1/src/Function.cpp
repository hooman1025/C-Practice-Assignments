#include "Function.hpp"
#include <iostream>

int64_t Function::input_number(void) {
    int64_t num;

    std::cin >> num;

    return num;
}

uint64_t Function::factorial_rec(const uint64_t num) {
    uint64_t fac_num = num;

    if (1 >= num) {
        fac_num = 1;
    } else {
        fac_num = num * factorial_rec(num - 1);
    }
    
    return fac_num;
}

uint64_t Function::factorial_wo(const uint64_t num) {
    uint64_t fac_num = num;
    uint64_t orig_num = num;

    if (1 >= orig_num) {
        fac_num = 1;
    } else {
        while (1 != orig_num) {
            fac_num *= orig_num - 1;
            orig_num--;
        }
    }

    return fac_num;
}

bool Function::is_valid_number(const int64_t num) {
    bool result = true;

    if (0 > num || 20 < num) {
        result = false;
    }

    return result;
}
