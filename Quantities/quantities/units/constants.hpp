#pragma once
#include "quantities/units/si.hpp"

namespace quantities {
  namespace units {
    // Defining constants for the SI, by resolution A of the 26th meeting of the CGPM.
    constexpr Speed SpeedOfLight = 299'792'458 * (Metre / Second);
    constexpr Action PlanckConstant = 6.626'070'15e-34 * Joule * Second;
    constexpr Charge ElementaryCharge = 1.602'176'634e-19 * Coulomb;
    constexpr Entropy BoltzmannConstant = 1.380'649e-23 * (Joule / Kelvin);
    constexpr Inverse<Amount> AvogadroConstant = 6.022'140'76e23 * (1 / Mole);
    constexpr Quotient<Entropy, Amount> GasConstant = BoltzmannConstant * AvogadroConstant;

    // We use the 2014 CODATA recommended values.  We do not support uncertainties.
    constexpr double FineStructureConstant = 7.297'352'5664e-3;
    constexpr Quotient<GravitationalParameter, Mass> GravitationalConstant
        = 6.674'08e-11 * Newton * pow<2>(Metre) / pow<2>(Kilogram);

    constexpr Mass ElectronMass = 9.109'382'91e-31 * Kilogram;
    constexpr Mass ProtonMass = 1.672'621'777e-27 * Kilogram;

    constexpr Acceleration StandardGravity = 9.80665 * Metre / pow<2>(Second);

    constexpr Permeability VacuumPermeability
      = 2 * FineStructureConstant * PlanckConstant * Steradian / (pow<2>(ElementaryCharge) * SpeedOfLight);
    constexpr Permittivity VacuumPermittivity
        = pow<2>(ElementaryCharge) / (2 * FineStructureConstant * PlanckConstant * SpeedOfLight * Steradian);

    // Units derived from the defining constants.
    constexpr Energy ElectronVolt = ElementaryCharge * Volt;
    constexpr Mass Dalton = (Gram / Mole) / AvogadroConstant;
  }
}
