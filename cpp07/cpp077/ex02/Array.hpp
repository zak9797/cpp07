#pragma once

#include <cstddef>
#include <exception>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(Array const &other);
    Array &operator=(Array const &other);
    ~Array();

    T &operator[](std::size_t idx);
    T const &operator[](std::size_t idx) const;

    std::size_t size() const;

private:
    T* _data;
    std::size_t _size;
};

#include "Array.tpp"
