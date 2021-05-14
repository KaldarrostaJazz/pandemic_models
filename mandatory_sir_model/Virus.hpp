#ifndef VIRUS_HPP
#define VIRSU_HPP
#include <cassert>
struct Virus {
  double beta;
  double gamma;
  Virus(double beta, double gamma) : beta(beta), gamma(gamma) {}
  assert(0. < beta && beta < 1.);
  assert(0. < gamma && gamma < 1.);
};
#endif
