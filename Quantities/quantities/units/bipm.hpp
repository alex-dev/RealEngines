#pragma once
#include "quantities/units/si.hpp"

namespace quantities {
  namespace units {
    // This namespace contains the other non-SI units listed in the BIPM's
    // SI brochure 8, section 4.1, table 8,
    // http://www.bipm.org/en/si/si_brochure/chapter4/table8.html.
    namespace bipm {
      constexpr Pressure Bar = 1e5 * Pascal;
      constexpr Pressure MillimetreOfMercury = 133.322 * Pascal;
      constexpr Length �ngstr�m = 1e-10 * Metre;
      constexpr Length NauticalMile = 1852 * Metre;
      constexpr Speed Knot = 1 * NauticalMile / Hour;
      constexpr Area Barn = 1e-28 * pow<2>(Metre);
    }
  }
}
