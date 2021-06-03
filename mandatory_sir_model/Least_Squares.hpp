#ifndef LEAST_SQUARES_HPP
#define LEAST_SQUARES_HPP
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>

#include "Pandemy.hpp"

class Least_Squares {
 private:
  std::vector<State> pandemic_data;

 public:
  Least_Squares(std::vector<State> const& pandemic_data)
      : pandemic_data{pandemic_data} {}
  double Chi_Square(std::vector<State> const& data_values,
                    std::vector<State> const& theoretical_values);
  Virus get_parameters(double precision);
};
#endif
