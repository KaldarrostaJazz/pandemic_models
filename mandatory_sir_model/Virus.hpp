#ifndef VIRUS_HPP
#define VIRSU_HPP
#include <stdexcept>
struct Virus {
  double beta;
  double gamma;
  Virus(double beta = 0.8, double gamma = 0.5) : beta{beta}, gamma{gamma} {
    if (beta < 0. || beta > 1. || gamma < 0. || gamma > 1.) {
      throw std::range_error(
          "Beta and gamma must be within the range [0.; 1.]");
    }
  }
};
bool operator==(Virus const& left, Virus const& right);
#endif
