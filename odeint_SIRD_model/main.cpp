#include <boost/numeric/odeint.hpp>
#include <cmath>
#include <iostream>

#include "Sird_odeint.hpp"
#include "Virus.hpp"

void print_simple(state_type const& x, double t) {
  std::cout << t << " " << x[0] << " " << x[1] << " " << x[2] << " " << x[3]
            << '\n';
}

int main() {
  double beta, gamma, f, S, I, R, D, d;
  std::cin >> beta >> gamma >> f >> S >> I >> R >> D >> d;
  Virus virus{beta, gamma, f};
  state_type x{S, I, R, D};
  Pandemy pandemy{virus};
  boost::numeric::odeint::runge_kutta4<state_type> step;
  boost::numeric::odeint::integrate_const(step, pandemy, x, 0.0, d, 1.0,
                                          print_simple);
}
