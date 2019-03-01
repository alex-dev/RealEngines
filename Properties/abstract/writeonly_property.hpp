#pragma once
#include "abstract/abstract_property.hpp"

namespace properties {
  namespace abstract {
    template<typename T, typename Child>
    struct WriteOnlyProperty : AbstractProperty<T> {
      static_assert(!std::is_const_v<T>, "A writeonly property cannot be const.");

      constexpr T& operator=(T const& value);
      constexpr T& operator=(T&& value);

      /// <summary>This call operator is only a access method for conveniance.</summary>
      constexpr T& operator()(T const& value);
      /// <summary>This call operator is only a access method for conveniance.</summary>
      constexpr T& operator()(T&& value);

    protected:
      constexpr T& set(T const& value);
    };
  }
}

#include "writeonly_property.ipp"
