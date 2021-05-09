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
    s.S = last.S - (beta / people) * last.S * last.I;
    s.I = last.I + (beta / people) * last.S * last.I - gamma * last.I;
    s.R = last.R + gamma * last.I;
    assert(Pandemy::people == round(s.S + s.I + s.R));
    result.push_back(s);
  }
  return result;
}
