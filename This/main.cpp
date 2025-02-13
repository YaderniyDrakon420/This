#include "String.h"
#include "Array.h"
#include <iostream>

int main() {
    String str1("Hello");
    String str2(" World!");
    String str3 = str1 + str2;

    std::cout << "Concatenation: " << str3 << std::endl;

    str1 += str2;
    std::cout << "After += : " << str1 << std::endl;

    std::cout << "Char at index 1: " << str1[1] << std::endl;

    if (str1 == str3) {
        std::cout << "str1 and str3 are equal" << std::endl;
    }
    else {
        std::cout << "str1 and str3 are not equal" << std::endl;
    }

    return 0;
}

//#2

//
//
//int main() {
//    Array<int> arr(5, 10);
//    arr.display();
//
//    arr.append(20);
//    arr.display();
//
//    arr.remove(2);  
//    arr.display();
//
//    return 0;
//}
//
