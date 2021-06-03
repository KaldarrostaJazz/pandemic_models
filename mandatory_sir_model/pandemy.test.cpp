#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Least_Squares.hpp"
#include "Pandemy.hpp"
#include "doctest.h"

TEST_CASE("TEST PROGRESSION N. 1") {
  State default_state{};
  Virus default_virus{};
  Pandemy default_pandemy;
  auto const progression = default_pandemy.progression(6);
  CHECK(default_state.S == 900.);
  CHECK(default_state.I == 100.);
  CHECK(default_state.R == 0.);
  CHECK(default_state.i_sigma == doctest::Approx(9.4868));
  CHECK(default_virus.beta == 0.8);
  CHECK(default_virus.gamma == 0.5);
  CHECK(default_pandemy.get_state() == default_state);
  CHECK(default_pandemy.get_virus() == default_virus);
  for (int i = 0; i != 6; ++i) {
    CHECK(doctest::Approx(progression[i].N) == default_state.N);
  }
  CHECK(progression[0].S == doctest::Approx(900.));
  CHECK(progression[1].I == doctest::Approx(122.));
  CHECK(progression[2].R == doctest::Approx(111.));
  CHECK(progression[3].S == doctest::Approx(662.418632));
  CHECK(progression[4].I == doctest::Approx(160.3350827));
  CHECK(progression[5].R == doctest::Approx(339.9114249));
}
TEST_CASE("TEST FITTING N. 1") {
  Pandemy default_pandemy;
  Virus default_virus{};
  auto const data_to_fit = default_pandemy.progression(200);
  Least_Squares fitting{data_to_fit};
  Virus computed_virus = fitting.get_parameters(0.01);
  CHECK(computed_virus == default_virus);
}
TEST_CASE("TEST PROGRESSION N. 2") {
  State initial_state{50000., 200.};
  Virus virus{0.7, 0.4};
  Pandemy pandemy{initial_state, virus};
  auto const progression = pandemy.progression(20);
  CHECK(progression[8].S == doctest::Approx(46874.23));
  CHECK(progression[12].I == doctest::Approx(3396.296));
  CHECK(progression[19].R == doctest::Approx(19145.16));
  for (int i = 0; i != 20; ++i) {
    CHECK(doctest::Approx(progression[i].N) == initial_state.N);
  }
}
