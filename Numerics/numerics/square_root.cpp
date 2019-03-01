#include "square_root.hpp"
#include <pmmintrin.h>

namespace numerics {
  double sqrt(double radicand) {
    __m128d const x_128d = _mm_set_sd(radicand);
    return _mm_cvtsd_f64(_mm_sqrt_sd(x_128d, x_128d));
  }
}
