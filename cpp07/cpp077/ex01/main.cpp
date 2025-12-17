#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(int &x) { std::cout << x << std::endl; }
void printIntConst(int const &x) { std::cout << x << std::endl; }
void increment(int &x) { ++x; }

void printString(std::string &s) { std::cout << s << std::endl; }
void printStringConst(std::string const &s) { std::cout << s << std::endl; }

int main() {
    int arr[] = {1, 2, 3, 4};
    iter(arr, 4, printInt);
    iter(arr, 4, increment);
    iter(arr, 4, printIntConst);

    std::string strs[] = {"one", "two", "three"};
    iter(strs, 3, printString);
    iter(strs, 3, printStringConst);

    const int carr[] = {10, 20, 30};
    iter(carr, 3, printIntConst);

    return 0;
}
