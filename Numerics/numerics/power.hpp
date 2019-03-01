#pragma once

namespace numerics {
  template<long long exponent>
  constexpr double pow(double base);

  template<>
  constexpr double pow<-3>(double base);

  template<>
  constexpr double pow<-2>(double base);

  template<>
  constexpr double pow<-1>(double base);

  template<>
  constexpr double pow<0>(double);

  template<>
  constexpr double pow<1>(double base);

  template<>
  constexpr double pow<2>(double base);

  template<>
  constexpr double pow<3>(double base);
}

#include "power.ipp"
