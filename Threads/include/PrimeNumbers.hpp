#ifndef __PRIMENUMBERS_HPP__
#define __PRIMENUMBERS_HPP__

#define LOGNUMBER index % 2
#define THREADNUMBER index - 1
#define MAXNUMBER 10000000000

enum class Arguement {
    NOARGUEMENT = 1,
    MINIMUNARGUEMENT,
    MAXARGUEMENT = 11
};

enum class ExitStatus {
    SUCCESS,
    FAILURE
};

class PrimeNumbers {
public:
    static void primeNumber(const char* inputNumber, int* presult);
    static void primeThread(const int argc, char* argv[]);
    static bool isValidNumber(const int argc, char* argv[]);
};

#endif  // __PRIMENUMBERS_HPP__
