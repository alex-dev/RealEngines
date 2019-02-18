#pragma once
#include <type_traits>
#include "base/not_constructible.hpp"
#include "quantities/dimensions/dimensions.hpp"

namespace quantities {
  namespace dimensions {
    template<typename Dimensions>
    struct is_dimensions
        : std::is_same<Dimensions, dimensions::Dimensions<Dimensions::Length, Dimensions::Mass, Dimensions::Time, Dimensions::Current, Dimensions::Temperature,
                                                          Dimensions::Amount, Dimensions::LuminousIntensity, Dimensions::Angle>>,
          base::not_constructible {};

    template<typename Type>
    constexpr bool is_dimensions_v = is_dimensions<Type>::value;
  }
}
