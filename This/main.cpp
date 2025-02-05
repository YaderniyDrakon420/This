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
    Array<int> arr1(10, 1, 100);

    std::cout << "Initial array: ";
    arr1.display();

    arr1.sort();
    std::cout << "Sorted array: ";
    arr1.display();

    std::cout << "Min: " << arr1.min() << ", Max: " << arr1.max() << std::endl;

    arr1.resize(5);
    std::cout << "Resized array (5 elements): ";
    arr1.display();

    return 0;
}

