#include "quantities/quantities/traits.hpp"

namespace quantities {
  namespace quantities {
    template<typename Value>
    constexpr bool operator>(Value const & left, Value const & right) {
      static_assert(is_quantity_v<Value>, "Value is not a valid quantity.");

      return left.value > right.value;
    }

    template<typename Value>
    constexpr bool operator<(Value const & left, Value const & right) {
      static_assert(is_quantity_v<Value>, "Value is not a valid quantity.");

      return left.value < right.value;
    }

    template<typename Value>
    constexpr bool operator>=(Value const & left, Value const & right) {
      static_assert(is_quantity_v<Value>, "Value is not a valid quantity.");

      return left.value >= right.value;
    }

    template<typename Value>
    constexpr bool operator<=(Value const & left, Value const & right) {
      static_assert(is_quantity_v<Value>, "Value is not a valid quantity.");

      return left.value <= right.value;
    }

    template<typename Value>
    constexpr bool operator==(Value const & left, Value const & right) {
      static_assert(is_quantity_v<Value>, "Value is not a valid quantity.");

      return left.value == right.value;
    }

    template<typename Value>
    constexpr bool operator!=(Value const & left, Value const & right) {
      static_assert(is_quantity_v<Value>, "Quantity is not a valid quantity.");

      return left.value != right.value;
    }
  }
}
