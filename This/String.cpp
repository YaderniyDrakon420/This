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

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] this->str;
        this->size = other.size;
        this->str = new char[this->size + 1];
        for (size_t i = 0; i <= this->size; ++i) {
            this->str[i] = other.str[i];
        }
    }
    return *this;
}

String String::operator+(const String& other) const {
    size_t newSize = this->size + other.size;
    char* newStr = new char[newSize + 1];

    for (size_t i = 0; i < this->size; ++i) {
        newStr[i] = this->str[i];
    }
    for (size_t i = 0; i <= other.size; ++i) {
        newStr[this->size + i] = other.str[i];
    }

    String result(newStr);
    delete[] newStr;
    return result;
}

String& String::operator+=(const String& other) {
    size_t newSize = this->size + other.size;
    char* newStr = new char[newSize + 1];

    for (size_t i = 0; i < this->size; ++i) {
        newStr[i] = this->str[i];
    }
    for (size_t i = 0; i <= other.size; ++i) {
        newStr[this->size + i] = other.str[i];
    }

    delete[] this->str;
    this->str = newStr;
    this->size = newSize;
    return *this;
}

char String::operator[](size_t index) const {
    if (index >= this->size) {
        return '\0';
    }
    return this->str[index];
}

std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.str;
    return os;
}

bool String::operator==(const String& other) const {
    if (this->size != other.size) {
        return false;
    }
    for (size_t i = 0; i < this->size; ++i) {
        if (this->str[i] != other.str[i]) {
            return false;
        }
    }
    return true;
}

bool String::operator!=(const String& other) const {
    return !(*this == other);
}

bool String::operator>(const String& other) const {
    return this->size > other.size;
}

bool String::operator<(const String& other) const {
    return this->size < other.size;
}

void String::input() {
    std::cout << "Enter a string: ";
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
