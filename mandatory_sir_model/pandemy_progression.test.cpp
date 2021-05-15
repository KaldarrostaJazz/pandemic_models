#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Pandemy.hpp"
#include "doctest.h"

TEST_CASE("TEST PROGRESSION N. 1") {
  {
    State default_state{};
    Virus default_virus{};
    Pandemy default_pandemy;
    auto const progression = default_pandemy.progression(15);
    CHECK(default_state.S == 900.);
    CHECK(default_state.I == 100.);
    CHECK(default_state.R == 0.);
    CHECK(default_state.i_sigma == doctest::Approx(9.4868));
    CHECK(default_virus.beta == 0.8);
    CHECK(default_virus.gamma == 0.5);
    CHECK(default_pandemy.get_state() == default_state);
    CHECK(default_pandemy.get_virus() == default_virus);
    for (int i = 0; i != 15; ++i) {
	    CHECK(doctest::Approx(progression[i].N) == default_state.N);
    }
    /*CHECK(progression[0] == {900., 100., 0.});
    CHECK(progression[1] == ({(doctest::Approx(828.)), (doctest::Approx(122.)),
                              (doctest::Approx(50.))}));
    CHECK(progression[2] ==
          ({(doctest::Approx(747.1872)), (doctest::Approx(141.8128)),
            (doctest::Approx(111.))}));
    CHECK(progression[3] ==
          ({(doctest::Approx(662.418632)), (doctest::Approx(155.674967)),
            (doctest::Approx(181.9064))}));
    CHECK(progression[4] ==
          ({(doctest::Approx(579.9210337)), (doctest::Approx(160.3350827)),
            (doctest::Approx(259.7438836))}));
    CHECK(progression[5] ==
          ({(doctest::Approx(505.535684)), (doctest::Approx(154.5528909)),
            (doctest::Approx(339.9114249))}));
    CHECK(progression[6] ==
          ({(doctest::Approx(443.030083)), (doctest::Approx(139.7820466)),
            (doctest::Approx(417.1878704))}));
    CHECK(progression[7] ==
          ({(doctest::Approx(393.4879617)), (doctest::Approx(119.4341447)),
            (doctest::Approx(487.0788937))}));
    CHECK(progression[8] ==
          ({(doctest::Approx(355.8915579)), (doctest::Approx(97.31297605)),
            (doctest::Approx(546.795466))}));
    CHECK(progression[9] ==
          ({(doctest::Approx(328.1852646)), (doctest::Approx(76.36278135)),
            (doctest::Approx(595.451954))}));
    CHECK(progression[10] ==
          ({(doctest::Approx(308.1363529)), (doctest::Approx(58.23030236)),
            (doctest::Approx(633.6333447))}));
    CHECK(progression[11] ==
          ({(doctest::Approx(293.7820545)), (doctest::Approx(43.46944958)),
            (doctest::Approx(662.7484959))}));
    CHECK(progression[12] ==
          ({(doctest::Approx(283.5656192)), (doctest::Approx(31.95116015)),
            (doctest::Approx(684.4832207))}));
    CHECK(progression[13] ==
          ({(doctest::Approx(276.3174188)), (doctest::Approx(23.22378049)),
            (doctest::Approx(700.4588007))}));
    CHECK(progression[14] ==
          ({(doctest::Approx(271.1837107)), (doctest::Approx(16.74559831)),
            (doctest::Approx(712.070691))}));*/
  }
}
