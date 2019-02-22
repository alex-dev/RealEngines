#pragma once
#include <optional>
#include <quantities.hpp>
#include <string>

namespace solver {
  namespace thermodynamics {
    using SpecificGasConstant
        = quantities::Quotient<quantities::Entropy, quantities::Product<quantities::Amount, quantities::Mass>>;

    class MolecularGas {
    public:
      constexpr MolecularGas(std::string const && name, quantities::Entropy const && Cp,
                             quantities::MolarMass const && M);
      constexpr MolecularGas(std::string const && name, quantities::Entropy const && Cp,
                             quantities::MolarMass const && M, quantities::Density const && unitMass);

      std::string const name;

      /// <summary>Isentropic expansion factor or specific heat ratio.</summary>
      constexpr double const & γ() const {
        return _γ;
      }

      /// <summary>Isobaric heat capacity.</summary>
      constexpr quantities::Entropy const & Cp() const;

      /// <summary>Isochoric heat capacity.</summary>
      constexpr quantities::Entropy const & Cv() const;

      /// <summary>Specific gas constant.</summary>
      constexpr SpecificGasConstant const & R() const;

      /// <summary>Molar mass.</summary>
      constexpr quantities::MolarMass const & M() const;

      /// <summary>Represent, in KSP, density of a resource in kg/unit. If null, it is simply not a
      /// resource handled by KSP and should never cross into managed code.</summary>
      constexpr std::optional<quantities::Density> const & unitMass() const;

    private:
      double const _γ;
      quantities::Entropy const Cp;
      quantities::Entropy const Cv;
      SpecificGasConstant const R;
      quantities::MolarMass const M;
      std::optional<quantities::Density> const unitMass;
    };
  }
}
