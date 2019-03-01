#pragma once
#include "abstract/abstract_property.hpp"

namespace properties {
  namespace abstract {
    template<typename R>
    struct ReferencingProperty {
      static_assert(!std::is_pointer_v<R> && !std::is_member_pointer_v<R>,
                    "Referencing properties cannot be referencing to pointers.");
      static_assert(!std::is_reference_v<R>,
                    "Referencing properties cannot be referencing to references of references.");

      constexpr ReferencingProperty(R& reference);

    protected:
      R& reference;
    };
  }
}

#include "referencing_property.ipp"
