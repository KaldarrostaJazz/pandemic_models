#include <boost/array.hpp>
#include <boost/numeric/odeint.hpp>
#include <iostream>

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
  double const d, b, g;
  int const N;
  double S, I, R;
  std::cin >> N >> b >> g >> S >> I >> R >> d;
  state x = {S, I, R};  // intial conditions
  boost::numeric::odeint::integrate(sir, x, 0.0, d, 0.1, print_sir);
}
