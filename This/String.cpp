#include "String.h"
#include <iostream>

String::String() : size(0), capacity(80) {
    this->str = new char[this->capacity + 1];
    this->str[0] = '\0';
}

String::String(size_t n) : size(0), capacity(n) {
    this->str = new char[this->capacity + 1];
    this->str[0] = '\0';
}

String::String(const char* input) : size(0), capacity(0) {
    while (input[size] != '\0') {
        ++size;
    }
    capacity = size + 80;  
    this->str = new char[capacity + 1];
    for (size_t i = 0; i <= size; ++i) {
        this->str[i] = input[i];
    }
}

String::String(const String& other) : size(other.size), capacity(other.capacity) {
    this->str = new char[this->capacity + 1];
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
        this->capacity = other.capacity;
        this->str = new char[this->capacity + 1];
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
    if (newSize > this->capacity) {
        reserve(newSize + 80);  
    }

    for (size_t i = 0; i <= other.size; ++i) {
        this->str[this->size + i] = other.str[i];
    }
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

    if (this->size > this->capacity) {
        reserve(this->size + 80);
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

size_t String::getSize() const {
    return this->size;
}

size_t String::getCapacity() const {
    return this->capacity;
}

void String::append(char c) {
    if (this->size + 1 > this->capacity) {
        reserve(this->capacity + 80);
    }
    this->str[this->size] = c;
    this->str[this->size + 1] = '\0';
    ++this->size;
}

void String::append(const String& str) {
    if (this->size + str.size > this->capacity) {
        reserve(this->capacity + str.size + 80);
    }
    for (size_t i = 0; i <= str.size; ++i) {
        this->str[this->size + i] = str.str[i];
    }
    this->size += str.size;
}

void String::clear() {
    delete[] this->str;
    this->size = 0;
    this->capacity = 80;
    this->str = new char[this->capacity + 1];
    this->str[0] = '\0';
}

void String::reserve(size_t newCapacity) {
    if (newCapacity > this->capacity) {
        char* newStr = new char[newCapacity + 1];
        for (size_t i = 0; i <= this->size; ++i) {
            newStr[i] = this->str[i];
        }
        delete[] this->str;
        this->str = newStr;
        this->capacity = newCapacity;
    }
}

void String::shrink() {
    if (this->size < this->capacity) {
        char* newStr = new char[this->size + 1];
        for (size_t i = 0; i <= this->size; ++i) {
            newStr[i] = this->str[i];
        }
        delete[] this->str;
        this->str = newStr;
        this->capacity = this->size;
    }
}
