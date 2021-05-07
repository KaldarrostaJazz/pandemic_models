#include <fstream>
#include <iostream>

#include "Pandemy.hpp"

/*********************************************************************************
void print(std::vector<State> const& result) {
  int day = 1;
  std::ofstream output_file;
  output_file.open("prog.dat");
  for (auto& state : result) {
    std::cout << "*--------------------------------------------------*" << '\n';
    std::cout << "S = " << state.S << " I = " << state.I << " R = " << state.R
              << '\n';
    output_file << "Day = " << day << "S = " << state.S << " I = " << state.I
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
    std::cout << i << " " << state.S << " " << state.I << " " << state.R
              << '\n';
    output_file << i << " " << state.S << " " << state.I << " " << state.R << '\n';
    ++i;
  }
  output_file.close();
}
int main() {
  int N;
  std::cout << "Enter N: ";
  std::cin >> N;
  Virus virus;
  std::cout << "Enter virus parameters:" << '\n';
  std::cout << "Beta: ";
  std::cin >> virus.beta;
  std::cout << "Gamma: ";
  std::cin >> virus.gamma;
  State s;
  std::cout << "Enter initial conditions: " << '\n';
  std::cout << "S = ";
  std::cin >> s.S;
  std::cout << "I = ";
  std::cin >> s.I;
  std::cout << "R = ";
  std::cin >> s.R;
  double D;
  std::cout << "Enter duration: ";
  std::cin >> D;
  Pandemy pandemy{N, s, virus};
  auto const& states = pandemy.progression(D);
  // print(states);
  print_simple(states);
}
