#include <limits>
#include <unordered_map>
#include <CppUnitTest.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests {
  namespace numerics {
    TEST_CLASS(SquareRoot) {
    private:
	  double const positiveZero = +0;
	  double const negativeZero = -0;
	  double const NaN = std::numeric_limits<double>::quiet_NaN();
	  double const infinity = std::numeric_limits<double>::infinity();
      std::unordered_map<double, double> const data {
		{1, 1}, {2, 1.414213562373095048801688724209698078569671875376948073176},
		{3, 1.732050807568877293527446341505872366942805253810380628055}, {4, 2},
		{5, 2.236067977499789696409173668731276235440618359611525724270},
		{6, 2.449489742783178098197284074705891391965947480656670128432},
		{7, 2.645751311064590590501615753639260425710259183082450180368},
		{2e53, 4.4721359549995793928183473374625524708812367192230514e26},
		{2.66666666666, 1.6329931618534108240125354589461888234150640485653962}
	  };

    public:

	  TEST_METHOD(ShouldCalculateCloseToKnownValue) {
		// TODO: Ici, votre code de test
	  }

	  TEST_METHOD(ShouldCalculateCorrectInfinity) {
		  // TODO: Ici, votre code de test
	  }

	  TEST_METHOD(ShouldCalculateCorrectPositiveZero) {
		  // TODO: Ici, votre code de test
	  }

	  TEST_METHOD(ShouldCalculateCorrectNegativeZero) {
		  // TODO: Ici, votre code de test
	  }

	  TEST_METHOD(ShouldHandleNaNError) {
		  // TODO: Ici, votre code de test
	  }

	  TEST_METHOD(ShouldHandleDomainError) {
		  // TODO: Ici, votre code de test
	  }
    };
  }
}