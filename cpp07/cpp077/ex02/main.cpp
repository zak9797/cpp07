#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    Array<int> empty;
    std::cout << "empty size: " << empty.size() << std::endl;

    Array<int> a(5);
    for (std::size_t i = 0; i < a.size(); ++i)
        a[i] = static_cast<int>(i + 1);

    std::cout << "a contents:";
    for (std::size_t i = 0; i < a.size(); ++i)
        std::cout << " " << a[i];
    std::cout << std::endl;

    Array<int> copy = a; // copy constructor
    a[0] = 42;
    std::cout << "after modify a[0]=42, copy[0] = " << copy[0] << ", a[0] = " << a[0] << std::endl;

    Array<std::string> sarr(3);
    sarr[0] = "one";
    sarr[1] = "two";
    sarr[2] = "three";
    std::cout << "sarr:";
    for (std::size_t i = 0; i < sarr.size(); ++i)
        std::cout << " " << sarr[i];
    std::cout << std::endl;

    try {
        std::cout << "Access out of bounds: " << a[10] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // assignment
    Array<int> b;
    b = a;
    a[1] = 99;
    std::cout << "after assign and modify a[1]=99, b[1] = " << b[1] << ", a[1] = " << a[1] << std::endl;

    // const access
    const Array<int> ca = a;
    std::cout << "const access ca[0] = " << ca[0] << std::endl;

    return 0;
}
