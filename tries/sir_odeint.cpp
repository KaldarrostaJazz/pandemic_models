#include <boost/array.hpp>
#include <boost/numeric/odeint.hpp>

double const b = 0.1;
double const g = 0.05;
int const N = 100;

typedef boost::array<double, 3> state;

void sir(state const& x, state  &dxdt, double t) {
  dxdt[0] = -(b / N) * x[0] * x[1];
  dxdt[1] = (b / N) * x[0] * x[1] - g * x[1];
  dxdt[2] = g * x[1];
}

void print_sir(state const& x, double const t) {
  std::cout << t << " " << x[0] << " " << x[1] << " " << x[2] << '\n';
}

int main() {
  state x = {99., 1., 0.};  // intial conditions
  boost::numeric::odeint::integrate(sir, x, 0.0, 200.0, 0.1, print_sir);
}
