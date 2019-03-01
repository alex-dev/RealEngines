#pragma once
#include <optional>
#include <string>
#include <default_readonly_property.hpp>
#include "thermodynamics/quantities.hpp"

namespace solver {
  namespace thermodynamics {
    class MolecularGas {
    public:
      constexpr MolecularGas(std::string const&& name, Entropy const Cp, Entropy const Cv, MolarMass const M);
      constexpr MolecularGas(std::string const&& name, Entropy const Cp, Entropy const Cv,
                             MolarMass const M, Density const unitMass);

      properties::DefaultReadOnlyProperty<std::string> const name;

      /// <summary>Isentropic expansion factor or specific heat ratio.</summary>
      properties::DefaultReadOnlyProperty<double> const γ;

      /// <summary>Isobaric heat capacity.</summary>
      properties::DefaultReadOnlyProperty<Entropy> const Cp;

      /// <summary>Isochoric heat capacity.</summary>
      properties::DefaultReadOnlyProperty<Entropy> const Cv;

      /// <summary>Specific gas constant.</summary>
      properties::DefaultReadOnlyProperty<SpecificGasConstant> const R;

      /// <summary>Molar mass.</summary>
      properties::DefaultReadOnlyProperty<MolarMass> const M;

      /// <summary>Represent, in KSP, density of a resource in kg/unit. If null, it is simply not a
      /// resource handled by KSP and should never cross into managed code.</summary>
      properties::DefaultReadOnlyProperty<std::optional<MolarMass>> const unitMass;
    };
  }
}
