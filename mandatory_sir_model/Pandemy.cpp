#include "Pandemy.hpp"

#include <cassert>
#include <cmath>
#include <cstring>
#include <fstream>
#include <stdexcept>
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
    double diff = people - (current.S + current.I + current.R);
    if (diff < -0.001 || diff > 0.001) {
      if (current.R > 1.) {
        current.R = people - (current.S + current.I);
      } else {
        current.S = people - (current.I + current.R);
      }
    }
    assert(-0.001 < diff && diff < 0.001);
    result.push_back(current);
  }
  return result;
}
std::vector<State> Pandemy::get_data(std::string const& file) {
  std::vector<State> pandemic_data{};
  double day, S, I, R;
  std::ifstream data_file{file};
  if (!data_file) {
    throw std::runtime_error(
        "The choosen file doens't exist. Maybe you've entered the wrong path.");
  }
  while (data_file.good()) {
    data_file >> day >> S >> I >> R;
    State s{S, I, R};
    pandemic_data.push_back(s);
  }
  data_file.close();
  return pandemic_data;
}
