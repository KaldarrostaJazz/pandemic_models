#ifndef STATE_HPP
#define STATE_HPP
#include <cmath>
#include <cassert>
struct State {
  double S;
  double I;
  double R;
  State(double susceptibles = 900., double infected = 100., double removed = 0.)
      : S(susceptibles), I(infected), R(removed) {}
  double N = S + I + R;
  double i_sigma = std::sqrt(I * (N - I) / N);
  //assert(S > 0. && I > 0. && R > 0.);
};
#endif
