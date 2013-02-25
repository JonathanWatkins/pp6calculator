#include "physics.hpp"

double invariantMass(double E, double px, double py, double pz) {
	return E*E - px*px - py*py - pz*pz;
}
