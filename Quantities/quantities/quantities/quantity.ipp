#include <limits>

template<typename Dimensions>
constexpr quantities::quantities::Quantity<Dimensions> quantities::quantities::Quantity<Dimensions>::infinity() {
  return std::numeric_limits<double>::infinity();
}

template<typename Dimensions>
constexpr quantities::quantities::Quantity<Dimensions> quantities::quantities::Quantity<Dimensions>::NaN() {
  return std::numeric_limits<double>::quiet_NaN();
}

template<typename Dimensions>
constexpr quantities::quantities::Quantity<Dimensions>::Quantity() : Quantity(1.0) {}

template<typename Dimensions>
constexpr quantities::quantities::Quantity<Dimensions>::Quantity(double value) : value(value) {}
