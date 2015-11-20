#include <iostream>

template <int N, int i = N / 2>
struct is_prime {
  static_assert(N > 2, "N must be greater than 2");
  enum { value = (N % i != 0 && is_prime<N, i - 1>::value == 1) ? 1 : 0 };
};

template <int N>
struct is_prime<N, 2> {
  enum { value = N % 2 ? 1 : 0 };
};

template <int N>
struct is_prime<N, 1> {
  enum { value = 1 };
};

template <int N>
void print_prime() {
  print_prime<N - 1>();
  if (is_prime<N>::value) std::cout << N << std::endl;
}

template <>
void print_prime<1>() {}

int main() { print_prime<1000>(); }
