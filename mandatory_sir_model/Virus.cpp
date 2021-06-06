#include "Virus.hpp"

bool operator==(Virus const& left, Virus const& right) {
  return left.beta == right.beta && left.gamma == right.gamma;
}
