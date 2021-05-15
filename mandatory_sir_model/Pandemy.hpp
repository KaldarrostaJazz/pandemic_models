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
  Pandemy() {}
  Pandemy(State const& state, Virus const& virus)
      : state(state), virus(virus) {}
  State get_state() const {return state;}
  Virus get_virus() const {return virus;}
  std::vector<State> progression(int const duration) const;
  std::vector<State> get_data(std::string& file);
};
bool operator==(Pandemy const& left, Pandemy const& right);
#endif
