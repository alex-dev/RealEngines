#pragma once
#include <type_traits>

namespace base {
  template<typename Child>
  struct simple_augmented_assignment {
    constexpr Child& operator++();
    constexpr Child& operator--();

    constexpr Child operator++(int);
    constexpr Child operator--(int);

    constexpr Child& operator+=(Child const& other);
    constexpr Child& operator-=(Child const& other);
  };

  template<typename Child, typename Numeric>
  struct advanced_augmented_assignment {
    static_assert(std::disjunction_v<std::is_convertible<Numeric, double>, std::is_convertible<Numeric, long long>,
                                     std::is_convertible<Numeric, unsigned long long>>,
                  "Numeric must be implicitly convertible to an arithmetic type.");

    constexpr Child& operator*=(Numeric const& other);
    constexpr Child& operator/=(Numeric const& other);
  };
}

#include "advanced_augmented_assignment.ipp"
#include "simple_augmented_assignment.ipp"
