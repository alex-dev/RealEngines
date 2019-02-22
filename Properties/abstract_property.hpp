#pragma once
#include <type_traits>

namespace properties {
  template<typename T>
  struct AbstractProperty {
    static_assert(!std::is_pointer_v<T> && !std::is_member_pointer_v<T>,
                  "Properties cannot be applied to pointers.");
    static_assert(!std::is_reference_v<T>, "Properties cannot be applied to references.");
  };
}
