#ifndef VIRUS_HPP
#define VIRUS_HPP
struct Virus {
  double beta;   // infection rate
  double alpha;  // incubation rate
  int T;         // infection period
  double f;      // dead-removed ratio
};
#endif
