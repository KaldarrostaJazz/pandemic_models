#include "Sird_odeint.hpp"
#include <algorithm>
#include <numeric>
void Pandemy::operator()(state_type const& x, state_type& dxdt,
                         double const /*t*/) {
  dxdt[0] = -(virus.beta / std::accumulate(x.begin(), x.end(), 0.)) * x[0] * x[1];  // susceptibles
  dxdt[1] =
      (virus.beta / std::accumulate(x.begin(), x.end(), 0.)) * x[0] * x[1] - virus.gamma * x[1];  // infected
  dxdt[2] = virus.gamma * (1 - virus.f) * x[1];                  // removed
  dxdt[3] = virus.gamma * virus.f * x[1];                        // deads
}
