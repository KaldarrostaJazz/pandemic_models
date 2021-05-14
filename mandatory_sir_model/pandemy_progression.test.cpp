#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Pandemy.hpp"
#include "doctest.h"

bool State::operator==(State const& left, State const& right) {
  return left.S == right.S && left.I == right.I && left.R == right.R;
}
bool Virus::operator==(Virus const& left, Virus const& right) {
  return left.beta == right.beta && left.gamma == right.gamma;
}
bool Pandemy::operator==(Pandemy const& left, Pandemy const& right) {
  return left.state == right.state && left.virus == right.virus;
}

TEST_CASE("TEST PROGRESSION N. 1") {
  {
    State default_state{};
    Virus default_virus{};
    Pandemy default_pandemy;
    CHECK(default_state == {900., 100., 0.});
    CHECK(default_state.i_sigma == doctest::Approx(9.4868));
    CHECK(default_virus == {0.8, 0.5});
    CHECK(default_pandemy == {{900., 100., 0.}, {0.8, 0.5}});
    CHECK(default_pandemy.progression(15)[0] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
    CHECK(default_pandemy.progression(15)[1] ==
          {doctest::Approx(828.), doctest::Approx(122.), doctest::Approx(50.)});
    CHECK(default_pandemy.progression(15)[2] == {doctest::Approx(747.1872),
                                                 doctest::Approx(141.8128),
                                                 doctest::Approx(111.)});
    CHECK(default_pandemy.progression(15)[3] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
    CHECK(default_pandemy.progression(15)[4] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
    CHECK(default_pandemy.progression(15)[5] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
    CHECK(default_pandemy.progression(15)[6] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
    CHECK(default_pandemy.progression(15)[7] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
    CHECK(default_pandemy.progression(15)[8] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
    CHECK(default_pandemy.progression(15)[9] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
    CHECK(default_pandemy.progression(15)[10] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
    CHECK(default_pandemy.progression(15)[11] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
    CHECK(default_pandemy.progression(15)[12] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
    CHECK(default_pandemy.progression(15)[13] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
    CHECK(default_pandemy.progression(15)[14] ==
          {doctest::Approx(900.), doctest::Approx(100.), doctest::Approx(0.)});
  }
}
