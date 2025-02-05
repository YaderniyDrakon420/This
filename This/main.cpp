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
    Array<int> arr(5, 10);
    arr.display();

    arr.append(20);
    arr.display();

    arr.remove(2);  
    arr.display();

    return 0;
}

