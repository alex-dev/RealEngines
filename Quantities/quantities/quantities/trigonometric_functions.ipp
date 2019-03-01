#include <cmath>

namespace quantities {
  namespace quantities {
    inline double sin(Quantity<dimensions::Angle> const& α) {
      return std::sin(α.value);
    }

    inline double cos(Quantity<dimensions::Angle> const& α) {
      return std::cos(α.value);
    }

    inline double tan(Quantity<dimensions::Angle> const& α) {
      return std::tan(α.value);
    }

    inline Quantity<dimensions::Angle> asin(double const x) {
      return std::asin(x);
    }

    inline Quantity<dimensions::Angle> acos(double const x) {
      return std::acos(x);
    }

    inline Quantity<dimensions::Angle> atan(double const x) {
      return std::atan(x);
    }

    inline Quantity<dimensions::Angle> atan(double const y, double const x) {
      return std::atan2(y, x);
    }

    inline double sinh(Quantity<dimensions::Angle> const& α) {
      return std::sinh(α.value);
    }

    inline double cosh(Quantity<dimensions::Angle> const& α) {
      return std::cosh(α.value);
    }

    inline double tanh(Quantity<dimensions::Angle> const& α) {
      return std::tanh(α.value);
    }

    inline Quantity<dimensions::Angle> asinh(double const x) {
      return std::asinh(x);
    }

    inline Quantity<dimensions::Angle> acosh(double const x) {
      return std::acosh(x);
    }

    inline Quantity<dimensions::Angle> atanh(double const x) {
      return std::atanh(x);
    }
  }
}
