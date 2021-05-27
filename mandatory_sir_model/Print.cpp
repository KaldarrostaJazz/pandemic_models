#include "Print.hpp"

#include <iostream>

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
/*void print_fitting(std::vector<State> const& data, std::vector<State> const&
fit) { std::ifstream file_to_read{data_name}; std::ofstream
file_to_write{"sir_fitting_predictions.csv"}; file_to_write <<
"day,data_S,fit_S,data_I,fit_I,data_R,fit_R" << '\n'; for (auto& state : fit) {
                int day, S, I, R;
                file_to_read >> d >> S >> I >> R;
                file_to_write << day << "," << S << "," << state.S << "," << I
<< "," << state.I << "," << R << "," << state.R << '\n'; assert(state.N -
(state.S + state.I + state.R) > -0.001); assert(state.N - (state.S + state.I +
state.R) > 0.001);
        }
        file_to_read.close();
        file_to_write.close();
}*/
