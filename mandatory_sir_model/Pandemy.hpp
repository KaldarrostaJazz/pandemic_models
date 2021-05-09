#ifndef PROGRESSION_HPP
#define PROGRESSION_HPP
#include <iostream>
#include <stdexcept>
#include <vector>

#include "State.hpp"
#include "Virus.hpp"
class Pandemy {
 private:
  int people;
  State state;
  Virus virus;

 public:
  Pandemy(int const& people, State const& state, Virus const& virus)
      : people{people}, state{state}, virus{virus} {
    if (state.S < 0 || state.I < 0 || state.R < 0) {
      throw std::runtime_error("S, I and R must be positive integer values!");
    } else if (people != state.S + state.I + state.R) {
      throw std::runtime_error("It must be N = S + I + R");
    } else if (virus.beta < 0. || virus.beta > 1. || virus.gamma < 0. ||
               virus.gamma > 1.) {
      throw std::runtime_error("Beta and gamma must be in the range [0. ; 1.]");
    }
  }
  std::vector<State> progression(int const& D) const;
};
#endif
