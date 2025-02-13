#include "String.h"
#include "Array.h"
#include <iostream>
//
//int main() {
//    String str1("Hello");
//    String str2(" World!");
//    String str3 = str1 + str2;
//
//    std::cout << "Concatenation: " << str3 << std::endl;
//
//    str1 += str2;
//    std::cout << "After += : " << str1 << std::endl;
//
//    std::cout << "Char at index 1: " << str1[1] << std::endl;
//
//    if (str1 == str3) {
//        std::cout << "str1 and str3 are equal" << std::endl;
//    }
//    else {
//        std::cout << "str1 and str3 are not equal" << std::endl;
//    }
//
//    return 0;
//}

//#2
int main() {
    Array<int> arr(10, 1, 100);
    arr.display();

    arr.append(200);
    arr.append(300);
    arr.display();

    arr.remove(2);
    arr.display();

    std::cout << "Size after appending: " << arr.getSize() << std::endl;

    std::cout << "Min: " << arr.min() << std::endl;
    std::cout << "Max: " << arr.max() << std::endl;

    arr.sort();
    std::cout << "Sorted Array: ";
    arr.display();

    Array<int> arr2(5, 50);
    arr2.display();

    Array<int> combined = arr + arr2;
    std::cout << "Combined Array: ";
    combined.display();

    std::cout << "Is arr == arr2? " << (arr == arr2 ? "Yes" : "No") << std::endl;
    std::cout << "Is arr > arr2? " << (arr > arr2 ? "Yes" : "No") << std::endl;

    Array<int> intersected = arr * arr2;
    std::cout << "Intersected Array: ";
    intersected.display();

    arr.reserve(30);
    std::cout << "New capacity after reserve: " << arr.getCapacity() << std::endl;

    arr.shrink();
    std::cout << "New capacity after shrink: " << arr.getCapacity() << std::endl;

    return 0;
}




