
#ifndef FITTING_HPP
#define FITTING_HPP
#include <string>

#include "Sirs_odeint.hpp"

struct Push_back {
  std::vector<state_type>& m_states;
  Push_back(std::vector<state_type>& states)
      : m_states{states} {}

  void operator()(const state_type& x, double /*t*/) {
    m_states.push_back(x);
  }
};
class Fitting {
 public:
  Fitting() = default;
  std::vector<state_type> data_acquisition(std::string const& file_name) const;
  double Chi_Square(std::vector<state_type> const& data_values,
                    std::vector<state_type> const& theoretical_values);
  Virus get_parameters(std::vector<state_type> const& pandemic_data);
};
#endif
