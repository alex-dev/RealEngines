#pragma once
#include "quantities/units/si.hpp"

namespace quantities {
  namespace units {
    // This namespace contains the imperial units as defined by the international
    // yard and pound agreement, as well as the units of the English Engineering
    // system.
    namespace uk {
      constexpr Mass Pound = 0.45359237 * Kilogram;
      constexpr Mass Ounce = Pound / 16;
      constexpr Mass Drachm = Pound / 256;
      constexpr Mass Grain = Pound / 7000;
      constexpr Mass Stone = 14 * Pound;
      constexpr Mass Quarter = 2 * Stone;
      constexpr Mass Hundredweight = 4 * Quarter;
      constexpr Mass Ton = 20 * Hundredweight;

      constexpr Length Yard = 0.9144 * Metre;
      constexpr Length Foot = Yard / 3;
      constexpr Length Inch = Foot / 12;
      constexpr Length Thou = Inch / 1000;
      constexpr Length Chain = 22 * Yard;
      constexpr Length Furlong = 10 * Chain;
      constexpr Length Mile = 8 * Furlong;
      constexpr Length League = 3 * Mile;
      constexpr Length Link = Chain / 100;
      constexpr Length Rod = Chain / 4;

      constexpr Area Perch = pow<2>(Rod);
      constexpr Area Rood = Furlong * Rod;
      constexpr Area Acre = Furlong * Chain;

      constexpr Volume FluidOunce = 28.4130625 * Milli(Litre);
      constexpr Volume Gill = 5 * FluidOunce;
      constexpr Volume Pint = 4 * Gill;
      constexpr Volume Quart = 2 * Pint;
      constexpr Volume Gallon = 4 * Quart;

      constexpr Force PoundForce = Pound * StandardGravity;
      constexpr Power HorsePower = 550 * PoundForce * Foot / Second;
      constexpr Pressure PoundPerSquareInch = PoundForce / pow<2>(Inch);

      namespace admiralty {
        constexpr Length NauticalMile = 6080 * Foot;
        constexpr Length Cable = NauticalMile / 10;
        constexpr Length Fathom = Cable / 100;
      }
    }
  }
}
