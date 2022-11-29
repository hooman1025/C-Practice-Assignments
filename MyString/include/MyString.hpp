#ifndef __MYSTRING_HPP__
#define __MYSTRING_HPP__

#include <cstddef>
#include <ostream>

class MyString {
private:
    size_t length = 0;
    char* pstr = nullptr;
    
public:
    static const size_t npos = -1;

    MyString();
    explicit MyString(const char& c);
    explicit MyString(const char* inputPstr);
    MyString(const MyString& inputPstr);
    ~MyString();

    char* getStr(void) const;
    void setStr(const MyString& inputPstr);
    size_t getLength(void) const;

    friend std::ostream& operator<<(std::ostream& out, const MyString& inputPstr);
    friend std::istream& operator>>(std::istream& in, MyString& inputPstr);
    MyString& operator=(const MyString& inputPstr);
    MyString& operator=(const char* inputPstr);
    MyString& operator+(const MyString& inputPstr);
    MyString& operator+(const char* inputPstr);
    MyString& operator+=(const MyString& inputPstr);
    MyString& operator+=(const char* inputPstr);
    bool operator==(const MyString& inputPstr);
    bool operator==(const char* inputPstr);
    bool operator!=(const MyString& inputPstr);
    bool operator!=(const char* inputPstr);

    const size_t size(void) const;
    const bool empty(void) const;
    const char front(void) const;
    const char back(void) const;
    const char* begin(void) const;
    const char* end(void) const;

    void print(void) const;
    void println(void) const;

    void clear(void);

    void insert(const size_t pos, const MyString& inputPstr);
    void insert(const size_t pos, const char* inputPstr);
    void insert(const size_t pos, const char& c);

    const char at(const size_t pos) const;

    const char* reverse(void);

    void append(const MyString& inputPstr);
    void append(const char* inputPstr);

    const size_t find(const MyString& inputPstr);
    const size_t find(const char* inputPstr);
    const size_t find(const char& c);

    void replace(const size_t pos, const size_t len, const MyString& inputPstr);
    void replace(const size_t pos, const size_t len, const MyString& inputPstr, const size_t strLen, const size_t strPos = 0);
    void replace(const size_t pos, const size_t len, const char* inputPstr);
    void replace(const size_t pos, const size_t len, const char* inputPstr, const size_t strLen, const size_t strPos = 0);
    void replace(const size_t pos, const size_t len, const size_t inputCnt, const char& c);

    void erase(const size_t pos, const size_t len = npos);
    void erase(const char* pos, const char* end);

    const int compare(const MyString& inputPstr);
    const int compare(const char* inputPstr);
    const int compare(const size_t pos, const size_t len, const MyString& inputPstr);
    const int compare(const size_t pos, const size_t len, const char* inputPstr);
    
    const MyString substr(const size_t pos = 0, const size_t len = npos) const;

    const char* assign(const size_t len, const char& c);
    const char* assign(const MyString& inputPstr, const size_t len = npos, const size_t pos = 0);
    const char* assign(const char* inputPstr, const size_t len = npos, const size_t pos = 0);

    const size_t copy(MyString& inputPstr, size_t len = npos, size_t pos = 0);
    const size_t copy(char* inputPstr, size_t len = npos, size_t pos = 0);

    void mySwap(MyString& inputPstr);

    void myMove(MyString& inputPstr);
};

const int myStrlen(const char* inputPstr);

#endif  // __MYSTRING_HPP__
