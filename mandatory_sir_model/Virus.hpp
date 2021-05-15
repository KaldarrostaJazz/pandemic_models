#ifndef VIRUS_HPP
#define VIRSU_HPP
struct Virus {
  double beta;
  double gamma;
  Virus(double beta = 0.8, double gamma = 0.5) : beta(beta), gamma(gamma) {}
};
bool operator==(Virus const& left, Virus const& right);
#endif
