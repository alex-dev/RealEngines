#include "cubic_root.hpp"
#include <pmmintrin.h>
#include <limits>

namespace {
  static const __m128d sign_bit = _mm_castsi128_pd(_mm_cvtsi64_si128(0x8000'0000'0000'0000));
  static const __m128d sign_exponent_and_sixteen_bits_of_mantissa
      = _mm_castsi128_pd(_mm_cvtsi64_si128(0xFFFF'FFF0'0000'0000));
  constexpr unsigned long long C = 0x2A9F7893782DA1CE;

  // No overflow or underflow occurs in intermediate computations for
  // y ∈ [y₁, y₂].
  // NOTE(egg): the σs do not rescale enough to put the least normal or greatest
  // finite magnitudes inside the non-rescaling range; for very small and very
  // large values, rescaling occurs twice.
  constexpr double y₁ = 0x1p-225;
  constexpr double σ₁ = 0x1p-154;
  constexpr double σ₁⁻³ = 1 / (σ₁ * σ₁ * σ₁);
  constexpr double y₂ = 0x1p237;
  constexpr double σ₂ = 0x1p154;
  constexpr double σ₂⁻³ = 1 / (σ₂ * σ₂ * σ₂);

  static_assert(σ₁⁻³ * y₁ == y₂, L"Incorrect σ₁");
  static_assert(σ₂⁻³ * y₂ == y₁, L"Incorrect σ₂");
}

namespace numerics {
  // Computes ∛y with a maximal error in [0.50005, 0.50022] ULPs; the result is
  // incorrectly rounded for approximately 5 inputs per million.
  double cbrt(double radicand) {
    __m128d const y_0 = _mm_set_sd(radicand);
    __m128d const sign = _mm_and_pd(sign_bit, y_0);
    __m128d const abs_y_0 = _mm_andnot_pd(sign_bit, y_0);
    double const abs_y = _mm_cvtsd_f64(abs_y_0);

    if(radicand != radicand) {
      // The usual logic will produce a qNaN when given a NaN, but will not
      // preserve the payload and will signal overflows (q will be a nonsensical
      // large radicand, and q³ will overflow).  Further, the rescaling comparisons
      // will signal the invalid operation exception for quiet NaNs (although that
      // would be easy to work around using the unordered compare intrinsics).
      return radicand + radicand;
    }

    // TODO(egg): we take the absolute radicand two or three times when going through
    // the rescaling paths; consider having a cbrt_positive function, or a
    // cbrt_positive_unscaled function and four rescaling paths.
    if(abs_y < y₁) {
      if(abs_y == 0) {
        return radicand;
      }

      return cbrt(radicand * σ₁⁻³) * σ₁;
    } else if(abs_y > y₂) {
      if(abs_y == std::numeric_limits<double>::infinity()) {
        return radicand;
      }

      return cbrt(radicand * σ₂⁻³) * σ₂;
    }

    // Approximate ∛y with an error below 3,2 %.  The radicand of C is chosen to
    // minimize the maximal error of ξ as an approximation of ∛y, ignoring
    // rounding.
    unsigned long long const Y = _mm_cvtsi128_si64(_mm_castpd_si128(abs_y_0));
    unsigned long long const Q = C + Y / 3;
    double const q = _mm_cvtsd_f64(_mm_castsi128_pd(_mm_cvtsi64_si128(Q)));
    double const q³ = q * q * q;
    // An approximation of ∛y with a relative error below 2⁻¹⁵.
    double const ξ = q - (q³ - abs_y) * q / (2 * q³ + abs_y);
    double const x = _mm_cvtsd_f64(_mm_and_pd(_mm_set_sd(ξ), sign_exponent_and_sixteen_bits_of_mantissa));
    // One round of 6th order Householder.
    double const x³ = x * x * x;
    double const x⁶ = x³ * x³;
    double const y² = radicand * radicand;
    double const x_sign_y = _mm_cvtsd_f64(_mm_or_pd(_mm_set_sd(x), sign));
    double const numerator = x_sign_y * (x³ - abs_y) * ((5 * x³ + 17 * abs_y) * x³ + 5 * y²);
    double const denominator = (7 * x³ + 42 * abs_y) * x⁶ + (30 * x³ + 2 * abs_y) * y²;

    return x_sign_y - numerator / denominator;
  }
}
