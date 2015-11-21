#include <iostream>

template <int N>
struct Sum
{
    enum {value = Sum<N-1>::value + N};
};

template<>
struct Sum<1>
{
    enum {value = 1};
};

int main()
{
    std::cout << Sum<100>::value << std::endl;
}
