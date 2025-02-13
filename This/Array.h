#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array {
private:
    T* data;
    size_t size;
    size_t capacity;  

public:
    Array(size_t n = 0);
    Array(size_t n, T min, T max);
    Array(size_t n, T value);
    Array(const Array& other);
    ~Array();

    void display() const;
    void fillRandom(T min, T max);
    void resize(size_t newSize);
    void sort();
    T min() const;
    T max() const;
    void append(T value);
    void remove(size_t index);
    void clear();

    void reserve(size_t newCapacity);  
    void shrink();  

    size_t getSize() const;
    size_t getCapacity() const;

    Array<T>& operator=(const Array<T>& other);
    Array<T> operator+(const Array<T>& other) const;
    Array<T>& operator+=(const Array<T>& other);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    bool operator==(const Array<T>& other) const;
    bool operator!=(const Array<T>& other) const;
    bool operator>(const Array<T>& other) const;
    bool operator<(const Array<T>& other) const;
    Array<T> operator*(const Array<T>& other) const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Array<U>& arr);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr);

#endif



