#ifndef PRINT_HPP
#define PRINT_HPP
#include <fstream>

void print(std::vector<State> const& result) {
  int day = 1;
  for (auto& state : result) {
    std::cout << "*--------------------------------------------------*" << '\n';
    std::cout << "Day = " << day << "S = " << state.S << " I = " << state.I
              << " R = " << state.R << '\n';
    ++day;
  }
}

void print_simple(std::vector<State> const& result) {
  int day = 1;
  for (auto& state : result) {
    std::cout << day << " " << state.S << " " << state.I << " " << state.R
              << '\n';
    ++day;
  }
}
#endif
