#ifndef PARSER_HPP
#define PARSER_HPP
#include <iostream>
#include <lyra/lyra.hpp>

#include "Least_Squares.hpp"
#include "Pandemy.hpp"
#include "Print.hpp"

struct Command {
  double beta;
  double gamma;
  double S;
  double I;
  double R;
  int duration;
  double precision = 0.01;
  std::string file_name;
  bool show_help = false;

  Command(lyra::cli& cli);

  void sir_command(lyra::group const& group);
  void fit_command(const lyra::group& group);
};
#endif
