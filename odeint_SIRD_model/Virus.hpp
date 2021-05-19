#ifndef VIRUS_HPP
#define VIRUS_HPP
struct Virus {
  double beta;   // infection rate
  double gamma;  // inverse of the infection period
  double f;      // dead-removed ratio
  Virus(double beta, double gamma, double f) : beta(beta), gamma(gamma), f(f) {}
};
#endif
