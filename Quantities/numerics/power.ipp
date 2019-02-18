#include <cmath>

namespace numerics {
  template<long long exponent>
  constexpr double pow(double base) {
    return std::pow(base, exponent);
  }

  template<>
  constexpr double pow<-3>(double base) {
    return 1 / (base * base * base);
  }

  template<>
  constexpr double pow<-2>(double base) {
    return 1 / (base * base);
  }

  template<>
  constexpr double pow<-1>(double base) {
    return 1 / base;
  }

  template<>
  constexpr double pow<0>(double) {
    return 1;
  }

  template<>
  constexpr double pow<1>(double base) {
    return base;
  }

  template<>
  constexpr double pow<2>(double base) {
    return base * base;
  }

  template<>
  constexpr double pow<3>(double base) {
    return base * base * base;
  }
}
