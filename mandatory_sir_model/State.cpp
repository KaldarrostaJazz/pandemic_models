#include "State.hpp"

bool operator==(State const& left, State const& right) {
  return left.S == right.S && left.I == right.I && left.R == right.R;
}
