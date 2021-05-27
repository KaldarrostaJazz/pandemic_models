#ifndef PROGRESSION_HPP
#define PROGRESSION_HPP
#include <string>
#include <vector>

#include "State.hpp"
#include "Virus.hpp"
class Pandemy {
 private:
  State state{};
  Virus virus{};

 public:
  Pandemy() = default; 
  Pandemy(State const& m_state, Virus const& m_virus)
      : state{m_state}, virus{m_virus} {}
  State get_state() const { return state; }
  Virus get_virus() const { return virus; }
  std::vector<State> progression(int const duration) const;
  std::vector<State> get_data(std::string const& file);
};
#endif
