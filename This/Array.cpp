#include "Array.h"

template <typename T>
Array<T>::Array(size_t n) : size(n) {
    this->data = new T[this->size]{};
}

template <typename T>
Array<T>::Array(size_t n, T min, T max) : size(n) {
    this->data = new T[this->size];
    this->fillRandom(min, max);
}

template <typename T>
Array<T>::Array(size_t n, T value) : size(n) {
    this->data = new T[this->size];
    for (size_t i = 0; i < this->size; ++i) {
        this->data[i] = value;
    }
}

template <typename T>
Array<T>::Array(const Array& other) : size(other.size) {
    this->data = new T[this->size];
    for (size_t i = 0; i < this->size; ++i) {
        this->data[i] = other.data[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] this->data;
}

template <typename T>
void Array<T>::display() const {
    for (size_t i = 0; i < this->size; ++i) {
        std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Array<T>::fillRandom(T min, T max) {
    static T seed = 12345;
    for (size_t i = 0; i < this->size; ++i) {
        seed = (seed * 214013 + 2531011);
        if constexpr (std::is_integral<T>::value) {
            this->data[i] = min + (seed % (max - min + 1));
        }
        else if constexpr (std::is_floating_point<T>::value) {
            this->data[i] = min + static_cast<T>(seed) / static_cast<T>(0x7FFFFFFF) * (max - min);
        }
    }
}

template <typename T>
void Array<T>::resize(size_t newSize) {
    T* newData = new T[newSize]{};
    size_t minSize = (newSize < this->size) ? newSize : this->size;
    for (size_t i = 0; i < minSize; ++i) {
        newData[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newData;
    this->size = newSize;
}

template <typename T>
void Array<T>::sort() {
    for (size_t i = 0; i < this->size - 1; ++i) {
        for (size_t j = 0; j < this->size - i - 1; ++j) {
            if (this->data[j] > this->data[j + 1]) {
                T temp = this->data[j];
                this->data[j] = this->data[j + 1];
                this->data[j + 1] = temp;
            }
        }
    }
}

template <typename T>
T Array<T>::min() const {
    T minVal = this->data[0];
    for (size_t i = 1; i < this->size; ++i) {
        if (this->data[i] < minVal) {
            minVal = this->data[i];
        }
    }
    return minVal;
}

template <typename T>
T Array<T>::max() const {
    T maxVal = this->data[0];
    for (size_t i = 1; i < this->size; ++i) {
        if (this->data[i] > maxVal) {
            maxVal = this->data[i];
        }
    }
    return maxVal;
}

template <typename T>
void Array<T>::append(T value) {
    resize(this->size + 1);
    this->data[this->size - 1] = value;
}

template <typename T>
void Array<T>::remove(size_t index) {
    if (index >= this->size) {
        return;
    }
    for (size_t i = index; i < this->size - 1; ++i) {
        this->data[i] = this->data[i + 1];
    }
    resize(this->size - 1);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] this->data;
        this->size = other.size;
        this->data = new T[this->size];
        for (size_t i = 0; i < this->size; ++i) {
            this->data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
Array<T> Array<T>::operator+(const Array<T>& other) const {
    Array<T> result(this->size + other.size);
    for (size_t i = 0; i < this->size; ++i) {
        result.data[i] = this->data[i];
    }
    for (size_t i = 0; i < other.size; ++i) {
        result.data[this->size + i] = other.data[i];
    }
    return result;
}

template <typename T>
Array<T>& Array<T>::operator+=(const Array<T>& other) {
    size_t newSize = this->size + other.size;
    T* newData = new T[newSize];

    for (size_t i = 0; i < this->size; ++i) {
        newData[i] = this->data[i];
    }
    for (size_t i = 0; i < other.size; ++i) {
        newData[this->size + i] = other.data[i];
    }

    delete[] this->data;
    this->data = newData;
    this->size = newSize;

    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    return this->data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    return this->data[index];
}


template <typename T>
bool Array<T>::operator==(const Array<T>& other) const {
    if (this->size != other.size) {
        return false;
    }
    for (size_t i = 0; i < this->size; ++i) {
        if (this->data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Array<T>::operator!=(const Array<T>& other) const {
    return !(*this == other);
}

template <typename T>
bool Array<T>::operator>(const Array<T>& other) const {
    return this->size > other.size;
}

template <typename T>
bool Array<T>::operator<(const Array<T>& other) const {
    return this->size < other.size;
}

template <typename T>
Array<T> Array<T>::operator*(const Array<T>& other) const {
    Array<T> result;
    for (size_t i = 0; i < this->size; ++i) {
        for (size_t j = 0; j < other.size; ++j) {
            if (this->data[i] == other.data[j]) {
                result.append(this->data[i]);
                break;
            }
        }
    }
    return result;
}

template class Array<int>;
template class Array<float>;
template class Array<double>;





