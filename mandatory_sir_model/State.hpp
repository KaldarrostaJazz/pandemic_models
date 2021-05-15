#ifndef STATE_HPP
#define STATE_HPP
#include <cmath>
struct State {
  double S;
  double I;
  double R;
  State(double susceptibles = 900., double infected = 100., double removed = 0.)
      : S(susceptibles), I(infected), R(removed) {}
  double N = S + I + R;
  double i_sigma = std::sqrt(I * (N - I) / N);
};
bool operator==(State const& left, State const& right);
#endif
