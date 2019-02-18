#pragma once

namespace quantities {
  namespace units {
    template<typename Quantity>
    constexpr Quantity Yotta(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Zetta(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Exa(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Peta(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Tera(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Giga(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Mega(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Kilo(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Hecto(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Deca(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Deci(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Centi(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Milli(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Micro(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Nano(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Pico(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Femto(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Atto(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Zepto(Quantity const & base);
    template<typename Quantity>
    constexpr Quantity Yocto(Quantity const & base);
  }
}

#include "prefixes.ipp"
