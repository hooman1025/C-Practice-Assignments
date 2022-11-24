#include "MyString.hpp"
#include <iostream>
#include <memory>

MyString::MyString() {
    length = 1;
    std::unique_ptr<char[]> newPstr(new char[length]());

    newPstr[0] = '\0';

    pstr = move(newPstr);
}

MyString::MyString(const char &c) {
    length = 2;
    std::unique_ptr<char[]> newPstr(new char[length]());

    newPstr[0] = c;
    newPstr[1] = '\0';

    pstr = move(newPstr);
}

MyString::MyString(const char *inputPstr) {
    length = myStrlen(inputPstr);
    std::unique_ptr<char[]> newPstr(new char[length]());

    for (int index = 0; index < length; ++index) {
        newPstr[index] = inputPstr[index];
    }

    newPstr[length] = '\0';
    pstr = move(newPstr);
}

MyString::MyString(const MyString &inputPstr) {
    length = myStrlen(inputPstr.pstr.get());
    std::unique_ptr<char[]> newPstr(new char[length]());

    for (int index = 0; index < length; ++index) {
        newPstr[index] = inputPstr.pstr[index];
    }

    newPstr[length] = '\0';
    pstr = move(newPstr);
}

MyString::~MyString() {
}

char* MyString::getStr(void) const {
    return pstr.get();
}

void MyString::setStr(const MyString &inputPstr) {
    length = myStrlen(inputPstr.pstr.get());
    std::unique_ptr<char[]> newPstr(new char[length]());

    for (int index = 0; index < length; ++index) {
        newPstr[index] = inputPstr.pstr[index];
    }

    newPstr[length] = '\0';
    pstr = move(newPstr);
}

size_t MyString::getLength(void) const {
    return length;
}

const size_t MyString::size(void) const {
    return myStrlen(pstr.get());
}

const bool MyString::empty(void) const {
    return ('\0' == pstr[0]) ? true : false;
}

const char MyString::front(void) const {
    return pstr[0];
}

const char MyString::back(void) const {
    return pstr[length - 1];
}

const char* MyString::begin(void) const {
    return &pstr[0];
}

const char* MyString::end(void) const {
    return &pstr[length];
}

std::ostream &operator<<(std::ostream &out, const MyString &inputPstr) {
    out << inputPstr.pstr.get();

    return out;
}

std::istream &operator>>(std::istream &in, MyString &inputPstr) {
    in >> inputPstr.pstr.get();

    inputPstr.length = myStrlen(inputPstr.pstr.get());

    return in;
}

MyString &MyString::operator=(const MyString &inputPstr) {
    length = myStrlen(inputPstr.pstr.get());
    std::unique_ptr<char[]> newPstr(new char[length]());
    
    for (int index = 0; index < length; ++index) {
        newPstr[index] = inputPstr.pstr[index];
    }
    
    newPstr[length] = '\0';
    
    pstr = move(newPstr);

    return *this;
}

MyString &MyString::operator=(const char *inputPstr) {
    length = myStrlen(inputPstr);
    std::unique_ptr<char[]> newPstr(new char[length]());

    for (int index = 0; index < length; ++index) {
        newPstr[index] = inputPstr[index];
    }

    newPstr[length] = '\0';

    pstr = move(newPstr);

    return *this;
}

MyString &MyString::operator+(const MyString &inputPstr) {
    size_t tmpLength = length + inputPstr.length;
    std::unique_ptr<char[]> newPstr(new char[tmpLength]());

    for (int index = 0; index < tmpLength; ++index) {
        if (index < length) {
            newPstr[index] = pstr[index];
        } else {
            newPstr[index] = inputPstr.pstr[index - length];
        }
    }

    newPstr[tmpLength] = '\0';

    length = tmpLength;
    pstr = move(newPstr);

    return *this;
}

MyString &MyString::operator+(const char *inputPstr) {
    size_t tmpLength = length + myStrlen(inputPstr);
    std::unique_ptr<char[]> newPstr(new char[tmpLength]());

    for (int index = 0; index < tmpLength; ++index) {
        if (index < length) {
            newPstr[index] = pstr[index];
        } else {
            newPstr[index] = inputPstr[index - length];
        }
    }

    newPstr[tmpLength] = '\0';

    length = tmpLength;
    pstr = move(newPstr);

    return *this;
}

MyString &MyString::operator+=(const MyString &inputPstr) {
    size_t tmpLength = length + inputPstr.length;
    std::unique_ptr<char[]> newPstr(new char[tmpLength]());

    for (int index = 0; index < tmpLength; ++index) {
        if (index < length) {
            newPstr[index] = pstr[index];
        } else {
            newPstr[index] = inputPstr.pstr[index - length];
        }
    }

    newPstr[tmpLength] = '\0';

    length = tmpLength;
    pstr = move(newPstr);

    return *this;
}

MyString &MyString::operator+=(const char *inputPstr) {
    size_t tmpLength = length + myStrlen(inputPstr);
    std::unique_ptr<char[]> newPstr(new char[tmpLength]());

    for (int index = 0; index < tmpLength; ++index) {
        if (index < length) {
            newPstr[index] = pstr[index];
        } else {
            newPstr[index] = inputPstr[index - length];
        }
    }

    newPstr[tmpLength] = '\0';

    length = tmpLength;
    pstr = move(newPstr);

    return *this;
}

bool MyString::operator==(const MyString &inputPstr) {
    return (0 == compare(inputPstr)) ? true : false;
}

bool MyString::operator==(const char *inputPstr) {
    return (0 == compare(inputPstr)) ? true : false;
}

bool MyString::operator!=(const MyString &inputPstr) {
    return (0 == compare(inputPstr)) ? false : true;
}

bool MyString::operator!=(const char *inputPstr) {
    return (0 == compare(inputPstr)) ? false : true;
}

void MyString::print(void) const {
    for (int index = 0; index < length; ++index) {
        std::cout << pstr[index];
    }
}

void MyString::println(void) const {
    for (int index = 0; index < length; ++index) {
        std::cout << pstr[index];
    }

    std::cout << std::endl;
}

void MyString::clear(void) {
    length = 1;
    std::unique_ptr<char[]> newPstr(new char[length]());

    newPstr[0] = '\0';
    
    pstr = move(newPstr);
}

void MyString::insert(const size_t pos, const MyString &inputPstr) {
    size_t inputLength = myStrlen(inputPstr.pstr.get());
    size_t tmpLength = length + inputLength;

    if (pos <= tmpLength) {
        std::unique_ptr<char[]> newPstr(new char[tmpLength]());

        for (int index = 0; index < tmpLength; ++index) {
            if (index < pos) {
                newPstr[index] = pstr[index];
            } else if (index >= pos && index < inputLength + pos) {
                newPstr[index] = inputPstr.pstr[index - pos];
            } else {
                newPstr[index] = pstr[index - inputLength];
            }
        }

        newPstr[tmpLength] = '\0';
        length = tmpLength;
        pstr = move(newPstr);
    }
}

void MyString::insert(const size_t pos, const char *inputPstr) {
    size_t inputLength = myStrlen(inputPstr);
    size_t tmpLength = length + inputLength;

    if (pos <= tmpLength) {
        std::unique_ptr<char[]> newPstr(new char[length]());

        for (int index = 0; index < tmpLength; ++index) {
            if (index < pos) {
                newPstr[index] = pstr[index];
            } else if (index >= pos && index < inputLength + pos) {
                newPstr[index] = inputPstr[index - pos];
            } else {
                newPstr[index] = pstr[index - inputLength];
            }
        }

        newPstr[tmpLength] = '\0';
        length = tmpLength;
        pstr = move(newPstr);
    }
}

void MyString::insert(const size_t pos, const char &c) {
    size_t inputLength = 1;
    size_t tmpLength = length + inputLength;

    if (pos <= tmpLength) {
        std::unique_ptr<char[]> newPstr(new char[length]());

        for (int index = 0; index < tmpLength; ++index) {
            if (index < pos) {
                newPstr[index] = pstr[index];
            } else if (index >= pos && index < inputLength + pos) {
                newPstr[index] = c;
            } else {
                newPstr[index] = pstr[index - inputLength];
            }
        }

        newPstr[tmpLength] = '\0';
        length = tmpLength;
        pstr = move(newPstr);
    }
}

const char MyString::at(const size_t pos) const {
    const char retChar = (pos >= length) ? '\0' : *(pstr.get() + pos);

    return retChar;
}

const char* MyString::reverse(void) {
    std::unique_ptr<char[]> newPstr(new char[length]());

    for (int index = 0; index < length; ++index) {
        newPstr[index] = pstr[(length - 1) - index];
    }

    newPstr[length] = '\0';

    pstr = move(newPstr);

    return pstr.get();
}

void MyString::append(const MyString &inputPstr) {
    size_t tmpLength = length + inputPstr.length;
    std::unique_ptr<char[]> newPstr(new char[tmpLength]());

    for (int index = 0; index < tmpLength; ++index) {
        if (index < length) {
            newPstr[index] = pstr[index];
        } else {
            newPstr[index] = inputPstr.pstr[index - length];
        }
    }

    newPstr[tmpLength] = '\0';

    length = tmpLength;
    pstr = move(newPstr);
}

void MyString::append(const char *inputPstr) {
    size_t tmpLength = length + myStrlen(inputPstr);
    std::unique_ptr<char[]> newPstr(new char[tmpLength]());

    for (int index = 0; index < tmpLength; ++index) {
        if (index < length) {
            newPstr[index] = pstr[index];
        } else {
            newPstr[index] = inputPstr[index - length];
        }
    }

    newPstr[tmpLength] = '\0';

    length = tmpLength;
    pstr = move(newPstr);
}

const size_t MyString::find(const MyString &inputPstr) {
    size_t pos = length;

    for (int index = 0; index < length; ++index) {
        if (pstr[index] == inputPstr.pstr[0]) {
            if (0 == compare(index, inputPstr.length, inputPstr)) {
                pos = index;
                break;
            }
        }
    }

    return pos;
}

const size_t MyString::find(const char *inputPstr) {
    size_t inputLength = myStrlen(inputPstr);
    size_t pos = length;

    for (int index = 0; index < length; ++index) {
        if (pstr[index] == inputPstr[0]) {
            if (0 == compare(index, inputLength, inputPstr)) {
                pos = index;
                break;
            }
        }
    }

    return pos;
}

const size_t MyString::find(const char &c) {
    size_t pos = length;

    for (int index = 0; index < length; ++index) {
        if (pstr[index] == c) {
            if (0 == compare(index, 1, c)) {
                pos = index;
                break;
            }
        }
    }

    return pos;
}

void MyString::replace(const size_t pos, const size_t len, const MyString &inputPstr) {
    erase(pos, len);
    insert(pos, inputPstr.pstr.get());
}

void MyString::replace(const size_t pos, const size_t len, const MyString &inputPstr, const size_t strLen, const size_t strPos) {
    erase(pos, len);
    insert(pos, inputPstr.substr(strPos, strLen));
}

void MyString::replace(const size_t pos, const size_t len, const char *inputPstr) {
    erase(pos, len);
    insert(pos, inputPstr);
}

void MyString::replace(const size_t pos, const size_t len, const char *inputPstr, const size_t strLen, const size_t strPos) {
    MyString str = inputPstr;

    erase(pos, len);
    insert(pos, str.substr(strPos, strLen));
}

void MyString::replace(const size_t pos, const size_t len, const size_t inputCnt, const char &c) {
    size_t cnt = 0;

    erase(pos, len);

    while(inputCnt > cnt) {
        insert(pos, c);
        ++cnt;
    }
}

void MyString::erase(const size_t pos, const size_t len) {
    size_t inputLength = (npos == len) ? length : len;

    if (pos < length) {
        std::unique_ptr<char[]> newPstr(new char[length]());

        for (int index = 0; index < length; ++index) {
            if (index < pos) {
                newPstr[index] = pstr[index];
            } else if (index >= inputLength + pos) {
                newPstr[index - inputLength] = pstr[index];
            }
        }

        length = myStrlen(newPstr.get());
        pstr = move(newPstr);
    }
}

void MyString::erase(const char* start, const char* end) {
    int pos = find(start);
    int len = find(end) - pos;

    if (pos < length && len + pos < length) {
        std::unique_ptr<char[]> newPstr(new char[length]());

        for (int index = 0; index < length; ++index) {
            if (index < pos) {
                newPstr[index] = pstr[index];
            } else if (index >= len + pos) {
                newPstr[index - len] = pstr[index];
            }
        }

        length = myStrlen(newPstr.get());
        pstr = move(newPstr);
    }
}

const int MyString::compare(const MyString &inputPstr) {
    size_t firstLength = myStrlen(pstr.get());
    size_t secondLength = myStrlen(inputPstr.pstr.get());
    int result = 0;

    if (firstLength == secondLength) {
        for (int index = 0; index < firstLength; ++index) {
            if (pstr[index] > inputPstr.pstr[index]) {
                result = 1;
                break;
            } else if (pstr[index] < inputPstr.pstr[index]) {
                result = -1;
                break;
            }
        }
    } else {
        if (firstLength > secondLength) {
            result = 1;
        } else {
            result = -1;
        }
    }

    return result;
}

const int MyString::compare(const char *inputPstr) {
    size_t firstLength = myStrlen(pstr.get());
    size_t secondLength = myStrlen(inputPstr);
    int result = 0;

    if (firstLength == secondLength) {
        for (int index = 0; index < firstLength; ++index) {
            if (pstr[index] > inputPstr[index]) {
                result = 1;
                break;
            } else if (pstr[index] < inputPstr[index]) {
                result = -1;
                break;
            }
        }
    } else {
        if (firstLength > secondLength) {
            result = 1;
        } else {
            result = -1;
        }
    }

    return result;
}

const int MyString::compare(size_t pos, size_t len, const MyString &inputPstr) {
    size_t firstLength = myStrlen(pstr.get());
    size_t secondLength = myStrlen(inputPstr.pstr.get());
    int result = 0;

    for (int index = 0; index < len; ++index) {
        if (pstr[index + pos] > inputPstr.pstr[index]) {
            result = 1;
            break;
        } else if (pstr[index + pos] < inputPstr.pstr[index]) {
            result = -1;
            break;
        }
    } 

    return result;
}

const int MyString::compare(size_t pos, size_t len, const char *inputPstr) {
    size_t firstLength = myStrlen(pstr.get());
    size_t secondLength = myStrlen(inputPstr);
    int result = 0;

    for (int index = 0; index < len; ++index) {
        if (pstr[index + pos] > inputPstr[index]) {
            result = 1;
            break;
        } else if (pstr[index + pos] < inputPstr[index]) {
            result = -1;
            break;
        }
    } 

    return result;
}

const MyString MyString::substr(const size_t pos, const size_t len) const {
    MyString newStr;
    size_t inputLength = (npos == len) ? length : len;

    if (pos < length) {
        for (int index = 0; index < inputLength; ++index) {
            newStr.pstr[index] = pstr[pos + index];
        }
    }

    newStr.pstr[inputLength] = '\0';

    return newStr.pstr.get();
}

const char* MyString::assign(const size_t len, const char &c) {
    std::unique_ptr<char[]> newPstr(new char[length]());
    size_t cnt = 0;

    while(len > cnt) {
        newPstr[cnt] = c;
        ++cnt;
    }

    pstr = move(newPstr);
    length = myStrlen(pstr.get());

    return pstr.get();
}

const char* MyString::assign(const MyString &inputPstr, const size_t len, const size_t pos) {
    MyString str = inputPstr.substr(pos, len);

    pstr = move(str.pstr);
    length = myStrlen(pstr.get());

    return pstr.get();
}

const char* MyString::assign(const char *inputPstr, const size_t len, const size_t pos) {
    MyString str = inputPstr;

    str = str.substr(pos, len);
    pstr = move(str.pstr);
    length = myStrlen(pstr.get());

    return pstr.get();
}

const size_t MyString::copy(MyString &inputPstr, size_t len, size_t pos) {
    size_t inputLength = (npos == len) ? length : len;

    inputPstr.clear();
    inputPstr = substr(pos, inputLength);

    inputPstr.pstr[inputLength] = '\0';
    inputPstr.length = inputLength;

    return inputLength;
}

const size_t MyString::copy(char* inputPstr, size_t len, size_t pos) {
    size_t inputLength = (npos == len) ? length : len;
    MyString str = substr(pos, inputLength);

    for (int index = 0; index < inputLength; ++index) {
        inputPstr[index] = str.pstr[index];
    }

    inputPstr[inputLength] = '\0';

    return inputLength;
}

void MyString::mySwap(MyString &inputPstr) {
    pstr.swap(inputPstr.pstr);
    length = myStrlen(pstr.get());
    
    inputPstr.length = myStrlen(inputPstr.pstr.get());
}

void MyString::myMove(MyString &inputPstr) {
    pstr = move(inputPstr.pstr);
    length = myStrlen(pstr.get());

    inputPstr.clear();
}

const int myStrlen(const char *inputPstr) {
    int cnt = 0;
    int index = 0;

    while (inputPstr[index] != '\0') {
        ++cnt;
        ++index;
    }

    return cnt;
}
