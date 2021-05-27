#include "Least_Squares.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>

#include "Pandemy.hpp"

double Chi_Square(std::vector<State> const& data_values,
                  std::vector<State> const& theoretical_values) {
  int stop = std::min(data_values.size(), theoretical_values.size());
  double Chi_Square = 0.;
  for (int day = 0; day != stop; ++day) {
    Chi_Square += std::pow((data_values[day].I - theoretical_values[day].I) /
                               data_values[day].i_sigma,
                           2);
  }
  assert(Chi_Square >= 0.);
  return Chi_Square;
}
Virus get_parameters(std::vector<State> const& pandemic_data,
                     double precision) {
  std::vector<double> chi_squares{};
  for (double beta = 0.0; beta < 1.0; beta += precision) {
    for (double gamma = 0.0; gamma < 1.0; gamma += precision) {
      Virus data_virus{beta, gamma};
      Pandemy lattice_curve{pandemic_data[0], data_virus};
      auto const computed_data =
          lattice_curve.progression(pandemic_data.size());
      chi_squares.push_back(Chi_Square(pandemic_data, computed_data));
    }
  }
  auto it = std::min_element(chi_squares.begin(), chi_squares.end());
  std::cout << "Chi Square = " << *it << '\n';
  int index = std::distance(chi_squares.begin(), it);
  int p = 1 / precision;
  int b = index / p, g = index % p;
  double beta = b * precision, gamma = g * precision;
  Virus parameter{beta, gamma};
  return parameter;
}
