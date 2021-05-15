#include <iostream>

#include "Least_Squares.hpp"
#include "Pandemy.hpp"
#include "Print.hpp"

int main() {
  std::string option;
  std::cin >> option;
  if (option == "sir") {
    double beta, gamma, S, I, R;
    int duration;
    std::cin >> beta >> gamma >> S >> I >> R >> duration;
    std::cout << '\n';
    State initial_state{S, I, R};
    Virus virus{beta, gamma};
    Pandemy pandemy{initial_state, virus};
    auto const states = pandemy.progression(duration);
    // print(states);
    print_simple(states);
  } else if (option == "fit") {
    std::string data_file;
    std::cin >> data_file;
    Pandemy pandemy;
    auto const pandemic_data = pandemy.get_data(data_file);
    auto const virus = get_parameters(pandemic_data);
    std::cout << virus.beta << " " << virus.gamma << '\n';
  } else {
    std::cerr << "Please, insert valid option\n";
  }
}
