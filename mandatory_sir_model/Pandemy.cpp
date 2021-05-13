#include "Pandemy.hpp"

#include <cmath>
#include <fstream>
std::vector<State> Pandemy::progression(int D) const {
  std::vector<State> result{state};
  double const beta = virus.beta;
  double const gamma = virus.gamma;
  for (int day = 1; day != D; ++day) {
    auto const last = result.back();
    State s{};
    s.S = last.S - round((beta / people) * last.S * last.I);
    s.I = last.I + round((beta / people) * last.S * last.I) -
          round(gamma * last.I);
    s.R = last.R + round(gamma * last.I);
    assert(people == s.S + s.R + s.I);
    result.push_back(s);
  }
  return result;
}
std::vector<State> Pandemy::get_data(std::string& file) const {
  std::vector<State> pandemic_data{};
  int day, S, I, R;
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
