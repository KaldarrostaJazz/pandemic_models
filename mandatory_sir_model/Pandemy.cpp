#include "Pandemy.hpp"

#include <cassert>
#include <cmath>
#include <cstring>
#include <fstream>
std::vector<State> Pandemy::progression(int const duration) const {
  std::vector<State> result{state};
  double const beta = virus.beta;
  double const gamma = virus.gamma;
  int const people = state.S + state.I + state.R;
  for (int day = 1; day != duration; ++day) {
    auto const last = result.back();
    State current{last.S - (beta / people) * last.S * last.I,
                  last.I + (beta / people) * last.S * last.I - gamma * last.I,
                  last.R + gamma * last.I};
    if (people != current.S + current.I + current.R) {
      current.R = people - (current.S + current.I);
    }
    assert(people == current.S + current.I + current.R);
    result.push_back(current);
  }
  return result;
}
std::vector<State> Pandemy::get_data(std::string& file) {
  std::vector<State> pandemic_data{};
  double day, S, I, R;
  std::ifstream data_file;
  data_file.open(file);
  while (data_file.good()) {
    data_file >> day >> S >> I >> R;
    State s = {S, I, R};
    pandemic_data.push_back(s);
  }
  data_file.close();
  return pandemic_data;
}
