#ifndef LEAST_SQUARES_HPP
#define LEAST_SQUARES_HPP
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>

#include "Pandemy.hpp"

double Chi_Square(std::vector<State> const& data_values,
                  std::vector<State> const& theoretical_values);
Virus get_parameters(std::vector<State> const& pandemic_data, double precision);
#endif
