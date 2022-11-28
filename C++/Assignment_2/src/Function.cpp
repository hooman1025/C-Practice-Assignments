#include "Function.hpp"
#include <iostream>
#include <vector>

std::string Function::input_number(void) {
    std::string input_num;

    getline(std::cin, input_num);

    return input_num;
}

int Function::decimal(const std::string& input_number) {
    std::vector<int> bin_num;
    uint64_t number = stoull(input_number);
    int element = 0;
    int dec_tmp = 1;
    int dec_num = 0;

    while (0 != number) {
        bin_num.push_back(number % 10);
        number /= 10;
    }

    for (; element < bin_num.size(); ++element) {
        dec_num += bin_num.at(element) * dec_tmp;
        dec_tmp *= 2;
    }

    return dec_num;
}

std::string Function::hexadecimal(const std::string& input_number) {
    std::vector<char> hex_value = {'0', '1', '2', '3',
                                   '4', '5', '6', '7',
                                   '8', '9', 'A', 'B',
                                   'C', 'D', 'E', 'F'};
    std::vector<char> bin_num;
    std::string hex_num = "0x";
    uint64_t dec_num;
    int hex_tmp;

    dec_num = Function::decimal(input_number);

    if (0 != dec_num) {
        while (0 != dec_num) {
            hex_tmp = dec_num % 16;
            bin_num.insert(bin_num.begin(), hex_value.at(hex_tmp));
            dec_num /= 16;
        }

        for (int index = 0; index < bin_num.size(); ++index) {
            hex_num.push_back(bin_num.at(index));
        }
    } else {
        hex_num.push_back('0');
    }

    return hex_num;
}

bool Function::is_valid_number(const std::string& number) {
    int length = number.size();
    bool result = true;

    if (0 >= length || 20 < length) {
        result = false;
    } else {
        for (int index = 0; index < length; ++index) {
            if (' ' == number[index] || ('1' != number[index] && '0' != number[index])) {
                result = false;
            }
        }
    }

    return result;
}