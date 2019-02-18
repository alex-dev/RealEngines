#pragma once
#include "base/not_constructible.hpp"
#include "quantities/dimensions/generators_dimensions.hpp"
#include "quantities/quantities/traits.hpp"

namespace quantities {
  namespace quantities {
#pragma region Collapse

    template<typename Quantity>
    struct Collapse : base::not_constructible {
      using Type = Quantity;
    };

    template<>
    struct Collapse<Quantity<dimensions::NoDimensions>> : base::not_constructible {
      using Type = double;
    };

#pragma endregion

#pragma region ExponentiationGenerator

    template<typename Base, long long exponent>
    struct ExponentiationGenerator : base::not_constructible {
      static_assert(is_quantity_v<Base>, "Base is not a valid quantity.");

    private:
      using Generator = dimensions::DimensionsExponentiationGenerator<typename Base::Dimensions, exponent>;

    public:
      using Type = typename Collapse<Quantity<typename Generator::Type>>::Type;
    };

    template<short exponent>
    struct ExponentiationGenerator<double, exponent> : base::not_constructible {
      using Type = double;
    };

#pragma endregion

#pragma region RootGenerator

    template<typename Radicand, long long degree>
    struct RootGenerator : base::not_constructible {
      static_assert(is_quantity_v<Radicand>, "Radicand is not a valid quantity.");

    private:
      using Generator = dimensions::DimensionsRootGenerator<typename Radicand::Dimensions, degree>;

    public:
      using Type = typename Collapse<Quantity<typename Generator::Type>>::Type;
    };

    template<short degree>
    struct RootGenerator<double, degree> : base::not_constructible {
      using Type = double;
    };

#pragma endregion

#pragma region ProductGenerator

    template<typename Left, typename Right>
    struct ProductGenerator : base::not_constructible {
      static_assert(is_quantity_v<Left>, "Left is not a valid quantity.");
      static_assert(is_quantity_v<Right>, "Right is not a valid quantity.");

    private:
      using Generator = dimensions::DimensionsProductGenerator<typename Left::Dimensions, typename Right::Dimensions>;

    public:
      using Type = typename Collapse<Quantity<typename Generator::Type>>::Type;
    };

    template<typename Left>
    struct ProductGenerator<Left, double> : base::not_constructible {
      static_assert(is_quantity_v<Left>, "Left is not a valid quantity.");

      using Type = Left;
    };

    template<typename Right>
    struct ProductGenerator<double, Right> : base::not_constructible {
      static_assert(is_quantity_v<Right>, "Right is not a valid quantity.");

      using Type = Right;
    };

    template<>
    struct ProductGenerator<double, double> : base::not_constructible {
      using Type = double;
    };

#pragma endregion

#pragma region QuotientGenerator

    template<typename Dividend, typename Divisor>
    struct QuotientGenerator : base::not_constructible {
      static_assert(is_quantity_v<Dividend>, "Dividend is not a valid quantity.");
      static_assert(is_quantity_v<Divisor>, "Divisor is not a valid quantity.");

    private:
      using Generator
          = dimensions::DimensionsQuotientGenerator<typename Dividend::Dimensions, typename Divisor::Dimensions>;

    public:
      using Type = typename Collapse<Quantity<typename Generator::Type>>::Type;
    };

    template<typename Dividend>
    struct QuotientGenerator<Dividend, double> : base::not_constructible {
      static_assert(is_quantity_v<Dividend>, "Dividend is not a valid quantity.");

      using Type = Dividend;
    };

    template<typename Divisor>
    struct QuotientGenerator<double, Divisor> : base::not_constructible {
      static_assert(is_quantity_v<Divisor>, "Divisor is not a valid quantity.");

    private:
      using Generator
          = dimensions::DimensionsQuotientGenerator<typename dimensions::NoDimensions, typename Divisor::Dimensions>;

    public:
      using Type = typename Collapse<Quantity<typename Generator::Type>>::Type;
    };

    template<>
    struct QuotientGenerator<double, double> : base::not_constructible {
      using Type = double;
    };

#pragma endregion
  }
}
