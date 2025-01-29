#include "String.h"
#include <iostream>

int main() {
    String str1;
    String str2(50);
    String str3("Hello World!");

    str1.output();
    str2.output();
    str3.output();

    str2.input();
    str2.output();

    String str4 = str3;
    str4.output();

    return 0;
}
