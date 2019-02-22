#pragma once
#include <iostream>
#include "abstract_property.hpp"

namespace properties {
  template<typename T, typename Child>
  struct AbstractReadOnlyProperty : AbstractProperty<T> {
    constexpr operator T const &() const;
    constexpr operator T &();
    constexpr T const & operator() const;
    constexpr T & operator();

    template<typename Char, typename Traits = std::char_traits<Char>>
    friend std::basic_ostream<Char, Traits> & operator<<(std::basic_ostream<Char, Traits> & stream,
                                                         AbstractReadOnlyProperty const & value);
  };
}

#include "abstract_readonly_property.ipp"
