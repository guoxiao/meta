#include <iostream>

template <int n>
struct fibonacci {
    enum {value = fibonacci<n-2>::value + fibonacci<n-1>::value};
};

template <>
struct fibonacci<1> {
    enum {value = 1};
};

template <>
struct fibonacci<2> {
    enum {value = 1};
};

int main() {
    std::cout << fibonacci<20>::value << std::endl;
}
