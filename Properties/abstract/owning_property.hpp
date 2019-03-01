#pragma once
#include "abstract/abstract_property.hpp"

namespace properties {
  namespace abstract {
    template<typename T>
    struct OwningProperty : AbstractProperty<T> {
      constexpr OwningProperty(T const& property);
      constexpr OwningProperty(T&& property);

    protected:
      T property;
    };
  }
}

#include "owning_property.ipp"
