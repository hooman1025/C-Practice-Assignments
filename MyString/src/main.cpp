#include "MyString.hpp"
#include <iostream>

int main(void) {
    std::cout << "Test 1. constructor ----------------------------------------------------" << std::endl;
    MyString str1("Hello World!");
    MyString str2('a');
    MyString str3(str1);
    MyString str4;

    std::cout << "str1 (char* constructor) : " << str1 << std::endl;
    std::cout << "str2 (char constructor) : " << str2 << std::endl;
    std::cout << "str3 (copy constructor) : " << str3 << std::endl;
    std::cout << "str4 (default constructor) : " << str4 << std::endl;
    std::cout << std::endl;


    std::cout << "Test 2. getLength(), size(), empty() -----------------------------------" << std::endl;
    std::cout << "str1 length() : " << str1.getLength() << std::endl;
    std::cout << "str2 size() : " << str2.size() << std::endl;
    std::cout << "str2 empty() : " << str2.empty() << std::endl;
    std::cout << "str4 size() : " << str4.size() << std::endl;
    std::cout << "str4 empty() : " << str4.empty() << std::endl;
    std::cout << std::endl;


    std::cout << "Test 3. getStr(), setStr() ---------------------------------------------" << std::endl;
    str4.setStr("abcde 123 456");
    char* str5 = str1.getStr();
    
    std::cout << "str4 setStr(abcde 123 456) : " << str4 << std::endl;
    std::cout << "str5 getStr(): " << str5 << std::endl;
    std::cout << std::endl;


    std::cout << "Test 4. front(), back() ------------------------------------------------" << std::endl;
    std::cout << "str1 front() : " << str1.front() << std::endl;
    std::cout << "str1 back(): " << str1.back() << std::endl;
    std::cout << std::endl;


    std::cout << "Test 5. begin(), end() --------------------------------------------------" << std::endl;
    std::cout << "str1 begin() + 3 : " << *(str1.begin() + 3) << std::endl;
    std::cout << "str1 end() - 2 : " << *(str1.end() - 2) << std::endl;
    std::cout << std::endl;


    std::cout << "Test 6. print(), println() ----------------------------------------------" << std::endl;
    str1.print();
    str4.println();
    std::cout << std::endl;


    std::cout << "Test 7. clear() ---------------------------------------------------------" << std::endl;
    std::cout << "str3 : " << str3 << std::endl; 
    str3.clear();
    std::cout << "str3 clear() : " << str3 << std::endl; 
    std::cout << std::endl;


    std::cout << "Test 8. insert() --------------------------------------------------------" << std::endl;
    std::cout << "str1 : " << str1 << std::endl; 
    str1.insert(6, "C++ ");
    std::cout << "str1 insert(6, C++ ) : " << str1 << std::endl; 
    std::cout << std::endl;


    std::cout << "Test 9. at() ------------------------------------------------------------" << std::endl;
    std::cout << "str1 at(4) : " << str1.at(4) << std::endl;
    std::cout << std::endl;


    std::cout << "Test 10. reverse() ------------------------------------------------------" << std::endl;
    std::cout << "str1 : " << str1 << std::endl;
    std::cout << "str1 reverse() : " << str1.reverse() << std::endl;
    std::cout << "str1 reverse() : " << str1.reverse() << std::endl;
    std::cout << std::endl;


    std::cout << "Test 11. append() -------------------------------------------------------" << std::endl;
    str3 = str1;
    std::cout << str3 << std::endl;
    str3.append(str4);
    std::cout << "str3 append(str4) : " << str3 << std::endl;
    std::cout << std::endl;


    std::cout << "Test 12. find() ---------------------------------------------------------" << std::endl;
    size_t position = str1.find("World");
    std::cout << "str1 : " << str1 << std::endl;
    std::cout << "str1 find(World) position : " << position << std::endl;
    std::cout << std::endl;


    std::cout << "Test 13. replace() -----------------------------------------------------" << std::endl;
    std::cout << "str1 : " << str1 << std::endl;
    str1.replace(6, 3, "Class");
    std::cout << "str1 replace(6, 3, Class) : " << str1 << std::endl;
    str1.replace(0, 5, "Hello!, Bye!", 3, 8);
    std::cout << "str1 replace(0, 5, Hello!, Bye!, 3, 8) : " << str1 << std::endl;
    std::cout << std::endl;


    std::cout << "Test 14. erase() ------------------------------------------------------" << std::endl;
    std::cout << "str1 : " << str1 << std::endl;
    str1.erase(4, 6);
    std::cout << "str1 erase(4, 6) : " << str1 << std::endl;
    std::cout << std::endl;


    std::cout << "Test 15. compare() ----------------------------------------------------" << std::endl;
    str2 = str1;
    str3 = "World";
    std::cout << "str1 : " << str1 << std::endl;
    std::cout << "str2 : " << str2 << std::endl;
    std::cout << "str3 : " << str3 << std::endl;
    std::cout << "str1.compare(str2) : " << str1.compare(str2) << std::endl;
    std::cout << "str1.compare(str3) : " << str1.compare(str3) << std::endl;
    std::cout << "str1.compare(10, 5, str3) : " << str1.compare(4, 5, str3) << std::endl;
    std::cout << std::endl;


    std::cout << "Test 16. substr() -----------------------------------------------------" << std::endl;
    std::cout << "str1 : " << str1 << std::endl;
    std::cout << "str1.substr(4, 5) : " << str1.substr(4, 5) << std::endl;
    std::cout << std::endl;

    
    std::cout << "Test 17. assign() -----------------------------------------------------" << std::endl;
    std::cout << "str1 assign(Goodbye! World!, 7) : " << str1.assign("Goodbye! World!", 7) << std::endl;
    std::cout << std::endl;


    std::cout << "Test 18. copy() -------------------------------------------------------" << std::endl;
    std::cout << "str1 : " << str1 << std::endl;
    std::cout << "str2 : " << str2 << std::endl;
    std::cout << "str1 copy(str2, 4) -> copied characters : " << str1.copy(str2, 4) << std::endl;
    std::cout << "str2 : " << str2 << std::endl;
    std::cout << std::endl;


    std::cout << "Test 19. mySwap() -----------------------------------------------------" << std::endl;
    std::cout << "str1 : " << str1 << std::endl;
    std::cout << "str3 : " << str3 << std::endl;
    str1.mySwap(str3);
    std::cout << "str1 mySwap(str3) : " << str1 << std::endl;
    std::cout << "str3 : " << str3 << std::endl;
    std::cout << std::endl;


    std::cout << "Test 20. myMove() -----------------------------------------------------" << std::endl;
    std::cout << "str1 : " << str1 << std::endl;
    std::cout << "str3 : " << str3 << std::endl;
    str1.myMove(str3);
    std::cout << "str1 myMove(str3) : " << str1 << std::endl;
    std::cout << "str3 : " << str3 << std::endl;
    std::cout << std::endl;


    std::cout << "Test 21. operators -----------------------------------------------------" << std::endl;
    str1.clear();
    str2.clear();

    std::cout << "input str1 : ";
    std::cin >> str1;
    std::cout << "str1 operator>>, << : " << str1 << std::endl;

    str2 = str1;
    std::cout << "str2 operator= : " << str2 << std::endl;

    str1 += str2;
    std::cout << "str1 operator+= : " << str1 << std::endl;

    if (str1 == str2) {
        std::cout << "str1 == str2 is true." << std::endl;
    } else {
        std::cout << "str1 == str2 is false." << std::endl;
    }

    if (str1 != str2) {
        std::cout << "str1 != str2 is true." << std::endl;
    } else {
        std::cout << "str1 != str2 is false." << std::endl;
    }
    
    return 0;
}