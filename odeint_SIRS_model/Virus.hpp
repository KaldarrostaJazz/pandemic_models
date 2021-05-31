#ifndef VIRUS_HPP
#define VIRUS_HPP
struct Virus {
  double beta;     // infection rate
  double gamma;    // inverse of the infection period
  double epsilon;  // inverse of the recovery rate
  Virus(double beta, double gamma, double epsilon)
      : beta(beta), gamma(gamma), epsilon(epsilon) {}
};
#endif
