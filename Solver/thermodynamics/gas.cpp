#include "gas.hpp"

namespace solver {
  namespace thermodynamics {
    constexpr Gas::Gas(std::shared_ptr<MolecularGas>&& gas, Amount n, Mass m)
        : gas(gas), n(n), m(m) {}

    constexpr std::string const& Gas::Name::get() const {
      return reference.name;
    }

    constexpr double const& Gas::γ::get() const {
      return reference.γ;
    }

    constexpr Entropy const& Gas::Cv::get() const {
      return reference.Cv;
    }

    constexpr Entropy const& Gas::Cp::get() const {
      return reference.Cp;
    }

    constexpr SpecificGasConstant const& Gas::R::get() const {
      return reference.R;
    }

    constexpr MolarMass const& Gas::M::get() const {
      return reference.M;
    }

    constexpr std::optional<MolarMass> const& Gas::UnitMass::get() const {
      return reference.unitMass;
    }
  }
}
