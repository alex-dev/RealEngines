#pragma once
#include <quantities.hpp>

namespace solver {
  namespace thermodynamics {
    using Amount = quantities::Amount;
    using Density = quantities::Density;
    using Entropy = quantities::Entropy;
    using Mass = quantities::Mass;
    using MolarMass = quantities::MolarMass;

    using SpecificGasConstant = quantities::Quotient<Entropy, MolarMass>;
    
    constexpr auto GasConstant = quantities::units::GasConstant;
  }
}
