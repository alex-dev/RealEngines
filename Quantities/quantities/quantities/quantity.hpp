#pragma once
#include <type_traits>
#include "base/augmented_assignment.hpp"
#include "quantities/dimensions/traits.hpp"
#include "quantities/operations.hpp"

namespace quantities {
  namespace quantities {
    template<typename Dimensions>
    struct Quantity final : base::simple_augmented_assignment<Quantity<Dimensions>>,
                            base::advanced_augmented_assignment<Quantity<Dimensions>, unsigned long long>,
                            base::advanced_augmented_assignment<Quantity<Dimensions>, long long>,
                            base::advanced_augmented_assignment<Quantity<Dimensions>, double> {
      static_assert(dimensions::is_dimensions_v<Dimensions>,
                    "Dimensions is not a valid dimensions.");

      typedef Dimensions Dimensions;

    public:
      static constexpr Quantity infinity() noexcept;
      static constexpr Quantity NaN() noexcept;

      constexpr Quantity() noexcept;

    protected:
      double value;

    private:
      constexpr Quantity(double value) noexcept;

#pragma region Friend Declarations

#pragma region Boolean Operators

      template<typename Value>
      friend constexpr bool operator>(Value const& left, Value const& right);
      template<typename Value>
      friend constexpr bool operator<(Value const& left, Value const& right);
      template<typename Value>
      friend constexpr bool operator>=(Value const& left, Value const& right);
      template<typename Value>
      friend constexpr bool operator<=(Value const& left, Value const& right);
      template<typename Value>
      friend constexpr bool operator==(Value const& left, Value const& right);
      template<typename Value>
      friend constexpr bool operator!=(Value const& left, Value const& right);

#pragma endregion

#pragma region Simple Arithmetic Operators

      template<typename Value>
      friend constexpr Value operator+(Value const& value);
      template<typename Value>
      friend constexpr Value operator-(Value const& value);

      template<typename Value>
      friend constexpr Value operator+(Value const& left, Value const& right);
      template<typename Value>
      friend constexpr Value operator-(Value const& left, Value const& right);

#pragma endregion

#pragma region Complex Arithmetic Operators

      template<typename Left, typename Right>
      friend constexpr Product<Left, Right> operator*(Left const& left, Right const& right);
      template<typename Left>
      friend constexpr Product<Left, double> operator*(Left const& left, double const& right);
      template<typename Right>
      friend constexpr Product<double, Right> operator*(double const& left, Right const& right);

      template<typename Left, typename Right>
      friend constexpr Quotient<Left, Right> operator/(Left const& left, Right const& right);
      template<typename Left>
      friend constexpr Quotient<Left, double> operator/(Left const& left, double const& right);
      template<typename Right>
      friend constexpr Quotient<double, Right> operator/(double const& left, Right const& right);

#pragma endregion

#pragma region Elementary Functions

      template<typename Left, typename Right>
      friend constexpr Product<Left, Right> fma(Left const& x, Right const& y, Product<Left, Right> const& z);
      template<typename Value>
      friend constexpr Value abs(Value const& value);

      template<typename Radicand>
      friend constexpr SquareRoot<Radicand> sqrt(Radicand const& radicand);
      template<typename Radicand>
      friend constexpr CubicRoot<Radicand> cbrt(Radicand const& radicand);
      template<short exponent, typename Base>
      friend constexpr Exponentiation<Base, exponent> pow(Base const& base);

#pragma endregion

#pragma region Trigonometry Functions

      friend double sin(Quantity<dimensions::Angle> const& α);
      friend double cos(Quantity<dimensions::Angle> const& α);
      friend double tan(Quantity<dimensions::Angle> const& α);
      friend Quantity<dimensions::Angle> asin(double const x);
      friend Quantity<dimensions::Angle> acos(double const x);
      friend Quantity<dimensions::Angle> atan(double const x);
      friend Quantity<dimensions::Angle> atan(double const y, double const x);

      friend double sinh(Quantity<dimensions::Angle> const& α);
      friend double cosh(Quantity<dimensions::Angle> const& α);
      friend double tanh(Quantity<dimensions::Angle> const& α);
      friend Quantity<dimensions::Angle> asinh(double const x);
      friend Quantity<dimensions::Angle> acosh(double const x);
      friend Quantity<dimensions::Angle> atanh(double const x);

#pragma endregion

#pragma endregion
    };
  }
}

#include "boolean_operators.ipp"
#include "complex_arithmetic_operators.ipp"
#include "elementary_functions.ipp"
#include "quantity.ipp"
#include "simple_arithmetic_operators.ipp"
#include "trigonometric_functions.ipp"
