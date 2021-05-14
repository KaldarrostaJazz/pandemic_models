#ifndef STATE_HPP
#define STATE_HPP
#include <cmath>
#include <cassert>
struct State {
  double S;
  double I;
  double R;
  State(double susceptibles, double infected, double removed)
      : S(susceptibles), I(infected), R(removed) {}
  double N = S + I + R;
  double i_sigma = std::sqrt(I * (N - I) / N);
  assert(S > 0. && I > 0. && R > 0.);
};
#endif
