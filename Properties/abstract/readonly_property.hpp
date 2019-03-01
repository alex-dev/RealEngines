#pragma once
#include "abstract/abstract_property.hpp"

namespace properties {
  namespace abstract {
    template<typename T, typename Child>
    struct ReadOnlyProperty : AbstractProperty<T> {
      /// <summary>Implicit conversion operator to access wrapped variable.</summary>
      constexpr operator T const&() const;

      /// <summary>This member access operator is to be used only as a conveniance method to access
      /// members.</summary>
      constexpr T const* const operator->() const;

      /// <summary>This call operator is only a access method for conveniance.</summary>
      constexpr T const& operator()() const;
    };
  }
}

#include "readonly_property.ipp"
