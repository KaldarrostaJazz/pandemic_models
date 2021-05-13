#include <iostream>

#include "Pandemy.hpp"
#include "print.hpp"

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
  int D;
  std::cout << "Enter duration: ";
  std::cin >> D;
  std::cout << '\n';
  Pandemy pandemy{N, s, virus};
  auto const states = pandemy.progression(D);
  // print(states);
  print_simple(states);
}
