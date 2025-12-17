#include "Array.hpp"
#include <algorithm>

template <typename T>
Array<T>::Array(): _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _data(NULL), _size(n) {
    if (n == 0) {
        _data = NULL;
    } else {
        _data = new T[n];
    }
}

template <typename T>
Array<T>::Array(Array const &other): _data(NULL), _size(other._size) {
    if (_size == 0) {
        _data = NULL;
    } else {
        _data = new T[_size];
        for (std::size_t i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
    if (this != &other) {
        // allocate new memory and copy
        T* newData = NULL;
        if (other._size > 0) {
            newData = new T[other._size];
            for (std::size_t i = 0; i < other._size; ++i)
                newData[i] = other._data[i];
        }
        delete [] _data;
        _data = newData;
        _size = other._size;
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete [] _data;
}

struct OutOfBoundsException : public std::exception {
    const char* what() const throw() { return "Index out of bounds"; }
};

template <typename T>
T &Array<T>::operator[](std::size_t idx) {
    if (idx >= _size) throw OutOfBoundsException();
    return _data[idx];
}

template <typename T>
T const &Array<T>::operator[](std::size_t idx) const {
    if (idx >= _size) throw OutOfBoundsException();
    return _data[idx];
}

template <typename T>
std::size_t Array<T>::size() const { return _size; }
