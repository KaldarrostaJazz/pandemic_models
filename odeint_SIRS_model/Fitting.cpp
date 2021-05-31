
#include "Fitting.hpp"

#include <algorithm>
#include <boost/numeric/odeint.hpp>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>
std::vector<state_type> Fitting::data_acquisition(
    std::string const& file_name) const {
  std::vector<state_type> data;
  std::ifstream in{file_name};
  if (!in) throw std::runtime_error("The choosen path is invalid");
  while (in.good()) {
    double day, S, I, R;
    in >> day >> S >> I >> R;
    state_type x{S, I, R};
    data.push_back(x);
  }
  in.close();
  return data;
}
double Fitting::Chi_Square(std::vector<state_type> const& data_values,
                           std::vector<state_type> const& theoretical_values) {
  int stop = std::min(data_values.size(), theoretical_values.size());
  double Chi_Square = 0.;
  for (int day = 0; day != stop; ++day) {
    Chi_Square +=
        std::pow((data_values[day][1] - theoretical_values[day][1]), 2) /
        theoretical_values[day][1];
  }
  assert(Chi_Square >= 0.);
  return Chi_Square;
}
Virus Fitting::get_parameters(std::vector<state_type> const& pandemic_data) {
  double d = pandemic_data.size();
  std::vector<double> chi_squares;
  for (double beta = 0.0; beta < 1.0; beta += 0.01) {
    for (double gamma = 0.0; gamma < 1.0; gamma += 0.01) {
      for (double epsilon = 0.0; epsilon < 1.0; epsilon += 0.01) {
        Virus data_virus{beta, gamma, epsilon};
        std::vector<state_type> computed_data;
        state_type x = pandemic_data[0];
	Push_back push {computed_data};
        Pandemy lattice_curve{data_virus};
        boost::numeric::odeint::runge_kutta4<state_type> step;
        boost::numeric::odeint::integrate_const(step, lattice_curve, x, 0.0, d, 1.0, push);
        chi_squares.push_back(Chi_Square(pandemic_data, computed_data));
      }
    }
    std::cout << beta << " ";
  }
  auto it = std::min_element(chi_squares.begin(), chi_squares.end());
  std::cout << "Chi Square = " << *it << '\n';
  int index = std::distance(chi_squares.begin(), it);
  int b = index / 10000;
  int pg = index - b * 10000;
  int g = pg / 100;
  int e = pg % 100;
  double beta = b * 0.01, gamma = g * 0.01, epsilon = e * 0.01;
  Virus parameter{beta, gamma, epsilon};
  return parameter;
}

