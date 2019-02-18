#pragma once
#include "quantities/units/si.hpp"
#include "quantities/units/prefixes.hpp"

namespace quantities {
  namespace units {
    // This namespace contains the non-SI units associated with the CGS and the CGS-
    // Gaussian system of units listed in the BIPM's SI brochure 8, section 4.1,
    // table 9, http://www.bipm.org/en/si/si_brochure/chapter4/table9.html.
    namespace cgs {
      constexpr Energy Erg = 1e-7 * Joule;
      constexpr Force Dyne = 1e-5 * Newton;
      constexpr Acceleration Gal = Centimetre / pow<2>(Second);

      constexpr Pressure Barye = 1 * Dyne / pow<2>(Centi(Metre));

      constexpr DynamicViscosity Poise = Barye * Second;
      constexpr KinematicViscosity Stokes = pow<2>(Centi(Metre)) / Second;

      constexpr Luminance Stilb = Candela / pow<2>(Centi(Metre));
      constexpr Illuminance Phot = Stilb * Steradian;

      constexpr MagneticFluxDensity Gauss = 1e-4 * Tesla;
      constexpr MagneticFlux Maxwell = Gauss * pow<2>(Centi(Metre));
      constexpr MagneticField Œrsted = 1e3 / (4 * π * Steradian) * Ampere / Metre;

      constexpr SpectroscopicWavenumber Kayser = 1 / Centi(Metre);
    }
  }
}
