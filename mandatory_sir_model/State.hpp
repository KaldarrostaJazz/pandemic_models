#ifndef STATE_HPP
#define STATE_HPP
#include <cmath>
#include <stdexcept>
struct State {
  double S;
  double I;
  double R;
  State(double susceptibles = 900., double infected = 100., double removed = 0.)
      : S(susceptibles), I(infected), R(removed) {
      if (S < 0. || I < 0. || R < 0.) {
      throw std::range_error("S, I, R must be positive values");
      }
      }
  double N = S + I + R;
  double i_sigma = std::sqrt(I * (N - I) / N);
};
bool operator==(State const& left, State const& right);
#endif
