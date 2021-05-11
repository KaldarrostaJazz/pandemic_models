#include <fstream>
#include <iostream>
#include <boost/numeric/odeint.hpp>
#include "Virus.hpp"

typedef std::vector<double> state_type;
Virus virus;
int people;
void pandemy (state_type const& x, state_type& dxdt, double const t) {
  dxdt[0] = -(virus.beta / people) * x[0] * x[2];  // susceptibles
  dxdt[1] = (virus.beta / people) * x[0] * x[2] - virus.alpha * x[1];  // exposed
  dxdt[2] = virus.alpha * x[1] - x[2] / virus.T;                 // infected
  dxdt[3] = (1 - virus.f) * x[2] / virus.T;                      // removed
  dxdt[4] = virus.f * x[2] / virus.T;                            // deads
}

void print_simple(state_type const& x, double t) {
	std::cout << t << " " << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << " " << x[4] << '\n';
}

int main() {
	double S, E, I, R, D;
	std::cin >> people >> S >> E >> I >> R >> D;
	std::cin >> virus.beta >> virus.alpha >> virus.T >> virus.f;
	double d;
	std::cin >> d;
	state_type x = {S, E, I, R, D};
	boost::numeric::odeint::runge_kutta4<state_type> step;
	boost::numeric::odeint::integrate_const(step, pandemy, x, 0.0, d, 1.0, print_simple);
}
