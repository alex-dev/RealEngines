#pragma once
#include "abstract/owning_property.hpp"
#include "abstract/readwrite_property.hpp"

namespace properties {
  template<typename T>
  struct DefaultReadWriteProperty : abstract::OwningProperty<T>,
                                    abstract::ReadOnlyProperty<T, DefaultReadWriteProperty<T>>,
                                    abstract::WriteOnlyProperty<T, DefaultReadWriteProperty<T>> {
    using abstract::OwningProperty<T>::OwningProperty;

  protected:
    constexpr T const& get() const;
    constexpr T& get();
    constexpr T& set(T const& value);
    constexpr T& set(T&& value);
  };
}

#include "default_readwrite_property.ipp"
