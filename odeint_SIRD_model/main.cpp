#include <boost/numeric/odeint.hpp>
#include <cmath>
#include <iostream>

#include "Sird_odeint.hpp"
#include "Virus.hpp"

void print_simple(state_type const& x, double t) {
  std::cout << t << " " << round(x[0]) << " " << round(x[1]) << " " << round(x[2]) << '\n';
}

int main() {
  double beta, gamma, epsilon, S, I, R, d;
  std::cin >> beta >> gamma >> epsilon >> S >> I >> R >> d;
  Virus virus{beta, gamma, epsilon};
  state_type x{S, I, R};
  Pandemy pandemy{virus};
  boost::numeric::odeint::runge_kutta4<state_type> step;
  boost::numeric::odeint::integrate_const(step, pandemy, x, 0.0, d, 1.0,
                                          print_simple);
}
