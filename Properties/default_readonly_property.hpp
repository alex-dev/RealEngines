#pragma once
#include "abstract/owning_property.hpp"
#include "abstract/readonly_property.hpp"

namespace properties {
  template<typename T>
  struct DefaultReadOnlyProperty : abstract::OwningProperty<T>,
                                   abstract::ReadOnlyProperty<T, DefaultReadOnlyProperty<T>> {
    using abstract::OwningProperty<T>::OwningProperty;

  protected:
    constexpr T const& get() const;
  };
}

#include "default_readonly_property.ipp"
