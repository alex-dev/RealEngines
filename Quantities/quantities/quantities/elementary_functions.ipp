#include <cmath>
#include "numerics.hpp"

namespace quantities {
  namespace quantities {
    template<typename Left, typename Right>
    constexpr Product<Left, Right> fma(Left const & x, Right const & y, Product<Left, Right> const & z) {
      return std::fma(x.value, y.value, z.value);
    }

    template<typename Value>
    constexpr Value abs(Value const & value) {
      return std::abs(value.value);
    }

    template<typename Radicand>
    constexpr SquareRoot<Radicand> sqrt(Radicand const & radicand) {
      return numerics::sqrt(radicand.value);
    }

    template<typename Radicand>
    constexpr CubicRoot<Radicand> cbrt(Radicand const & radicand) {
      return numerics::cbrt(radicand.value);
    }

    template<short exponent, typename Base>
    constexpr Exponentiation<Base, exponent> pow(Base const & base) {
      return numerics::pow<exponent>(base);
    }
  }
}
