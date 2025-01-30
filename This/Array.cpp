#include "Array.h"

Array::Array(size_t n) : size(n) {
    this->data = new int[this->size] {};
}

Array::Array(size_t n, int min, int max) : size(n) {
    this->data = new int[this->size];
    this->fillRandom(min, max);
}

Array::Array(size_t n, int value) : size(n) {
    this->data = new int[this->size];
    for (size_t i = 0; i < this->size; ++i) {
        this->data[i] = value;
    }
}

Array::Array(const Array& other) : size(other.size) {
    this->data = new int[this->size];
    for (size_t i = 0; i < this->size; ++i) {
        this->data[i] = other.data[i];
    }
}

Array::~Array() {
    delete[] this->data;
}

void Array::display() const {
    for (size_t i = 0; i < this->size; ++i) {
        std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
}

void Array::fillRandom(int min, int max) {
    int value = 12345;
    for (size_t i = 0; i < this->size; ++i) {
        value = (value * 214013 + 2531011) & 0x7FFFFFFF;
        this->data[i] = min + (value % (max - min + 1));
    }
}

void Array::resize(size_t newSize) {
    int* newData = new int[newSize] {};
    size_t minSize = (newSize < this->size) ? newSize : this->size;
    for (size_t i = 0; i < minSize; ++i) {
        newData[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newData;
    this->size = newSize;
}

void Array::sort() {
    for (size_t i = 0; i < this->size - 1; ++i) {
        for (size_t j = 0; j < this->size - i - 1; ++j) {
            if (this->data[j] > this->data[j + 1]) {
                int temp = this->data[j];
                this->data[j] = this->data[j + 1];
                this->data[j + 1] = temp;
            }
        }
    }
}

int Array::min() const {
    int minVal = this->data[0];
    for (size_t i = 1; i < this->size; ++i) {
        if (this->data[i] < minVal) {
            minVal = this->data[i];
        }
    }
    return minVal;
}

int Array::max() const {
    int maxVal = this->data[0];
    for (size_t i = 1; i < this->size; ++i) {
        if (this->data[i] > maxVal) {
            maxVal = this->data[i];
        }
    }
    return maxVal;
}
