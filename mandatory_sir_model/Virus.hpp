#ifndef VIRUS_HPP
#define VIRSU_HPP
#include <cassert>
struct Virus {
  double beta;
  double gamma;
  Virus(double beta = 0.8, double gamma = 0.5) : beta(beta), gamma(gamma) {}
  // assert(0. < beta && beta < 1.);
  // assert(0. < gamma && gamma < 1.);
};
bool operator==(Virus const& left, Virus const& right);
#endif
