#pragma once
#include "base/not_constructible.hpp"

namespace quantities {
  namespace dimensions {
    /// <remarks>Angles are strongly typed</remarks>
    template<long long LengthExponent, long long MassExponent, long long TimeExponent, long long CurrentExponent,
             long long TemperatureExponent, long long AmountExponent, long long LuminousIntensityExponent, long long AngleExponent>
    struct Dimensions : base::not_constructible {
      static const long long Length = LengthExponent;
      static const long long Mass = MassExponent;
      static const long long Time = TimeExponent;
      static const long long Current = CurrentExponent;
      static const long long Temperature = TemperatureExponent;
      static const long long Amount = AmountExponent;
      static const long long LuminousIntensity = LuminousIntensityExponent;
      static const long long Angle = AngleExponent;
    };

    /// <remarks>Represent a double in our quantities framework.</remarks>
    using NoDimensions = Dimensions<0, 0, 0, 0, 0, 0, 0, 0>;

    using Length = Dimensions<1, 0, 0, 0, 0, 0, 0, 0>;
    using Mass = Dimensions<0, 1, 0, 0, 0, 0, 0, 0>;
    using Time = Dimensions<0, 0, 1, 0, 0, 0, 0, 0>;
    using Current = Dimensions<0, 0, 0, 1, 0, 0, 0, 0>;
    using Temperature = Dimensions<0, 0, 0, 0, 1, 0, 0, 0>;
    using Amount = Dimensions<0, 0, 0, 0, 0, 1, 0, 0>;
    using LuminousIntensity = Dimensions<0, 0, 0, 0, 0, 0, 1, 0>;
    using Angle = Dimensions<0, 0, 0, 0, 0, 0, 0, 1>;
  }
}
