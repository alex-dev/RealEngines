#pragma once
#include <type_traits>
#include "base/not_constructible.hpp"
#include "quantities/dimensions/traits.hpp"

#pragma region Forward Declarations

namespace quantities {
  namespace quantities {
    template<typename Dimensions>
    struct Quantity;
  }
}

#pragma endregion

namespace quantities {
  namespace quantities {
    template<typename Quantity>
    struct is_quantity
        : std::conjunction<dimensions::is_dimensions<typename Quantity::Dimensions>,
                           std::is_same<Quantity, quantities::Quantity<typename Quantity::Dimensions>>>,
          base::not_constructible {};

    template<typename Dimensions>
    struct is_quantity<quantities::Quantity<Dimensions>> : dimensions::is_dimensions<Dimensions> {};

    template<typename Type>
    constexpr bool is_quantity_v = is_quantity<Type>::value;
  }
}
