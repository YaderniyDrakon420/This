#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
private:
    int* data;
    size_t size;

public:
    Array(size_t n = 0);
    Array(size_t n, int min, int max);
    Array(size_t n, int value);
    Array(const Array& other);
    ~Array();

    void display() const;
    void fillRandom(int min, int max);
    void resize(size_t newSize);
    void sort();
    int min() const;
    int max() const;
};

#endif 
