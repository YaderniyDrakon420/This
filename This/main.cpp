#include "String.h"
#include "Array.h"
#include <iostream>

//#1
//int main() {
//    String str1;
//    String str2(50);
//    String str3("Hello World!");
//
//    str1.output();
//    str2.output();
//    str3.output();
//
//    str2.input();
//    str2.output();
//
//    String str4 = str3;
//    str4.output();
//
//    return 0;
//}
//#2

int main() {
    Array<int> arr1(5, 1, 100);

    std::cout << "Initial array: ";
    arr1.display();

    arr1.append(42);
    std::cout << "Array after appending 42: ";
    arr1.display();

    return 0;
}

