#ifndef PROGRESSION_HPP
#define PROGRESSION_HPP
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
  Pandemy(int const people = 0, State const& state = {0, 0, 0},
          Virus const& virus = {0.0, 0.0})
      : people{people}, state{state}, virus{virus} {
    if (state.S < 0 || state.I < 0 || state.R < 0) {
      throw std::range_error("S, I and R must be positive integer values!");
    } else if (people != state.S + state.I + state.R) {
      throw std::range_error("It must be N = S + I + R");
    } else if (virus.beta < 0. || virus.beta > 1. || virus.gamma < 0. ||
               virus.gamma > 1.) {
      throw std::range_error("Beta and gamma must be in the range [0. ; 1.]");
    }
  }
  std::vector<State> progression(int D) const;
  std::vector<State> get_data(std::string& file) const;
};
#endif
