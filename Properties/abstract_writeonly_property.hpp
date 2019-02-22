#pragma once
#include <iostream>
#include "abstract_property.hpp"

namespace properties {
  template<typename T, typename Child>
  struct AbstractWriteOnlyProperty : AbstractProperty<T> {
    AbstractWriteOnlyProperty & operator=(T const & value);
    AbstractWriteOnlyProperty & operator=(T && value);

	template<typename Char, typename Traits = std::char_traits<Char>>
    friend std::basic_ostream<Char, Traits> & operator<<(std::basic_ostream<Char, Traits> & stream, 
		                                                 AbstractWriteOnlyProperty const & value);
  };
}
