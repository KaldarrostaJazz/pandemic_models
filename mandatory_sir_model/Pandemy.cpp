#include "Pandemy.hpp"

#include <cmath>
#include <fstream>
std::vector<State> Pandemy::progression(int D) const {
  std::vector<State> result{state};
  double beta = virus.beta;
  double gamma = virus.gamma;
  for (int day = 1; day != D; ++day) {
    auto const prev = result.back();
    State s{};
    s.S = prev.S - round((beta / people) * prev.S * prev.I);
    s.I = prev.I + round((beta / people) * prev.S * prev.I) -
          round(gamma * prev.I);
    s.R = prev.R + round(gamma * prev.I);
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
