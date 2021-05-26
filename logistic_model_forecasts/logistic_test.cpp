#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "logistic_model.hpp"

TEST_CASE("TEST LOGISTIC PROGRESSION N. 1") {
	std::array<double, 3> p {200., 300., 0.2};
  Logistic covid {p};
  CHECK(covid.cases_t(4) == doctest::Approx(1.472768265));
  CHECK(covid.dcases_t(15) == doctest::Approx(2.352516021));
}
