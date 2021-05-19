#ifndef SIRD_ODEINT_HPP
#define SIRD_ODEINT_HPP
#include <vector>

#include "Virus.hpp"
typedef std::vector<double> state_type;
class Pandemy {
 private:
  Virus virus;

 public:
  Pandemy(Virus const& virus) : virus(virus) {}
  void operator()(state_type const& x, state_type& dxdt, double const /*t*/);
};
#endif
