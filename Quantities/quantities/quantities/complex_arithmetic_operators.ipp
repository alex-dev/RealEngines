#include "quantities/quantities/traits.hpp"

namespace quantities {
  namespace quantities {
    template<typename Left, typename Right>
    constexpr Product<Left, Right> operator*(Left const& left, Right const& right) {
      return left.value * right.value;
    }

    template<typename Left>
    constexpr Product<Left, double> operator*(Left const& left, double const& right) {
      return left.value * right;
    }

    template<typename Right>
    constexpr Product<double, Right> operator*(double const& left, Right const& right) {
      return left * right.value;
    }

    template<typename Left, typename Right>
    constexpr Quotient<Left, Right> operator/(Left const& left, Right const& right) {
      return left.value / right.value;
    }

    template<typename Left>
    constexpr Quotient<Left, double> operator/(Left const& left, double const& right) {
      return left.value / right;
    }

    template<typename Right>
    constexpr Quotient<double, Right> operator/(double const& left, Right const& right) {
      return left / right.value;
    }
  }
}
