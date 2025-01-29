#pragma once
#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
    char* str;   
    size_t size; 

public:
    String();

    String(size_t n);

    String(const char* input);

    String(const String& other);

    ~String();

    void input();

    void output() const;
};

#endif 
