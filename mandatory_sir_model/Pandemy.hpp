#ifndef PROGRESSION_HPP
#define PROGRESSION_HPP
#include <stdexcept>
#include <iostream>
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
    } else if (virus.beta < 0. || virus.beta > 1. || virus.gamma < 0. || virus.gamma > 1.) {
      throw std::runtime_error("Beta and gamma must be in the range [0. ; 1.]");
    }
  }
  std::vector<State> progression(int const& D) const;
  /*std::vector<State> progression(int const& D) const {
    std::vector<State> result{state};
    double const& beta = virus.beta;
    double const& gamma = virus.gamma;
    for (int i = 1; i != D; ++i) {
      auto const& last = result.back();
      State s{};
      s.S = last.S - (beta / people) * last.S * last.I;
      s.I = last.I + (beta / people) * last.S * last.I - gamma * last.I;
      s.R = last.R + gamma * last.I;
      result.push_back(s);
    }
    return result;
  }*/
};
#endif
