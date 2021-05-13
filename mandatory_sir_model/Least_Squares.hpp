#ifndef LEAST_SQUARES_HPP
#define LEAST_SQUARES_HPP
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>

#include "Pandemy.hpp"

double Chi_Square(std::vector<State> const& data_values,
                  std::vector<State> const& theoretical_values) {
  std::vector<double> deviations{};
  int stop = std::min(data_values.size(), theoretical_values.size());
  for (int day = 0; day != stop; ++day) {
    double dev = std::pow((data_values[day].I - theoretical_values[day].I), 2) / data_values[day].I;
    deviations.push_back(dev);
  }
  double Chi_Square = std::accumulate(deviations.begin(), deviations.end(), 0);
  return Chi_Square;
}
Virus get_parameters(std::vector<State> const& pandemic_data, int N) {
  Virus data_virus;
  std::vector<double> chi_squares{};
  for (double beta = 0.0; beta <= 1.0; beta += 0.1) {
    data_virus.beta = beta;
    for (double gamma = 0.0; gamma <= 1.0; gamma += 0.1) {
      data_virus.gamma = gamma;
      Pandemy lattice_curve = {N, pandemic_data[0], data_virus};
      auto const computed_data =
          lattice_curve.progression(pandemic_data.size());
      chi_squares.push_back(Chi_Square(pandemic_data, computed_data));
    }
  }
  auto it = std::min_element(chi_squares.begin(), chi_squares.end());
  int index = std::distance(chi_squares.begin(), it);
  int b = index / 11, g = index % 11;
  double beta = b / 10., gamma = g / 10.;
  Virus parameter = {beta, gamma};
  return parameter;
}
#endif
