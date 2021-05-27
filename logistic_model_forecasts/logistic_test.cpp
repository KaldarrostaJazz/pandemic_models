#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "logistic_model.hpp"

TEST_CASE("TEST LOGISTIC PROGRESSION N. 1") {
  std::array<double, 3> p{200., 300., 0.2};
  Logistic covid{p};
  CHECK(covid.cases_t(4) == doctest::Approx(1.472768265));
  CHECK(covid.dcases_t(15) == doctest::Approx(2.352516021));
}
TEST_CASE("TEST DATA ACQUISITION METHODS N.1") {
  std::string file_name = "class_acquisition_data_test";
  Acquisition data{file_name};
  auto const Vector = data.Data();
  auto const dVector = data.dData();
  std::vector<int> daily_cases;
  std::ifstream read_file{file_name};
  for (long unsigned int i = 0; i != Vector.size(); ++i) {
    int day, cases;
    read_file >> day >> cases;
    CHECK(Vector[i] == cases);
    daily_cases.push_back(cases);
  }
  for (long unsigned int i = 1; i != daily_cases.size(); ++i) {
    daily_cases[i] -= daily_cases[i - 1];
    CHECK(dVector[i] == daily_cases[i]);
  }
}
TEST_CASE("TEST FIT CLASS METHODS N. 1") {
  std::string file_name = "class_acquisition_data_test";
  Fit fitting{14, 35, 0.0005, file_name};
  auto const initial_parameters = fitting.initial_guess();
  CHECK(initial_parameters[0] == doctest::Approx(88414.362));
  CHECK(initial_parameters[1] == doctest::Approx(225.23008));
  CHECK(initial_parameters[2] == doctest::Approx(0.2012299));
}
