#include "SEIRD_odeint.hpp"
void Pandemy::operator()(state_type const& x, state_type& dxdt, double const /*t*/) {
  dxdt[0] = -(virus.beta / people) * x[0] * x[2];  // susceptibles
  dxdt[1] = (virus.beta / people) * x[0] * x[2] - virus.alpha * x[1];  // exposed
  dxdt[2] = virus.alpha * x[1] - x[2] / virus.T;                 // infected
  dxdt[3] = (1 - virus.f) * x[2] / virus.T;                      // removed
  dxdt[4] = virus.f * x[2] / virus.T;                            // deads
}
