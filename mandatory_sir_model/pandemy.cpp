#include "Pandemy.hpp"
#include <cassert>

#include <cmath>

std::vector<State> Pandemy::progression(int const& D) const {
  std::vector<State> result{state};
  double const& beta = virus.beta;
  double const& gamma = virus.gamma;
  for (int i = 1; i != D; ++i) {
    auto const& last = result.back();
    State s{};
    s.S = last.S - round((beta / people) * last.S * last.I);
    s.I = last.I + round((beta / people) * last.S * last.I) -
          round(gamma * last.I);
    s.R = last.R + round(gamma * last.I);
    assert(s.S + s.R + s.I == people);
    result.push_back(s);
  }
  return result;
}
