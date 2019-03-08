#include <cmath>
#include <chrono>
#include <limits>
#include <unordered_map>
#include <CppUnitTest.h>
#include <numerics/square_root.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::chrono;
namespace num = numerics::implementation;

namespace tests {
  namespace numerics {
    TEST_CLASS(SquareRoot) {
    private:
      double const positiveZero = +0;
      double const negativeZero = -0;
      double const NaN = std::numeric_limits<double>::quiet_NaN();
      double const infinity = std::numeric_limits<double>::infinity();
      std::unordered_map<double, double> const precise_data{
          {1, 1},
          {2, 1.414213562373095048801688724209698078569671875376948073176},
          {3, 1.732050807568877293527446341505872366942805253810380628055},
          {4, 2},
          {5, 2.236067977499789696409173668731276235440618359611525724270},
          {6, 2.449489742783178098197284074705891391965947480656670128432},
          {7, 2.645751311064590590501615753639260425710259183082450180368},
          {2e53, 4.4721359549995793928183473374625524708812367192230514e26}};
      std::unordered_map<double, double> const imprecise_data{
          {2.66666666666, 1.6329931618534108240125354589461888234150640485653962}};

    public:
      TEST_METHOD(ShouldConstexprCalculatePreciseCloseToKnownValue) {
        for (auto const& [radicand, root] : precise_data) {
          volatile double const std_result = std::sqrt(radicand);
          volatile double const num_result = num::constexpr_sqrt(radicand);

          Assert::IsTrue((root - std_result) / root - (root - num_result) / root
                             <= std::numeric_limits<double>::epsilon(),
                         L"Numerics is less precise than stdlib.");
        }
      }

      TEST_METHOD(ShouldConstexprCalculateImpreciseCloseToKnownValue) {
        for (auto const& [radicand, root] : imprecise_data) {
          volatile double const std_result = std::sqrt(radicand);
          volatile double const num_result = num::constexpr_sqrt(radicand);

          Assert::IsTrue((root - std_result) / root - (root - num_result) / root
                             <= std::numeric_limits<double>::epsilon(),
                         L"Numerics is less precise than stdlib.");
        }
      }

      TEST_METHOD(ShouldConstexprCalculateCorrectInfinity) {
        Assert::AreEqual(infinity, num::constexpr_sqrt(infinity), 0,
                         L"Numerics doesn't return infinity.");
      }

      TEST_METHOD(ShouldConstexprCalculateCorrectPositiveZero) {
        Assert::AreEqual(positiveZero, num::constexpr_sqrt(positiveZero), 0,
                         L"Numerics doesn't return +0.");
      }

      TEST_METHOD(ShouldConstexprCalculateCorrectNegativeZero) {
        Assert::AreEqual(negativeZero, num::constexpr_sqrt(negativeZero), 0,
                         L"Numerics doesn't return -0.");
      }

      TEST_METHOD(ShouldConstexprHandleNaNError) {
        Assert::AreEqual(NaN, num::constexpr_sqrt(NaN), 0, L"Numerics doesn't return NaN.");
      }

      TEST_METHOD(ShouldConstexprHandleDomainError) {
        Assert::AreEqual(NaN, num::constexpr_sqrt(-1), 0, L"Numerics doesn't return NaN.");
      }
    };
  }
}