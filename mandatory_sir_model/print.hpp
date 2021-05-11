#ifndef PRINT_HPP
#define PRINT_HPP
#include "Pandemy.hpp"

/*********************************************************************************
void print(std::vector<State> const& result) {
  int day = 1;
  std::ofstream output_file;
  output_file.open("prog.dat");
  for (auto& state : result) {
    std::cout << "*--------------------------------------------------*" << '\n';
    std::cout << "Day = " << day << "S = " << state.S << " I = " <<
state.I << " R = " << state.R
              << '\n';
    output_file << "Day = " << day << "S = " << state.S << " I = " <<
state.I
                << " R = " << state.R << '\n';
    ++day;
  }
  output_file.close();
}
*********************************************************************************/

void print_simple(std::vector<State> const& result) {
  int i = 1;
  std::ofstream output_file;
  output_file.open("prog.dat");
  for (auto& state : result) {
    std::cout << i << " " << state.S << " " << state.I << " " << state.R << " "
              << state.S + state.I + state.R << '\n';
    output_file << i << " " << state.S << " " << state.I << " " << state.R
                << '\n';
    ++i;
  }
  output_file.close();
}
#endif
