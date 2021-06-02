#ifndef STATE_HPP
#define STATE_HPP
#include <cmath>
#include <stdexcept>
struct State {
  double S;
  double I;
  double R;
  State(double S = 900., double I = 100., double R = 0.) : S{S}, I{I}, R{R} {
    if (S < 0. || I < 0. || R < 0.)
      throw std::range_error("S, I, R must be positive values\n");
    if (S == 0. && I == 0. && R == 0.)
      throw std::range_error("At least one value must be != 0.\n");
  }
  double N = S + I + R;
  double i_sigma = std::sqrt(I * (N - I) / N);
};
bool operator==(State const& left, State const& right);
State copy_round(State const& state);
#endif
