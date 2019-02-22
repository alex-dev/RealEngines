#include <limits>

namespace quantities {
  namespace quantities {
    template<typename Dimensions>
    constexpr Quantity<Dimensions> Quantity<Dimensions>::infinity() noexcept {
      return std::numeric_limits<double>::infinity();
    }

    template<typename Dimensions>
    constexpr Quantity<Dimensions> Quantity<Dimensions>::NaN() noexcept {
      return std::numeric_limits<double>::quiet_NaN();
    }

    template<typename Dimensions>
    constexpr Quantity<Dimensions>::Quantity() noexcept : Quantity(1.0) {}

    template<typename Dimensions>
    constexpr Quantity<Dimensions>::Quantity(double value) noexcept : value(value) {}
  }
}
