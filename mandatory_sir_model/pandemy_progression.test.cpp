#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Pandemy.hpp"
#include "doctest.h"

bool operator==(State const& left, State const& right) {
  return left.S == right.S && left.I == right.I && left.R == right.R;
}
bool operator==(Virus const& left, Virus const& right) {
  return left.beta == right.beta && left.gamma == right.gamma;
}
bool operator==(Pandemy const& left, Pandemy const& right) {
  return left.get_state() == right.get_state() && left.get_virus() == right.get_virus();
}

TEST_CASE("TEST PROGRESSION N. 1") {
  {
    State default_state{};
    Virus default_virus{};
    Pandemy default_pandemy;
    CHECK(default_state == ({900., 100., 0.}));
    CHECK(default_state.i_sigma == (doctest::Approx(9.4868)));
    CHECK(default_virus == ({0.8, 0.5}));
    CHECK(default_pandemy == ({({900., 100., 0.}), ({0.8, 0.5})}));
    CHECK(default_pandemy.progression(15)[0] ==
          ({(doctest::Approx(900.)), (doctest::Approx(100.)), (doctest::Approx(0.))}));
    CHECK(default_pandemy.progression(15)[1] ==
          ({(doctest::Approx(828.)), (doctest::Approx(122.)), (doctest::Approx(50.))}));
    CHECK(default_pandemy.progression(15)[2] == ({(doctest::Approx(747.1872)),
                                                 (doctest::Approx(141.8128)),
                                                 (doctest::Approx(111.))}));
    CHECK(default_pandemy.progression(15)[3] == ({(doctest::Approx(662.418632)),
                                                 (doctest::Approx(155.674967)),
                                                 (doctest::Approx(181.9064))}));
    CHECK(default_pandemy.progression(15)[4] == ({(doctest::Approx(579.9210337)),
                                                 (doctest::Approx(160.3350827)),
                                                 (doctest::Approx(259.7438836))}));
    CHECK(default_pandemy.progression(15)[5] == ({(doctest::Approx(505.535684)),
                                                 (doctest::Approx(154.5528909)),
                                                 (doctest::Approx(339.9114249))}));
    CHECK(default_pandemy.progression(15)[6] == ({(doctest::Approx(443.030083)),
                                                 (doctest::Approx(139.7820466)),
                                                 (doctest::Approx(417.1878704))}));
    CHECK(default_pandemy.progression(15)[7] == ({(doctest::Approx(393.4879617)),
                                                 (doctest::Approx(119.4341447)),
                                                 (doctest::Approx(487.0788937))}));
    CHECK(default_pandemy.progression(15)[8] == ({(doctest::Approx(355.8915579)),
                                                 (doctest::Approx(97.31297605)),
                                                 (doctest::Approx(546.795466))}));
    CHECK(default_pandemy.progression(15)[9] == ({(doctest::Approx(328.1852646)),
                                                 (doctest::Approx(76.36278135)),
                                                 (doctest::Approx(595.451954))}));
    CHECK(default_pandemy.progression(15)[10] ==
          ({(doctest::Approx(308.1363529)), (doctest::Approx(58.23030236)),
           (doctest::Approx(633.6333447))}));
    CHECK(default_pandemy.progression(15)[11] ==
          ({(doctest::Approx(293.7820545)), (doctest::Approx(43.46944958)),
           (doctest::Approx(662.7484959))}));
    CHECK(default_pandemy.progression(15)[12] ==
          ({(doctest::Approx(283.5656192)), (doctest::Approx(31.95116015)),
           (doctest::Approx(684.4832207))}));
    CHECK(default_pandemy.progression(15)[13] ==
          ({(doctest::Approx(276.3174188)), (doctest::Approx(23.22378049)),
           (doctest::Approx(700.4588007))}));
    CHECK(default_pandemy.progression(15)[14] == ({(doctest::Approx(271.1837107)),
                                                  (doctest::Approx(16.74559831)),
                                                  (doctest::Approx(712.070691))}));
  }
}
