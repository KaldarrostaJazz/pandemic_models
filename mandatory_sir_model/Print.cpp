#include "Print.hpp"

void print(std::vector<State> const& result) {
  int day = 1;
  for (auto& state : result) {
    State rounded_state = copy_round(state);
    std::cout << "*--------------------------------------------------*" << '\n';
    std::cout << "Day = " << day << "S = " << rounded_state.S
              << " I = " << rounded_state.I << " R = " << rounded_state.R
              << '\n';
    assert(rounded_state.N -
               (rounded_state.S + rounded_state.I + rounded_state.R) >
           -0.001);
    assert(rounded_state.N -
               (rounded_state.S + rounded_state.I + rounded_state.R) <
           0.001);
    ++day;
  }
}

void print_simple(std::vector<State> const& result) {
  int day = 1;
  for (auto& state : result) {
    State rounded_state = copy_round(state);
    std::cout << day << " " << rounded_state.S << " " << rounded_state.I << " "
              << rounded_state.R << '\n';
    assert(rounded_state.N -
               (rounded_state.S + rounded_state.I + rounded_state.R) >
           -0.001);
    assert(rounded_state.N -
               (rounded_state.S + rounded_state.I + rounded_state.R) <
           0.001);
    ++day;
  }
}
