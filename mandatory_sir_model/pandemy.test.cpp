#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Pandemy.hpp"
#include "Least_Squares.hpp"
#include "doctest.h"

TEST_CASE("TEST PROGRESSION N. 1") {
    State default_state{};
    Virus default_virus{};
    Pandemy default_pandemy;
    auto const progression = default_pandemy.progression(11);
    CHECK(default_state.S == 900.);
    CHECK(default_state.I == 100.);
    CHECK(default_state.R == 0.);
    CHECK(default_state.i_sigma == doctest::Approx(9.4868));
    CHECK(default_virus.beta == 0.8);
    CHECK(default_virus.gamma == 0.5);
    CHECK(default_pandemy.get_state() == default_state);
    CHECK(default_pandemy.get_virus() == default_virus);
    for (int i = 0; i != 11; ++i) {
      CHECK(doctest::Approx(progression[i].N) == default_state.N);
    }
    CHECK(progression[0].S == doctest::Approx(900.));
    CHECK(progression[0].I == doctest::Approx(100.));
    CHECK(progression[0].R == doctest::Approx(0.));
    CHECK(progression[1].S == doctest::Approx(828.));
    CHECK(progression[1].I == doctest::Approx(122.));
    CHECK(progression[1].R == doctest::Approx(50.));
    CHECK(progression[2].S == doctest::Approx(747.1872));
    CHECK(progression[2].I == doctest::Approx(141.8128));
    CHECK(progression[2].R == doctest::Approx(111.));
    CHECK(progression[3].S == doctest::Approx(662.418632));
    CHECK(progression[3].I == doctest::Approx(155.674967));
    CHECK(progression[3].R == doctest::Approx(181.9064));
    CHECK(progression[4].S == doctest::Approx(579.9210337));
    CHECK(progression[4].I == doctest::Approx(160.3350827));
    CHECK(progression[4].R == doctest::Approx(259.7438836));
    CHECK(progression[5].S == doctest::Approx(505.535684));
    CHECK(progression[5].I == doctest::Approx(154.5528909));
    CHECK(progression[5].R == doctest::Approx(339.9114249));
    CHECK(progression[6].S == doctest::Approx(443.030083));
    CHECK(progression[6].I == doctest::Approx(139.7820466));
    CHECK(progression[6].R == doctest::Approx(417.1878704));
    CHECK(progression[7].S == doctest::Approx(393.4879617));
    CHECK(progression[7].I == doctest::Approx(119.4341447));
    CHECK(progression[7].R == doctest::Approx(487.0788937));
    CHECK(progression[8].S == doctest::Approx(355.8915579));
    CHECK(progression[8].I == doctest::Approx(97.31297605));
    CHECK(progression[8].R == doctest::Approx(546.795466));
    CHECK(progression[9].S == doctest::Approx(328.1852646));
    CHECK(progression[9].I == doctest::Approx(76.36278135));
    CHECK(progression[9].R == doctest::Approx(595.451954));
    CHECK(progression[10].S == doctest::Approx(308.1363529));
    CHECK(progression[10].I == doctest::Approx(58.23030236));
    CHECK(progression[10].R == doctest::Approx(633.6333447));
}
TEST_CASE("TEST FITTING N. 1") {
	Pandemy default_pandemy;
	Virus default_virus{};
	auto const data_to_fit = default_pandemy.progression(200);
	Virus computed_virus = get_parameters(data_to_fit);
	CHECK(computed_virus == default_virus);
}
