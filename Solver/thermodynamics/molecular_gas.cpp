#include "molecular_gas.hpp"

namespace solver {
  namespace thermodynamics {
    constexpr MolecularGas::MolecularGas(std::string const&& name, Entropy const Cp,
                                         Entropy const Cv, MolarMass const M)
        : name(name), γ(Cp / Cv), Cp(Cp), Cv(Cv), R(GasConstant / M), M(M), unitMass({}) {}

    constexpr MolecularGas::MolecularGas(std::string const&& name, Entropy const Cp,
                                         Entropy const Cv, MolarMass const M, Density const unitMass)
        : name(name), γ(Cp / Cv), Cp(Cp), Cv(Cv), R(GasConstant / M), M(M), unitMass(unitMass) {}
  }
}
