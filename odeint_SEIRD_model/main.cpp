#include <boost/numeric/odeint.hpp>
#include <cmath>
#include <fstream>
#include <iostream>

#include "SEIRD_odeint.hpp"
#include "Virus.hpp"

void print_simple(state_type const& x, double t) {
  std::cout << t << " " << x[0] << " " << x[1] << " " << x[2] << " " << x[3]
            << " " << x[4] << '\n';
}

int main() {
  int N;
  Virus virus;
  double S, E, I, R, D, d;
  std::cin >> N >> virus.beta >> virus.alpha >> virus.T >> virus.f >> S >> E >>
      I >> R >> D >> d;
  state_type x = {S, E, I, R, D};
  Pandemy pandemy = {N, virus};
  boost::numeric::odeint::runge_kutta4<state_type> step;
  boost::numeric::odeint::integrate_const(step, pandemy, x, 0.0, d, 1.0,
                                          print_simple);
}
