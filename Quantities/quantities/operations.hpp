#pragma once
#include <type_traits>
#include "quantities/quantities/generators.hpp"

namespace quantities {
  template<typename Left, typename Right>
  using Product = typename quantities::ProductGenerator<Left, Right>::Type;
  template<typename Dividend, typename Divisor>
  using Quotient = typename quantities::QuotientGenerator<Dividend, Divisor>::Type;
  template<typename Value>
  using Inverse = Quotient<double, Value>;

  template<typename Base, short exponent>
  using Exponentiation = typename quantities::ExponentiationGenerator<Base, exponent>::Type;
  template<typename Base>
  using Square = Exponentiation<Base, 2>;
  template<typename Base>
  using Cube = Exponentiation<Base, 3>;
  template<typename Radicand, short degree>
  using Root = typename quantities::RootGenerator<Radicand, degree>::Type;
  template<typename Radicand>
  using SquareRoot = Root<Radicand, 2>;
  template<typename Radicand>
  using CubicRoot = Root<Radicand, 3>;

  /// <remarks>The result of the <typeparamref name="order"/>-th derivative of a
  /// <typeparamref name="Value"/>-valued function with respect to its <typeparamref
  /// name="Argument"/>-valued argument.</remarks>
  template<typename Value, typename Argument, short order = 1>
  using Derivative =
      typename std::conditional_t<order == 0, Value, Quotient<Value, Exponentiation<Argument, order>>>;

  /// <remarks>The result of the <typeparamref name="order"/>-th derivative of a
  /// <typeparamref name="Value"/>-valued function with respect to
  /// <see cref="T:dimensions::Dimensions{0, 0, 1, 0, 0, 0, 0, 0}::Time"/>.</remarks>
  template<typename Value, short order = 1>
  using Variation
      = Derivative<Value, quantities::Quantity<dimensions::Dimensions<0, 0, 1, 0, 0, 0, 0, 0>>, order>;
}
