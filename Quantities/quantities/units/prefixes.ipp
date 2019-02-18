#include "quantities/quantities/traits.hpp"

namespace quantities {
  namespace units {
    template<typename Quantity>
    constexpr Quantity Yotta(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e24 * base;
    }

    template<typename Quantity>
    constexpr Quantity Zetta(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e21 * base;
    }


    template<typename Quantity>
    constexpr Quantity Exa(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e18 * base;
    }

    template<typename Quantity>
    constexpr Quantity Peta(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e15 * base;
    }

    template<typename Quantity>
    constexpr Quantity Tera(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e12 * base;
    }

    template<typename Quantity>
    constexpr Quantity Giga(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e9 * base;
    }

    template<typename Quantity>
    constexpr Quantity Mega(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e6 * base;
    }

    template<typename Quantity>
    constexpr Quantity Kilo(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e3 * base;
    }

    template<typename Quantity>
    constexpr Quantity Hecto(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e2 * base;
    }

    template<typename Quantity>
    constexpr Quantity Deca(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e1 * base;
    }

    template<typename Quantity>
    constexpr Quantity Deci(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e-1 * base;
    }

    template<typename Quantity>
    constexpr Quantity Centi(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e-2 * base;
    }

    template<typename Quantity>
    constexpr Quantity Milli(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e-3 * base;
    }

    template<typename Quantity>
    constexpr Quantity Micro(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e-6 * base;
    }

    template<typename Quantity>
    constexpr Quantity Nano(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e-9 * base;
    }

    template<typename Quantity>
    constexpr Quantity Pico(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e-12 * base;
    }

    template<typename Quantity>
    constexpr Quantity Femto(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e-15 * base;
    }

    template<typename Quantity>
    constexpr Quantity Atto(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e-18 * base;
    }

    template<typename Quantity>
    constexpr Quantity Zepto(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e-21 * base;
    }

    template<typename Quantity>
    constexpr Quantity Yocto(Quantity const & base) {
      static_assert(quantities::is_quantity_v<Quantity>, "Quantity is not a valid quantity.");

      return 1e-24 * base;
    }
  }
}
