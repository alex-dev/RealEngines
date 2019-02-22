#pragma once
#include <unordered_set>
#include <quantities.hpp>
#include "thermodynamics/gas.hpp"

namespace solver {
  namespace thermodynamics {
    class Mixture {
    public:
      constexpr quantities::Pressure p();
      constexpr quantities::Temperature T();
      constexpr quantities::Density ρ();
      constexpr quantities::SpecificVolume v();

    private:
      std::unordered_set<Gas> gases;
    };
  }
}
