#include "State.hpp"
#include <iostream>

bool operator==(State const& left, State const& right) {
  return left.S == right.S && left.I == right.I && left.R == right.R;
}
State copy_round(State const& state) {
	State rounded_state;
	rounded_state.N = round(state.N);
	rounded_state.S = round(state.S);
	rounded_state.I = round(state.I);
	rounded_state.R = round(state.R);
	if (rounded_state.N != rounded_state.S + rounded_state.I + rounded_state.R) {
		if (rounded_state.R > 1.) {
			rounded_state.R = rounded_state.N - (rounded_state.S + rounded_state.I);
		} else {
			rounded_state.S = rounded_state.N - (rounded_state.I + rounded_state.R);
		}
	}
	assert(rounded_state.N - (rounded_state.I + rounded_state.I + rounded_state.R) > -0.001); 
	assert(rounded_state.N - (rounded_state.I + rounded_state.I + rounded_state.R) < 0.001);
	return rounded_state;
}
