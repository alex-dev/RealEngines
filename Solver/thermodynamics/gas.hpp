#pragma once
#include <memory>
#include <quantities.hpp>
#include <string>
#include "thermodynamics/molecular_gas.hpp"

namespace solver {
  namespace thermodynamics {
    class Gas {
    public:
      constexpr Gas(std::shared_ptr<MolecularGas> && gas, quantities::Amount && n, quantities::Mass && m);

      /// <summary>Quantity in mole.</summary>
      quantities::Amount n;

      /// <summary>Mass.</summary>
      quantities::Mass m;

#pragma region MolecularGas accessors

      constexpr std::string const & name() const;

      /// <summary>Isentropic expansion factor or specific heat ratio.</summary>
      constexpr double const & γ() const;

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

#pragma endregion

    private:
      std::shared_ptr<MolecularGas> gas;
    };
  }
}
