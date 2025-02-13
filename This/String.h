#pragma once
#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
    char* str;
    size_t size;
    size_t capacity;

public:
    String();
    String(size_t n);
    String(const char* input);
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    String operator+(const String& other) const;
    String& operator+=(const String& other);
    char operator[](size_t index) const;
    friend std::ostream& operator<<(std::ostream& os, const String& s);
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    bool operator>(const String& other) const;
    bool operator<(const String& other) const;

    void input();
    void output() const;

    size_t getSize() const;
    size_t getCapacity() const;
    void append(char c);
    void append(const String& str);
    void clear();
    void reserve(size_t newCapacity);
    void shrink();
};

#endif
