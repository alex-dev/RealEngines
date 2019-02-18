#pragma once
#include "numerics.hpp"
#include "quantities/named_quantities.hpp"

namespace quantities {
  namespace units {
    // SI base units from the BIPM's SI brochure 8, section 2.1.2, table 1,
    // http://www.bipm.org/en/si/si_brochure/chapter2/2-1/.
    constexpr Length Metre;
    constexpr Mass Kilogram;
    constexpr Time Second;
    constexpr Current Ampere;
    constexpr Temperature Kelvin;
    constexpr Amount Mole;
    constexpr LuminousIntensity Candela;
    // Not a base unit in the SI.
    constexpr Angle Radian;

    // Gram, for use with prefixes.
    constexpr Mass Gram = 1e-3 * Kilogram;

    // Coherent derived units in the SI with special names and symbols
    // From the BIPM's SI brochure 8, section 2.2.2, table 3,
    // http://www.bipm.org/en/si/si_brochure/chapter2/2-2/table3.html.
    // We exclude the Becquerel, Gray and Sievert as they are weakly typed.
    // The Celsius only really makes sense as an affine temperature and is not taken
    // care of here.
    constexpr SolidAngle Steradian = Radian * Radian;
    constexpr Frequency Hertz = 1 / Second;
    constexpr Force Newton = Metre * Kilogram / (Second * Second);
    constexpr Pressure Pascal = Newton / (Metre * Metre);
    constexpr Energy Joule = Newton * Metre;
    constexpr Power Watt = Joule / Second;
    constexpr Charge Coulomb = Ampere * Second;
    constexpr Voltage Volt = Watt / Ampere;
    constexpr Capacitance Farad = Coulomb / Volt;
    constexpr Resistance Ohm = Volt / Ampere;
    constexpr Conductance Siemens = Ampere / Volt;
    constexpr MagneticFlux Weber = Volt * Second;
    constexpr MagneticFluxDensity Tesla = Weber / (Metre * Metre);
    constexpr Inductance Henry = Weber / Ampere;
    constexpr LuminousFlux Lumen = Candela * Steradian;
    constexpr CatalyticActivity Katal = Mole / Second;

    // Non-SI units accepted for use with the SI
    // From the BIPM's SI brochure 8, section 4.1, table 6,
    // http://www.bipm.org/en/si/si_brochure/chapter4/table6.html
    constexpr Time Minute = 60 * Second;
    constexpr Time Hour = 60 * Minute;
    constexpr Time Day = 24 * Hour;

    constexpr Angle Degree = numerics::π / 180 * Radian;
    constexpr Angle ArcMinute = numerics::π / 10800 * Radian;
    constexpr Angle ArcSecond = numerics::π / 648000 * Radian;

    constexpr Area Hectare = 1e4 * Metre * Metre;
    constexpr Volume Litre = 1e-3 * Metre * Metre * Metre;

    constexpr Mass Tonne = 1e3 * Kilogram;
  }
}
