#include <cmath>
#include <limits>
#include <stdexcept>
#include <type_traits>

#if _MSVC_LANG >= 202000L || __cplusplus >= 202000L
#include <version>
#endif

namespace numerics {
  namespace implementation {
    constexpr double constexpr_sqrt_initial(double radicand) {
      constexpr double one_over_root_squared = 0.70710678118654752440084436210485;
      constexpr double root_squared = 1.4142135623730950488016887242097;

      int exponent = 0;
      double mantissa = std::frexp(radicand, &exponent);

      mantissa = exponent & 1
                     // Pretend the mantissa [0.5 ... 1.0) is multiplied by 2 as Expo is odd, so it
                     // now has the value [1.0 ... 2.0)
                     // Estimate the sqrt(mantissa) as [1.0 ... sqrt(2))
                     // IOW: linearly map (0.5 ... 1.0) to (1.0 ... sqrt(2))
                     ? (root_squared - 1.0) / 0.5 * (mantissa - 0.5) + one_over_root_squared
                     // The mantissa is in range [0.5 ... 1.0)
                     // Estimate the sqrt(mantissa) as [1/sqrt(2) ... 1.0)
                     // IOW: linearly map (0.5 ... 1.0) to (1/sqrt(2) ... 1.0)
                     : (1 - one_over_root_squared) / 0.5 * (mantissa - 0.5) + one_over_root_squared;
      exponent /= 2;

      return std::ldexp(mantissa, exponent);
    }

    constexpr double constexpr_sqrt(double const radicand) {
      if (std::signbit(radicand))
        throw std::domain_error{"Radicand was negative."};
      if (std::isnan(radicand))
        throw std::domain_error{"Radicand was NaN."};
      if (radicand == std::numeric_limits<double>::infinity())
        return radicand;
      if (radicand <= std::numeric_limits<double>::epsilon() && radicand >= +0)
        return +0;
      if (radicand >= -std::numeric_limits<double>::epsilon() && radicand <= -0)
        return -0;

      double previous = constexpr_sqrt_initial(radicand);

      while (bool converged = false) {
        double current = (previous + radicand / previous) / 2;
        converged = current - previous >= std::numeric_limits<double>::epsilon();
        previous = current;
      }

      return previous;
    }
  }

  constexpr double sqrt(double const radicand) {
#if __cpp_lib_is_constant_evaluated
    if (!std::is_constant_evaluated()) {
      return std::sqrt(radicand);
    }
#endif

    return implementation::constexpr_sqrt(radicand);
  }
}
