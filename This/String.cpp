#include "String.h"
#include <iostream>

String::String() : size(80) {
    this->str = new char[this->size + 1];
    this->str[0] = '\0';
}

String::String(size_t n) : size(n) {
    this->str = new char[this->size + 1];
    this->str[0] = '\0';
}

String::String(const char* input) {
    this->size = 0;
    while (input[this->size] != '\0') {
        ++this->size;
    }
    this->str = new char[this->size + 1];
    for (size_t i = 0; i <= this->size; ++i) {
        this->str[i] = input[i];
    }
}

String::String(const String& other) : size(other.size) {
    this->str = new char[this->size + 1];
    for (size_t i = 0; i <= this->size; ++i) {
        this->str[i] = other.str[i];
    }
}

String::~String() {
    delete[] this->str;
}

void String::input() {
    std::cout << "enter a string: ";
    char buffer[1000];
    std::cin.getline(buffer, 1000);
    this->size = 0;
    while (buffer[this->size] != '\0') {
        ++this->size;
    }
    delete[] this->str;
    this->str = new char[this->size + 1];
    for (size_t i = 0; i <= this->size; ++i) {
        this->str[i] = buffer[i];
    }
}

void String::output() const {
    std::cout << "String: " << this->str << std::endl;
}
