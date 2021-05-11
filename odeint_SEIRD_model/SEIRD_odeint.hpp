#ifndef SEIRD_ODEINT_HPP
#define SEIRD_ODEINT_HPP
#include <vector>

#include "Virus.hpp"
typedef std::vector<double> state_type;
class Pandemy {
 private:
  int people;
  Virus virus;

 public:
  Pandemy(int const& people, Virus const& virus)
      : people(people), virus(virus) {}
  void operator()(state_type const& x, state_type& dxdt, double const /*t*/);
};
#endif
