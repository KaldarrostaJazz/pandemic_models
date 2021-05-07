#include <boost/array.hpp>
#include <boost/numeric/odeint.hpp>

double const beta = 0.1;
double const gamma = 0.05;

typedef boost::array<double , 3> state;

void sir(state const& x, state const& dxdt, double t) {
	dxdt[0] = -beta * x[0] * x[1];
	dxdt[1] = beta * x[0] * x[1] - gamma*x[1];
	dxdt[2] = gamma * x[1];
}

void print_sir(state const& x, double const t) {
	std::cout << t << " " << x[0] << " " << x[1] << " " << x[2] << '\n';
}

int main() {
	state x = {0.99, 0.01, 0.0}; //intial conditions
	boost::numeric::odeint::integrate(sir, x, 0.0, 200.0, 0.1, print_sir);
}
