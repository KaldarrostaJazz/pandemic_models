#include <algorithm>
#include <numeric>

#include "Sirs_odeint.hpp"
void Pandemy::operator()(state_type const& x, state_type& dxdt,
                         double const /*t*/) {
  dxdt[0] =
      -(virus.beta / std::accumulate(x.begin(), x.end(), 0.)) * x[0] * x[1] +
      virus.epsilon * x[2];  // susceptibles
  dxdt[1] =
      (virus.beta / std::accumulate(x.begin(), x.end(), 0.)) * x[0] * x[1] -
      virus.gamma * x[1];                               // infected
  dxdt[2] = virus.gamma * x[1] - virus.epsilon * x[2];  // removed
}
