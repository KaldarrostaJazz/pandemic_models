#ifndef PRINT_HPP
#define PRINT_HPP
#include "Pandemy.hpp"

void print(std::vector<State> const& result);
void print_simple(std::vector<State> const& result);
void print_fitting(std::vector<State> const& data,
                   std::vector<State> const& fit);
#endif
