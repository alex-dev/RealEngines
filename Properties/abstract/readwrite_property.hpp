#pragma once
#include "abstract/readonly_property.hpp"
#include "abstract/writeonly_property.hpp"

namespace properties {
  namespace abstract {
    template<typename T, typename Child>
    struct ReadWriteProperty : ReadOnlyProperty<T, Child>, WriteOnlyProperty<T, Child> {
      /// <summary>Implicit conversion operator to access wrapped variable.</summary>
      constexpr operator T&();

      /// <summary>This member access operator is to be used only as a conveniance method to access
      /// members.</summary>
      constexpr T* const operator->();

      /// <summary>This call operator is only a access method for conveniance.</summary>
      constexpr T& operator()();

    protected:
      constexpr T& get();
    };
  }
}

#include "readwrite_property.ipp"
