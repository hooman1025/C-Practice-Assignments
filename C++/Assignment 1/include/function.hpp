#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include <cstdint>

class Function {
public:
    static int64_t input_number(void);
    static uint64_t factorial_rec(const uint64_t num);
    static uint64_t factorial_wo(const uint64_t num);
    static bool is_valid_number(const int64_t num);
};

#endif //__FUNCTION_HPP__