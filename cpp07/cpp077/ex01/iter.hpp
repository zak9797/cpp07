#pragma once

#include <cstddef>

template <typename T>
void iter(T *arr, std::size_t len, void (*f)(T &)) {
    for (std::size_t i = 0; i < len; ++i)
        f(arr[i]);
}

template <typename T>
void iter(T *arr, std::size_t len, void (*f)(T const &)) {
    for (std::size_t i = 0; i < len; ++i)
        f(arr[i]);
}

// Overloads accepting arrays deduced as references to avoid decay
template <typename T, std::size_t N>
void iter(T (&arr)[N], void (*f)(T &)) {
    iter<T>(arr, N, f);
}

template <typename T, std::size_t N>
void iter(T const (&arr)[N], void (*f)(T const &)) {
    iter<T>(const_cast<T*>(arr), N, f);
}
