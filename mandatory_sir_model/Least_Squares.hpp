#ifndef LEAST_SQUARES_HPP
#define LEAST_SQUARES_HPP
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>

#include "Pandemy.hpp"

double Chi_Square(std::vector<State> const& data_values,
                  std::vector<State> const& theoretical_values) {
  std::vector<double> deviations{};
  int stop = std::min(data_values.size(), theoretical_values.size());
  for (int day = 0; day != stop; ++day) {
    double deviation =
        std::pow((data_values[day].I - theoretical_values[day].I) /
                     data_values[day].i_sigma,
                 2);
    deviations.push_back(deviation);
  }
  //double Chi_Square = std::accumulate(deviations.begin(), deviations.end(), 0);
  double Chi_Square = 0.;
  for (auto it = deviations.begin(); it != deviations.end(); ++it) {
	  Chi_Square += *it;
  }
  assert(Chi_Square >= 0.);
  return Chi_Square;
}
Virus get_parameters(std::vector<State> const& pandemic_data) {
  std::vector<double> chi_squares{};
  for (double beta = 0.0; beta < 1.0; beta += 0.01) {
    for (double gamma = 0.0; gamma < 1.0; gamma += 0.01) {
      Virus data_virus{beta, gamma};
      Pandemy lattice_curve{pandemic_data[0], data_virus};
      auto const computed_data =
          lattice_curve.progression(pandemic_data.size());
      chi_squares.push_back(Chi_Square(pandemic_data, computed_data));
    }
  }
  auto it = std::min_element(chi_squares.begin(), chi_squares.end());
  int index = std::distance(chi_squares.begin(), it);
  int b = index / 100, g = index % 100;
  double beta = b / 100., gamma = g / 100.;
  Virus parameter{beta, gamma};
  return parameter;
}
#endif
