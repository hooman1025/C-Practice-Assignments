#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include <string>
#include <vector>

enum class OperatorsNumber{
    ERROR = -1,
    AND,
    OR,
    XOR,
    NOR
};

class Function {
public:
    static std::string binaryCalculator(const std::string& inputFirstBinary, const std::string& inputSecondBinary, const OperatorsNumber inputOperatorFlag);
    static std::string inputString(void);
    static bool isValidBinary(const std::string& inputString);
    static OperatorsNumber convertOperator(std::string& inputOperator);
    static void pushBackBinary(const std::string& inputFirstBinary, std::vector<char>& firstBinary, const std::string& inputSecondBinary, std::vector<char>& secondBinary, size_t pushSize);
};

#endif //__FUNCTION_HPP__