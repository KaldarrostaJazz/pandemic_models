#ifndef LOGISTIC_MODEL_HPP
#define LOGISTIC_MODEL_HPP
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
int const max_number_of_iterations = 10000;
class Logistic {
 public:
  Logistic(std::array<double, 3> parameters)
      : K{parameters[0]}, A{parameters[1]}, r{parameters[2]} {}
  double K, A, r;
  double cases_t(int t);
  double dcases_t(int t);
  std::array<double, 3> cases_grad(int t_end);
  void log(int t_end);
};
class Acquisition {
 public:
  Acquisition(std::string& file_name) : file_name{file_name} {}
  std::string file_name;
  std::vector<int> Data();
  std::vector<int> dData();
};
class Fit {
 public:
  Fit(double m, double k, double alpha, std::string& file_name)
      : m{m}, k{k}, alpha{alpha}, file_name{file_name} {
    if (alpha <= 0. || alpha >= 1.)
      throw std::range_error(
          "Invalid value for alpha. Valid values: [0. < aplha < 1.]");
    if (m <= 0. || k <= m)
      throw std::range_error(
          "Invalid value for (m, k). Valid values: k > m > 0.");
  }
  double m, k;
  double alpha;
  std::string file_name;
  Acquisition pandemy {file_name};
  std::array<double, 3> initial_guess();
  double variance(Logistic& theoretical_pandemy);
  double std_dev(Logistic& theoretical_pandemy);
  std::array<double, 3> var_grad(Logistic& theoretical_pandemy);
  std::array<double, 3> steepest_descent(std::array<double, 3> const& delta);
};
#endif
