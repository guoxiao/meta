template<unsigned long long N>
struct binary {
  enum {
    value = (binary<N/10>::value << 1) + N % 10
  };
};

template<>
struct binary<0> {
  enum {
    value = 0
  };
};


template<>
struct binary<1> {
  enum {
    value = 1
  };
};

inline constexpr int binary2(unsigned long long dec) {
  return (dec == 0 ? 0 :
         dec == 1 ? 1 :
         ((binary2(dec/10) << 1) + dec % 10));
}

#include <iostream>
int main() {
  std::cout << binary<101010>::value << std::endl;
  std::cout << (constexpr int)binary2(101010) <<std::endl;
  std::cout << binary<1>::value << std::endl;
  std::cout << binary<10>::value << std::endl;
  std::cout << binary<11>::value << std::endl;
  std::cout << binary<1000>::value << std::endl;
  std::cout << binary<100001>::value << std::endl;
}
