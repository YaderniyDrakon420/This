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
    Array<int> arr1(3, 1);
    Array<int> arr2(3, 2);

    std::cout << "arr1: " << arr1 << std::endl;
    std::cout << "arr2: " << arr2 << std::endl;

    Array<int> arr3 = arr1;
    std::cout << "arr3 (after = arr1): " << arr3 << std::endl;

    Array<int> arr4 = arr1 + arr2;
    std::cout << "arr4 (arr1 + arr2): " << arr4 << std::endl;

    arr1 += arr2;
    std::cout << "arr1 after arr1 += arr2: " << arr1 << std::endl;

    std::cout << "Element arr1[1]: " << arr1[1] << std::endl;
    arr1[1] = 99;
    std::cout << "arr1 after changing arr1[1]: " << arr1 << std::endl;

    std::cout << "arr1 == arr2: " << (arr1 == arr2) << std::endl;

    std::cout << "arr1 != arr3: " << (arr1 != arr3) << std::endl;

    std::cout << "arr1 > arr2: " << (arr1 > arr2) << std::endl;
    std::cout << "arr1 < arr2: " << (arr1 < arr2) << std::endl;

    Array<int> arr5(5);
    arr5[0] = 1; arr5[1] = 2; arr5[2] = 3; arr5[3] = 4; arr5[4] = 5;
    Array<int> arr6(3);
    arr6[0] = 2; arr6[1] = 4; arr6[2] = 6;

    Array<int> arr7 = arr5 * arr6;
    std::cout << "arr7 (common elements of arr5 * arr6): " << arr7 << std::endl;

    return 0;
}



