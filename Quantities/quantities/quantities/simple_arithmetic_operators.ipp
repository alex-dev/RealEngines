#include "quantities/quantities/traits.hpp"

namespace quantities {
  namespace quantities {
    template<typename Value>
    constexpr Value operator+(Value const & value) {
      static_assert(is_quantity_v<Value>, "Value is not a valid quantity.");

      return value;
    }

    template<typename Value>
    constexpr Value operator-(Value const & value) {
      static_assert(is_quantity_v<Value>, "Value is not a valid quantity.");

      return -value.value;
    }

    template<typename Value>
    constexpr Value operator+(Value const & left, Value const & right) {
      static_assert(is_quantity_v<Value>, "Value is not a valid quantity.");

      return left.value + right.value;
    }

    template<typename Value>
    constexpr Value operator-(Value const & left, Value const & right) {
      static_assert(is_quantity_v<Value>, "Value is not a valid quantity.");

      return left.value - right.value;
    }
  }
}
