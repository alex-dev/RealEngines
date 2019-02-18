#include <cmath>

namespace quantities {
  namespace quantities {
    inline constexpr double sin(Quantity<dimensions::Angle> const & α) {
      return std::sin(α.value);
    }

    inline constexpr double cos(Quantity<dimensions::Angle> const & α) {
      return std::cos(α.value);
    }

    inline constexpr double tan(Quantity<dimensions::Angle> const & α) {
      return std::tan(α.value);
    }

    inline constexpr Quantity<dimensions::Angle> asin(double const x) {
      return std::asin(x);
    }

    inline constexpr Quantity<dimensions::Angle> acos(double const x) {
      return std::acos(x);
    }

    inline constexpr Quantity<dimensions::Angle> atan(double const x) {
      return std::atan(x);
    }

    inline constexpr Quantity<dimensions::Angle> atan(double const y, double const x) {
      return std::atan2(y, x);
    }

    inline constexpr double sinh(Quantity<dimensions::Angle> const & α) {
      return std::sinh(α.value);
    }

    inline constexpr double cosh(Quantity<dimensions::Angle> const & α) {
      return std::cosh(α.value);
    }

    inline constexpr double tanh(Quantity<dimensions::Angle> const & α) {
      return std::tanh(α.value);
    }

    inline constexpr Quantity<dimensions::Angle> asinh(double const x) {
      return std::asinh(x);
    }

    inline constexpr Quantity<dimensions::Angle> acosh(double const x) {
      return std::acosh(x);
    }

    inline constexpr Quantity<dimensions::Angle> atanh(double const x) {
      return std::atanh(x);
    }
  }
}
