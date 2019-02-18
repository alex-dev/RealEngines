#pragma once
#include <limits>
#include "base/not_constructible.hpp"
#include "quantities/dimensions/dimensions.hpp"
#include "quantities/dimensions/traits.hpp"

namespace quantities {
  namespace dimensions {
    template<typename Base, long long exponent>
    struct DimensionsExponentiationGenerator : base::not_constructible {
#pragma region static_assert

      static_assert(is_dimensions_v<Base>, "Base is not a valid Dimensions");
      static_assert(Base::Length * exponent > std::numeric_limits<long long>::min()
                        && Base::Length * exponent < std::numeric_limits<long long>::max(),
                    "Length dimension is out of bound.");
      static_assert(Base::Mass * exponent > std::numeric_limits<long long>::min()
                        && Base::Mass * exponent < std::numeric_limits<long long>::max(),
                    "Mass dimension is out of bound.");
      static_assert(Base::Time * exponent > std::numeric_limits<long long>::min()
                        && Base::Time * exponent < std::numeric_limits<long long>::max(),
                    "Time dimension is out of bound.");
      static_assert(Base::Current * exponent > std::numeric_limits<long long>::min()
                        && Base::Current * exponent < std::numeric_limits<long long>::max(),
                    "Current dimension is out of bound.");
      static_assert(Base::Temperature * exponent > std::numeric_limits<long long>::min()
                        && Base::Temperature * exponent < std::numeric_limits<long long>::max(),
                    "Temperature dimension is out of bound.");
      static_assert(Base::Amount * exponent > std::numeric_limits<long long>::min()
                        && Base::Amount * exponent < std::numeric_limits<long long>::max(),
                    "Amount dimension is out of bound.");
      static_assert(Base::LuminousIntensity * exponent > std::numeric_limits<long long>::min()
                        && Base::LuminousIntensity * exponent < std::numeric_limits<long long>::max(),
                    "LuminousIntensity dimension is out of bound.");
      static_assert(Base::Angle * exponent > std::numeric_limits<long long>::min()
                        && Base::Angle * exponent < std::numeric_limits<long long>::max(),
                    "Angle dimension is out of bound.");

#pragma endregion

      using Type = Dimensions<Base::Length * exponent, Base::Mass * exponent, Base::Time * exponent,
                              Base::Current * exponent, Base::Temperature * exponent, Base::Amount * exponent,
                              Base::LuminousIntensity * exponent, Base::Angle * exponent>;
    };

    template<typename Radicand, long long degree>
    struct DimensionsRootGenerator : base::not_constructible {
#pragma region static_assert

      static_assert(is_dimensions_v<Radicand>, "Radicand is not a valid Dimensions");
      static_assert(Radicand::Length % degree == 0, "Length cannot be divided by degree.");
      static_assert(Radicand::Mass % degree == 0, "Mass cannot be divided by degree.");
      static_assert(Radicand::Time % degree == 0, "Time cannot be divided by degree.");
      static_assert(Radicand::Current % degree == 0, "Current cannot be divided by degree.");
      static_assert(Radicand::Temperature % degree == 0, "Temperature cannot be divided by degree.");
      static_assert(Radicand::Amount % degree == 0, "Amount cannot be divided by degree.");
      static_assert(Radicand::LuminousIntensity % degree == 0,
                    "LuminousIntensity cannot be divided by degree.");
      static_assert(Radicand::Angle % degree == 0, "Angle cannot be divided by degree.");

#pragma endregion

      using Type = Dimensions<Radicand::Length / degree, Radicand::Mass / degree, Radicand::Time / degree,
                              Radicand::Current / degree, Radicand::Temperature / degree, Radicand::Amount / degree,
                              Radicand::LuminousIntensity / degree, Radicand::Angle / degree>;
    };

    template<typename Left, typename Right>
    struct DimensionsProductGenerator : base::not_constructible {
#pragma region static_assert

      static_assert(is_dimensions_v<Left>, "Left is not a valid Dimensions");
      static_assert(is_dimensions_v<Right>, "Right is not a valid Dimensions");
      static_assert(Left::Length + Right::Length > std::numeric_limits<long long>::min()
                        && Left::Length + Right::Length < std::numeric_limits<long long>::max(),
                    "Length dimension is out of bound.");
      static_assert(Left::Mass + Right::Mass > std::numeric_limits<long long>::min()
                        && Left::Mass + Right::Mass < std::numeric_limits<long long>::max(),
                    "Mass dimension is out of bound.");
      static_assert(Left::Time + Right::Time > std::numeric_limits<long long>::min()
                        && Left::Time + Right::Time < std::numeric_limits<long long>::max(),
                    "Time dimension is out of bound.");
      static_assert(Left::Current + Right::Current > std::numeric_limits<long long>::min()
                        && Left::Current + Right::Current < std::numeric_limits<long long>::max(),
                    "Current dimension is out of bound.");
      static_assert(Left::Temperature + Right::Temperature > std::numeric_limits<long long>::min()
                        && Left::Temperature + Right::Temperature < std::numeric_limits<long long>::max(),
                    "Temperature dimension is out of bound.");
      static_assert(Left::Amount + Right::Amount > std::numeric_limits<long long>::min()
                        && Left::Amount + Right::Amount < std::numeric_limits<long long>::max(),
                    "Amount dimension is out of bound.");
      static_assert(Left::LuminousIntensity + Right::LuminousIntensity > std::numeric_limits<long long>::min()
                        && Left::LuminousIntensity + Right::LuminousIntensity
                               < std::numeric_limits<long long>::max(),
                    "LuminousIntensity dimension is out of bound.");
      static_assert(Left::Angle + Right::Angle > std::numeric_limits<long long>::min()
                        && Left::Angle + Right::Angle < std::numeric_limits<long long>::max(),
                    "Angle dimension is out of bound.");

#pragma endregion

      using Type
          = Dimensions<Left::Length + Right::Length, Left::Mass + Right::Mass, Left::Time + Right::Time,
                       Left::Current + Right::Current, Left::Temperature + Right::Temperature, Left::Amount + Right::Amount,
                       Left::LuminousIntensity + Right::LuminousIntensity, Left::Angle + Right::Angle>;
    };

    template<typename Dividend, typename Divisor>
    struct DimensionsQuotientGenerator : base::not_constructible {
#pragma region static_assert

      static_assert(is_dimensions_v<Dividend>, "Dividend is not a valid Dimensions");
      static_assert(is_dimensions_v<Divisor>, "Divisor is not a valid Dimensions");
      static_assert(Dividend::Length - Divisor::Length > std::numeric_limits<long long>::min()
                        && Dividend::Length - Divisor::Length < std::numeric_limits<long long>::max(),
                    "Length dimension is out of bound.");
      static_assert(Dividend::Mass - Divisor::Mass > std::numeric_limits<long long>::min()
                        && Dividend::Mass - Divisor::Mass < std::numeric_limits<long long>::max(),
                    "Mass dimension is out of bound.");
      static_assert(Dividend::Time - Divisor::Time > std::numeric_limits<long long>::min()
                        && Dividend::Time - Divisor::Time < std::numeric_limits<long long>::max(),
                    "Time dimension is out of bound.");
      static_assert(Dividend::Current - Divisor::Current > std::numeric_limits<long long>::min()
                        && Dividend::Current - Divisor::Current < std::numeric_limits<long long>::max(),
                    "Current dimension is out of bound.");
      static_assert(Dividend::Temperature - Divisor::Temperature > std::numeric_limits<long long>::min()
                        && Dividend::Temperature - Divisor::Temperature < std::numeric_limits<long long>::max(),
                    "Temperature dimension is out of bound.");
      static_assert(Dividend::Amount - Divisor::Amount > std::numeric_limits<long long>::min()
                        && Dividend::Amount - Divisor::Amount < std::numeric_limits<long long>::max(),
                    "Amount dimension is out of bound.");
      static_assert(Dividend::LuminousIntensity - Divisor::LuminousIntensity > std::numeric_limits<long long>::min()
                        && Dividend::LuminousIntensity - Divisor::LuminousIntensity
                               < std::numeric_limits<long long>::max(),
                    "LuminousIntensity dimension is out of bound.");
      static_assert(Dividend::Angle - Divisor::Angle > std::numeric_limits<long long>::min()
                        && Dividend::Angle - Divisor::Angle < std::numeric_limits<long long>::max(),
                    "Angle dimension is out of bound.");

#pragma endregion

      using Type
          = Dimensions<Dividend::Length - Divisor::Length, Dividend::Mass - Divisor::Mass,
                       Dividend::Time - Divisor::Time, Dividend::Current - Divisor::Current,
                       Dividend::Temperature - Divisor::Temperature, Dividend::Amount - Divisor::Amount,
                       Dividend::LuminousIntensity - Divisor::LuminousIntensity, Dividend::Angle - Divisor::Angle>;
    };
  }
}
